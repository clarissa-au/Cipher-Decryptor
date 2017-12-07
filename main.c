/*
 * main.c
 *
 *  Created on: 6 Dec 2017
 *      Author: sunnyau
 */

#include<stdio.h>
#include<stdlib.h>
#include"printArray.h"
#include"ProgramHelp.h"
#include"ShiftCipherDecryptor.h"
#include"ImportFile.h"

typedef int bool;
#define true 1
#define false 0

const char startup[6][50] = {
		{"     --------------------------------"},
		{"     Cipher Decryptor Tool           "},
		{"     Version:0.1.0                   "},
		{"     Made by Clarissa Au             "},
		{"     As a part of the ICT SBA Project"},
		{"     --------------------------------"}
};

int main ()
{
	bool exit=false;
	char choice[10], arg1[10], arg2[10], arg3[10], cont;
	while(exit==false){
		system("cls");
		printArray(startup, 6);
		scanf("%s %s %s %s", &choice, &arg1, &arg2, &arg3);
		if(choice=="shc"){
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
			ImportFile();
		}
		if(choice=="help"){
			ProgramHelp();
		}
	}
}
