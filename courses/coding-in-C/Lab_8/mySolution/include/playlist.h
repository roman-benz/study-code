#include <stdlib.h>

#ifndef PLAYLIST_H
#define PLAYLIST_H
#define MAX_SONGS 1000;

typedef struct Song {
    char title[100];
    char artist[100];
    struct Song *naechsterSong;
} Song;

typedef struct Playlist {
    Song *headsong;
    int laenge;
} Playlist;

void init_playlist(Playlist *einePlaylist);

void song_anhaengen(Playlist *einePlaylist, Song *einSong);

Song* song1_entfernen(Playlist *einePlaylist);

void song_entfernen(Playlist *einePlaylist, Song *einSong);

#endif //PLAYLIST_H
