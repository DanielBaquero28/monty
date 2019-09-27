# 0x19. C - Stacks, Queues - LIFO, FIFO

---
## Setup
####Monty interpreter
This command will be used to compile the monty interpreter:
``gcc -Wall -Werror -Wextra -pedantic *.c -o monty``
Please use gcc-4.8

####Brainfuck programs
To install the brainfuck interpreter:
``sudo apt_get install bf``

## Usage
####Monty interpreter
The MOnty language is a very simple programming languaje. Monty relies on a unique stack of integers and perfomrs some operations.
Usage is : `./monty FILE` where `FILE` contains lines of commands.
Lines are of the type `opcode [argument]`.
Current opcodes are:
1. Push: push onto stack. This OPCODE is the only one requiring an argument. must be an integer.
2. Pall : print all stack
3. pop : pop the value at the top of the stack
4. pint : peek the top of the stack
5. swap : swap the top 2 elements of the stack
6. queue : change the functionment of the stack to one of a queue. Enqueue to the bottom of the stack and dequeue from the top.
7. stack : is the reverse of queue, it reestablishes the stack.
8. nop : does not do anything
<br>
The monty language allows for any space before or after the opcode and its argument. ANy text after the argument is disregarded.
Any line starting with a # is considered a comment.
Currently the stack is implemented as a doubly linked list.

####Brainfuck program
in the brainfuck folder: bf FILE.

## Description of Files
<h6>monty.h</h6>
header file for the project, contains the struct used throughout.

<h6>monty.c</h6>
Entry point of the interpreter. Feeds a line at a time to execute

## Bugs
Who doesn't ?

### Authors
All code written by
[Daniel Baquero](https://github.com/DanielBaquero28)
[Carlos Alvarez](https://github.com/charlyhackr/)
