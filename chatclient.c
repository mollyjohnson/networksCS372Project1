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
#define HOST_ADDRESS "flip1.engr.oregonstate.edu"

/*
pre-conditions:
post-conditions:
description:
*/
bool StringMatch(char *string1, char *string2){
	//use strcmp to see if string one and two are equal. if equal, strcmp will return 0.
	//strcmp will return non-zero if the two strings are not equal.
	if(strcmp(string1, string2) == 0){
		//if the two strings are a match, return true
		return true;
	}
	//if the two strings are not a match, return false
	return false;
}

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
void ArgCheck(int argCount, char *args[])
{
    if (argCount != 3){
        fprintf(stderr, "Wrong number of arguments! Must enter the correct hostname and a valid port number. Start the program again.\n");
        fflush(stdout); exit(1);    
    }
	//using atoi to convert from string to int adapted from:
	//https://www.quora.com/How-do-I-convert-character-value-to-integer-value-in-c-language
	if ((!IntInputValidation(args[2])) || (atoi(args[2]) < 0 ) || (atoi(args[2]) > 65535)){
		fprintf(stderr, "You entered a negative number, string or otherwise invalid port number argument. Start the program again.\n");
       	fflush(stdout); exit(1);    
	}
	if (!StringMatch(args[1], HOST_ADDRESS)){
		fprintf(stderr, "Your host argument doesn't match the server host. Start the program again and use flip1.engr.oregonstate.edu as your host.\n");
       	fflush(stdout); exit(1);    
	}
}

/*
pre-conditions:
post-conditions:
description:
*/
int main(int argc, char *argv[]){
    ArgCheck(argc, argv);

	int portNum = atoi(argv[2]);
	char *hostAddress = argv[1];

    return 0;
}