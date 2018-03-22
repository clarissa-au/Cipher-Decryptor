/*
 * FixedSpaceTranslator.c
 *
 *  Created on: 23 Mar 2018
 *      Author: sunnyau
 */

#include<stdio.h>
#include"../main.h"
#define TEXTNUMBERS 5
extern struct Ciphertext All_texts[TEXTNUMBERS];



void FixedSpaceTranslator(int key, char textchar){
	int text,i=0;
	char c;
	text = (textchar-49);
	while(i<=All_texts[text].capacity){
		c=All_texts[text].ciphertext[i];
		if(c>=65 && c<=90){
			if((c+key)>90){
				c=c-26+key;
			}
			else if((c+key)<65){
				c=c+26+key;
			}
			else{
				c=c+key;
			}
		}
		if(c>=97 && c<=122){
			if((c+key)<97){
				c=c+26+key;
			}
			else if((c+key)>122){
				c=c-26+key;
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
