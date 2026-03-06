/*
 * File: main.c
 * Description: Program to demo usage of playlist
 */
#include "playlist.h"

/**
 * @brief exemplary usage of playlist
 *
 * @return int status code
 */
int main(void)
{
    printf("\nMaximum playlist size is set to %d songs.\n", MAX_SONGS);
    Playlist myPlaylist;
    init_playlist(&myPlaylist);

    add_song(&myPlaylist, "Crawling", "Linkin Park");
    add_song(&myPlaylist, "Layla", "Eric Clapton");
    add_song(&myPlaylist, "Esperanto", "Max Herre");
    print_playlist(&myPlaylist);

    const char title[50] = "Layla";
    const char *p_title = title;

    Song *einSong = find_song_by_title(&myPlaylist, p_title);
    printf("\n");
    printf("%s", einSong->artist);

    printf("\n%d\n", count_songs_recursive(einSong));


    delete_firstSong(&myPlaylist);
    print_playlist(&myPlaylist);

    delete_playlist(&myPlaylist);

    return 0;
}
