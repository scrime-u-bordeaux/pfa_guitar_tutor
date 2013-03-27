#ifndef AUDIOSYNC_H
#define AUDIOSYNC_H

#include <QtWidgets/QWidget>
#include <QtGui>
#include <QtWidgets/QGridLayout>
#include "TimeEdit.h"
#include "TempoEdit.h"
#include <QtWidgets/QToolButton>
#include <QtWidgets/QPushButton>
#include <QTime>
#include <QtWidgets/QLabel>
#define TIMER_BEGINNING 0
#define TIMER_END       1
#define TIMER_BAR       2
#define TIMER_PLAY		3
class TimeEdit;

/**
 * @brief Interface de synchronisation audio
 */
class AudioSync : public QWidget
{
	Q_OBJECT

	QGridLayout* m_layout;
	TimeEdit *m_beginning, *m_end, *m_bar;
	QToolButton* m_bbeginning, *m_bend, *m_bbar;
	QLabel *m_lbeginning, *m_lend, *m_lbar, *m_lbpm;
	TempoEdit *m_bpm;
	QPushButton *m_sendButton;
	QTime m_tempBarTime;

	unsigned int m_timeSignature;


public:
	AudioSync(QWidget* parent = 0);
	~AudioSync();
	void activeButtons(bool active);

	void setBarTimer(const QTime);
	void setBeginningTimer(const QTime);
	void setEndTimer(const QTime);
	int getBeginning();
	int getBar();
	int getEnd();

	void checkTimes();
	void updateTempo();

public slots:
	void sendData();
	void tempoClicked();
	void recvTimer(int, QTime);
	void setTimeSignature(int);

private slots:
	void emitSignalTimer();
	void beginningChanged(QTime);
	void barChanged(QTime);
	void endChanged(QTime);
	void tempoChanged(int);

signals:
	void refreshTimer(int);
	void sendTimers(QTime, QTime, QTime);
	void sendTimer(int, QTime);
};

#endif // AUDIOSYNC_H
