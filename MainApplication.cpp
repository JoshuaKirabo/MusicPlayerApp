//
//  MainApplication.cpp
//  Music Player
//
//  Created by Joshua Kirabo on 11/14/23.
//

#include "MainApplication.hpp"

#include "MainApplication.hpp"
#include <iostream>

MainApplication::MainApplication()
    {
        // Initialize your application components
    }

MainApplication::~MainApplication()
    {
        // Clean up your application
    }

void MainApplication::scanDirectory(const fs::path& path)
    {
        for (const auto& entry : fs::recursive_directory_iterator(path))
            {
                if (fs::is_regular_file(entry) && entry.path().extension() == ".mp3")
                    {
                        // Assuming the file name contains the song name, artist, and album
                        musicLibrary.push_back(MusicFile(entry.path().string()));
                    }
            }
    }

void MainApplication::run()
{
    std::string directory = loadMusicDirectoryPath();

    // If we have no saved directory
    if (directory.empty())
        {
            std::cout << "Enter directory path to scan for music files: ";
            std::getline(std::cin, directory);
            saveMusicDirectoryPath(directory);
        }

       scanDirectory(directory);

       // If the directory is empty
       if (musicLibrary.empty())
           {
               std::cout << "No music files found in the directory." << std::endl;
               return;
           }

       for (size_t i = 0; i < musicLibrary.size(); ++i)
           {
               std::cout << i + 1 << ". " << musicLibrary[i].getTitle() << " - "
                         << musicLibrary[i].getArtist() << " - "
                         << musicLibrary[i].getAlbum() << "\n";
           }

       std::cout << "Enter the number of the song to play: ";
       size_t choice;
       std::cin >> choice;

       if (std::cin.fail())
           {
               std::cin.clear(); // Clear error state
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
               std::cout << "Invalid input. Please enter a number." << std::endl;
               return;
           }

       if (choice > 0 && choice <= musicLibrary.size())
           {
               player.loadTrack(musicLibrary[choice - 1]);
               player.play();
           }
       else
           {
               std::cout << "Invalid song number. Please try again." << std::endl;
           }
}

void MainApplication::saveMusicDirectoryPath(const std::string& path) {
    std::ofstream outFile("music_directory.txt");
    if (outFile) {
        outFile << path;
    }
    outFile.close();
}

std::string MainApplication::loadMusicDirectoryPath() {
    std::ifstream inFile("music_directory.txt");
    std::string path;
    if (inFile) {
        std::getline(inFile, path);
    }
    inFile.close();
    return path;
}


