#!/usr/bin/env python3

#

from socket import *
import sys

serverPort = int(sys.argv[1]) 
print('my arg entered is: ')
print(serverPort)
print('\n')
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('', serverPort))
serverSocket.listen(1)
print('The server is ready to receive')
while(1):
	connectionSocket, addr = serverSocket.accept()
	sentence = connectionSocket.recv(1024)
	capitalizedSentence = sentence.upper()
	connectionSocket.send(capitalizedSentence)
	connectionSocket.close()
