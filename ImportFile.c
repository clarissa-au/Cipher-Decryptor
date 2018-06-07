/*
 * ImportFile.c
 *
 *  Created on: 7 Dec 2017
 *      Author: sunnyau
 */
#include<stdio.h>
#include<string.h>

#include"CiphertextFunctions.h"
#include"PastAction.h"

struct Ciphertext{
	int size;
	int capacity;
	char filename[20];
	char *ciphertext;
};
#define CIPHERTEXT_INIT_SPACE 100


int ImportFile(char filename[], int x, struct Ciphertext text[]){

	char c;

	FILE *ciphertextpt;

	if ((ciphertextpt = fopen(filename, "r"))){
    		printf("File %s exist - Importing to slot %d.\n",filename, (x+1));
    }
    else{
    		printf("File %s does not exist, press a key to get back to the main page.",filename);
    		PastAction("Import Failed.");
    		getchar();
    		return 1;
    }

	strcpy(text[x].filename, filename);

	while( !feof(ciphertextpt) ){
		insertText(&text[x],c);
		c = fgetc(ciphertextpt);
	}

	fclose(ciphertextpt);
	PastAction("Import Succeed.");

	printf("Import succeed, file stored at slot %d.\n", (x+1));
	printf("Press enter to continue...\n");

	getchar();

	return 0;
}

