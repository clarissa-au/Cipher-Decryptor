/*
 * ShiftCipherDecryptor.c
 *
 *  Created on: 6 Jan 2018
 *      Author: sunnyau
 */
#include<stdio.h>
#include<ctype.h>
#include"ShiftCipher/CharacterFunnel.h"
#include"ShiftCipher/FixedSpaceTranslator.h"
#include"ShiftCipher/CheckValidity.h"
#include"TrivialTools.h"

#define TEXTNUMBERS 5
extern struct Ciphertext All_texts[TEXTNUMBERS];
#include"main.h"

#define TEXTNUMBERS 5
int characterlist[26];

void ShiftCipherDecoder(char file[]){
	char filec=file[0];
	int maxelem;
	int key;
	int rvkey;
	while((filec-49)<0||(filec-49)>(TEXTNUMBERS-1)){
		char c;
		while ((c = getchar()) != '\n' && c != EOF) { }
		printf("You have entered an invalid text reference number.\n");
		printf("Please reenter the text reference number.\n");
		printf("Text Reference Number > ");
		scanf("%c", &filec);
	}

	char choice;
	char c;
	while ((c = getchar()) != '\n' && c != EOF) { }
	printf("Please enter a decryption method[_A_uto/_D_ict]:\n");
	printf("Choice > ");
	choice = getchar();
	choice = tolower(choice);

	while (choice != 'a' && choice != 'd'){
		printf("Please reenter a decryption method[_A_uto/_D_ict]:\n");
		printf("Choice > ");
		choice = getchar();
		choice = tolower(choice);
	}

	if (choice == 'a'){
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
	}
	if (choice == 'd'){
		CharacterFunnel(filec);
		int solved = 0;
		int cases = 1;
		int resolve = 0;
		int currentelem = 0;
		while(solved == 0 && cases <= 26){
			currentelem = Element26(characterlist, cases);
			key = currentelem-4;
			if(key<0){
				key=key+26;
			}
			rvkey = 26-key;
			FixedSpaceTranslator(rvkey, filec);
			char SampleText[1000][25];
			int text;
			text = (filec-49);
			int j=0, i=0, k=0;
			while(i<=All_texts[text].capacity && j<1000){
				//Dictionary[10000][25]
				c = All_texts[text].ciphertext[i];
				c = tolower(c);
				if (c == ' '){
					k = 0;
					j++;
				}
				else{
					SampleText[j][k] = c;
					k++;
				}
				i++;
			}
			resolve = CheckValidity(SampleText, j);
			if (resolve == 1){
				solved = 1;
			}
			else{
				FixedSpaceTranslator(key, filec);
			}
			cases++;
			printf("\r%d/26", cases);
		}
		printf("\rComplete.");
		printf("\n");
		if(solved == 1){
			printf("File %d has been decrypted on a key of %d using Shift Cipher.\n",(filec-48), key);
			printf("You can view it using the command 'read %d'\n", (filec-48));
			printf("Press enter to continue...\n");
			getchar();
		}
		else{
			printf("File %d cannot be decrypted using Shift Cipher.\n",(filec-48));
			printf("Press enter to continue...\n");
			getchar();
		}
	}
	return;
}
