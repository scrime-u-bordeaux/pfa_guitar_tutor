#include "TrackLoader.h"

TrackLoader::TrackLoader() {



}

TrackLoader::~TrackLoader() {



}

/* Fonction de chargement d'un fichier-piste au format XML
    @return -1 si le fichier spécifié n'existe pas
    @return -2 si le document XML ouvert ne peut être associé au QDomDocument
    @return -3 si le document XML n'est pas un fichier associé au projet
    @return 0 si le fichier a été correctement chargé
*/
int TrackLoader::ConvertXmlToLogicalTrack(QString xmlFileName) {

    QDomDocument *dom = new QDomDocument(xmlFileName); // Structure contenant le XML préalablement chargé
    QFile xmlDoc(xmlFileName); // Ouverture du fichier XML

    if(!xmlDoc.open(QIODevice::ReadOnly)) { // Erreur à l'ouverture du .xml ?
        return -1;
    }

    if (!dom->setContent(&xmlDoc)) { // Impossibilité de linker le fichier .xml ouvert au QDomDocument ?
         xmlDoc.close();
         return -2;
    }

    xmlDoc.close(); // Fermeture du document xml maintenant contenu dans un QDomDocument

    // On créé la structure de donnée de la piste logique

    currentTrack = new LogicalTrack();

    QDomElement domElement = dom->documentElement();
    QDomNode node = domElement.firstChild();

    // Inscription des datas dans la structure de piste LogicalTrack

    while(!node.isNull()) {
        if(!domElement.isNull()) {

            if (domElement.tagName() == "nom") {
                currentTrack->SetTrackName(domElement.text());
            }

            else if (domElement.tagName() == "artiste") {
                currentTrack->SetArtist(domElement.text());
            }

            else if (domElement.tagName() == "fichier") {
                currentTrack->SetAudioFileName(domElement.text());
            }

            else if (domElement.tagName() == "partie") {

                if(domElement.attribute("nom",0) == 0) {
                    delete currentTrack;
                    return -3;
                }

                currentTrack->AddPartTrackToList(domElement.attribute("nom",0));

                QDomNode chordNode = node.firstChild();
                while(!chordNode.isNull()) {
                    if(!domElement.isNull()) {



                    }
                }
            }
        }
    node = node.nextSibling();
    }
    return 0;
}
