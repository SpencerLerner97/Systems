#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "Sorter.h"
#include "mergesort.c"

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
  size_t nbytes = 0 * sizeof(char);
  Record * prevRec = NULL;
  Record * head = NULL;

  //eat stdin line by line
  while (getline(&line, &nbytes, stdin) != -1) {
    head = (Record *)malloc(sizeof(Record));
    int start = 0;
    int end = 0;
    char lookAhead = line[end];
    int colId = 0;
    short inString = 0;
    while((lookAhead = line[end]) != '\n'){
        if(lookAhead == '"'){
        inString = inString == 0 ? 1 : 0; //keep track if we are inside of quotes
      }
      else{ //normal char
        if(lookAhead == ',' && inString == 0){ //token found!
          char * token = NULL;
          if(end != start){ //if end == start, this is an empty entry
            token = (char *)malloc(sizeof(char) * (end-start));
            if(line[start] == '"' && line[end-1] == '"'){ //trims quotes
              //trim whitespace
              int tempEnd = end;
              while(isspace(line[tempEnd - 1])){
                tempEnd--;
              }
              while(isspace(line[start+1])){
                start++;
              }
              line[end - 1] = '\0';
              memcpy(token, line + start + 1, end - start - 1);
            }
            else{
              //trim whitespace
              int tempEnd = end;
              while(isspace(line[tempEnd])){
                tempEnd--;
              }
              while(isspace(line[start])){
                start++;
              }
              memcpy(token, line + start, tempEnd - start);
            }
          }
          switch(colId){
            case 0:
              head->color = token;
              break;
            case 1:
              head->director_name = token;
              break;
            case 2:
              head->num_critic_for_reviews = token == NULL ? -1 : atoi(token);
              break;
            case 3:
              head->duration = token == NULL ? -1 : atoi(token);
              break;
            case 4:
              head->director_facebook_likes = token == NULL ? -1 : atoi(token);
              break;
            case 5:
              head->actor_3_facebook_likes = token == NULL ? -1 : atoi(token);
              break;
            case 6:
              head->actor_2_name = token;
              break;
            case 7:
              head->actor_1_facebook_likes = token == NULL ? -1 : atoi(token);
              break;
            case 8:
              head->gross = token == NULL ? -1 : atoi(token);
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
              head->num_voted_users = token == NULL ? -1 : atoi(token);
              break;
            case 13:
              head->cast_total_facebook_likes = token == NULL ? -1 : atoi(token);
              break;
            case 14:
              head->actor_3_name = token;
              break;
            case 15:
              head->facenumber_in_poster = token == NULL ? -1 : atoi(token);
              break;
            case 16:
              head->plot_keywords = token;
              break;
            case 17:
              head->movie_imdb_link = token;
              break;
            case 18:
              head->num_user_for_reviews = token == NULL ? -1 : atoi(token);
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
              head->budget = token == NULL ? -1 : atoi(token);
              break;
            case 23:
              head->title_year = token == NULL ? -1 : atoi(token);
              break;
            case 24:
              head->actor_2_facebook_likes = token == NULL ? -1 : atoi(token);
              break;
            case 25:
              head->imdb_score = token == NULL ? -1 : atof(token);
              break;
            case 26:
              head->aspect_ratio = token == NULL ? -1 : atof(token);
              break;
            case 27:
              head->movie_facebook_likes = token == NULL ? -1 : atoi(token);
              break;
            default:
              break;
          }
          colId++;
          start = ++end;
          continue;
        }
      }
      end++;
    }
    //create a struct
    head->next = prevRec;
    prevRec = head;
  }
  while(prevRec->next != NULL){
    if(prevRec->movie_title != NULL){
      printf("%s\n",prevRec->movie_title);
    }
    prevRec = prevRec->next;
  }
  Record * newHead = mergesort(head, sortbyCol);
  //PRINT TO CSV(newHead)

  //free weezy
  while(head->next != NULL){
    /*free(head->color);
    free(head->director_name);
    free(head->num_critic_for_reviews);
    free(head->duration);
    free(head->director_facebook_likes);
    free(head->actor_3_facebook_likes);
    free(head->actor_2_name);
    free(head->gross);
    free(head->genres);
    free(head->actor_1_name);
    free(head->movie_title);
    free(head->num_voted_users);
    free(head->cast_total_facebook_likes);
    free(head->actor_3_name);
    free(head->facenumber_in_poster);
    free(head->plot_keywords);
    free(head->movie_imdb_link);
    free(head->num_user_for_reviews);
    free(head->language);
    free(head->country);
    free(head->content_rating);
    free(head->budget);
    free(head->title_year);
    free(head->actor_2_facebook_likes);
    free(head->imdb_score);
    free(head->aspect_ratio);
    free(head->movie_facebook_likes);head->num_critic_for_reviews);
    free(head->duration);
    free(head->director_facebook_likes);
    free(head->actor_3_facebook_likes);
    free(head->actor_2_name);
    free(head->gross);
    free(head->genres);
    free(head->actor_1_name);
    free(head->movie_title);
    free(head->num_voted_users);
    free(head->cast_total_facebook_likes);
    free(head->actor_3_name);
    free(head->facenumber_in_poster);
    free(head->plot_keywords);
    free(head->movie_imdb_link);
    free(head->num_user_for_reviews);
    free(head->language);
    free(head->country);
    free(head->content_rating);
    free(head->budget);
    free(head->title_year);
    free(head->actor_2_facebook_likes);
    free(head->imdb_score);
    free(head->aspect_ratio);
    free(head->movie_facebook_likes)*/
    Record * temp = head;
    head = head->next;
    free(temp);
  }
  return 0;
}
