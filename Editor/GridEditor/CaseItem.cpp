/*
Author: Fabien Fleurey
Created on 28/02/12
Last change on 14/04/12
*/

/**
 *
 */

#include "CaseItem.h"
#include <QMenu>
#include <QMouseEvent>
/**
 * @brief CaseItem::CaseItem
 *
 * Constructeur des cases de la grille.
 */
CaseItem::CaseItem() :  QTableWidgetItem(), m_color(new QColor())
{
    m_beginningTimer = QTime(0,0);
    m_part = "";
    m_color->setRgb(255, 255, 255);
    m_timerManuallySet = false;
    this->setBackgroundColor(m_color->toRgb());
	this->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable);
    this->setTextAlignment(Qt::AlignCenter);
}

/**
 * @brief CaseItem::CaseItem
 * @param item
 *
 * Constructeur surchagé (ressemble vaguement à une copie.)
 */
CaseItem::CaseItem(const QTableWidgetItem& item) : QTableWidgetItem(item), m_color(new QColor(item.background().color()))
{
	this->text() = item.text();
}

CaseItem::~CaseItem() {
    delete m_color;
}

/**
 * @brief CaseItem::set_color
 * @param r Rouge
 * @param g Vert
 * @param b Bleu
 * @param a Alpha
 *
 * Configure la couleur de la case.
 */
void CaseItem::set_color(int r, int g, int b, int a = 255) {
    m_color->setRgb(r, g, b, a);
    this->setBackgroundColor(m_color->toRgb());
}

/**
 * @brief CaseItem::get_color
 * @return La couleur actuelle de la case.
 *
 * Donne la couleur actuelle de la case. La couleur permet de déterminer l'état de la case.
 */
QColor* CaseItem::get_color() const {
    return m_color;
}

/**
 * @brief CaseItem::set_chord
 * @param chord Nom de l'accord à ajouter à la case.
 *
 * Met à jour le texte de la case pour afficher le nom de l'accord entré.
 */
void CaseItem::set_chord(QString chord) {
    this->setText(chord);
}

/**
 * @brief CaseItem::get_chord
 * @return La chaîne de caractère correspondant à l'accord entré dans la case.
 *
 * Donne le contenu de la case. Le contenu est censé être un accord.
 */
QString CaseItem::get_chord() const {
    return this->text();
}

/**
 * @brief CaseItem::clone
 * @return Une copie de la case courante.
 *
 * Permet de créer une copie de la case sélectionnée.
 * question (jm): à quoi sert cette méthode si on a un constructeur par recopie ?
 */
CaseItem* CaseItem::clone() const
{
    QTableWidgetItem* item = QTableWidgetItem::clone();
    return new CaseItem((const QTableWidgetItem&) *item);
}

QString& CaseItem::getPart()
{
	return m_part;
}

void CaseItem::setPart(QString part)
{
	m_part = part;
}

bool CaseItem::isPartSet()
{
    return m_part.length() > 0;
}

void CaseItem::setBeginningTimer(QTime t, bool timerManuallySet)
{
    m_beginningTimer = t;
    m_timerManuallySet = timerManuallySet;
}

QTime CaseItem::getBeginning()
{
    return m_beginningTimer;
}

bool CaseItem::isTimerManuallySet()
{
    return m_timerManuallySet;
}
