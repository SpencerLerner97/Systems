#ifndef SORTER_H
#define SORTER_H

enum CHAR_TYPES{ color = 0, 
                director_name = 1, 
                actor_2_name=2,
                genres=3,
                actor_1_name=4, 
                movie_title = 5, 
                actor_3_name = 6, 
                plot_keywords = 7,
                movie_imdb_link = 8,
                language = 9,
                country = 10,
                content_rating = 11
               }
enum INT_TYPES{ num_critic_for_reviews = 0,
               duration = 1,
               director_facebook_likes = 2,
               actor_3_facebook_likes = 3,
               actor_1_facebook_likes = 4,
               gross = 5,
               num_voted_users = 6,
               cast_total_facebook_likes = 7,
               facenumber_in_poster = 8,
               num_user_for_reviews = 9,
               budget = 10,
               title_year = 11,
               actor_2_facebook_likes = 12,
               movie_facebook_likes = 13
              }
enum FLOAT_TYPES{ imdb_scores = 0,
                 aspect_ration = 1}
struct rStruct{
  /*char * c_types[12];
  int i[14];
  float f[2];
  */
  char* color;
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

  struct rStruct * next;
};
typedef struct rStruct Record;

#endif
