/*
 * main.c
 *
 *  Created on: 6 Dec 2017
 *      Author: sunnyau
 */

#include<stdio.h>

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
	char choice[10];
	while(exit==false){
		get(choice);
		if(choice=="shc"){

		}
		if(choice=="help"){
			help();
		}
	}
}

