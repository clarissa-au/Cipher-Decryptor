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

#include"TrivialTools.h"
#include"PastAction.h"

#include"ImportFile.h"
#include"ExportFile.h"

#include"ProgramHelp.h"
#include"Textlist.h"

#include"ShiftCipherDecryptor.h"
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

	char c;

	int key[100];

	struct args Input;

	for(int i=0; i<TEXTNUMBERS; i++){
		Textlist[i]=false; //true == not avaliable, or used.
	}

	while(exit==false){

		for(int i=0;i<10; i++){ Input.arg0[i] = ' ';}
		for(int i=0;i<10; i++){ Input.arg1[i] = ' ';}
		for(int i=0;i<10; i++){ Input.arg2[i] = ' ';}
		for(int i=0;i<10; i++){ Input.arg3[i] = ' ';}

		ClearScreen();

		printf("    +---------------------------------+\n");
		printf("    | Cipher Decryptor Tool           |\n");
		printf("    | Version:0.1.0                   |\n");
		printf("    | Made by Clarissa Au             |\n");
		printf("    | As a part of the ICT SBA Project|\n");
		printf("    +---------------------------------+\n");

		printf("\n");
		printf("\n");
		PrintPastAction();
		printf("\n");
		printf("\n");
		printTextlist();

		Input = ArgsGet(); //getting args for prg

		if(strncmp( Input.arg0 ,"shc", 3)==0){
			bool istext=false;
			for(int i=0; i<TEXTNUMBERS; i++){
				if(Textlist[i]==true){
					istext=true;
				}
			}
			if(istext==true){
				if(strncmp( Input.arg1 ,"-d", 2)==0){
					ShiftCipherDecoder(Input.arg2);
					PastAction("Decoded Shift Cipher.");
				}
				else if(strncmp( Input.arg1 ,"-e", 2)==0){
					ShiftCipherEncoder(Input.arg2, All_texts);
					PastAction("Encoded Shift Cipher.");
				}
				else if(strncmp( Input.arg1 ,"-rotn", 5)==0){
					printf("ROTN Ciphers are as secure as Shift Ciphers.\n");
					printf("Use with caution.\n");
					int type , chosen = 0;
					while(chosen == 0){
						//type 1 = ROT5
						//type 2 = ROT13
						//type 3 = ROT47
						if(strncmp( Input.arg3 ,"-5", 2)==0){
							chosen = 1;
							type = 1;
						}
						if(strncmp( Input.arg3 ,"-13", 3)==0){
							chosen = 1;
							type = 2;
						}
						if(strncmp( Input.arg3 ,"-47", 3)==0){
							chosen = 1;
							type = 3;
						}
						if(chosen == 0){
							printf("You have entered an invalid ROT encryption argument.\n");
							printf("Please reenter the specific argument for ROT encryption.\n");
							printf("Valid argument: -5 / -13 / -47 \n");
							printf("ROT encryption argument > ");
							scanf("%10s", Input.arg3);
						}
					}
					RotationN(Input.arg2, type);
					PastAction("Encoded/Decoded Shift Cipher of the ROTN variant.");
				}
				else{
					printf("Correct Usage: shc -d/-e/-rotn [arguments...]\n");
					printf("Please use 'help' for more details.\n");
					printf("Press enter to continue, or press X and enter to quit...\n");
					PastAction("Error. Please use 'help' for more details.");
					cont=getchar();
					if (cont=='x'||cont=='X'){
						exit=true;
					}
				}
			}
			else{
				printf("Please import a file before you proceed.\n");
				PastAction("Error. Please import file.");
				printf("Press enter to continue, or press X and enter to quit...\n");
				cont=getchar();
				if (cont=='x'||cont=='X'){
					exit=true;
				}
			}
		}

		else if(strncmp( Input.arg0 ,"import", 6)==0){
			int txtnum;
			char filename[15];
			bool found = false;
			for(int i=0; i<TEXTNUMBERS; i++){
				if(Textlist[i]==false){
					found=true;
					Textlist[i]=true;
					txtnum=i;
					break;
				}
			}
			if(found == false){
				printf("No blank file slots found. Which file slot do you wish to overwrite?\n");
				printf("Slot > ");
				scanf("%d", &txtnum);
				txtnum--;
				Textlist[txtnum]=false;
				resetText(&All_texts[txtnum]);
			}
			printf("Please enter a valid text file path:\n");
			printf("Path > ");
			scanf("%15s", filename);
			initText(&All_texts[txtnum]);
			int flag_successful;
			flag_successful = ImportFile(filename, txtnum, All_texts);
			if(flag_successful == 1){
				Textlist[txtnum] = false;
			}
		}

		else if(strncmp( Input.arg0 ,"export", 6)==0){
			ExportFile(Input.arg1, All_texts);
			PastAction("File exported.");
		}

		else if(strncmp( Input.arg0 ,"help", 4)==0){
			ProgramHelp();
		}

		else if(strncmp( Input.arg0 ,"clrhistory", 10)==0){
			ClearPastActions();
		}

		else if(strncmp( Input.arg0 ,"read", 4)==0){
			Read(Input.arg1);
			PastAction("File read.");
		}

		else if(strncmp( Input.arg0 ,"stat", 4)==0){
			Stat(Input.arg1);
			PastAction("File information read.");
		}

		else{
			printf("Correct Usage: shc / import / help / clrhistory / read / stat\n");
			printf("Please use 'help' for more details.\n");
			printf("Press enter to continue, or press X and enter to quit...\n");
			PastAction("Error. Please use 'help' for more details.");

			cont = getchar();
			if (cont=='x'||cont=='X'){
				exit=true;
			}
		}

		while ((c = getchar()) != '\n' && c != EOF) { }

	}

	return 0;

}
