#include "EntireSong.h"
#include "Controler.hpp"
#include <QGraphicsOpacityEffect>
#include "PlayerScene.h"

#define PIXEL_PER_MSECOND 0.3


EntireSong::EntireSong(QGraphicsItem *parent) :
	QGraphicsItem(parent),
	currentChord(0),
	pixPerMsec(PIXEL_PER_MSECOND)
{
	controler = (Controler*) scene()->parent();

	QPen borderPen(Qt::black, 3);
	QPen lightPen(Qt::black, 1);
	QBrush innerCont(Qt::white);
	QFont chordFont("Roboto", 36);
	QFont scrollingChordFont("Roboto", 60);

   /* QGraphicsRectItem* lineCont = new QGraphicsRectItem(1470, 108, 355, 53, this);
	lineCont->setBrush(innerCont);
	lineCont->setPen(borderPen);*/


	// Conteneur pour les accords défilants
	QPixmap playingMask(":/images/maskplaying.png");
	QGraphicsSimpleTextItem* maskingTextContainer = new QGraphicsSimpleTextItem(this);
	maskingTextContainer->setFlag(QGraphicsItem::ItemDoesntPropagateOpacityToChildren, true);
	maskingTextContainer->setOpacity(0.01); // Pour ne pas voir le masque mais qu'il ne soit pas desactivé

	// Masque pour cacher ce qui est hors du cadre
	QGraphicsOpacityEffect* textMasking = new QGraphicsOpacityEffect();
	QBrush brushMask(playingMask);
	textMasking->setOpacity(0.9);
	textMasking->setOpacityMask(brushMask);
	maskingTextContainer->setGraphicsEffect(textMasking);
	scrollingTextContainer = new QGraphicsItemGroup(maskingTextContainer);
	scrollingTextContainer->setPos(180, 440);


	QList<PlayerChord>::iterator ite;
	QGraphicsRectItem* tempCase;
	QGraphicsTextItem* tempText;
	QGraphicsTextItem* tempScrollingChord;

	int i=0, j=0;
    for (ite = controler->getChordList()->begin(); ite != controler->getChordList()->end(); ++ite)
	{

		// Partie chanson entiere
		tempCase = new QGraphicsRectItem(1471 + 355/4*i, 108 + 73*j, 355/4, 53, this);
		tempCase->setBrush(innerCont);
		tempCase->setPen(lightPen);
		cList.append(tempCase);

		tempText = new QGraphicsTextItem(tempCase);
		tempText->setFont(chordFont);
		tempText->setDefaultTextColor(QColor(14,153,204));
		tempText->setTextWidth(355/4);
        tempText->setHtml("<p align='center'>"+ite->getName()+"</p>");
		tempText->setPos(tempCase->rect().topLeft());
		if(i==3)
		{
			j++;
			i=0;
		}
		else
			i++;
		ite->fullSongItem = tempCase;

		// Partie accords defilants

		tempScrollingChord = new QGraphicsTextItem(scrollingTextContainer);
		tempScrollingChord->setFont(scrollingChordFont);
        tempScrollingChord->setPos(ite->getTime()*pixPerMsec, 0);
        tempScrollingChord->setHtml("<font color=\"#ffffff\">"+ite->getName()+"</font>");

		ite->scrollingChordItem = tempScrollingChord;

	}

	// partie temporelle
	lastRefresh = 0;
    controler->getChordList()->at(currentChord).fullSongItem->setBrush(Qt::yellow);
	isCurrentChordValidated = false;
    totalPlayedChords = 0;
    totalValidatedChords = 0;
}

void EntireSong::nextChord() {
	((PlayerScene*) scene())->resetNoteCheck();
	if(!isCurrentChordValidated)
		validateChord(false);
	isCurrentChordValidated = false;
	currentChord++;
    controler->getChordList()->at(currentChord).fullSongItem->setBrush(Qt::yellow);
    if(currentChord>=controler->getChordList()->size())
		currentChord=0;
}

void EntireSong::advance ( int phase ) {
	if(phase == 1) // advance est appellée automatiquement par la scene, deux fois (voir doc)
	{
		int currentTime = controler->elapsedTime();
        static bool isLastChordAlreadyValidated = false;
		QTransform textTrans;
		textTrans.translate(-pixPerMsec*(currentTime-lastRefresh), 0);
		scrollingTextContainer->setTransform(textTrans, true);

        if(currentChord+1 < controler->getChordList()->size()) {
            if(controler->getChordList()->at(currentChord+1).getTime()<currentTime)
                nextChord();
        }
        else if(!isLastChordAlreadyValidated && !isCurrentChordValidated
                && controler->getChordList()->at(currentChord).getTime() + getCurrentDuration() < currentTime) {//Dernier accord du morceau
            validateChord(false);
            isLastChordAlreadyValidated = true;
        }
		lastRefresh = currentTime;
	}
}

void EntireSong::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

}

QRectF EntireSong::boundingRect() const {
	// This rectangle is false, but may decrease performance if determined precisely
	return QRectF(0,0,1920,1080);

}
void EntireSong::validateChord(bool v)
{
	if(v) {
        controler->getChordList()->at(currentChord).fullSongItem->setBrush(Qt::green);
		isCurrentChordValidated = true;
        totalValidatedChords++;
	}
	else
        controler->getChordList()->at(currentChord).fullSongItem->setBrush(Qt::red);
    totalPlayedChords++;
    ((PlayerScene*)scene())->updateStats(totalValidatedChords, totalPlayedChords);
}

QString EntireSong::getCurrentChord() const
{
    return controler->getChordList()->at(currentChord).getName();
}

int EntireSong::getCurrentDuration() const
{
    if(currentChord+1 < controler->getChordList()->size())
        return controler->getChordList()->at(currentChord+1).getTime() - controler->getChordList()->at(currentChord).getTime();
    return 2000; //TODO
}

int EntireSong::getTotalValidatedChords() const
{
    return totalValidatedChords;
}

int EntireSong::getTotalPlayedChords() const
{
    return totalPlayedChords;
}

bool EntireSong::getIsCurrentChordValidated() const
{
    return isCurrentChordValidated;
}