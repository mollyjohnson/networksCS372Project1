#Programmer Name: Molly Johnson (johnsmol)
#Program Name: ClientServerChat
#Program Description: ClientServerChat is my program for completing the requirements of the cs372 Project 1
#Assignment. This program works basically as a chat program between a server on one host (A) and a client on
#another host (B). A connection will be established between host A and host B, and the client
#and server can send messages back and forth to one another until the user (who is controlling
#both the client and server) requests to quit the program, at which point the connection will be closed.
#The server will then remain waiting on the port for any additional connections until a SIGINT is received.
#The name of the server portion of the program is chatserve and the name of the client portion of the program
#is chatclient. 
#Course Name: CS 372 Intro to Networks
#Last Modified: 11/03/19

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
