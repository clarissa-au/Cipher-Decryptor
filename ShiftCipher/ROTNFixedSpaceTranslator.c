/*
 * ROTNFixedSpaceTranslator.c
 *
 *  Created on: 7 Jun 2018
 *      Author: sunnyau
 */

#include<stdio.h>
#include"../main.h"
#define TEXTNUMBERS 5
extern struct Ciphertext All_texts[TEXTNUMBERS];



void ROTNFixedSpaceTranslator(int key, int text, int type){
	int upperbound = 0, lowerbound = 0, difference = 0;
	if (type == 10){
		upperbound = 57;
		lowerbound = 48;
		difference = 10;
	}
	if (type == 94){
		upperbound = 126;
		lowerbound = 33;
		difference = 94;
	}
	int i = 0;
	char c;
	while(i <= All_texts[text].capacity){
		c = All_texts[text].ciphertext[i];
		if(c>=lowerbound && c<=upperbound){
			if((c+key)>upperbound){
				c=c-difference+key;
			}
			else if((c+key)<lowerbound){
				c=c+difference+key;
			}
			else{
				c=c+key;
			}
		}
		All_texts[text].ciphertext[i]=c;
		i++;
	}
	return;
}

