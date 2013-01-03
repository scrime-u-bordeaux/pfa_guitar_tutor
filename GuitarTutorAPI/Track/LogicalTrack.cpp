#include "LogicalTrack.h"

/**
 * @brief LogicalTrack::LogicalTrack
 *
 * Constructeur par défaut de la classe LogicalTrack
 */
LogicalTrack::LogicalTrack() {

}

/**
 * @brief LogicalTrack::~LogicalTrack
 *
 * Destructeur de la classe LogicalTrack
 */
LogicalTrack::~LogicalTrack() {

    for(QList<PartTrack*>::Iterator i = listPartTrack.begin(); i != listPartTrack.end() ; i++)
        delete (*i);
}

/**
 * @brief LogicalTrack::SetTrackName
 * @param NewTrackName chaîne de caractères
 *
 * Change la valeur de l'attribut TrackName de la classe LogicalTrack
 */
void LogicalTrack::SetTrackName(QString newTrackName) {

    trackName = newTrackName;

}

/**
 * @brief LogicalTrack::GetTrackName
 *
 * Renvoie la valeur de l'attribut TrackName de la classe LogicalTrack
 */
QString LogicalTrack::GetTrackName() {

    return trackName;

}

/**
 * @brief LogicalTrack::SetArtist
 * @param NewArtist chaîne de caractères
 *
 * Change la valeur de l'attribut Artist de la classe LogicalTrack
 */
void LogicalTrack::SetArtist(QString newArtist) {

    artist = newArtist;

}

/**
 * @brief LogicalTrack::GetArstist
 *
 * Renvoie la valeur de l'attribut Artist de la classe LogicalTrack
 */
QString LogicalTrack::GetArtist() {

    return artist;

}

/**
 * @brief LogicalTrack::SetAudioFileName
 * @param NewFileName chaîne de caractères
 *
 * Change la valeur de l'attribut FileName de la classe LogicalTrack
 */
void LogicalTrack::SetAudioFileName(QString newAudioFileName) {

    audioFileName = newAudioFileName;

}

/**
 * @brief LogicalTrack::GetAudioFileName
 *
 * Renvoie la valeur de l'attribut AudioFileName de la classe LogicalTrack
 */
QString LogicalTrack::GetAudioFileName() {

    return audioFileName;

}

/**
 * @brief LogicalTrack::AddPartTrackToList
 * @param newPartTrack : Partie de moreceau à rajouter
 *
 * Ajoute une PartTrack à la liste des PartTrack de la LogicalTrack
 */
void LogicalTrack::AddPartTrackToList(PartTrack* newPartTrack) {

    listPartTrack.append(newPartTrack);

}

/**
 * @brief LogicalTrack::getListPartTrack
 *
 * Renvoie un pointeur sur la liste des PartTrack de la LogicalTrack
 */
QList<PartTrack*> LogicalTrack::getListPartTrack() {

    return listPartTrack;

}

/**
 * @brief LogicalTrack::setRep
 *
 * Permet de changer la valeur du nombre de répétition. Si la valeur entrée n'est pas correcte, rep sera mis à -1.
 */
void LogicalTrack::setMesure(int nb){
    if(nb>=0)
        mesure = nb;
    else
        mesure = -1;
}
