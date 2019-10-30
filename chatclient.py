#!/usr/bin/env python3

#

#imported libraries
from socket import *
import sys

serverPort = 34000
hostAddress = 'flip1.engr.oregonstate.edu'
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((hostAddress, serverPort))
sentence = input('Input lowercase sentence:')
clientSocket.send(sentence.encode())
modifiedSentence = clientSocket.recv(1024)
print('From Server: ', modifiedSentence.decode())
clientSocket.close()