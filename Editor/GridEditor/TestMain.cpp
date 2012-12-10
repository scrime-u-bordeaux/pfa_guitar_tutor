/*
Author: Fabien Fleurey
Created on 28/02/12
Last change on 28/02/12
*/

#include <QApplication>
#include "GridEditor.h"

/**
 * @brief main
 * @param argc
 * @param argv
 * @return Le résultat de l'exécution de l'éditeur.
 *
 * Fonction main à but de test.
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GridEditor win;
    win.show();
    return app.exec();
}