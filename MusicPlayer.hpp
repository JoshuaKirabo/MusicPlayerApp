//
//  MusicPlayer.hpp
//  Music Player
//
//  Created by Joshua Kirabo on 11/14/23.
//

#ifndef MusicPlayer_hpp
#define MusicPlayer_hpp

#include "MusicFile.hpp"
#include <iostream>
#include <memory> // For std::unique_ptr

class MusicPlayer
{
        public:
            MusicPlayer();
            ~MusicPlayer();

            void play();
            void pause();
            void stop();
            void loadTrack(const MusicFile& track);

    private:
        std::unique_ptr<MusicFile> currentTrack;
        // Add more member variables as needed for managing playback state, etc.
};


#endif /* MusicPlayer_hpp */
