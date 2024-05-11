# sysmon

## Introduction
This repository contains a C program for tracing system calls made by a target process using the `ptrace` system call. The program attaches to a running process specified by its process ID (PID), monitors its system calls, and prints out the system call numbers as they occur.

## Prerequisites
To compile and run this program, you need:
- A system with a C compiler (e.g., GCC)
- Basic understanding of C programming
- Familiarity with system calls and process management in Linux

## Installation
1. Clone this repository to your local machine: 
```~$ git clone https://github.com/ankushT369/sysmon.git```

2. Navigate to the cloned directory: ```~$ cd sysmon```

3. Compile the program using the provided Makefile: ```~$ make```

4. Run ```~$ sudo ./main <pid>```


## Usage
Once the program is compiled, you can use it to trace system calls of a target process. Follow these steps:

1. Identify the PID of the target process you want to trace.

2. Execute the compiled program with the PID of the target process as a command-line argument:

Replace `<pid>` with the actual PID of the target process.

3. The program will attach to the target process, start tracing its system calls, and print out the system call numbers as they occur.

4. To stop the tracing, press `Ctrl + C` in the terminal. This will terminate the program and detach it from the target process.

## Example
Suppose you have a program named `example_program` running with PID 1234, and you want to trace its system calls. You can use this program as follows:

## Notes
- This program uses the `ptrace` system call for process tracing, which is a powerful debugging tool. Exercise caution when using it, as it can disrupt the normal execution of processes.
- Tracing system calls can be useful for debugging and analyzing the behavior of programs, but it may also have security implications. Ensure that you have the necessary permissions to trace processes on your system.
- Refer to the accompanying source code comments and documentation for detailed explanations of the implementation.
