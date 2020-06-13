Programmer Name: Molly Johnson (johnsmol)
Program Name: README.txt
Program Description: README.txt that will describe to the user how to compile, execute,
and control the programs. 
Course Name: CS 372 Intro to Networks
Last Modified: 11/04/19

Instructions for how to compile, execute, and control the program:
Log onto the Oregon State flip1 server terminal (flip1.engr.oregonstate.edu) using an SSH client like Putty.
In a separate window, log onto the Oregon State flip2 or flip3 terminal (either one, just so long as it's different
from the flip1 server as the chatserver will be on flip1 and thus the chatclient must be on a different flip, so either
flip2 or flip3). Use flip2.engr.oregonstate.edu for flip2 or flip3.engr.oregonstate.edu for flip3. Copy all of my program's
files into some folder on the Oregon State server (README.txt, makefile, chatclient.c, and chatserve). Note: the chatserve
file is a python file, even though it doesn't have the .py file extension, the shebang at the top of the chatserve file
will make sure the script is run with python3. Now that all 4 files are in some folder on the OSU server (AND you're in that directory),
type "make" (minus the quotes), and this will compile the chatclient.c file into an executable file just called chatclient. The
makefile will also instruct the python file (chatserve) to have its permissions modified so the file can be executable (through a 
chmod +x command in the makefile ). You should now see two files, chatclient and chatserve, each with execution permissions. Now, you
are ready to start the chat application. In the window for flip1, type "./chatserve [PORTNUM]", minus the quotes and  where PORTNUM
is some valid port number within the valid port number range that's not currently being used by someone else. The valid range 
for port numbers is 0-65535, but it's recommended to choose some number that's not a well-known port number, so maybe some number
in the range of 30000-65535. This will start chatserve on the host (flip1.engr.oregonstate.edu) on the specified port so it's
waiting for a connection. Now go to the other window (which should be on either flip2 or flip3, whichever you chose). Make sure you're
in the directory containing all of the program files. Type "./chatclient [HOSTNAME] [PORTNUM]", minus the quotes, where HOSTNAME is
the hostname used by chatserve (so here the hostname should be flip1.engr.oregonstate.edu) and PORTNUM is the same port number you
used when executing the chatserve program. At this point, in the chatclient window (so on flip2 or flip3, whichever you chose), you should
now be prompted to enter your desired user handle (the handle for the server has been hard-coded, as this was listed as an acceptable
option in the assignment instructions). Enter your client user handle and press enter. The chatclient program should then show your
handle and an arrow, a space, and then wait for your input. So it would look something like "[chatclientHandle]> ". Enter your first
message in the chatclient window here that you want to send to the server and press enter. This will establish the connection between
chatserve and chatclient. Now go to the chatserve window (flip1). You should see the prepended handle and the client's message printed
there, and on the next line you should see the hard-coded chatserve handle, an arrow, and a space, with the chatserve program now waiting
for your input. Enter the message you want to send back to the client from the server and press enter. Now go back to the chatclient window
(flip2 or flip3 whichever you chose). There, you should see the message sent by the server printed along with their prepended user handle,
and chatclient will be again waiting for your input to send to the server. You can continue sending messages back and forth in this way
in an alternating fashion, chatclient-chatserve-chatclient-chatserve-chatclient-chatserve for as long as you wish. Once you're done
messaging and are ready to close the connection between this client and the server, just type "\quit" (minus the quotes) as your message
on either the chatserve or chatclient windows. \quit will end the client connection regardless of whether you enter this \quit message
in the chatserve or chatclient windows. At that point, the connection with that chatclient and the chatserve will close, and the chatclient
program will end. The chatserve program, however, will continue running and waiting on its host and portnumber specified, waiting for
additional connections. If you want to establish another connection, repeat the execution of the chatclient program, using 
"./chatclient [HOSTNAME] [PORTNUM]", again where HOSTNAME is the host used for the server (flip1.engr.oregonstate.edu in this case) and
PORTNUM is whatever port number you used when executing chatserve. You can then enter your new handle in the chatclient window just
as before, send an initial message from there to the server, and then send messages back and forth in an alternating fashion
chatclient-chatserve-chatclient-chatserve for as long as you wish, again sending the message "\quit" whenever you want to close the
connection. You can do this entire sequence again for as many chatclients as you wish, as each time a chatclient connection is closed,
chatserve will continue to wait on the host and port number specified for additional connections. When you're completely done and ready
to terminate the chatserve program as well, just give it a SIGINT signal (press Ctrl-c), as this will terminate the chatserve program.

-----------------------------------------------------------------------------------------------------------------------------------

CS 372 Introduction to Computer Networks
Programming Assignment #1
Due Sunday, end of Week 5, by 11:59pm
Submit the source files, Makefile, and README in a .zip file to Canvas.
Objectives:
1. Implement a client-server network application
2. Learn to use the sockets API
3. Use the TCP protocol
4. Refresh programming skills
The Program:
Design and implement a simple chat system that works for one pair of users, i.e., create two programs: a chat server and a chat client. The final version of your programs must accomplish the following tasks:
1. chatserve starts on host A.
2. chatserve on host A waits on a port (specified by command-line) for a client request.
3. chatclient starts on host B, specifying host A’s hostname and port number on the command line.
4. chatclient on host B gets the user’s “handle” by initial query (a one-word name, up to 10 characters). chatclient will display this handle as a prompt on host B, and will prepend it to all messages sent to host A. e.g., “ SteveO> Hi!!”
5. chatclient on host B sends an initial message to chatserve on host A : PORTNUM. This causes a connection to be established between Host A and Host B. Host A and host B are now peers, and may alternate sending and receiving messages. Responses from host A should have host A’s “handle” prepended.
6. Host A responds to Host B, or closes the connection with the command “\quit”
7. Host B responds to Host A, or closes the connection with the command “\quit”
8. If the connection is not closed, repeat from 6.
9. If the connection is closed, chatserve repeats from 2 (until a SIGINT is received).
Requirements:
• chatserve must be implemented in Java or Python
• chatclient must be implemented in C/C++.
• Of course, your program must be well-modularized and well-documented.
• Your programs must run on an OSU flip server (for example: flip1.engr.oregonstate.edu). Specify your testing machine in the program documentation.
• Your programs should be able to send messages of up to 500 characters.
• Use the directories in which the programs are running. Don't hard-code any directories, since they might be inaccessible to the graders.
• Be sure to cite any references, and credit any collaborators.
• Provide a README.txt with detailed instructions on how to compile, execute, and control your program.
• Combine all program files into one *.zip archive (no .7z or .gz allowed). The .zip file should not contain any folders – only files!
page 2 of 2
Notes:
• For your C implementation, read Beej's Guide. It has everything you need for this assignment. You will probably learn the most about socket programming by using C.
• If you are using Python, check http://docs.python.org/release/2.6.5/library/internet.html,
• If you are using Java, check http://docs.oracle.com/javase/tutorial/networking/sockets/index.html.
• It’s OK to hard-code host A’s handle.
• It’s OK to implement this system so that it requires the two users to take turns sending messages, i.e., when a user sends a message, s/he must wait for a response before sending the next message.
• When debugging, don't use the well-known port numbers, because these will already be in use. I’d suggest using 30020 or 30021, though other students may be using these when you’re on the servers.
• If you use additional include-files or make-files, be sure to include them in your .zip file.
• You can test these programs using just one computer. Start the server, then start the client in a new window. You can then switch back and forth between the two terminal windows.
• Project #1 will be accepted up to one week late with a penalty of up to 10% per day.
Extras:
• If you implement extra credit features, be sure to describe those features in your program documentation and README.txt or you will not receive any credit.
• There are many possibilities for extra credit. Be sure that your program satisfies the requirements first, and then do the extra credit in separate files.
• Extra credit possibilities include (but are not limited to) …
- Set up your programs so that either host can make first contact.
- Make it possible for either host to send at any time (while the connection is active) without “taking turns”.
- Make your server multi-threaded.
- Split the screen to show host B’s typing in one panel, and host A’s responses in the other panel.
- Make the characters appear on the receiving host as they are being typed on the sending host (instead of waiting for the entire line to be sent).
