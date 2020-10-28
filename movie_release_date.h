//Library to print release date of a movie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MOVIE_DETAILS_FILE "movie_details.dat"

char* get_release_date(char* file_name)
{
	char movie_details[1000];
 	FILE* fp_movie_details = fopen(file_name, "r");
 	fread(movie_details, sizeof(movie_details), 1, fp_movie_details);
 	char* movie_details_token = strtok(movie_details, "{,\":");
 	char* release_date;
 	while(movie_details_token !=  NULL)
 	{
 		char is_found = 'n';
 		if(strcmp(movie_details_token, "Released") == 0)
 		{
 			is_found = 'y';
 		}
 		movie_details_token = strtok(NULL, "{,\":");
 		if(is_found == 'y')
 		{
 			release_date = movie_details_token;
 			break;
 		}
 	}
 	fclose(fp_movie_details);
 	return release_date;
}

void display_release_date(char* movie_name)
{
	char cmd[100];
	sprintf(cmd, "curl \"http://www.omdbapi.com/?apikey=602069c1&t=%s\" > %s -s", movie_name, MOVIE_DETAILS_FILE);
	system(cmd);
	char* release_date = get_release_date(MOVIE_DETAILS_FILE);
	printf("The movie %s is released in %s", movie_name, release_date);
}
