#include "playlist.h"
#include <iostream>

PlayList::PlayList(const string& username, int capacity): username(username), capacity(capacity) {
    songs = new const Song*[capacity];  // assuming a maximum of 100 songs
    for (int i = 0; i < capacity; i++) {
        songs[i] = nullptr;
    }
}

PlayList::PlayList(const string& username, const PlayList& playlist, int capacity) : username(username), capacity(capacity) {
    // TODO 3: PlayList constructor.
    for(int i = 0 ; i < this->capacity; i++){
        if(i >= playlist.capacity){
            this->songs[i] = nullptr;
        } else{
            this->songs[i] = playlist.songs[i];
        }
    }
}

PlayList::~PlayList() {
    // TODO 6: Build the destructors.
    for(int i = 0; i < this->capacity; i++){
        if(this->songs[i]){
            delete this->songs;
        }
    }
}

void PlayList::addSong(const Song* song) {
    // TODO 4: Add and Remove Songs of a Playlist.
    for(int i = 0; i < this->capacity; i++){
        if(this->songs[i] == nullptr){
            this->songs[i] = song;
            return;
        }
    }
}

void PlayList::removeSong(const string& name) {
    // TODO 4: Add and Remove Songs of a Playlist.
    for(int i = 0; i < this->capacity; i++){
        if(this->songs[i]->getName() == name){
            delete songs[i];
            for(int j = i; j < this->capacity-1 ;j++){
                this->songs[j] = this->songs[j+1];
            }
            this->songs[capacity-1] = nullptr;
        }
    }
}

string PlayList::getUsername() const {
    return username;
}

void PlayList::display() const {
    cout << "========================================" << endl; 
    cout << "Playlist of " << username << endl;
    for (int i = 0; i < capacity; i++) {
        if (songs[i] != nullptr) {
            cout << i << ". " << songs[i]->getName() << " - " << songs[i]->getSinger()->getName() << endl;
        }
    }
    cout << "========================================" << endl;
}

