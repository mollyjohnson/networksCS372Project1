#!/usr/bin/env python3

#

#imported libraries
from socket import *
import sys

#using command line arguments using sys library and argv adapted from:
#https://stackoverflow.com/questions/4033723/how-do-i-access-command-line-arguments-in-python
serverPort = int(sys.argv[1]) 
print('my arg entered is: ' + str(serverPort))
hostAddress = 'flip1.engr.oregonstate.edu'
#basic socket server setup adapted from OSU CS 372 lecture 15 slides
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind((hostAddress, serverPort))
serverSocket.listen(1)
print('The server is ready to receive')
while(1):
	connectionSocket, addr = serverSocket.accept()
	sentence = connectionSocket.recv(1024)
	capitalizedSentence = sentence.upper()
	connectionSocket.send(capitalizedSentence)
	connectionSocket.close()
