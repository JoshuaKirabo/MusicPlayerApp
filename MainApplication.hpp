//
//  MainApplication.hpp
//  Music Player
//
//  Created by Joshua Kirabo on 11/14/23.
//

#ifndef MainApplication_hpp
#define MainApplication_hpp

#include "MusicPlayer.hpp"
#include <vector>
#include <filesystem> // Requires C++17
#include <fstream>


namespace fs = std::filesystem;

class MainApplication
{
    public:
        MainApplication();
        ~MainApplication();

        void run();
        void scanDirectory(const fs::path& path);

    private:
        MusicPlayer player;
        std::vector<MusicFile> musicLibrary;
        void saveMusicDirectoryPath(const std::string& path);
        std::string loadMusicDirectoryPath();
};

#endif /* MainApplication_hpp */
