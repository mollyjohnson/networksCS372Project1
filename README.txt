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
Programming Assignment #2
Due Sunday, end of Week 9, by 11:59pm
Submit the source files, Makefile, and README in a .zip file to Canvas.
Objectives:
1. Implement 2-connection client-server network application
2. Practice using the sockets API
3. Refresh programming skills
The Program:
Design and implement a simple file transfer system, i.e., create a file transfer server and a file transfer client. Write the ftserver and the ftclient programs. The final version of your programs must accomplish the following tasks:
1. ftserver starts on Host A, and validates command-line parameters (<SERVER_PORT>).
2. ftserver waits on <PORTNUM> for a client request.
3. ftclient starts on Host B, and validates any pertinent command-line parameters. (<SERVER_HOST>, <SERVER_PORT>, <COMMAND>, <FILENAME>, <DATA_PORT>, etc…)
4. ftserver and ftclient establish a TCP control connection on <SERVER_PORT>. (For the remainder of this description, call this connection P)
5. ftserver waits on connection P for ftclient to send a command.
6. ftclient sends a command (-l (list) or -g <FILENAME> (get)) on connection P.
7. ftserver receives command on connection P.
If ftclient sent an invalid command
• ftserver sends an error message to ftclient on connection P, and ftclient displays the message on-screen.
otherwise
• ftserver initiates a TCP data connection with ftclient on <DATA_PORT>. (Call this connection Q)
• If ftclient has sent the -l command, ftserver sends its directory to ftclient on connection Q, and ftclient displays the directory on-screen.
• If ftclient has sent -g <FILENAME>, ftserver validates FILENAME, and either
- sends the contents of FILENAME on connection Q. ftclient saves the file in the current default directory (handling "duplicate file name" error if necessary), and displays a "transfer complete" message on-screen
or
- sends an appropriate error message (“File not found”, etc.) to ftclient on connection P, and ftclient displays the message on-screen.
• ftserver closes connection Q (don’t leave open sockets!).
8. ftclient closes connection P (don’t leave open sockets!) and terminates.
9. ftserver repeats from 2 (above) until terminated by a supervisor (SIGINT).
Page 2 of 3
Program Requirements:
• ftserver must be written in C/C++.
• ftclient must be written in Java or Python.
• Of course, your program must be well-modularized and well-documented.
• Your programs must run on a flip server: (flip1, flip2, flip3).engr.oregonstate.edu
o Probably the best way to do this is to use SSH Secure Shell, Putty, or another terminal emulator to log onto access.engr.oregonstate.edu using your ENGR username/password and note which flip you get.
o It will be easiest if you bring up two instances of the shell on the separate flip servers and use one to run the server, and the other to run the client (this is how I will be testing!).
• You may not use sendfile or any other predefined function that makes the problem trivial.
• Your program should be able to send a complete text file. You are not required to handle an “out of memory” error. Separate grading for short text files and long text files.
• Use the directories in which the programs are running. Don't hard-code any directories that might be inaccessible to the graders.
• Combine all program files into one *.zip archive (no .7z or .gz allowed). The .zip file should not contain any folders – only files!
• If you use additional include-files or make-files, be sure to include them in your .zip file.
• Create a README containing detailed instructions on how to compile and run your server and client.
• Be absolutely sure to cite any references and credit any collaborators. I’m sick of giving failing grades for people not doing this.
Options:
There are many possibilities for extra credit. All extra credit must be documented and referenced in your program description and README.txt to receive any credit. Here are a few ideas to get you started:
• Make your server multi-threaded.
• Implement username/password access to the server.
• Allow client to change directory on the server.
• Transfer files additional to text files (e.g. binary files) (a text file with a non-.txt extension doesn’t count.
• etc…
Page 3 of 3
Notes:
• Beej's Guide will be helpful. It has many things you’ll need for this assignment.
• Don't hard-code the port numbers
• Don’t use the well-known FTP port numbers, or 30021 or 30020, as these will be probably in use (by network services or other students).
• We will test your system with text files only (unless your README specifies additional file types), one very large and one small.
• If you implement extra credit features, be sure to fully describe those features, and how to use them, in your README, or you won’t receive any extra credit.
• Programs will be accepted up to 48 hours late with a 10% penalty per 24-hour period.
Example Execution:
SERVER (flip1)
CLIENT (flip2)
Input to console
Output
Input to Console
Output
> ftserver 30021
Server open on 30021
> ftclient flip1 30021 –l 30020
Connection from flip2.
List directory requested on port 30020.
Sending directory contents to flip2:30020
Receiving directory structure from flip1:30020
shortfile.txt
longfile.txt
> ftclient flip1 30021 –g shortfile.txt 30020
Connection from flip2.
File “shortfile.txt” requested on port 30020.
Sending “shortfile.txt” to flip2:30020
Receiving “shortfile.txt” from flip1:30020
File transfer complete.
> ftclient flip1 30021 –g longfileee.txt 30020
Connection from flip2.
File “longfileee.txt” requested on port 30020.
File not found. Sending error message to flip2:30021
flip1:30021 says FILE NOT FOUND
