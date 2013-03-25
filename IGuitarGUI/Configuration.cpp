#include "Configuration.h"

int Configuration::m_width = 1920;
int Configuration::m_height = 1080;

/*
int Configuration::width = 1920;
int Configuration::height = 1080;
*/
float Configuration::m_quotient = float(Configuration::m_height)/float(Configuration::originalHeight); // L'image de base est de hauteur 1080, pour mise a l'echelle

Configuration::Configuration()
{
	m_inputIndex = 0;
	m_outputIndex = 0;
    pause_setting = PAUSE_TO_LAST_CHORD;
    loop_on_failure = false;
    percent_to_go_to_next_part = PERCENT_TO_VALIDATE_EASY;
    songDirectory = "Tracks";
}

float Configuration::getQuotient()
{
	return Configuration::m_quotient;
}


QRect Configuration::getWindowSize()
{
	return QRect(0, 0, Configuration::m_width, Configuration::m_height);
}

void Configuration::setWindowSize(int w, int h)
{
   Configuration::m_width = w;
   Configuration::m_height = h;
   Configuration::m_quotient = float(Configuration::m_width)/float(Configuration::originalWidth);
}

void Configuration::setWindowSize(QRect qr)
{
   setWindowSize(qr.width(), qr.height());
}

void Configuration::setSongName(QString songName)
{
	m_currentSongName = songName;
}

QString Configuration::getSongName()
{
	return m_currentSongName;
}

void Configuration::setAudioInput(QString audioInput)
{
	m_audioInput = audioInput;
}
QString Configuration::getAudioInput()
{
	return m_audioInput;
}

void Configuration::setAudioOutput(QString audioOutput)
{
	m_audioOutput = audioOutput;
}

QString Configuration::setAudioOutput()
{
	return m_audioOutput;
}

int Configuration::getInputIndex() const
{
	return m_inputIndex;
}

int Configuration::getOutputIndex() const
{
	return m_outputIndex;
}


void Configuration::setInputIndex(int i)
{
	m_inputIndex = i;
}

void Configuration::setOutputIndex(int i)
{
	m_outputIndex = i;
}


int Configuration::getPauseSetting() const
{
	return pause_setting;
}

void Configuration::setPauseSetting(int s)
{
	pause_setting = s;
}

bool Configuration::getLoopSetting() const
{
	return loop_on_failure;
}

void Configuration::setLoopSetting(bool b)
{
	loop_on_failure = b;
}

int Configuration::getDifficulty() const
{
	return percent_to_go_to_next_part;
}

void Configuration::setDifficulty(int d)
{
	percent_to_go_to_next_part = d;
}

QString Configuration::getSongDirectory() const
{
    return songDirectory;
}

void Configuration::setSongDirectory(QString sd)
{
    songDirectory = sd;
}