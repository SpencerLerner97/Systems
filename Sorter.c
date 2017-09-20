#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "Sorter.h"

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
  Record * record = (Record *)malloc(sizeof(Record));
  char * line = NULL;
  size_t nbytes = 5000 * sizeof(char);

  //get next line, break it up into tokens
  getline(&line, &nbytes, stdin);
  while (line != NULL) {
    char * token = strtok(line, ",");
    //loop through each token in the line
    int colId = 0;
    //CREATE COLUMN ARRAY HERE MAPING INTS TO COLUMN HEADERS
    while (token != NULL){
      printf("%s: %s\n", column[colId], token);
      colId++;
      token = strtok(NULL, ",");
    }
    if(getline(&line, &nbytes, stdin) == -1){
      break;
    }
  }
  return 0;
}
