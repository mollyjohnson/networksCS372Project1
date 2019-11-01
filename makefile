#

all: chatclient

chatclient: chatclient.c
	gcc -Wall -g -o chatclient chatclient.c

clean:
	rm -f chatclient

cleanall: 
	rm -f chatclient