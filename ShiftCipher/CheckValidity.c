/*
 * CheckValidity.c
 *
 *  Created on: 4 Nov 2018
 *      Author: sunnyau
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"../main.h"
#define TEXTNUMBERS 5
extern struct Ciphertext All_texts[TEXTNUMBERS];
extern char Dictionary[10000][25];

/* Checks the validity of a solution.
 * if the solution is correct, return 1;
 * Otherwise, return 0.
 */

/* Sometimes the space allocated is not enough to fill the ciphertext in all of it's entirety.
 * As it is a sample of the passage, no problem.
 */

int CheckValidity(char SampleText[][25], int num){
	int hi, mid, low;
	int search;
	int tested=0, correct=0;
	for (int m = 0; m<=num; m++){
		tested ++;
		search = 0;
		hi = 9999;
		low = 0;
		while (hi > low+1 && search == 0){
			mid = (hi+low)/2;
      printf("%s %s\n", SampleText[m], Dictionary[mid]);
			if (strcmp(SampleText[m],Dictionary[mid])>0){
				low = mid;
			}
			else if(strcmp(SampleText[m],Dictionary[mid])==0){
				search = 1;
				correct++;
			}
			else{
				hi = mid;
			}
		}
	}
  //printf("%d\n", correct*100/tested);
	if(correct*100/tested > 70){
		return 1;
	}
	else{
		return 0;
	}
}
