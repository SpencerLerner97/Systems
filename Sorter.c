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
  return 0;
}
