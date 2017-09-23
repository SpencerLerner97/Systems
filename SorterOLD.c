#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "Sorter.h"
#include "mergesort.c"

char * colIds[28] = {
  "color",
  "director_name",
  "num_critic_for_reviews",
  "duration",
  "director_facebook_likes",
  "actor_3_facebook_likes",
  "actor_2_name",
  "actor_1_facebook_likes",
  "gross",
  "genres",
  "actor_1_name",
  "movie_title",
  "num_voted_users",
  "cast_total_facebook_likes",
  "actor_3_name",
  "facenumber_in_poster",
  "plot_keywords",
  "movie_imdb_link",
  "num_user_for_reviews",
  "language",
  "country",
  "content_rating",
  "budget",
  "title_year",
  "actor_2_facebook_likes",
  "imdb_score",
  "aspect_ratio",
  "movie_facebook_likes"
};

int main(int argc, char *argv[]){
  //make sure we have all 3 args
  if(argc != 3){
    printf("Missing arguments. Usage is: 'cat input.file | ./sorter -c  movie_title'\n");
    return 0;
  }
  //sorter can only support column sorting right now
  if(strcmp(argv[1], "-c") != 0){
    printf("Usage is: 'cat input.file | ./sorter -c  movie_title'\n");
  }
  char * sortbyCol = argv[2];
  char * line = NULL;
  size_t nbytes = 5000 * sizeof(char);
  Record * prevRec = NULL;
  Record * head  = (Record *)malloc(sizeof(Record));

  //get next line, break it up into tokens
  getline(&line, &nbytes, stdin);
  while (line != NULL) {
    char * token = strtok(line, ",");
    int length = strlen(token);
    char * entry = (char *)malloc(sizeof(char) * (length+1));
    strcpy(entry,token);

    //loop through each token in the line
    int colId = 0;
    while (token != NULL){
      switch(colId){
        case 0:
          head->color = entry;
          break;
        case 1:
          head->director_name = entry;
          break;
        case 2:
          head->num_critic_for_reviews = atoi(entry);
          break;
        case 3:
          head->duration = atoi(entry);
          break;
        case 4:
          head->director_facebook_likes = atoi(entry);
          break;
        case 5:
          head->actor_3_facebook_likes = atoi(entry);
          break;
        case 6:
          head->actor_2_name = entry;
          break;
        case 7:
          head->actor_1_facebook_likes = atoi(entry);
          break;
        case 8:
          head->gross = atoi(entry);
          break;
        case 9:
          head->genres = entry;
          break;
        case 10:
          head->actor_1_name = entry;
          break;
        case 11:
          head->movie_title = entry;
          break;
        case 12:
          head->num_voted_users = atoi(entry);
          break;
        case 13:
          head->cast_total_facebook_likes = atoi(entry);
          break;
        case 14:
          head->actor_3_name = entry;
          break;
        case 15:
          head->facenumber_in_poster = atoi(entry);
          break;
        case 16:
          head->plot_keywords = entry;
          break;
        case 17:
          head->movie_imdb_link = entry;
          break;
        case 18:
          head->num_user_for_reviews = atoi(entry);
          break;
        case 19:
          head->language = entry;
          break;
        case 20:
          head->country = entry;
          break;
        case 21:
          head->content_rating = entry;
          break;
        case 22:
          head->budget = atoi(entry);
          break;
        case 23:
          head->title_year = atoi(entry);
          break;
        case 24:
          head->actor_2_facebook_likes = atoi(entry);
          break;
        case 25:
          head->imdb_score = atof(entry);
          break;
        case 26:
          head->aspect_ratio = atof(entry);
          break;
        case 27:
          head->movie_facebook_likes = atoi(entry);
          break;
        default:
          break;
      }
      colId++;
      token = strtok(NULL, ",");
      if(token == NULL){
        break;
      }
      length = strlen(token);
      entry = (char *)malloc(sizeof(char) * (length+1));
      strcpy(entry,token);
    }
    //add to head
    head->next = prevRec;
    prevRec = head;
    if(getline(&line, &nbytes, stdin) == -1){
      //done with reading csv
      break;
    }
    head  = (Record *)malloc(sizeof(Record));
  }
  while(head->next != NULL){
    printf("%s\n", head->movie_title);
    head = head->next;
  }
  Record * newHead = mergesort(head, sortbyCol);
  //PRINT TO CSV(HEAD)
  return 0;
}
