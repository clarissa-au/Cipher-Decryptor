/*
 * Textlist.c
 *
 *  Created on: 6 Jan 2018
 *      Author: sunnyau
 */
#include<stdio.h>

#define TEXTNUMBERS 5

struct Ciphertext{
	int size;
	int capacity;
	char filename[20];
	char *ciphertext;
};
#define CIPHERTEXT_INIT_SPACE 100

typedef int bool;
#define true 1
#define false 0

extern struct Ciphertext All_texts[TEXTNUMBERS];
extern bool Textlist[TEXTNUMBERS];

/*
Txt  Str?   Filename
 1    T     example1.txt
 2    T     test.txt
 3    F
 4    F
 5    F
*/

void printTextlist(){
	printf("Txt  Str?   Filename\n");
	for(int i=0;i<TEXTNUMBERS;i++){
		printf(" ");
		printf("%d", i+1);
		printf("    ");
		if(Textlist[i]==true){ //true == not avaliable
			printf("T");
			printf("     ");
			printf("%s\n", All_texts[i].filename);
		}
		else{
			printf("F\n");
		}
	}
	return;
}

