/*  MovieData.h
    Jonathan Hanson
    CS 121
    Lab 10

    This header defines the MovieData struct.  Movies
    for the data base have their information stored in
    this format.

*/

struct MovieData{
    char title[256];
    char year[5];
    int actor_count;
    char (actor_list[32])[256];
};
typedef struct MovieData *MovieDataPtr;

void movieDataCpy(MovieDataPtr,MovieDataPtr);  //Deep copy of MovieData structs

