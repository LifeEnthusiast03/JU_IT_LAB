/***********************************************************************
*
* Name:            Sougata Saha, Soham Chakraborty
* Roll:            002311001037, 002311001042
* Team No:         10
* Date:            02/09/2025
* Title:           Assignment - 5
*
* Assignment Details:
* A multi-threaded C program that uses shared memory and semaphores.
* A main process generates random (X, Y) pairs, and three threads
* concurrently perform the following calculations on them:
* A = X * Y
* B = (X * Y) / 2
* C = X + Y
* D = (X * Y) / (X + Y)
* E = (X + Y) * (X - Y)
*
* Input Description:
* The program takes a single command-line argument: a positive
* integer 'N', which specifies the number of random (X, Y) pairs to
* be processed by the program.
*
* Output Description:
* The program outputs a formatted table to the console. Each row in the
* table displays a random (X, Y) pair and the results of the five
* calculations (A, B, C, D, E) performed by the worker threads.
*
* Compilation Command:
* gcc A3_10_5.c -o assignment5 -lpthread
*
* Execution Sequence:
* 1. Compile the program using the command above.
* 2. Run the executable with an integer argument N (e.g., ./assignment5 5).
* 3. To capture the ipcs output, temporarily add `getchar();` after
* the `shmat()` call in the code. Run the program, and while it's
* paused, run `ipcs -m` in a second terminal.
*
* ipcs Command Output from `ipcs -m`:
* ------ Shared Memory Segments --------
* key        shmid      owner      perms      bytes      nattch     status
* 0x41434ff7 3          soham      666        28         1
*
* Sample Input and Output generated (for N=5):
*
* --- Input ---
* ./assignment5 5
*
* --- Output ---
* ------------------------------------------------------------------
* | Pairs(X,Y) |    A    |    B    |    C    |    D    |     E    |
* ------------------------------------------------------------------
* |    (9, 5)   |   45.00 |   22.50 |   14.00 |    3.21 |    56.00 |
* |    (2, 6)   |   12.00 |    6.00 |    8.00 |    1.50 |   -32.00 |
* |    (4, 1)   |    4.00 |    2.00 |    5.00 |    0.80 |    15.00 |
* |    (1, 6)   |    6.00 |    3.00 |    7.00 |    0.86 |   -35.00 |
* |    (1, 2)   |    2.00 |    1.00 |    3.00 |    0.67 |    -3.00 |
* ------------------------------------------------------------------
*
***********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <time.h>

typedef struct {
    int x, y;
    float a, b, c, d, e;
} SharedData;

SharedData *shared_data;
int num_pairs;

sem_t start_th1_sem, start_th2_sem, start_th3_sem;
sem_t calc_done_sem;

void *thread1_func(void *arg) {
    for (int i = 0; i < num_pairs; i++) {
        sem_wait(&start_th1_sem);
        shared_data->a = shared_data->x * shared_data->y;
        sem_post(&calc_done_sem);
    }
    pthread_exit(NULL);
}

void *thread2_func(void *arg) {
    for (int i = 0; i < num_pairs; i++) {
        sem_wait(&start_th2_sem);
        shared_data->b = (shared_data->x * shared_data->y) / 2.0f;
        if ((shared_data->x + shared_data->y) != 0) {
            shared_data->d = (float)(shared_data->x * shared_data->y) / (shared_data->x + shared_data->y);
        } else {
            shared_data->d = 0;
        }
        sem_post(&calc_done_sem);
    }
    pthread_exit(NULL);
}

void *thread3_func(void *arg) {
    for (int i = 0; i < num_pairs; i++) {
        sem_wait(&start_th3_sem);
        shared_data->c = shared_data->x + shared_data->y;
        shared_data->e = (shared_data->x + shared_data->y) * (shared_data->x - shared_data->y);
        sem_post(&calc_done_sem);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_pairs>\n", argv[0]);
        return 1;
    }
    num_pairs = atoi(argv[1]);
    if (num_pairs <= 0) {
        fprintf(stderr, "Number of pairs must be a positive integer.\n");
        return 1;
    }

    FILE *temp_file = fopen("tempShare", "w");
    if (temp_file == NULL) {
        perror("Could not create temp file for key generation");
        return 1;
    }
    fclose(temp_file);

    key_t key = ftok("tempShare", 65);
    int shmid = shmget(key, sizeof(SharedData), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }
    shared_data = (SharedData *)shmat(shmid, NULL, 0);

    sem_init(&start_th1_sem, 0, 0);
    sem_init(&start_th2_sem, 0, 0);
    sem_init(&start_th3_sem, 0, 0);
    sem_init(&calc_done_sem, 0, 0);

    pthread_t th1, th2, th3;
    pthread_create(&th1, NULL, thread1_func, NULL);
    pthread_create(&th2, NULL, thread2_func, NULL);
    pthread_create(&th3, NULL, thread3_func, NULL);

    srand(time(NULL));

    printf("------------------------------------------------------------------\n");
    printf("| Pairs(X,Y) |    A    |    B    |    C    |    D    |     E    |\n");
    printf("------------------------------------------------------------------\n");
    
    for (int i = 0; i < num_pairs; i++) {
        shared_data->x = (rand() % 9) + 1;
        shared_data->y = (rand() % 9) + 1;

        sem_post(&start_th1_sem);
        sem_post(&start_th2_sem);
        sem_post(&start_th3_sem);

        sem_wait(&calc_done_sem);
        sem_wait(&calc_done_sem);
        sem_wait(&calc_done_sem);

        SharedData current_result = *shared_data;

        printf("|    (%d, %d)   | %7.2f | %7.2f | %7.2f | %7.2f | %8.2f |\n", 
               current_result.x, current_result.y, current_result.a, current_result.b, 
               current_result.c, current_result.d, current_result.e);
    }
    printf("------------------------------------------------------------------\n");

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);

    sem_destroy(&start_th1_sem);
    sem_destroy(&start_th2_sem);
    sem_destroy(&start_th3_sem);
    sem_destroy(&calc_done_sem);
    
    shmdt(shared_data);
    shmctl(shmid, IPC_RMID, NULL);
    remove("tempShare");

    return 0;
}