/*
 * ImportFile.c
 *
 *  Created on: 7 Dec 2017
 *      Author: sunnyau
 */
#include <stdio.h>

#include"CiphertextFunctions.h"

struct Ciphertext{
	int size;
	int capacity;
	char filename[20];
	char *ciphertext;
};
#define CIPHERTEXT_INIT_SPACE 100

void ImportFile(char filename[], int x, struct Ciphertext text[]){

	char c;

	FILE *ciphertextpt;

	ciphertextpt = fopen(filename, "r");

	if (ciphertextpt){
    		printf("File %s exist - Importing to slot %d.",filename, (x+1));
    }
    else{
    		printf("File %s does not exist, press a key get back to the main page.",filename);
    		getchar();
    		return;
    }

	while( !feof(ciphertextpt) ){
		insertText(&text[x],c);
		c = fgetc(ciphertextpt);
	}

	fclose(ciphertextpt);

	return;
}

