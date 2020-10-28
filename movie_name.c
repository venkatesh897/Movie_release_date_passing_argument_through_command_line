//program to take movie name as argument in cmd
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "movie_release_date.h"
int main(int argc, char  *argv[])
{
	char* movie_name;
	movie_name = argv[1];
	display_release_date(movie_name);
	return 0;
}
