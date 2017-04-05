#include<iostream>
#include<cstring>
using namespace std;

#include"MovieData.h"

void movieDataCpy(MovieDataPtr a,MovieDataPtr b)
{
    strcpy(a->title,b->title);
    strcpy(a->year,b->year);
    a->actor_count = b->actor_count;
    for(int i = 0; i < b->actor_count ; i++)
    {
        strcpy(a->actor_list[i],b->actor_list[i]);
    }
}

