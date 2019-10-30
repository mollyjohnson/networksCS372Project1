#!/usr/bin/env python3

#

#imported libraries
from socket import *
import sys

#pre-conditions:
#post-conditions:
#description:
def ArgCheck():
	#should be 2 args, one for program name and one for port number
	if len(sys.argv) != 2:
		print('Wrong number of arguments! Must enter a valid port number. Start the program again.')
		exit()
	else:
		#else if there's the right nuber of arguments, make sure the argument is a valid port number.
		#using isdigit() to check if a string represents a non-negative integer adapted from:
		#https://stackoverflow.com/questions/1265665/how-can-i-check-if-a-string-represents-an-int-without-using-try-except
		if sys.argv[1].isdigit() == False:
			print('You entered a negative integer or string for the port number! Must enter a valid port number. Start the program again.')
			exit()
		#if a non-neg integer was entered, check it's in valid port num range. valid port number range: 0-65535
		#valid port values excerpted from:
		#https://www.webopedia.com/quick_ref/portnumbers.asp
		elif int(sys.argv[1]) > 65535:
			print('You entered a port number above the valid port number range. Must enter a valid port number. Start the program again.')
			exit()

#pre-conditions:
#post-conditions:
#description:
def main():
	
	#check user entered correct port number argument
	ArgCheck()

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
	while True:
		connectionSocket, addr = serverSocket.accept()
		sentence = connectionSocket.recv(1024).decode()
		capitalizedSentence = sentence.upper()
		connectionSocket.send(capitalizedSentence.encode())
		connectionSocket.close()

#used to call the main function
#using a main() function in python adapted from:
#https://www.journaldev.com/17752/python-main-function
if __name__ == '__main__':	
	main()