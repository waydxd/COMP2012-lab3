#include <iostream>
#include "manager.h"

MusicManager::MusicManager(int user_max, int singers_max, int songs_max) :
user_capacity(user_max), singers_capacity(singers_max), songs_capacity(songs_max)
{
    // TODO 1: MusicManager constructor.
    this->user_list = new PlayList*[user_max];
    this->singer_list = new Singer*[singers_max];
    this->song_list = new Song*[songs_max];
    this->num_of_singers = 0;
    this->num_of_songs = 0;
    this->num_of_user = 0;
    cout << "MusicManager constructor" << endl;
}

MusicManager::~MusicManager() {
    // TODO 6: Build the destructors.
    delete[] user_list;
    delete[] singer_list;
    delete[] song_list;
    cout << "MusicManager destructor" << endl;
}

void MusicManager::createSinger(const string& name, const string& nationality) {
    singer_list[num_of_singers++] = new Singer(name, nationality);
}

void MusicManager::createSong(const string& name, const string& singer_name) 
{
    // TODO 2: Add a song into the MusicManager.
    for(int i = 0;i<num_of_singers;i++){
        if(this->singer_list[i]->getName() == singer_name){
            song_list[num_of_singers++] = new Song(name,singer_list[i]); 
        }
    }
}

void MusicManager::createPlaylist(const string& user_name) {
    user_list[num_of_user++] = new PlayList(user_name, MAX_SIZE);
    cout << "[Creation] Playlist of " << user_name << endl;
    // Add a new user with the given name to your data structure
    // (You can assume that the name is unique and the user list is not full.
}

void MusicManager::createPlaylistFromOther(const string& des_user_name, const string& src_user_name) {
    // TODO 5: Copy the playlist from your friend.
    int dest;
    int src;
    for(dest = 0;dest<=num_of_user;dest++){
        if(dest==num_of_user){return;}
        if(this->user_list[dest]->getUsername()==des_user_name){break;}
    }
    for(src = 0; src<=num_of_user;src++){
        if(src==num_of_user){return;}
        if(this->user_list[src]->getUsername()==src_user_name){break;}
    }
    PlayList *temp = new PlayList(des_user_name,*this->user_list[src]);
    delete user_list[dest];
    user_list[dest] = temp;
    cout << "[CopyCreation] Playlist of " << des_user_name << " (From:" << src_user_name << ")." << endl;
    return;
}

void MusicManager::displayPlaylist(const string& user_name) const {
    for (int i = 0; i < num_of_user; i++) {
        if (user_list[i]->getUsername() == user_name) {
            user_list[i]->display();
            return;
        }
    }
}

void MusicManager::addSongToPlaylist(const string& user_name, const string& song_name) {
    for (int i = 0; i < num_of_user; i++) {
        if (user_list[i]->getUsername() == user_name) {
            for (int j = 0; j < num_of_songs; j++) {
                if (song_list[j]->getName() == song_name) {
                    user_list[i]->addSong(song_list[j]);
                    cout << "[Add] Song " << song_list[j]->getName() << " to playlist of " << user_list[i]->getUsername() << endl;
                    return;
                }
            }
        }
    }
}

void MusicManager::removeSongFromPlaylist(const string& user_name, const string& song_name) {
    for (int i = 0; i < num_of_user; i++) {
        if (user_list[i]->getUsername() == user_name) {
            user_list[i]->removeSong(song_name);
            cout << "[Remove] Song " << song_name << " from playlist of " << user_list[i]->getUsername() << endl;
            return;
        }
    }
}

