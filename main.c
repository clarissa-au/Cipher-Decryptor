/*
 * main.c
 *
 *  Created on: 6 Dec 2017
 *      Author: sunnyau
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"main.h"

#include"TrivialTool/ClearScreen.h"
#include"TrivialTool/ArgsGet.h"

#include"ProgramHelp.h"
#include"Textlist.h"
#include"ShiftCipherDecryptor.h"
#include"ImportFile.h"
#include"PastAction.h"
#include"CiphertextFunctions.h"

#include"ShiftCipherDecryptor.h"
#include"ShiftCipherEncoder.h"
#include"RotationN.h"

typedef int bool;
#define true 1
#define false 0

struct args{
	char arg0[10];
	char arg1[10];
	char arg2[10];
	char arg3[10];
};

#define PASTACTIONSTORED 5
#define ACTIONLENGTH 50
char PastActionArray[PASTACTIONSTORED][ACTIONLENGTH]; //global char array
int ActionCount=0;

#define CIPHERTEXT_INIT_SPACE 100

#define TEXTNUMBERS 5

struct Ciphertext All_texts[TEXTNUMBERS];

bool Textlist[TEXTNUMBERS];

int main ()
{
	bool exit=false;
	char cont=' ';

	char key[100];

	struct args Input;

	for(int i=0; i<TEXTNUMBERS; i++){
		Textlist[i]=false;
	}

	while(exit==false){

		ClearScreen();

		printf("    +---------------------------------+\n");
		printf("    | Cipher Decryptor Tool           |\n");
		printf("    | Version:0.1.0                   |\n");
		printf("    | Made by Clarissa Au             |\n");
		printf("    | As a part of the ICT SBA Project|\n");
		printf("    +---------------------------------+\n");

		PrintPastAction();
		printTextlist();

		Input = ArgsGet(); //getting args for prg

		if(strncmp( Input.arg0 ,"shc", 4)==0){
			if(strncmp( Input.arg1 ,"-d", 3)==0){
				ShiftCipherDecoder(Input.arg2);
			}
			else if(strncmp( Input.arg1 ,"-e", 3)==0){
				ShiftCipherEncoder(Input.arg2);
			}
			else if(strncmp( Input.arg1 ,"-rotn", 3)==0){
				RotationN(Input.arg2);
			}
			else{
				printf("Correct Usage: shc -d/-e/-rotn [arguments...]\n");
				printf("Please use 'help' for more details.\n");
				printf("Press key to continue, or press X to quit...\n");
				PastAction("Error. Please use 'help' for more details.");
				cont=getchar();
				if (cont=='x'||cont=='X'){
					exit=true;
				}
			}
		}

		if(strncmp( Input.arg0 ,"import", 7)==0){
			int txtnum;
			bool found;
			for(int i=0; i<TEXTNUMBERS; i++){
				if(Textlist[i]==true){
					found=true;
					txtnum=i;
				}
			}
			if(found == false){
				printf("No blank file slots found. Which file slot do you wish to overwrite?");
				scanf("%d", &txtnum);
				resetText(&All_texts[txtnum]);
			}
			ImportFile(Input.arg1, txtnum, All_texts);
		}

		if(strncmp( Input.arg0 ,"help", 5)==0){
			ProgramHelp();
		}

		if(strncmp( Input.arg0 ,"clrhistory", 11)==0){
			ClearPastActions();
		}

	}

	return 0;

}
