/*
 * main.c
 *
 *  Created on: 6 Dec 2017
 *      Author: sunnyau
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"TrivialTool/ArraytoLowerCase.h"
#include"TrivialTool/ClearScreen.h"
#include"ProgramHelp.h"
#include"ShiftCipherDecryptor.h"
#include"ImportFile.h"

typedef int bool;
#define true 1
#define false 0

int main ()
{
	bool exit=false;
	char choice[10], arg1[10], arg2[10], arg3[10], cont;
	char *texta;
	char *textb;
	char *textc;
	char *textd;
	char *texte;	//data link still not finished
	char key[100];
	while(exit==false){
		ClearScreen();

		printf("    ---------------------------------\n");
		printf("     Cipher Decryptor Tool           \n");
		printf("     Version:0.1.0                   \n");
		printf("     Made by Clarissa Au             \n");
		printf("     As a part of the ICT SBA Project\n");
		printf("     --------------------------------\n");

		//scanf("%s %s %s %s", &choice, &arg1, &arg2, &arg3);   here!!
		choice=tolower("choice"); //string compare tool
		//arg1=tolower("arg1");
		//arg2=tolower("arg2");
		//arg3=tolower("arg3");
		if(choice=="shc"){
			arg1=tolower("arg1");
			if(arg1=="-d"){
				ShiftCipherDecoder();
			}
			else if(arg1=="-e"){
				ShiftCipherEncoder();
			}
			else if(arg1=="-rotn"){
				RotationN();
			}
			else{
				printf("Correct Usage: shc -d/-e/-rotn [arguments...]\n");
				printf("Please use 'help' for more details.\n");
				printf("Press key to continue, or press X to quit...\n");
				PastAction("Error. Please use 'help' for more details.");
				cont=getchar();
				if (cont=="x"||cont=="X"){
					exit=true;
				}
			}
		}
		if(choice=="import"){
			ImportFile(arg1, arg2);
		}
		if(choice=="help"){
			ProgramHelp();
		}
	}
	free(texta);
	free(textb);
	free(textc);
	free(textd);
	free(texte);
	return 0;
}
