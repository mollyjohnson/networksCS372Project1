all: ChatClient

ChatClient: chatclient.c
	gcc -Wall -g -o ChatClient chatclient.c

clean:
	rm -f ChatClient

cleanall: 
	rm -f ChatClient