/*
 * CiphertextFunctions.c
 *
 *  Created on: 5 Jan 2018
 *      Author: sunnyau
 */
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

#define RATIO 1.618

struct Ciphertext{
	int size;
	int capacity;
	char filename[20];
	char *ciphertext;
};
#define CIPHERTEXT_INIT_SPACE 100

//This int function returns a succeed/fail statement. Ignore if needed :)
int initText(struct Ciphertext *text){
	for(int i=0; i<20; i++){
		text->filename[i]=' ';
	}
	text->size=CIPHERTEXT_INIT_SPACE;
	text->capacity=0;
	text->ciphertext=calloc(CIPHERTEXT_INIT_SPACE, sizeof(char));
	if (text->ciphertext[CIPHERTEXT_INIT_SPACE] == 0){
		//Print Errors, but will later tend to implementation.
		return -1;
	}
	//Print succeed, later tend to implementation.
	return 0;
}

void insertText(struct Ciphertext *text, char c){
	if (text->capacity == text->size){
		text->ciphertext= realloc(text->ciphertext, round(text->size*RATIO));
		text->size=round(text->size*RATIO);
		if (text->ciphertext[text->size] == 0){
			//Print Errors, but will later tend to implementation. Break??
		}
	}
	text->ciphertext[text->capacity]=c;
	text->capacity++;
	return;
}

void resetText(struct Ciphertext *text){//please reset the bool Textexist if using.
	free(text->ciphertext);
	initText(text);
	return;
}

void freeText(struct Ciphertext *text){//please reset the bool Textexist if using.
	free(text->ciphertext);
	return;
}
