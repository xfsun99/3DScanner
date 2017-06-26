#ifndef _UiStateManager_H
#define _UiStateManager_H
#include <QObject>
#include <QAction>
class UiStateManager:public QObject
{
	Q_OBJECT
public:
	static UiStateManager*getInstance();
	~UiStateManager();
signals:
	void setRedoEnabledSignal(bool);
	void setUndoEnabledSignal(bool);
	public slots:
		void setRedoEnabledSlot(bool);
		void setUndoEnabledSlot(bool);
		//reaction of redo
		void RedoActionTriggeredSlot();
		//reaction of undo
		void UndoActionTriggeredSlot();
		//ui state update when actor sturct change
		void uiRedoUndoStateUpdateSlot(bool);

private:
	UiStateManager();
	static UiStateManager*Instance;
};
#endif