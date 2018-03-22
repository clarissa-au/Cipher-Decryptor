/*
 * FixedSpaceTranslator.c
 *
 *  Created on: 23 Mar 2018
 *      Author: sunnyau
 */

#include"../main.h"
#define TEXTNUMBERS 5
extern struct Ciphertext All_texts[TEXTNUMBERS];



void FixedSpaceTranslator(int key, char textchar){
	int text,i=0;
	text = (textchar-49);
	while(i<=All_texts[text].capacity){
		if(All_texts[text].ciphertext[i]>=65 && All_texts[text].ciphertext[i]<=90){
			All_texts[text].ciphertext[i]=All_texts[text].ciphertext[i]+key;
			if(All_texts[text].ciphertext[i]>90){
				All_texts[text].ciphertext[i]=All_texts[text].ciphertext[i]-26;
			}
		}
		if(All_texts[text].ciphertext[i]>=97 && All_texts[text].ciphertext[i]<=122){
			All_texts[text].ciphertext[i]=All_texts[text].ciphertext[i]+key;
			if(All_texts[text].ciphertext[i]>122){
				All_texts[text].ciphertext[i]=All_texts[text].ciphertext[i]-26;
			}
		}
		i++;
	}
	return;
}
