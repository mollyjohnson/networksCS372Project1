#

all: chatApp

chatApp: chatclient.c
	gcc -Wall -g -o chatclient chatclient.c
	chmod +x chatserve

clean:
	rm -f chatclient
	chmod -x chatserve

cleanall: 
	rm -f chatclient
	chmod -x chatserve
