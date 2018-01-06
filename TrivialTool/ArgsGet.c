/*
 * ArgsGet.c
 *
 *  Created on: 26 Dec 2017
 *      Author: sunnyau
 */

#include<stdio.h>
#include<string.h>

struct args{
	char arg0[10];
	char arg1[10];
	char arg2[10];
	char arg3[10];
};

struct args ArgsGet(){//returning args

	int i=0, args=0, inargs=0;

	int chars;

	struct args Args;

	char str[40];

	scanf("%[^\n]s", str);

	for(i = 0; i<strlen(str) ; i++){
		str[i] = tolower(str[i]);
	}

	for(i=0; i<strlen(str); i++){
		if(str[i]!=32){
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
		}
		else{
			inargs=0;
			args++;
		}
	}

	return Args; //returning args
}
