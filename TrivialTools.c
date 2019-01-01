/*
 * TrivialTools.c
 *
 *  Created on: 30 Jan 2018
 *      Author: sunnyau
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define TEXTNUMBERS 5

struct args{
	char arg0[10];
	char arg1[10];
	char arg2[10];
	char arg3[10];
};

struct Ciphertext{
	int size;
	int capacity;
	char filename[20];
	char *ciphertext;
};

extern struct Ciphertext All_texts[TEXTNUMBERS];

struct args ArgsGet(){//returning args

	int i=0, args=0, inargs=0;

	struct args Args;

	char str[40];

	scanf("%[^\n]s", str);

	for(i = 0; i<strlen(str) ; i++){
		str[i] = tolower(str[i]);
	}

	for(i=0; i<strlen(str); i++){
		if(str[i]!=' '){
			if(args==0){
				Args.arg0[inargs]=str[i];
			}
			if(args==1){
				Args.arg1[inargs]=str[i];
			}
			if(args==2){
				Args.arg2[inargs]=str[i];
			}
			if(args==3){
				Args.arg3[inargs]=str[i];
			}
			inargs++;
		}
		else{
			inargs=0;
			args++;
		}
	}

	return Args; //returning args
}

void ClearScreen(){
	int i;
	for(i=0; i<100; i++){
		printf("\n");
	}
	return;
}

void Read(char filec[]){
	char file=filec[0];
	int fileint=file-49;
	int i;
	while((fileint > 4) || (fileint < 0)){
		printf("Invalid Input, please reenter your choice.\n");
		printf("File Number > ");
		scanf("%d", &fileint);
		fileint = fileint - 1;
	}
	printf("Reading text %d, with %d characters.\n", (fileint+1), All_texts[fileint].capacity);
	printf("----------\n");
	for(i=0;i<All_texts[fileint].capacity;i++){
		printf("%c", All_texts[fileint].ciphertext[i]);
	}
	printf("\n----------\n");
	printf("Press enter to continue...\n");
	getchar();
}

void Stat(char filec[]){
	char file=filec[0];
	int fileint=file-49;
	while((fileint > 4) || (fileint < 0)){
		printf("Invalid Input, please reenter your choice.\n");
		printf("File Number > ");
		scanf("%d", &fileint);
		fileint = fileint - 1;
	}
	printf("\n File %d\n---------- \n", (fileint+1));
	printf("Filesize: %d\n", All_texts[fileint].capacity);
	printf("Current Maximum Filesize: %d\n", All_texts[fileint].size);
	printf("Filename: %s\n",All_texts[fileint].filename);
	printf("\n");
	printf("Press enter to continue...\n");
	getchar();
}

int LargestElement26(int array[26]){
	int max=0;
	int result=0;
	for (int i=0; i<26;i++){
		if (array[i]>max){
			max=array[i];
		}
	}
	for(int i=0; i<26;i++){
		if (array[i]==max){
			result=i;
		}
	}
	return result;
}

void Swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void BubbleSort(int arr[], int n){
   int i;
   int j;
   for (i = 0; i < n-1; i++){
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1]){
              Swap(&arr[j], &arr[j+1]);
           }
       }
   }
}

int Element26(int basearray[26], int place){
	place --;
	int comparativearray[26];
	int result=0;
	for (int i=0; i<26;i++){
		comparativearray[i]=basearray[i];
	}
	BubbleSort(comparativearray, 26);
	for(int i=0; i<26;i++){
		if (basearray[i]==comparativearray[place]){
			result=i;
		}
	}
	return result;
}
