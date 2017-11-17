#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "Sorter.h"
#include "mergesort.c"
#include <sys/time.h>


struct spencer{
int i;
struct spencer *me;
};



record ** insertionSort(record ** input){
	if(((*input)->next == NULL) || (*input) == NULL){
		return input;
	}
	record * Sorted = *input;
	*input = (*input)->next;
	Sorted->next = NULL;
	while(*input){
		
	


int main(int argc, char** argv){














}