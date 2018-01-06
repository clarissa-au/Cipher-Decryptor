/*
 * PastAction.c
 *
 *  Created on: 5 Jan 2018
 *      Author: sunnyau
 */
extern int ActionCount;

#define TEXTNUMBERS 5 //related to main.c, no externs in #define

#define PASTACTIONSTORED 5 //related to main.c, no externs in #define
#define ACTIONLENGTH 50 //related to main.c

extern char PastActionArray[5][50];

#include<stdio.h>
#include<string.h>

void PastAction(char *action){
	if(ActionCount<5){
		strcpy(PastActionArray[ActionCount],action);
		ActionCount++;
	}
	else{
		for(int i=1; i<TEXTNUMBERS; i++){
			strcpy(PastActionArray[i-1],PastActionArray[i]);
		}
		strcpy(PastActionArray[(TEXTNUMBERS-1)],action);
	}
	return;
}

void PrintPastAction(){
	for (int i=0; i<ActionCount; i++){
		printf("%s\n", PastActionArray[i]);
	}
	return;
}

void ClearPastActions(){
	ActionCount=0;
	for(int i=0; i<PASTACTIONSTORED; i++){
		for(int j=0; j<ACTIONLENGTH; j++){
			PastActionArray[i][j]=' ';
		}
	}
	return;
}
