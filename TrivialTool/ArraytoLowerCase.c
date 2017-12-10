#include<ctype.h>
#include<stdio.h>
/*
 * ArraytoLowerCase.c
 *
 *  Created on: 10 Dec 2017
 *      Author: sunnyau
 */
void ArraytoLowerCase(char *array[]){
	int i;
	for(i=0; array[i]; i++){
	  array[i] = tolower(array[i]);
	}
	return;
}

