/*
 * ShiftCipherEncoder.c
 *
 *  Created on: 6 Jan 2018
 *      Author: sunnyau
 */
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"main.h"

#include"CiphertextFunctions.h"
#include"ShiftCipher/FixedSpaceTranslator.h"

#define TEXTNUMBERS 5

void ShiftCipherEncoder(char file[], struct Ciphertext Ciphertext[]){
	int key=0, flag0=0;
	srand(time(0));
	char filec;

	printf("Please enter a key for Shift Cipher Encryption.\n");
	printf("For a random key, please input 0.\n");
	printf("Key > ");
	scanf("%d", &key);


	if(key==0){
		key = rand() % 26; //TODO RANDOM
		printf("The random key used for the encryption is: %d\n", key);
	}

	if(key%26==0){
		flag0=1;
	}

	while(flag0==1){
		printf("Your input will result in a direct transcription!\n");
		printf("If you want to continue, enter 0.\n");
		printf("Otherwise, enter the new key you wish to use.\n");
		printf("Key > ");
		scanf("%d", &key);

		if(key%26==0){
			if(key==0){
				flag0=0;
			}
			else{
				flag0=1;
			}
		}
		else{
			flag0=0;
		}
	}


	if(key>25){
		key = key%26;
		printf("The augmented key used for the encryption is: %d\n", key);
	}
	if(key<0){
		key = (key%26)*-1;
		printf("The augmented key used for the encryption is: %d\n", key);
	}

	filec=file[0];

	while((filec-49)<0||(filec-49)>TEXTNUMBERS){
		char c;
		while ((c = getchar()) != '\n' && c != EOF) { }
		printf("You have entered an invalid text reference number.\n");
		printf("Please reenter the text reference number.\n");
		printf("Text Reference Number > ");
		scanf("%c", &filec);
	}


	FixedSpaceTranslator(key, filec);

	printf("File %d has been encrypted using Shift Cipher on a key of %d.\n",(filec-48), key );
	printf("You can view it using the command 'read %d'\n", (filec-48));
	printf("Press enter to continue...\n");

	getchar();


	//START OF DEBUG TASK
	//int k;
	//for(k=0;k<All_texts[(filec-49)].capacity;k++){
	//	printf("%c",All_texts[(filec-49)].ciphertext[k]);
	//}
	//END OF TASK, CURRENT DEBUG


	return;
}

