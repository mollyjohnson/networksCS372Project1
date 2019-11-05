#Programmer Name: Molly Johnson (johnsmol)
#Program Name: makefile 
#Program Description: makefile that will compile the .c file into an executable and
#add executable permissions to the python file
#Course Name: CS 372 Intro to Networks
#Last Modified: 11/04/19

#makefile adapted from  my own work during OSU CS 344 Winter 2019, last updated 3/3/19.
#make all be the default target, with the dependency of ChatApp
all: chatApp

#chatApp target with the dependency of chatclient.c and command to compile chatclient.c into
#the chatclient executable using gcc. Also includes the chmod +x command to add executable permissions
#to the chatserve file (which is a python file) so that this script can be executed with simply
#the command "./chatserve [PORTNUM] as indicated in the assignment instructions.
chatApp: chatclient.c
	gcc -Wall -g -o chatclient chatclient.c
	chmod +x chatserve

#if the user enters "make clean" or "make cleanall", remove the chatclient executable and
#remove the executable permissions from the chatserve python file.
clean:
	rm -f chatclient
	chmod -x chatserve

cleanall: 
	rm -f chatclient
	chmod -x chatserve
