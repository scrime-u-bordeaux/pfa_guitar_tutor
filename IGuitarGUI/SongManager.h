#ifndef SONGMANAGER_H
#define SONGMANAGER_H

#include <QObject>
#include <QTime>
#include <QTimer>

#include <MusicManager.h>
#include <GuitarTutor/Chord.h>
#include <Track/LogicalTrack.h>
#include "Configuration.h"

/**
 * @brief The SongManager class
 *
 * Classe qui gère le transport dans la partition. Contrôle la lecture audio de manière
 * à ce que l'audio soit synchronisé avec ces informations.
 */
class SongManager: public QObject

{
		Q_OBJECT
	public:
		SongManager(QObject* parent);
		~SongManager();

		void load(LogicalTrack* track);
		void mute(bool);
        TrackChord* getCurrentChord();

        int getElapsedTime();
        void goToBeginning();
        void resetChordsFrom(TrackChord* chord);
public slots:
		void compareChordWithPlayed();
		void checkTime();
		void goToChord(TrackChord*);

		void play();
		void pause();
		void stop();

	signals:
		void currentlyPlayedChord(BasicChord);
		void updateChord(TrackChord*);
        void updateStats(int, int);
		void nonNaturalChange(TrackChord*);
		void lastChordCorrectness(TrackChord*, double);


	private:
		LogicalTrack* m_track;
		MusicManager* m_musicManager;

		PartTrack* m_currentPart;
		TrackChord* m_currentChord;

		BasicChord* m_currentInputChord;
		chord_ctrl* m_chordControl;
        Configuration* m_configuration;

		QTime m_time;

		int number_of_valid_chord_checks;
		int number_of_chord_checks;

        int well_played_chords_in_current_part;
        int played_chords_in_current_part;

        int m_totalPlayedChords;
        int m_totalValidatedChords;

		int precision_in_ms;
		int m_elapsedTime;
        bool m_isFirstChord;
        bool m_partRepeated;

};

#endif // SONGMANAGER_H