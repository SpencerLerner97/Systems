#include <stdio.h>
#include <string.h>
#include <math.h>
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
  size_t nbytes = 5000 * sizeof(char);
  Record * prevRec = NULL;
  Record * head  = (Record *)malloc(sizeof(Record));

  //eat stdin line by line
  while (getline(&line, &nbytes, stdin) != -1) {
    int start = 0;
    int end = 0;
    char lookAhead = line[end];
    int colId = 0;
    short inString = 0;
    while((lookAhead = line[end]) != '\n'){
      if(lookAhead == '"'){
        inString = ~inString; //keep track if we are inside of quotes
      }
      else{
        //duplicate if statement
        if(lookAhead == ',' && ~inString){ //token found!
          char * token = NULL;
          if(end != start){
            token = (char *)malloc(sizeof(char) * (end-start));
            memcpy(token, line + start, end-start);
          }
          start = ++end;
          //switch and add to structs
          colId++;
          //new head, prev
          printf("%s|", token);
        }
      }
      end++;
    }
    printf("\n\n");
  }
  while(head->next != NULL){
    printf("%s\n", head->movie_title);
    head = head->next;
  }
  Record * newHead = mergesort(head, sortbyCol);
  //PRINT TO CSV(HEAD)

  /*
  USE FOR STRUCT LOADING
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
  */
  return 0;
}
