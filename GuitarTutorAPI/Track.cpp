/*
 * Track.cpp
 *
 *  Created on: 9 mars 2011
 *      Author: raphael
 */

#include "Track.h"
#include <vector>

Track::Track()
{

}

Track::Track(std::string fileName) {
	m_fileName = fileName;
	m_isMute = false;

	load();
}

Track::Track(unsigned int silenceTrackTimeInMs)
{
	m_channelsCount = NUM_CHANNELS;
	m_framesCount = (silenceTrackTimeInMs/1000.0) * SAMPLE_RATE;

	m_buffer = new float[(unsigned int) (m_framesCount * m_channelsCount)];

	for (unsigned int i = 0; i < (unsigned int) (m_framesCount * m_channelsCount); ++i)
	{
		m_buffer[i] = 0.0;
	}
}

Track::~Track()
{
	//delete[] m_buffer;
}

float *Track::getBuffer() const
{
	return m_buffer;
}

int Track::getChannelsCount() const
{
	return m_channelsCount;
}

int Track::getFramesCount() const
{
	return m_framesCount;
}

void Track::setFramesCount(int m_framesCount)
{
	this->m_framesCount = m_framesCount;
}

int Track::load()
{
	//get the file
	SF_INFO sfInfo;
	sfInfo.format=0;
	SNDFILE* sndFile = sf_open(m_fileName.c_str(),SFM_READ,&sfInfo);

	if(!sndFile)
	{
		std::cout << "Error loading file " << m_fileName << std::endl;
		return -1;
	}

	//test the samplerate
	int sampleRate = sfInfo.samplerate;
	(void) sampleRate;

	//channels
	m_channelsCount =  sfInfo.channels;

	//frames number
	m_framesCount = (long)(sfInfo.frames);

	m_buffer = new float[m_framesCount * m_channelsCount];


	int nbFrameToRead = 1000;
	float cf[m_channelsCount * nbFrameToRead];

	int nbFrame;
	int pos = 0;
	while ((nbFrame = sf_readf_float(sndFile,cf,nbFrameToRead)) > 0)
	{
		for (int i = 0; i < nbFrame * 2; i++)
		{
			m_buffer[pos] = cf[i];
			++pos;
		}
	}

	//close the file
	if(sf_close(sndFile))
		return -1;

	return 0;
}

bool Track::isMute() const
{
	return m_isMute;
}

void Track::setMuteState(bool isMute)
{
	m_isMute = isMute;
}