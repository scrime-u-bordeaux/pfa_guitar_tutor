#ifndef UNDOMANAGER_H
#define UNDOMANAGER_H

#include <QStack>
#include "StatePacket.h"

class GridEditor;
class UndoManager: public QObject
{
		Q_OBJECT
	public:
		explicit UndoManager(GridEditor *editor);
		~UndoManager();

		StatePacket* currentEditorState();
		bool canUndo();
		bool canRedo();
		void firstSave();
		void clear();
		void emptyList(QList<StatePacket*>* );

	signals:
		void save();

	public slots:
		void saveSlot();

		void saveState(bool redo = false);
		void undo();
		void redo();


	private:
		void restoreState(StatePacket*);
		GridEditor* m_editor;
		int max_depth;

		QList<StatePacket*> undoList;
		QList<StatePacket*> redoList;

		bool m_undoState, m_redoState; // sert à éviter des sauvegardes en doublon si on undo plusieurs fois d'affilée
		StatePacket* m_currentState;
};

#endif // UNDOMANAGER_H
