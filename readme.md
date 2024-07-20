# pipex

## Introduction

The `pipex` project is designed to handle pipes and execute shell commands with file redirection. This README outlines the program's requirements, usage, and behavior.

## Objectives

The goal is to create a program that mimics the behavior of shell piping. Your program should be able to execute two shell commands with file redirection, just like:

```bash
< file1 cmd1 | cmd2 > file2
```

## Program Details
- Program Name: pipex
- Files to Submit: Makefile, *.h, *.c
- Makefile Rules:
- NAME: Name of the program.
- all: Build the program.
- clean: Remove object files.
- fclean: Remove object files and the executable.
- re: Rebuild the program.

## Usage
    Run the program with four arguments: two file names and two shell commands. The command should be executed as follows:

    ./pipex file1 cmd1 cmd2 file2
    file1: Input file to be used by cmd1.
    cmd1: First shell command with its parameters.
    cmd2: Second shell command with its parameters.
    file2: Output file where the result of cmd2 will be written.

## Examples
    For the command:

    ./pipex infile "ls -l" "wc -l" outfile
    This should behave like:

    < infile ls -l | wc -l > outfile
    For the command:

    ./pipex infile "grep a1" "wc -w" outfile
    This should behave like:

    < infile grep a1 | wc -w > outfile

## Requirements
    Makefile: Must compile your source files without relinking.
    Error Handling: Handle all possible errors and ensure the program doesn't quit unexpectedly (e.g., segmentation faults, bus errors, double frees).
    Memory Management: No memory leaks allowed.
    Behavior: Mimic shell command behavior for < file1 cmd1 | cmd2 > file2.

## External Functions
    open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid
    ft_printf or equivalent (if you coded it)
    Functions from MiniLibX are not required for this project.

## Author
    NUILED
    Let me know if you need any more adjustments!