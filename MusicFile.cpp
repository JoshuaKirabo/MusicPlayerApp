//
//  MusicFile.cpp
//  Music Player
//
//  Created by Joshua Kirabo on 11/14/23.
//

#include "MusicFile.hpp"
#include <taglib/fileref.h>
#include <taglib/tag.h>


MusicFile::MusicFile(const std::string &filePath)
    : title(""), artist(""), album(""), genre(""), duration(0)
{
    this->filePath = filePath;
    
    // Use TagLib to extract metadata
    TagLib::FileRef f(filePath.c_str());

    if (!f.isNull() && f.tag())
    {
        TagLib::Tag *tag = f.tag();
        title = tag->title().toCString(true);  // Convert to std::string
        artist = tag->artist().toCString(true); // Convert to std::string
        album = tag->album().toCString(true);   // Convert to std::string
        // You can also extract other metadata like genre, year, etc.
    }
}

MusicFile::~MusicFile()
{
    // Destructor code (if needed)
}

// Getters
std::string MusicFile::getFilePath() const {return filePath;}
std::string MusicFile::getTitle() const { return title; }
std::string MusicFile::getArtist() const { return artist; }
std::string MusicFile::getAlbum() const { return album; }
std::string MusicFile::getGenre() const { return genre; }
int MusicFile::getDuration() const { return duration; }

// Setters
void MusicFile::setTitle(const std::string &title) { this->title = title; }
void MusicFile::setArtist(const std::string &artist) { this->artist = artist; }
void MusicFile::setAlbum(const std::string &album) { this->album = album; }
void MusicFile::setGenre(const std::string &genre) { this->genre = genre; }
void MusicFile::setDuration(int duration) { this->duration = duration; }

