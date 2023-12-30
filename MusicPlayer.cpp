//
//  MusicPlayer.cpp
//  Music Player
//
//  Created by Joshua Kirabo on 11/14/23.
//


#include "MusicPlayer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

MusicPlayer::MusicPlayer() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
}

MusicPlayer::~MusicPlayer()
{
    // Free up resources
}

void MusicPlayer::play() {
    if (currentTrack) {
        Mix_Music* music = Mix_LoadMUS(currentTrack->getFilePath().c_str());
        if (!music) {
            std::cerr << "Error loading music: " << Mix_GetError() << std::endl;
            return;
        }
        if (Mix_PlayMusic(music, 1) == -1) {
            std::cerr << "Error playing music: " << Mix_GetError() << std::endl;
            return;
        }

        std::cout << "Playing song: " << currentTrack->getTitle() << std::endl;

        // Loop to keep the program running while music is playing
        while (Mix_PlayingMusic()) {
            SDL_Delay(100); // Wait and let the music play
        }

        // Clean up
        Mix_FreeMusic(music);
    }
}


void MusicPlayer::pause()
{
    Mix_PauseMusic();
}

void MusicPlayer::stop()
{
    Mix_HaltMusic();
}

void MusicPlayer::loadTrack(const MusicFile& track)
{
    currentTrack = std::make_unique<MusicFile>(track);
    // Loading the track is handled in play() for SDL_mixer
}
