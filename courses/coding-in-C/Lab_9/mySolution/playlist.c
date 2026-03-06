/*
 * File: playlist.c
 * Description: Includes the code/logic for functions of playlist.h
 */
#include "playlist.h"
#include <string.h>
#include <stdlib.h>

/**
 * @brief Initialize a new playlist
 *
 * @param p_playlist pointer the playlist
 */
void init_playlist(Playlist *p_playlist)
{
    p_playlist->p_head = NULL;
    p_playlist->size = 0;
}

/**
 * @brief add a new song to the end of the playlist
 *
 * @param playlist pointer to playlist
 * @param title    title of the new song
 * @param artist   artist of the new song
 */
void add_song(Playlist *playlist, const char *title, const char *artist)
{
    if (playlist->size >= MAX_SONGS)
    {
        printf("Warning: Playlist reached maximum size (%d songs). New song discarded.\n", MAX_SONGS);
        return;
    }

    Song *newSong = malloc(sizeof(*newSong));
    if (!newSong)
        return;

    newSong->title = malloc(strlen(title) + 1);
    newSong->artist = malloc(strlen(artist) + 1);

    if (!newSong->title || !newSong->artist)
    {
        free(newSong->title);
        free(newSong->artist);
        free(newSong);
        return;
    }

    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->p_nextSong = NULL;

    if (!playlist->p_head)
    {
        playlist->p_head = newSong;
    }
    else
    {
        Song *last = playlist->p_head;
        while (last->p_nextSong)
            last = last->p_nextSong;
        last->p_nextSong = newSong;
    }

    playlist->size++;
}

/**
 * @brief print out all songs of the playlist
 *
 * @param playlist pointer to playlist
 */
void print_playlist(const Playlist *playlist)
{
    printf("Playlist contains %d song(s):\n", playlist->size);
    Song *current = playlist->p_head;
    while (current)
    {
        printf("Title: %s, Artist: %s\n", current->title, current->artist);
        current = current->p_nextSong;
    }
}

/**
 * @brief delete the first song of the playlist
 *
 * @param playlist pointer to playlist
 */
void delete_firstSong(Playlist *playlist)
{
    if (!playlist->p_head)
        return;

    Song *tmp = playlist->p_head;
    playlist->p_head = tmp->p_nextSong;

    free(tmp->title);
    free(tmp->artist);
    free(tmp);

    playlist->size--;
}

/**
 * @brief delete playlist and free up memory
 *
 * @param playlist pointer to playlist
 */
void delete_playlist(Playlist *playlist)
{
    while (playlist->p_head)
        delete_firstSong(playlist);
}

Song* find_song_by_title(Playlist *playlist, const char *title){
    if (playlist->p_head == NULL)
    {
        return NULL;
    }
    if (title == NULL)
    {
        return NULL;
    }
    
    Song *temp = playlist->p_head;
    do
    {
        if (strcmp(temp->title, title) == 0)
        {
            return temp;
        }
        temp = temp->p_nextSong;
    }
    while(temp->p_nextSong != NULL);
    
    return NULL;
}

int count_songs_recursive(const Song *current){
    
    if (current == NULL)
    {
        return 1;
    }
    else {
        return count_songs_recursive(current->p_nextSong) + 1;
    }

}
void sort_playlist_by_title(Playlist *playlist){

    if (playlist->p_head == NULL || playlist->p_head->p_nextSong == NULL)
    {
        exit(0);
    }
    
    Playlist *left;
    init_playlist(left);
    
    Playlist *right;
    init_playlist(right);

    Song *links_aktuell = NULL;
    Song *rechts_aktuell = NULL;

    left->p_head = links_aktuell;
    right->p_head = rechts_aktuell;

    Song *pivot = playlist->p_head;
    do
    {
        if (strcmp(pivot->title, pivot->p_nextSong->title) > 0) //erster String größer
        {
            links_aktuell = pivot->p_nextSong;
            links_aktuell->p_nextSong = NULL;
            links_aktuell = links_aktuell->p_nextSong;
            sort_playlist_by_title(left);
        }
        if (strcmp(pivot->title, pivot->p_nextSong->title) < 0) //erster String kleiner
        {
            rechts_aktuell = pivot->p_nextSong;
            rechts_aktuell->p_nextSong = NULL;
            rechts_aktuell = rechts_aktuell->p_nextSong;
            sort_playlist_by_title(right);
        }
        if (strcmp(pivot->title, pivot->p_nextSong->title) == 0) //gleichgroß
        {
            pivot->p_nextSong = pivot->p_nextSong->p_nextSong;
        }
        
    } while (pivot->p_nextSong != NULL);

    links_aktuell->p_nextSong = right->p_head;

    Song *einSong = playlist->p_head;
    Song *linksSong = left->p_head;
    while (einSong->p_nextSong != NULL)
    {
        einSong = linksSong;
        linksSong = linksSong->p_nextSong;
        einSong = einSong->p_nextSong;
    }

}
