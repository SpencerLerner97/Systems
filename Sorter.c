#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "Sorter.h"
#include "mergesort.c"
#include <pthread.h>

int main(int argc, char *argv[]){
  //make sure we have all 3 args
  if(argc != 3){
    fprintf(stderr, "Missing arguments. Usage is: 'cat input.file | ./sorter -c  [column]'\n");
    return 0;
  }
  //sorter can only support column sorting right now
  if(strcmp(argv[1], "-c") != 0){
    fprintf(stderr, "Usage is: 'cat input.file | ./sorter -c [column]'\n");
  }
  const char * sortByCol = argv[2];
  char * line = NULL;
  size_t nbytes = 0 * sizeof(char);
  Record * prevRec = NULL;
  Record * head = NULL;
  getline(&line, &nbytes, stdin); //skip over first row

  //eat stdin line by line
  while (getline(&line, &nbytes, stdin) != -1) {
    //if(line[0] == 'c')
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
            while(isspace(line[tempEnd-1])){
              tempEnd--;
            }
            while(isspace(line[start])){
              start++;
            }
            if(line[tempEnd - 1] == ' '){
              line[tempEnd - 1] = '\0';
            }
            else{
              line[tempEnd] = '\0';
            }
            token = (char *)realloc(token, sizeof(char) * (tempEnd-start+1));
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
              head->budget = token[0] == '\0' ? -1 :atol(token);
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
    //printf("%d - %s\n", head->duration, head->director_name);
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
  else if(strcmp(sortByCol, "aspect_ratio")==0)sortInt=26;
  else if(strcmp(sortByCol, "movie_facebook_likes")==0)sortInt=27;
  else{
    printf("Please use a valid column name!\n");
    return 0;
  }

  //sort the linked list based off of sort column
  Record ** Shead = mergesort(&head, sortInt);
  Record * sortedHead = *Shead;
  //Record * sortedHead = head;

  //print CSV to stdout
  printf("color,director_name,num_critic_for_reviews,duration,director_facebook_likes,"
  "actor_3_facebook_likes,actor_2_name,actor_1_facebook_likes,gross,genres,actor_1_name,"
  "movie_title,num_voted_users,cast_total_facebook_likes,actor_3_name,facenumber_in_poster,"
  "plot_keywords,movie_imdb_link,num_user_for_reviews,language,country,content_rating,"
  "budget,title_year,actor_2_facebook_likes,imdb_score,aspect_ratio,movie_facebook_likes\n");

  while(sortedHead != NULL){
    Record * r = sortedHead;
    char numCritic[50] = "";
    char duration[50] = "";
    char directLikes[50] = "";
    char actor3Likes[50] = "";
    char actor1Likes[50] = "";
    char gross[50] = "";
    char numVoted[50] = "";
    char castLikes[50] = "";
    char faceNumber[50] = "";
    char numReviews[50] = "";
    char budget[50] = "";
    char actor2Likes[50] = "";
    char titleYear[50] = "";
    char imdbScore[50] = "";
    char aspectRatio[50] = "";
    char movieLikes[50] = "";

    if(r->num_critic_for_reviews != -1){
        snprintf(numCritic, 5000, "%d",r->num_critic_for_reviews);
    }
    if(r->duration != -1){
        snprintf(duration, 5000, "%d",r->duration);
    }
    if(r->director_facebook_likes != -1){
        snprintf(directLikes, 5000, "%d",r->director_facebook_likes);
    }
    if(r->actor_3_facebook_likes != -1){
        snprintf(actor3Likes, 5000, "%d",r->actor_3_facebook_likes);
    }
    if(r->actor_1_facebook_likes != -1){
        snprintf(actor1Likes, 5000, "%d",r->actor_1_facebook_likes);
    }
    if(r->gross != -1){
        snprintf(gross, 5000, "%d",r->gross);
    }
    if(r->num_voted_users != -1){
        snprintf(numVoted, 5000, "%d",r->num_voted_users);
    }
    if(r->cast_total_facebook_likes != -1){
        snprintf(castLikes, 5000, "%d",r->cast_total_facebook_likes);
    }
    if(r->facenumber_in_poster != -1){
        snprintf(faceNumber, 5000, "%d",r->facenumber_in_poster);
    }
    if(r->num_critic_for_reviews != -1){
        snprintf(numReviews, 5000, "%d",r->num_critic_for_reviews);
    }
    if(r->budget != -1){
        snprintf(budget, 5000, "%li",r->budget);
    }
    if(r->actor_2_facebook_likes != -1){
        snprintf(actor2Likes, 5000, "%d",r->actor_2_facebook_likes);
    }
    if(r->title_year != -1){
        snprintf(titleYear, 5000, "%d",r->title_year);
    }
    if(r->imdb_score != -1){
        snprintf(imdbScore, 5000, "%f",r->imdb_score);
    }
    if(r->aspect_ratio != -1){
        snprintf(aspectRatio, 5000, "%f",r->aspect_ratio);
    }
    if(r->movie_facebook_likes != -1){
        snprintf(movieLikes, 5000, "%d",r->movie_facebook_likes);
    }

    if(strchr(r->movie_title, ',') == NULL){ //no commas in this movie title
      printf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
            r->color, r->director_name, numCritic, duration,
            directLikes, actor3Likes, r->actor_2_name,
            actor1Likes, gross, r->genres, r->actor_1_name,
            r->movie_title, numVoted, castLikes,
            r->actor_3_name, faceNumber, r->plot_keywords, r->movie_imdb_link,
            numReviews,r->language, r->country, r->content_rating,
            budget, titleYear, actor2Likes, imdbScore,
            aspectRatio, movieLikes);
    }
    else{ //put quotes around the movie title
      printf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,\"%s\",%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
              r->color, r->director_name, numCritic, duration,
              directLikes, actor3Likes, r->actor_2_name,
              actor1Likes, gross, r->genres, r->actor_1_name,
              r->movie_title, numVoted, castLikes,
              r->actor_3_name, faceNumber, r->plot_keywords, r->movie_imdb_link,
              numReviews,r->language, r->country, r->content_rating,
              budget, titleYear, actor2Likes, imdbScore,
              aspectRatio, movieLikes);
    }
    Record * temp = sortedHead;
    sortedHead = sortedHead->next;
    /*free(&temp->color);
    free(&temp->director_name);
    free(&temp->num_critic_for_reviews);
    free(&temp->duration);
    free(&temp->director_facebook_likes);
    free(&temp->actor_3_facebook_likes);
    free(&temp->actor_2_name);
    free(&temp->gross);
    free(&temp->genres);
    free(&temp->actor_1_name);
    free(&temp->movie_title);
    free(&temp->num_voted_users);
    free(&temp->cast_total_facebook_likes);
    free(&temp->actor_3_name);
    free(&temp->facenumber_in_poster);
    free(&temp->plot_keywords);
    free(&temp->movie_imdb_link);
    free(&temp->num_user_for_reviews);
    free(&temp->language);
    free(&temp->country);
    free(&temp->content_rating);
    free(&temp->budget);
    free(&temp->title_year);
    free(&temp->actor_2_facebook_likes);
    free(&temp->imdb_score);
    free(&temp->aspect_ratio);
    free(&temp->movie_facebook_likes);*/
    //free(temp);
  	}
  //printf("count before %d\n count after %d\n",bcount, pcount);
  return 0;
}
