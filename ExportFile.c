/*
 * ExportFile.c
 *
 *  Created on: 7 Jun 2018
 *      Author: sunnyau
 */

#include<stdio.h>
#include<string.h>

struct Ciphertext{
	int size;
	int capacity;
	char filename[20];
	char *ciphertext;
};

void ExportFile(char file[], struct Ciphertext text[]){
	char filec=file[0];
	int x = filec-49;
	while((x > 4) || (x < 0)){
		printf("Invalid Input, please reenter your choice.\n");
		printf("File Number > ");
		scanf("%d", &x);
		x = x - 1;
	}
	char filename[35];

	printf("Please enter the name of the exported file:\n");
	printf("Name > ");
	scanf("%30s", filename);

	FILE *exportfilept;

	exportfilept = fopen(filename, "w");
	strcat(filename, ".txt");
	printf("The file at slot %d would be exported to %s.\n",(x+1) , filename);

	for(int i=0;i<text[x].capacity;i++){
		fputc(text[x].ciphertext[i], exportfilept);
	}

	fclose(exportfilept);

	printf("File successfully exported.\n");
	printf("Press enter to continue...\n");

	getchar();
	return;
}
