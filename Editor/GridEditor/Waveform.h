#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <QLabel>
#include <QColor>
#include "MusicPlayer.h"

class Waveform : public QLabel
{
	QWidget* parent;
	Q_OBJECT
	QImage* image;

	int* spectrum;
	unsigned int m_width;
	unsigned int m_height;

	QPoint oldMousePos;

	static const uint green_color;
	protected:
		void mouseMoveEvent(QMouseEvent * event);
		void mousePressEvent(QMouseEvent * event);

	public:
		explicit Waveform(QWidget *parent, int w, int h);
		void update();
		void display();
		void initImage();
		
		void setWidth(int w);
		void setHeight(int h);

		int getWidth();
		int* getSpectrum();

	signals:
		
	public slots:
		
};

#endif // WAVEFORM_H