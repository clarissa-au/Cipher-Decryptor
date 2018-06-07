/*
 * RotationN.c
 *
 *  Created on: 6 Jan 2018
 *      Author: sunnyau
 */
#include<stdio.h>

#include"ShiftCipher/FixedSpaceTranslator.h"
#include"ShiftCipher/ROTNFixedSpaceTranslator.h"

#define TEXTNUMBERS 5

						//type 1 = ROT5
						//type 2 = ROT13
						//type 3 = ROT47
						//type 4 = ROT13.5 -> TODO:ROT13.5

void RotationN(char file[], int type){
	char filec=file[0];
	int x = filec-49;
	int typeused = 0;
	while(x < 0 || x > (TEXTNUMBERS-1) ){
		printf("You have entered an invalid text reference number.\n");
		printf("Please reenter the text reference number.\n");
		printf("Text Reference Number > ");
		scanf("%d", &x);
		filec = x + 49;
	}
	if(type == 1){
		ROTNFixedSpaceTranslator(5, x, 10);
		typeused = 5;
	}
	if(type == 2){
		FixedSpaceTranslator(13, filec);
		typeused = 13;
	}
	if(type == 3){
		ROTNFixedSpaceTranslator(47, x, 94);
		typeused = 47;

	}

	printf("File %d has been encrypted using ROT %d Cipher System.\n",(x+1), typeused);
	printf("You can view it using the command 'read %d'\n", (x+1));
	printf("Press enter to continue...\n");

	getchar();

	return;
}

