/*
 * ShiftCipherDecryptor.c
 *
 *  Created on: 6 Jan 2018
 *      Author: sunnyau
 */
#include<stdio.h>
#include"ShiftCipher/CharacterFunnel.h"
#include"ShiftCipher/FixedSpaceTranslator.h"
#include"TrivialTools.h"

#define TEXTNUMBERS 5
int characterlist[26];

void ShiftCipherDecoder(char file[]){
	char filec=file[0];
	int maxelem;
	int key;
	int rvkey;
	while((filec-49)<0||(filec-49)>TEXTNUMBERS){
		char c;
		while ((c = getchar()) != '\n' && c != EOF) { }
		printf("You have entered an invalid text reference number.\n");
		printf("Please reenter the text reference number.\n");
		printf("Text Reference Number > ");
		scanf("%c", &filec);
	}

	CharacterFunnel(filec);
	maxelem=LargestElement26(characterlist);
	key = maxelem-4;
	if(key<0){
		key=key+26;
	}
	rvkey = 26-key;
	FixedSpaceTranslator(rvkey, filec);

	printf("File %d has been decrypted on a key of %d using Shift Cipher.\n",(filec-48), key);
	printf("You can view it using the command 'read %d'\n", (filec-48));
	printf("Press enter to continue...\n");
	getchar();
	return;
}
