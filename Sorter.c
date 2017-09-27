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
  const char * sortByCol = argv[2];
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
          char * token = (char *)malloc(sizeof(char));
          token[0] = '\0';
          if(end != start){ //if end == start, this is an empty entry
            int tempEnd = end - 1;
            if(line[start] == '"' && line[end-1] == '"'){ //trim quotes
              tempEnd--;
              start++;
            }
            tempEnd++;//move past last valid character
            //trim whitespace
            while(isspace(line[tempEnd])){
              tempEnd--;
            }
            while(isspace(line[start])){
              start++;
            }
            token = (char *)realloc(token, sizeof(char) * (tempEnd-start+1));
            line[tempEnd] = '\0';
            memcpy(token, line + start, tempEnd - start+1);
          }
          switch(colId){
            case 0:
              head->color = token;
              break;
            case 1:
              head->director_name = token;
              break;
            case 2:
              head->num_critic_for_reviews = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 3:
              head->duration = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 4:
              head->director_facebook_likes = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 5:
              head->actor_3_facebook_likes = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 6:
              head->actor_2_name = token;
              break;
            case 7:
              head->actor_1_facebook_likes = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 8:
              head->gross = token[0] == '\0' ? -1 : atoi(token);
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
              head->num_voted_users = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 13:
              head->cast_total_facebook_likes = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 14:
              head->actor_3_name = token;
              break;
            case 15:
              head->facenumber_in_poster = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 16:
              head->plot_keywords = token;
              break;
            case 17:
              head->movie_imdb_link = token;
              break;
            case 18:
              head->num_user_for_reviews = token[0] == '\0' ? -1 : atoi(token);
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
              head->budget = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 23:
              head->title_year = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 24:
              head->actor_2_facebook_likes = token[0] == '\0' ? -1 : atoi(token);
              break;
            case 25:
              head->imdb_score = token[0] == '\0' ? -1 : atof(token);
              break;
            case 26:
              head->aspect_ratio = token[0] == '\0' ? -1 : atof(token);
              break;
            case 27:
              head->movie_facebook_likes = token[0] == '\0' ? -1 : atoi(token);
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
    //add final column
    char * token = (char *)malloc(sizeof(char) * (end-start));
    int tempEnd = end;
    while(isspace(line[tempEnd])){
      tempEnd--;
    }
    while(isspace(line[start])){
      start++;
    }
    memcpy(token, line + start, tempEnd - start + 1);
    head->movie_facebook_likes = token[0] == '\0' ? -1 : atoi(token);

    //create a struct
    head->next = prevRec;
    prevRec = head;
  }

  //parse sort column into an int for the sorting
  int sortInt = 0;
  if(strcmp(sortByCol,  "color")==0)sortInt=0;
  else if(strcmp(sortByCol, "director_name")==0)sortInt=1;
  else if(strcmp(sortByCol, "num_critic_for_reviews")==0)sortInt=2;
  else if(strcmp(sortByCol, "duration")==0)sortInt=3;
  else if(strcmp(sortByCol, "director_facebook_likes")==0)sortInt=4;
  else if(strcmp(sortByCol, "actor_3_facebook_likes")==0)sortInt=5;
  else if(strcmp(sortByCol, "actor_2_name")==0)sortInt=6;
  else if(strcmp(sortByCol, "actor_1_facebook_likes")==0)sortInt=7;
  else if(strcmp(sortByCol, "gross")==0)sortInt=8;
  else if(strcmp(sortByCol, "genres")==0)sortInt=9;
  else if(strcmp(sortByCol, "actor_1_name")==0)sortInt=10;
  else if(strcmp(sortByCol, "movie_title")==0)sortInt=11;
  else if(strcmp(sortByCol, "num_voted_users")==0)sortInt=12;
  else if(strcmp(sortByCol, "cast_total_facebook_likes")==0)sortInt=13;
  else if(strcmp(sortByCol, "actor_3_name")==0)sortInt=14;
  else if(strcmp(sortByCol, "facenumber_in_poster")==0)sortInt=15;
  else if(strcmp(sortByCol, "plot_keywords")==0)sortInt=16;
  else if(strcmp(sortByCol, "movie_imdb_link")==0)sortInt=17;
  else if(strcmp(sortByCol, "num_user_for_reviews")==0)sortInt=18;
  else if(strcmp(sortByCol, "language")==0)sortInt=19;
  else if(strcmp(sortByCol, "country")==0)sortInt=20;
  else if(strcmp(sortByCol, "content_rating")==0)sortInt=21;
  else if(strcmp(sortByCol, "budget")==0)sortInt=22;
  else if(strcmp(sortByCol, "title_year")==0)sortInt=23;
  else if(strcmp(sortByCol, "actor_2_facebook_likes")==0)sortInt=24;
  else if(strcmp(sortByCol, "imdb_score")==0)sortInt=25;
  else if(strcmp(sortByCol, "aspect_ratio")==0)sortInt=27;
  else if(strcmp(sortByCol, "movie_facebook_likes")==0)sortInt=27;
	mergesort(&head, sortInt);

  //print CSV to stdout
  printf("color,director_name,num_critic_for_reviews,duration,director_facebook_likes,"
  "actor_3_facebook_likes,actor_2_name,actor_1_facebook_likes,gross,genres,actor_1_name,"
  "movie_title,num_voted_users,cast_total_facebook_likes,actor_3_name,facenumber_in_poster,"
  "plot_keywords,movie_imdb_link,num_user_for_reviews,language,country,content_rating,"
  "budget,title_year,actor_2_facebook_likes,imdb_score,aspect_ratio,movie_facebook_likes\n");

  while(head->next != NULL){
    Record * r = head;
    if(strchr(r->movie_title, ',') == NULL){ //no commas in this movie title
      printf("%s,%s,%d,%d,%d,%d,%s,%d,%d,%s,%s,%s,%d,%d,%s,%d,%s,%s,%d,%s,%s,%s,%d,%d,%d,%f,%f,%d\n",
            r->director_name, r->director_name, r->num_critic_for_reviews, r->duration,
            r->director_facebook_likes, r->actor_3_facebook_likes, r->actor_2_name,
            r->actor_1_facebook_likes, r->gross, r->genres, r->actor_1_name,
            r->movie_title, r->num_voted_users, r->cast_total_facebook_likes,
            r->actor_3_name, r->facenumber_in_poster, r->plot_keywords, r->movie_imdb_link,
            r->num_user_for_reviews,r->language, r->country, r->content_rating,
            r->budget, r->title_year, r->actor_2_facebook_likes, r->imdb_score,
            r->aspect_ratio, r->movie_facebook_likes);
    }
    else{ //put quotes around the movie title
      printf("%s,%s,%d,%d,%d,%d,%s,%d,%d,%s,%s,\"%s\",%d,%d,%s,%d,%s,%s,%d,%s,%s,%s,%d,%d,%d,%f,%f,%d\n",
            r->director_name, r->director_name, r->num_critic_for_reviews, r->duration,
            r->director_facebook_likes, r->actor_3_facebook_likes, r->actor_2_name,
            r->actor_1_facebook_likes, r->gross, r->genres, r->actor_1_name,
            r->movie_title, r->num_voted_users, r->cast_total_facebook_likes,
            r->actor_3_name, r->facenumber_in_poster, r->plot_keywords, r->movie_imdb_link,
            r->num_user_for_reviews,r->language, r->country, r->content_rating,
            r->budget, r->title_year, r->actor_2_facebook_likes, r->imdb_score,
            r->aspect_ratio, r->movie_facebook_likes);
    }
    Record * temp = head;
    head = head->next;
    free(temp);
  }
  return 0;
}
