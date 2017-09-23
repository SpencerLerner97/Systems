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
    char curr = line[0];
    char lookAhead = line[0];
    int start = 0;
    int end = 0;
    int colId = 0;
    while(curr != '\n'){
      if(curr == '\"'){ //dealing with a string
        lookAhead = line[++end]; //move to after the quote
        curr = line[++start];
        while(lookAhead != '\"'){
          lookAhead = line[end++];
        }
        if(end > start){
          lookAhead = line[--end]; //move to before the quote
        }
      }
      else{ //dealing with a non-quoted entry
        lookAhead = line[end];
        while(lookAhead != ','){
          if(lookAhead == '\n' || lookAhead == EOF){
            break;
          }
          lookAhead = line[end++];
        }
        if(end > start){
          lookAhead = line[--end]; //move to before the comma
        }
      }
      //create token with known size
      char * token = (char *)malloc(sizeof(char) * (end-start));
      memcpy(token, line + start, end-start);
      printf("%d - %d: %s\n",start, end, token);
      switch(colId){
        case 0:
          head->color = token;
          break;
        case 1:
          head->director_name = token;
          break;
        case 2:
          head->num_critic_for_reviews = atoi(token);
          break;
        case 3:
          head->duration = atoi(token);
          break;
        case 4:
          head->director_facebook_likes = atoi(token);
          break;
        case 5:
          head->actor_3_facebook_likes = atoi(token);
          break;
        case 6:
          head->actor_2_name = token;
          break;
        case 7:
          head->actor_1_facebook_likes = atoi(token);
          break;
        case 8:
          head->gross = atoi(token);
          break;
        case 9:
          head->genres = token;
          break;
        case 10:
          head->actor_1_name = token;
          break;
        case 11:
          head->movie_title = token;
          break;
        case 12:
          head->num_voted_users = atoi(token);
          break;
        case 13:
          head->cast_total_facebook_likes = atoi(token);
          break;
        case 14:
          head->actor_3_name = token;
          break;
        case 15:
          head->facenumber_in_poster = atoi(token);
          break;
        case 16:
          head->plot_keywords = token;
          break;
        case 17:
          head->movie_imdb_link = token;
          break;
        case 18:
          head->num_user_for_reviews = atoi(token);
          break;
        case 19:
          head->language = token;
          break;
        case 20:
          head->country = token;
          break;
        case 21:
          head->content_rating = token;
          break;
        case 22:
          head->budget = atoi(token);
          break;
        case 23:
          head->title_year = atoi(token);
          break;
        case 24:
          head->actor_2_facebook_likes = atoi(token);
          break;
        case 25:
          head->imdb_score = atof(token);
          break;
        case 26:
          head->aspect_ratio = atof(token);
          break;
        case 27:
          head->movie_facebook_likes = atoi(token);
          break;
        default:
          break;
      }
      colId++;
      while(lookAhead != ','){ //move to past next comma
        if(lookAhead == '\n' || lookAhead == EOF){
          break;
        }
        lookAhead = line[++end];
      }
      lookAhead = line[++end];
      curr = line[(start = end)];
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
