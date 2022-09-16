NAME
	Luke's Shell - CA216 Assigment

DESCRIPTION
	This is my own shell, created for my CA216 - Operating Systems assignment.
	The shell can be built by running 'make' in the default linux terminal.
        This will create the binary file 'myshell'.
        Once created, run ./myshell to start the shell.

	The shell supports input/output redirection. This means we can read standard input
	from a file and place standard output in a file. I.e. the input of the programme can come
	from one file, and the output of the programme can go into another.

	To redirect input, use:
		./myshell < input.txt

        where input.txt is the name of the input file.

	To redirect output, use:
		./myshell > output.txt

	where output.txt is the name of the output file.

	To direct both input and output:
		./myshell < input.txt > output.txt

OPTIONS
        *Text between asterisks like this represents the argument passed to the command.*

	cd *directory* - change directory. The directory must be valid.
	dir - lists the contents of the current directory.
        clr - clears the screen.
	echo *example text* - prints the command line arguments on the display.
        environ - lists all the environment strings.
	help - displays the user manual (this!)
	pause - pauses the shell until the ENTER key is pressed.
        quit - quits the shell.

ENVIRONMENT CONCEPTS
	An environment variable is a dynamically-named value that can alter the way running processess
	will operate on an operating system. Perhaps the most simple example is the TEMP variable, widely
	used across many operating systems. The TEMP variable stores a directory location that will hold temporary files.
	
	It is important to note that each process has its own environment and thus, its own set of environment variables.
	However, when a process is created, it inherits a duplicate run-time environment of its parent process.

THE 'PROCESS' CONCEPT
	A process is an instance of a program being executed. Processes create other processes, known as children.
	By default, a process runs in the foreground. This means it requires the user to interact with them via
	the terminal or command line. A background process runs behind the scenes, without user intervention. When a process 
	For example, scheduling and system monitoring. To run a progress in the background with this shell, add
	an ampersand to the end of the input.

REFERENCES
	Linuxhint.com. 2022. Exec System Call in C. [online] Available at: <https://linuxhint.com/exec_linux_system_call_c/> [Accessed 2 March 2022].
	GeeksforGeeks. 2022. chdir() in C language with Examples - GeeksforGeeks. [online] Available at: <https://www.geeksforgeeks.org/chdir-in-c-language-with-examples/> [Accessed 2 March 2022].
        Tutorialspoint.com. 2022. C library function - system(). [online] Available at: <https://www.tutorialspoint.com/c_standard_library/c_function_system.htm> [Accessed 2 March 2022].
        OpenGenus IQ: Computing Expertise & Legacy. 2022. chdir(), fchdir() and getcwd() in C. [online] Available at: <https://iq.opengenus.org/chdir-fchdir-getcwd-in-c/> [Accessed 2 March 2022].
	Techonthenet.com. 2022. Linux: MORE command. [online] Available at: <https://www.techonthenet.com/linux/commands/more.php> [Accessed 2 March 2022].
	Khintibidze, L., 2022. Use the getchar Function in C. [online] Delft Stack. Available at: <https://www.delftstack.com/howto/c/getchar-in-c/> [Accessed 7 March 2022].
	En.wikipedia.org. 2022. Environment variable - Wikipedia. [online] Available at: <https://en.wikipedia.org/wiki/Environment_variable> [Accessed 9 March 2022].
