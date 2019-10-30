/*

*/

//include other header files
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <stdbool.h>

//macro definitions
#define MAX_MESSAGE_SIZE 501

/*
pre-conditions:
post-conditions:
description:
*/  
bool IntInputValidation(char *inputString){
//create variables for char to be checked, loop counter, and length of the input string
	char asciiValue;
	int inputLength = strlen(inputString);
	int i;

	//loop through entire string so can check each char
	for(i = 0; i < inputLength; i++){
		//set temp char equal to the current string char
		asciiValue = inputString[i];

		//check if the current char is within the valid ascii values for ints 0-9 (i.e. ascii values 48-57)
		if((asciiValue < 48) || (asciiValue > 57)){
			//if ascii value of char being checked is outside of the range for integers, return false
			return false;
		}
	}
	//if all of the chars in the string to be checked were valid integers, return true
	return true;
}


/*
pre-conditions:
post-conditions:
description:
*/  
bool CharInputValidation(char *inputString){
    //create variables for char to be checked, and length of the input string
	char asciiValue;
	int k;
	int stringLength = strlen(inputString);

	//check each char of the string to see if matches one of the valid chars
	for(k = 0; k < stringLength; k++)
	{
		//check if the current char is within the valid ascii values for uppercase letters (ascii 65-90) or is a space char
		//(also valid for this assignment per the instructions)
		asciiValue = inputString[k];
		//if current char is outside of ascii range for uppercase letters AND is not a space char, return false
		if((asciiValue < 65 || asciiValue > 90) && (asciiValue != 32)){
			return true;
		}
	}
	//if all chars in the string were valid uppercase letters or space chars, return true
	return false;
}


/*
pre-conditions:
post-conditions:
description:
*/
void ArgCheck(int argCount, char *args[])
{
    if (argCount != 3){
        fprintf(stderr, "Wrong number of arguments! Must enter the correct hostname and a valid port number. Start the program again.\n");
        fflush(stdout); exit(1);    
    }
    else{
        printf("you're in argcheck w right num of args\n");
    }
}

/*
pre-conditions:
post-conditions:
description:
*/
int main(int argc, char *argv[]){
    ArgCheck(argc, argv);

    return 0;
}