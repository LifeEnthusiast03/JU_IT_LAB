/***************************************************************************************************
 * Name - Sougata Saha, Soham Chakraborty
 * Roll - 002311001037, 002311001042
 * Team Number - 10
 * Date - 05/08/2025
 *
 * Assignment Details:
 * Assignment Number - 2B
 * Assignment Description - This assignment demonstrates Inter-Process Communication (IPC) using named pipes (FIFOs) and the fork() system call. A 1GB file is sent from the parent process to the child through one FIFO, and then sent back from the child to the parent through another FIFO. The program measures the total transfer time and verifies correctness using the cmp or diff command.
 *
 * Input Description - No input needed
 * Output Description - The program displays file creation progress, FIFO communication steps, total transfer time, and confirms if the original and returned files are identical.
 *
 * Compilation command - gcc A3_10_2B.c
 * Execution command - ./a.out
 * 
 * Sample Input and Output - 
 * FIFO IPC Demo - File Size: 1024MB  
 * Creating 1024MB random string text file...  
 * Progress: 100MB written  
 * Progress: 200MB written  
 * Progress: 300MB written  
 * Progress: 400MB written  
 * Progress: 500MB written  
 * Progress: 600MB written  
 * Progress: 700MB written  
 * Progress: 800MB written  
 * Progress: 900MB written  
 * Progress: 1000MB written  
 * Random string test file created successfully: test_file.txt  
 * FIFO created successfully: parent_to_child  
 * FIFO created successfully: child_to_parent  
 * Starting double file transfer via FIFOs...  
 * Parent: Sending file to child via FIFO1...  
 * Child: Receiving file from parent via FIFO1...  
 * Parent: Receiving file from child via FIFO2...  
 * Child: File received, sending back to parent via FIFO2...  
 * Child: Transfer completed successfully  
 * Parent->Child->Parent transfer completed!  
 * Total transfer time: 1.00 seconds  
 * Comparing original and returned files...  
 * Files are identical - Transfer successful!  
 *   
 * File listings:  
 * prw-rw-r-- 1 adminpc adminpc    0 Aug  5 15:32 child_to_parent  
 * prw-rw-r-- 1 adminpc adminpc    0 Aug  5 15:32 parent_to_child  
 * -rw-r--r-- 1 adminpc adminpc 1.0G Aug  5 15:32 received_file.txt  
 * -rw-rw-r-- 1 adminpc adminpc 1.0G Aug  5 15:32 test_file.txt  
 * Program completed successfully  

 *****************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define BUFFER_SIZE 8192
#define DEFAULT_FILE_SIZE_MB 1024
#define FIFO1 "parent_to_child"
#define FIFO2 "child_to_parent"
#define TEST_FILE "test_file.txt"
#define RECEIVED_FILE "received_file.txt"
#define TEMP_FILE "temp_child_file.txt"

int create_test_file(const char* filename, long size_mb) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    long bytes_written = 0;
    long total_bytes = size_mb * 1024 * 1024;

    printf("Creating %ldMB random string text file...\n", size_mb);

    file = fopen(filename, "w");
    if (file == NULL) {
        perror("fopen failed for test file creation");
        return -1;
    }

    srand(time(NULL));

    while (bytes_written < total_bytes) {
        long remaining = total_bytes - bytes_written;
        long chunk_size = (remaining < BUFFER_SIZE) ? remaining : BUFFER_SIZE;

        for (int i = 0; i < chunk_size; i++) {
            buffer[i] = 'a' + (rand() % 26);
        }

        if (fwrite(buffer, 1, chunk_size, file) != chunk_size) {
            perror("fwrite failed");
            fclose(file);
            return -1;
        }

        bytes_written += chunk_size;

        if (size_mb >= 100 && bytes_written % (100 * 1024 * 1024) == 0) {
            printf("Progress: %ldMB written\n", bytes_written / (1024 * 1024));
        }
    }

    if (fclose(file) != 0) {
        perror("fclose failed");
        return -1;
    }

    printf("Random string test file created successfully: %s\n", filename);
    return 0;
}

int create_fifo(const char* fifo_name) {
    unlink(fifo_name);
    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo failed");
        return -1;
    }
    printf("FIFO created successfully: %s\n", fifo_name);
    return 0;
}

int send_file_via_fifo(const char* src_file, const char* fifo_name) {
    int src_fd, fifo_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    src_fd = open(src_file, O_RDONLY);
    if (src_fd == -1) {
        perror("open source file failed");
        return -1;
    }

    fifo_fd = open(fifo_name, O_WRONLY);
    if (fifo_fd == -1) {
        perror("open FIFO for writing failed");
        close(src_fd);
        return -1;
    }

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(fifo_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("write to FIFO failed");
            close(src_fd);
            close(fifo_fd);
            return -1;
        }
    }

    if (bytes_read == -1) perror("read from source file failed");

    close(src_fd);
    close(fifo_fd);
    return 0;
}

int receive_file_via_fifo(const char* dest_file, const char* fifo_name) {
    int dest_fd, fifo_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    fifo_fd = open(fifo_name, O_RDONLY);
    if (fifo_fd == -1) {
        perror("open FIFO for reading failed");
        return -1;
    }

    dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("open destination file failed");
        close(fifo_fd);
        return -1;
    }

    while ((bytes_read = read(fifo_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("write to destination file failed");
            close(fifo_fd);
            close(dest_fd);
            return -1;
        }
    }

    if (bytes_read == -1) perror("read from FIFO failed");

    close(fifo_fd);
    close(dest_fd);
    return 0;
}

int compare_files(const char* file1, const char* file2) {
    char command[512];
    int result;

    printf("Comparing original and returned files...\n");
    snprintf(command, sizeof(command), "cmp %s %s > /dev/null 2>&1", file1, file2);
    result = system(command);

    if (result == 0) {
        printf("Files are identical - Transfer successful!\n");
        return 0;
    } else {
        printf("Files differ - Transfer failed!\n");
        snprintf(command, sizeof(command), "diff %s %s | head -10", file1, file2);
        printf("First few differences:\n");
        system(command);
        return -1;
    }
}

void show_file_listings() {
    printf("\nFile listings:\n");
    system("ls -lh test_file.txt received_file.txt parent_to_child child_to_parent 2>/dev/null");
}

int main(int argc, char *argv[]) {
    pid_t pid;
    long file_size_mb = DEFAULT_FILE_SIZE_MB;
    time_t start_time, end_time;
    double transfer_time;
    int status;

    if (argc > 1) {
        file_size_mb = atol(argv[1]);
        if (file_size_mb <= 0) {
            fprintf(stderr, "Invalid file size. Using default 1024MB\n");
            file_size_mb = DEFAULT_FILE_SIZE_MB;
        }
    }

    printf("FIFO IPC Demo - File Size: %ldMB\n", file_size_mb);

    unlink(TEST_FILE);
    unlink(RECEIVED_FILE);
    unlink(TEMP_FILE);
    unlink(FIFO1);
    unlink(FIFO2);

    if (create_test_file(TEST_FILE, file_size_mb) != 0) exit(EXIT_FAILURE);

    if (create_fifo(FIFO1) != 0 || create_fifo(FIFO2) != 0) exit(EXIT_FAILURE);

    printf("Starting double file transfer via FIFOs...\n");
    time(&start_time);

    pid = fork();
    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Child: Receiving file from parent via FIFO1...\n");
        if (receive_file_via_fifo(TEMP_FILE, FIFO1) != 0) exit(EXIT_FAILURE);

        printf("Child: File received, sending back to parent via FIFO2...\n");
        if (send_file_via_fifo(TEMP_FILE, FIFO2) != 0) {
            unlink(TEMP_FILE);
            exit(EXIT_FAILURE);
        }

        unlink(TEMP_FILE);
        printf("Child: Transfer completed successfully\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("Parent: Sending file to child via FIFO1...\n");
        if (send_file_via_fifo(TEST_FILE, FIFO1) != 0) {
            kill(pid, SIGTERM);
            wait(NULL);
            exit(EXIT_FAILURE);
        }

        printf("Parent: Receiving file from child via FIFO2...\n");
        if (receive_file_via_fifo(RECEIVED_FILE, FIFO2) != 0) {
            kill(pid, SIGTERM);
            wait(NULL);
            exit(EXIT_FAILURE);
        }

        if (wait(&status) == -1) {
            perror("wait failed");
        } else if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            printf("Parent->Child->Parent transfer completed!\n");
        } else {
            printf("Child process failed\n");
        }

        time(&end_time);
        transfer_time = difftime(end_time, start_time);
        printf("Total transfer time: %.2f seconds\n", transfer_time);

        compare_files(TEST_FILE, RECEIVED_FILE);
        show_file_listings();
    }

    unlink(FIFO1);
    unlink(FIFO2);

    printf("Program completed successfully\n");
    return 0;
}
