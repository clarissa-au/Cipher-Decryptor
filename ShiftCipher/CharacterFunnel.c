/*
 * CharacterFunnel.c
 *
 *  Created on: 23 Mar 2018
 *      Author: sunnyau
 */

#include<stdio.h>
#define TEXTNUMBERS 5
#include"../main.h"
extern struct Ciphertext All_texts[TEXTNUMBERS];
extern int characterlist[26];
void CharacterFunnel(char textchar){
	for(int n=0;n<26;n++){
		characterlist[n] = 0;
	}
	int text,i=0;
	char c;
	text = (textchar-49);
	while(i<=All_texts[text].capacity){
		c=All_texts[text].ciphertext[i];
		switch(c){
			case'A':
			case'a':
				characterlist[0]++;
				break;
			case'B':
			case'b':
				characterlist[1]++;
				break;
			case'C':
			case'c':
				characterlist[2]++;
				break;
			case'D':
			case'd':
				characterlist[3]++;
				break;
			case'E':
			case'e':
				characterlist[4]++;
				break;
			case'F':
			case'f':
				characterlist[5]++;
				break;
			case'G':
			case'g':
				characterlist[6]++;
				break;
			case'H':
			case'h':
				characterlist[7]++;
				break;
			case'I':
			case'i':
				characterlist[8]++;
				break;
			case'J':
			case'j':
				characterlist[9]++;
				break;
			case'K':
			case'k':
				characterlist[10]++;
				break;
			case'L':
			case'l':
				characterlist[11]++;
				break;
			case'M':
			case'm':
				characterlist[12]++;
				break;
			case'N':
			case'n':
				characterlist[13]++;
				break;
			case'O':
			case'o':
				characterlist[14]++;
				break;
			case'P':
			case'p':
				characterlist[15]++;
				break;
			case'Q':
			case'q':
				characterlist[16]++;
				break;
			case'R':
			case'r':
				characterlist[17]++;
				break;
			case'S':
			case's':
				characterlist[18]++;
				break;
			case'T':
			case't':
				characterlist[19]++;
				break;
			case'U':
			case'u':
				characterlist[20]++;
				break;
			case'V':
			case'v':
				characterlist[21]++;
				break;
			case'W':
			case'w':
				characterlist[22]++;
				break;
			case'X':
			case'x':
				characterlist[23]++;
				break;
			case'Y':
			case'y':
				characterlist[24]++;
				break;
			case'Z':
			case'z':
				characterlist[25]++;
				break;
			default:
				break;
		}
		i++;
	}

	return;
}
