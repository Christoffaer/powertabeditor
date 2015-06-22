/*
  * Copyright (C) 2015 Cameron White
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
  
#ifndef MIDI_MIDIFILE_H
#define MIDI_MIDIFILE_H

#include <midi/midieventlist.h>
#include <vector>

class Barline;
class Score;
class System;
class SystemLocation;

class MidiFile
{
public:
    MidiFile();

    void load(const Score &score);

    int getTicksPerBeat() const { return myTicksPerBeat; }
    const std::vector<MidiEventList> &getTracks() const { return myTracks; }

private:
    int generateMetronome(const System &system, const Barline &current_bar,
                          const Barline &next_bar,
                          const SystemLocation &location, int current_tick,
                          MidiEventList &event_list);

    int myTicksPerBeat;
    std::vector<MidiEventList> myTracks;
};

#endif
