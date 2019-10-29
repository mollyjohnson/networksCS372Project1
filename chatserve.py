#!/usr/bin/env python3

#

#imported libraries
from socket import *
import sys

#convert system arg 1 (string) to an int for the server port number
#getting command line arguments using sys library and argv adapted from:
#https://stackoverflow.com/questions/4033723/how-do-i-access-command-line-arguments-in-python
#converting a string to an int adapted from:
#https://www.digitalocean.com/community/tutorials/how-to-convert-data-types-in-python-3
serverPort = int(sys.argv[1]) 
print('server port entered is: ' + str(serverPort))

#specify host address to a flip server
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
