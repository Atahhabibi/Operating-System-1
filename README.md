# CS480 Summer 2024 Assignment 1

## Team Members

- Member 1: [Atah-Habibi], [ID:130699943]
- Member 2: [Matthew-Press], [ID:129894281]

The project was developed and tested on the account of [Matthew-Press,atah-habibi].

## Project Overview

This project implements a program where several chat bots run in their own threads and write to a shared file named `QUOTE.txt`. The access to the file is managed using a semaphore to ensure data integrity. Each thread writes its thread ID and a specific quote to the file. Even-numbered threads write a quote by Brian Kernighan, while odd-numbered threads write a quote by Edsger Dijkstra. The threads run asynchronously but access the shared file in a controlled manner to prevent corruption.

## Project Structure

The project directory (`a1`) contains the following files:

- `main.c`: Contains the main logic of the program including thread creation and management.
- `threads.h`: Header file containing function declarations and necessary includes.
- `Makefile`: Script to automate the compilation process.
- `README.md`: This file, providing an overview and instructions.

### `main.c`

The `main.c` file includes:

- Necessary includes for thread and semaphore operations.
- Definition of the semaphore and thread function.
- Initialization of the semaphore and creation of threads in the `main` function.
- Implementation of the thread function where each thread writes to `QUOTE.txt` and prints its status to the console.

### `threads.h`

The `threads.h` file includes:

- Necessary includes.
- Definition of constants and the thread function declaration.

### `Makefile`

The `Makefile` includes:

- Definitions for the compiler and flags.
- Rules for building the executable and cleaning up files.

## How the Program Works

1. **Initialization**:

   - The program creates a file named `QUOTE.txt` and writes the process ID (PID) to it.
   - A semaphore named `FLAG` is initialized to control access to the file.

2. **Thread Creation**:

   - The program creates 7 threads using the `pthread_create()` function.
   - Each thread writes a specific message to `QUOTE.txt` and prints its status to the console periodically.
   - Even-numbered threads write every 2 seconds, and odd-numbered threads write every 3 seconds.

3. **Thread Execution**:

   - Each thread runs a loop 8 times where it acquires the semaphore, writes to the file, releases the semaphore, and sleeps for the specified duration.

4. **Cleanup**:
   - The program waits for all threads to complete using `pthread_join()`.
   - The semaphore is destroyed, and a message is printed indicating that all threads have completed.

## Compilation and Execution

### Compilation

To compile the project, navigate to the `a1` directory and run the `make` command:

```sh make


```
