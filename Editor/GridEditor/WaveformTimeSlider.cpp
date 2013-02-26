#include "WaveformTimeSlider.h"
#include "Util.hpp"

WaveformTimeSlider::WaveformTimeSlider(QString imagepath, int type, QWidget *parent):
	QWidget(parent),  type(type), m_time(0), m_pixmap(imagepath)
{
}


int WaveformTimeSlider::getTime()
{
	return m_time;
}

void WaveformTimeSlider::setTime(int time)
{
	m_time = time;
}

void WaveformTimeSlider::private_setTime(int time)
{
	m_time = time;
	emit timeChanged(type, SampleToQTime(time));
}

int WaveformTimeSlider::getPos()
{
	return pos_x;
}

void WaveformTimeSlider::setPos(int pos)
{
	pos_x = pos;
}

QPixmap& WaveformTimeSlider::getPixmap()
{
	return m_pixmap;
}

QRect WaveformTimeSlider::getPixmapSize()
{
	return m_pixmap.rect();
}
