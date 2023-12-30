//
//  MusicFile.hpp
//  Music Player
//
//  Created by Joshua Kirabo on 11/14/23.
//

#ifndef MusicFile_hpp
#define MusicFile_hpp

#include <string>

class MusicFile
{
    public:
        MusicFile(const std::string &filePath);
        ~MusicFile();

        // Getters
        std::string getTitle() const;
        std::string getArtist() const;
        std::string getAlbum() const;
        std::string getGenre() const;
        std::string getFilePath() const;
        int getDuration() const;  // Duration in seconds

        // Setters
        void setTitle(const std::string &title);
        void setArtist(const std::string &artist);
        void setAlbum(const std::string &album);
        void setGenre(const std::string &genre);
        void setDuration(int duration);

    private:
        std::string title;
        std::string artist;
        std::string album;
        std::string genre;
        std::string filePath;
        int duration; // Duration in seconds
};

#endif /* MusicFile_hpp */
