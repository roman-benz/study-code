#include "../include/playlist.h"

void init_playlist(Playlist *einePlaylist){
    einePlaylist->headsong = NULL;
    einePlaylist->laenge = 0;
}

void song_anhaengen(Playlist *einePlaylist, Song *einSong){
    if (einePlaylist->laenge == 0)
    {
        einePlaylist->headsong = einSong;
        einePlaylist->laenge++;
    }
    else{
        Song *tempsong = einePlaylist->headsong;
        while (tempsong->naechsterSong != NULL)
        {
            tempsong = tempsong->naechsterSong;
        }
        tempsong->naechsterSong = einSong;
        einePlaylist->laenge++;
    }
    
}

Song* song1_entfernen(Playlist *einePlaylist){
    if(einePlaylist->headsong == NULL){
        return NULL;
    }
    else{
        if (einePlaylist->headsong->naechsterSong == NULL)
        {
            Song *tempsong = einePlaylist->headsong;
            einePlaylist->headsong = NULL;
            einePlaylist->laenge--;
            return tempsong;
        }
        else{
            Song *tempsong = einePlaylist->headsong;
            einePlaylist->headsong = einePlaylist->headsong->naechsterSong;
            einePlaylist->laenge--;
            
        }
        
    }

}