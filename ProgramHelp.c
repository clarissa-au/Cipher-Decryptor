#include"TrivialTool/ClearScreen.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#include"PastAction.h"

typedef int bool;
#define true 1
#define false 0

void ProgramHelp(){
	bool exit=true;
	char cont=' ', choice=' ', choice2=' ';
	char c;
	while(exit==true){
		while ((c = getchar()) != '\n' && c != EOF) { }
		ClearScreen();
		printf("Cipher-Decryptor Main Help:\n");
		printf("Usage: [encoding] [arguments.....]\n");
		printf("For a list of updated encodings and arguments, please consult the documentation of the Program.\n");
		printf("Link: https://github.com/clarissa-au/Cipher-Decryptor/wiki \n");
		printf("Or you can alternatively use the search below:\n");
		printf("Please input the corresponding character to your query:\n");
		printf("[E]ncodings & associated arguments\n");
		printf("[I]mport\n");
		printf("E[x]port\n");

		choice = getchar();

		choice=tolower(choice);
		switch(choice){
		case 'e' :
			while ((c = getchar()) != '\n' && c != EOF) { }
			printf("View help for:");
			printf("[S]hift Cipher(shc)\n");
			choice2=getchar();
			choice2=tolower(choice2);
			switch(choice2){
			case 's':
				//shift cipher
				break;
			default:
				printf("Error Input.\n");
			}
			break;
		case 'i' :
			while ((c = getchar()) != '\n' && c != EOF) { }
			//import
			break;
		case 'x' :
			while ((c = getchar()) != '\n' && c != EOF) { }
			//export
			break;
		default:
			while ((c = getchar()) != '\n' && c != EOF) { }
			printf("Error Input.\n");
		}
		printf("Press key to continue searching for help, or press X to return to program...\n");
		cont=getchar();
		if (cont=='x'||cont=='X'){
			exit=false;
		}
	}
	PastAction("Help shown.");
	return;
}
