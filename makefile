#

all: chatclient

chatclient: chatclient.c
	#gcc -std=c11 -Wall -g -o chatclient chatclient.c
	gcc -Wall -g -o chatclient chatclient.c
clean:
	rm -f chatclient

cleanall: 
	rm -f chatclient