typedef int bool;
#define true 1
#define false 0

void ProgramHelp(){
	bool exit;
	char cont, choice;
	while(exit==true){
		system("cls");
		printf("Cipher-Decryptor Main Help:\n");
		printf("Usage: [encoding] [arguments.....]\n");
		printf("For a list of updated encodings and arguments, please consult the documentation of the Program.\n");
		printf("Link: https://github.com/clarissa-au/Cipher-Decryptor/wiki \n");
		printf("Or you can alternatively use the search below:\n");
		printf("Please input the corresponding character to your query:\n");
		printf("e: Encodings & associated arguments\n");
		printf("i: Import\n");
		printf("x: Export\n");
		choice=getchar();
		switch(choice){
		case 'e' :
			//Encodings & associated arguments
			break;
		case 'i' :
			//import
			break;
		case 'x' :
			//export
			break;
		default:
			//error again
		}
		printf("Press key to continue searching for help, or press X to return to program...\n");
		if (cont=="x"||cont=="X"){
			exit=false;
		}
	}
	PastAction("Help shown.");
	return;
}
