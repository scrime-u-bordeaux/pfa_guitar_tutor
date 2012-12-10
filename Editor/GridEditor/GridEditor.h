/*
Author: Fabien Fleurey
Created on 28/02/12
Last change on 08/05/12
*/

#ifndef GRIDEDITOR_H
#define GRIDEDITOR_H

#include <QCoreApplication>
#include <QtGui>
#include "ChordTableWidget.h"
#include "CaseItem.h"
#include "EditionSelector.h"
#include "ChordTree.h"

/**
 * @brief Fenêtre principale de l'éditeur
 */
class GridEditor : public QMainWindow
{
    Q_OBJECT

    QWidget* centralArea;
    QGridLayout* layout;
    ChordTableWidget* grid;
    ChordTree* chordTree;
    QLabel* title;

    QMenu *fileMenu, *editMenu, *optionMenu, *aboutMenu;
    QToolBar *toolBar;
    QAction *quitAction, *aboutAction, *newAction, *saveAction,
            *openAction, *addRowAction, *deleteRowAction,
            *copyDownAction, *renameAction, *addColumnAction,
            *deleteColumnAction;
    EditionSelector *editionSelector;

public:
    GridEditor();
    ~GridEditor();

private:
    void createMenu();
    void createActions();
    void setActionsToMenu();
    void createToolbar();
    void createCentralWidget();
    void connectActionToSlot();
    void buildChordTree();
    QTreeWidgetItem* buildChord(const QString tonality);

signals:

public slots:
    void changeState();
    void importXml();
    void exportXml();
    void newGrid();
    void rename();
    void newEditor(int);
};

#endif // GRIDEDITOR_H