#include "Sorter.h"
#include <string.h>
int
count(Record ** head)
{//count how many things are in the list
	int c=0;
	while(*head){
		head  = &(**head).next;
		++c;
	}
	return c;
}

void 
split(Record ** head, Record ** secondHead, int count)
{//this 2nd head should be an empty pointer. Count should be the number of elemnts in the list
	int iter; Record ** temp = head;
	for(iter = count/2; iter >0; iter --){
		temp = &(**temp).next;
	}
	*secondHead = (*temp)->next;
	(*temp)->next = NULL;
}

Record **
merge(Record ** head, Record ** secondHead, int sortBycol)
{//merge the two lists. Based on sort By col. Sort by col is a zer indexed integer that gives me which column in the struct we are sorting by.
      if(*head == NULL){
          return secondHead;
        }
      if(*secondHead == NULL){
        return head;
      }
  switch(sortBycol)
  {
		case 0: //char* color;
      if(strcmp(((*head)->color),((*head)->next)-> color)>0){
        (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 1: //char* director_name;
      if(strcmp(((*head)->director_name),((*head)->next)-> director_name)>0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 2: //int num_critic_for_reviews;
      if(((*head)->num_critic_for_reviews) < (((*secondHead)-> num_critic_for_reviews))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
        (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 3: //int duration;
       if(((*head)->duration) < (((*secondHead)-> duration))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 4: //int director_facebook_likes;
       if(((*head)->director_facebook_likes) < (((*secondHead)->director_facebook_likes))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 5: //int actor_3_facebook_likes;
       if(((*head)->actor_3_facebook_likes) < (((*secondHead)-> actor_3_facebook_likes))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 6: //char * actor_2_name;
      if(strcmp(((*head)->actor_2_name),((*head)->next)-> actor_2_name)>0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 7: //int actor_1_facebook_likes;
       if(((*head)->actor_1_facebook_likes) < (((*secondHead)-> actor_1_facebook_likes))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 8: //int gross;
       if(((*head)->gross) < (((*secondHead)-> gross))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 9: //char * genres;
      if(strcmp(((*head)->genres),((*head)->next)-> genres)>0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 10: //char * actor_1_name;
      if(strcmp(((*head)->actor_1_name),((*head)->next)-> actor_1_name)>0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 11: //char * movie_title;
      if(strcmp(((*head)->movie_title),((*head)->next)-> movie_title)>0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 12: //int num_voted_users;
       if(((*head)->num_voted_users) < (((*secondHead)-> num_voted_users))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 13: //int cast_total_facebook_likes;
       if(((*head)->cast_total_facebook_likes) < (((*secondHead)->cast_total_facebook_likes))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 14: //char * actor_3_name;
      if(strcmp(((*head)->actor_3_name),((*head)->next)-> actor_3_name)>0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 15: //int facenumber_in_poster;
       if(((*head)->facenumber_in_poster) < (((*secondHead)-> facenumber_in_poster))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 16: //char * plot_keywords;
      if(strcmp(((*head)->plot_keywords),((*head)->next)->plot_keywords)>0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 17: //char * movie_imdb_link;
       if(strcmp(((*head)->movie_imdb_link),((*head)->next)->movie_imdb_link)>0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 18: //int num_user_for_reviews;
        if(((*head)->num_user_for_reviews) < (((*secondHead)-> num_user_for_reviews))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
          return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 19: //char * language;
       if(strcmp(((*head)->language),((*head)->next)->language)>0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 20: //char * country;
       if(strcmp(((*head)->country),((*head)->next)->country)>0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 21: //char * content_rating;
       if(strcmp(((*head)->content_rating),((*head)->next)->content_rating)>0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 22: //int budget;
       if(((*head)->budget) < (((*secondHead)-> budget))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 23: //int title_year;
       if(((*head)->title_year) < (((*secondHead)->title_year))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 24: //int actor_2_facebook_likes;
       if(((*head)->actor_2_facebook_likes) < (((*secondHead)-> actor_2_facebook_likes))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 25: //float imdb_score;
       if(((*head)->imdb_score) < (((*secondHead)-> imdb_score))){
          (*head)->next = *merge(head,&((*secondHead)->next),sortBycol);
        }
          (*secondHead)->next = *merge(head,&(*secondHead)->next,sortBycol);
          return secondHead;
  	case 26: //float aspect_ratio;
       if(((*head)->aspect_ratio) < (((*secondHead)-> aspect_ratio))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 27: //int movie_facebook_likes;
       if(((*head)->movie_facebook_likes) < (((*secondHead)-> movie_facebook_likes))){
          (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
         return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  }
}


void 
mergesort(Record ** head, int sortByCol)
 {//mergesort on head done by which column. COlumn is currently a string but we may swithc it to a int.
	 int size = count(head);
	 if(size > 2){//the general case of a list with more than 2 items
		Record ** secondHead = head;
		split(head,secondHead,count);
		mergesort(head,sortByCol);
		mergesort(secondHead,sortByCol);
		merge(head,secondHead,sortByCol);

	}
	if(size == 2){ //if list has two items check, maybe swap and than get out.
		switch(sortByCol){
		  case 0: //char* color;
        if(strcmp((*head)->color,((*head)->next)-> color)>0){
         return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 1: //char* director_name;
        if(strcmp((*head)->director_name,((*head)->next)-> director_name)>0){
          return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 2: //int num_critic_for_reviews;
  		  if(((*head)->num_critic_for_reviews) < (((*head)->next)-> num_critic_for_reviews)){
  			 return;
  		  }
  		  Record * temp = (*head)->next;
  		  temp->next = *head;
  		  (*head)->next = NULL;
  		  *head = temp;
  		  return;
  		case 3: //int duration;
        if(((*head)->duration) < (((*head)->next)-> duration)){
        return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 4: //int director_facebook_likes;
        if(((*head)->director_facebook_likes) < (((*head)->next)->director_facebook_likes)){
        return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 5: //int actor_3_facebook_likes;
        if(((*head)->actor_3_facebook_likes) < (((*head)->next)-> actor_3_facebook_likes)){
        return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 6: //char * actor_2_name;
        if(strcmp((*head)->actor_2_name,((*head)->next)-> actor_2_name)>0){
         return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 7: //int actor_1_facebook_likes;
        if(((*head)->actor_1_facebook_likes) < (((*head)->next)->actor_1_facebook_likes)){
        return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 8: //int gross;
        if(((*head)->gross) < (((*head)->next)-> gross)){
        return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 9: //char * genres;
        if(strcmp((*head)->genres,((*head)->next)->genres)>0){
          return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 10: //char * actor_1_name;
        if(strcmp(((*head)->actor_1_name),((*head)->next)-> actor_1_name)>0){
          return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 11: //char * movie_title;
        if(strcmp((*head)->movie_title,((*head)->next)->movie_title)>0){
          return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 12: //int num_voted_users;
        if(((*head)->num_voted_users) < (((*head)->next)-> num_voted_users)){
        return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 13: //int cast_total_facebook_likes;
        if(((*head)->cast_total_facebook_likes) < (((*head)->next)-> cast_total_facebook_likes)){
        return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 14: //char * actor_3_name;
        if(strcmp((*head)->actor_3_name,((*head)->next)-> actor_3_name)>0){
          return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 15: //int facenumber_in_poster;
        if(((*head)->facenumber_in_poster) < (((*head)->next)-> facenumber_in_poster)){
        return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 16: //char * plot_keywords;
        if(strcmp((*head)->plot_keywords,((*head)->next)-> plot_keywords)>0){
          return;
          }
          Record * temp = (*head)->next;
          temp->next = *head;
          (*head)->next = NULL;
          *head = temp;
          return;
  		case 17: //char * movie_imdb_link;
        if(strcmp((*head)->movie_imdb_link,((*head)->next)-> movie_imdb_link)>0){
          return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 18: //int num_user_for_reviews;
        if(((*head)->num_user_for_reviews) < (((*head)->next)-> num_user_for_reviews)){
        return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 19: //char * language;
        if(strcmp((*head)->language,((*head)->next)-> language)>0){
          return;
          }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 20: //char * country;
        if(strcmp((*head)->country,((*head)->next)-> country)>0){
          return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 21: //char * content_rating;
        if(strcmp((*head)->content_rating,((*head)->next)-> content_rating)>0){
          return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 22: //int budget;
        if(((*head)->budget) < (((*head)->next)-> budget)){
        return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 23: //int title_year;
        if(((*head)->title_year) < (((*head)->next)-> title_year)){
        return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 24: //int actor_2_facebook_likes;
        if(((*head)->actor_2_facebook_likes) < (((*head)->next)-> actor_2_facebook_likes)){
        return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 25: //float imdb_score;
        if(((*head)->imdb_score) < (((*head)->next)-> imdb_score)){
          return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 26: //float aspect_ratio;
        if(((*head)->aspect_ratio) < (((*head)->next)-> aspect_ratio)){
          return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
  		case 27: //int movie_facebook_likes;
        if(((*head)->movie_facebook_likes) < (((*head)->next)-> movie_facebook_likes)){
          return;
        }
        Record * temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return;
	}
	if(size == 1){
		return;
	}
}


