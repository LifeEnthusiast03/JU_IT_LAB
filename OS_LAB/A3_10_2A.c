/****************************************************************************************
 * Name - Sougata Saha, Soham Chakraborty
 * Roll - 002311001037, 002311001042
 * Team Number - 10
 * Date - 05/08/2025
 *
 * Assignment Details:
 * Assignment Number - 2A
 * Assignment Description - Write a C program to handle the SIGINT signal using the signal() system call. When Ctrl+C is pressed, display “Ha Ha, Not Stopping” instead of terminating. Use perror() to handle errors during signal registration.
 *
 * Input Description - No input needed
 * Output Description - Program runs, pressing [ctrl + C]  prints "Ha Ha, Not Stopping" and pressing [ctrl + \] quits the program.
 *
 * Compilation command - gcc A3_10_2A.c
 * Execution command - ./a.out
 *
 * Sample Input and Output - 
 *
 * Signal handler registered successfully
 * Program running... Press Ctrl+C to test signal handling
 * Press Ctrl+\ to quit the program

 * Running... 
 * Running... 
 * Running... 
 * Running... 
 * ^C
 * Ha Ha, Not Stopping
 * Running... 
 * Running... 
 * ^C
 * Ha Ha, Not Stopping
 * Running... 
 * Running... 
 * ^\Quit (core dumped)

 * **************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
    printf("\nHa Ha, Not Stopping\n");
    fflush(stdout);
}

int main() {
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("signal failed");
        exit(EXIT_FAILURE);
    }

    printf("Signal handler registered successfully\n");
    printf("Program running... Press Ctrl+C to test signal handling\n");
    printf("Press Ctrl+\\ to quit the program\n\n");

    while (1) {
        printf("Running... \n");
        sleep(1);
    }

    return 0;
}

