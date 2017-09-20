#ifndef SORTER_H
#define SORTER_H

struct rStruct{
  char* director_name;
  int num_critic_for_reviews;
  int duration;
  int director_facebook_likes;
  int actor_3_facebook_likes;
  char * actor_2_name;
  int actor_1_facebook_likes;
  int gross;
  char * genres;
  char * actor_1_name;
  char * movie_title;
  int num_voted_users;
  int cast_total_facebook_likes;
  char * actor_3_name;
  int facenumber_in_poster;
  char * plot_keywords;
  char * movie_imdb_link;
  int num_user_for_reviews;
  char * language;
  char * country;
  char * content_rating;
  int budget;
  int title_year;
  int actor_2_facebook_likes;
  float imdb_score;
  float aspect_ratio;
  int movie_facebook_likes;
};
typedef struct rStruct Record;

#endif
