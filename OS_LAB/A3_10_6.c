/***********************************************************************
* Name - Sougata Saha, Soham Chakraborty
* Roll - 002311001037, 002311001042
* Team N0 - 10
* Date - 12/09/2025
*
* Assignment: Parallel Matrix Multiplication using Pthreads
*
* Input:
*  1) Matrix dimension N (square matrix of size N x N)
*  2) Number of threads T (1..#CPUs)
*  3) mod value M (used to initialize matrix elements as rand() % M)
*  4) print_switch (1 => print matrices, 0 => don't print)
*
* Output:
*  - (Optional) Prints input matrices A and B and result matrix C
*  - Prints elapsed time for the multiplication (using gettimeofday)
*
*
* Compilation :
* gcc -pthread A3_10_6.c -o matmul_pthread
*
* Execution example:
* ./matmul_pthread  <n> <Threads> <mod> <print_switch>
*
* ----------------- SAMPLE MONITORING INPUTS&OUTPUTS --------------------------
1.
./matmul_pthread 3000 1 100 0

Matrix multiplication finished. N=3000, threads=1, mod=100
Elapsed time (multiplication only): 174.258967 seconds

pgrep -a matmul_pthread
565 ./matmul_pthread 3000 1 100 0

ps -T -p 565
PID    SPID TTY          TIME CMD
    565     565 pts/0    00:00:00 matmul_pthread
    565     566 pts/0    00:00:24 matmul_pthread
    
sar 1 10
Linux 6.6.87.2-microsoft-standard-WSL2 (SOUGATA-SAHA)   09/12/25        _x86_64_    (12 CPU)

21:24:13        CPU     %user     %nice   %system   %iowait    %steal     %idle
21:24:14        all      8.33      0.00      0.00      0.00      0.00     91.67
21:24:15        all      8.43      0.00      0.00      0.00      0.00     91.57
21:24:16        all      8.33      0.00      0.00      0.00      0.00     91.67
21:24:17        all      8.33      0.00      0.00      0.00      0.00     91.67
21:24:18        all      8.32      0.00      0.08      0.00      0.00     91.60
21:24:19        all      8.25      0.00      0.16      0.39      0.00     91.20
21:24:23        all      8.38      0.00      0.16      0.00      0.00     91.47
21:24:24        all      8.33      0.00      0.00      0.00      0.00     91.67
21:24:25        all      8.35      0.00      0.00      0.00      0.00     91.65
21:24:26        all      8.32      0.00      0.00      0.00      0.00     91.68
Average:        all      8.34      0.00      0.04      0.04      0.00     91.58

2.
./matmul_pthread 3000 2 100 0
Matrix multiplication finished. N=3000, threads=2, mod=100
Elapsed time (multiplication only): 100.583459 seconds

pgrep -a matmul_pthread
626 ./matmul_pthread 3000 2 100 0

ps -T -p 626
    PID    SPID TTY          TIME CMD
    626     626 pts/0    00:00:00 matmul_pthread
    626     627 pts/0    00:00:17 matmul_pthread
    626     628 pts/0    00:00:17 matmul_pthread

sar 1 10
Linux 6.6.87.2-microsoft-standard-WSL2 (SOUGATA-SAHA)   09/12/25        _x86_64_    (12 CPU)

21:30:54        CPU     %user     %nice   %system   %iowait    %steal     %idle
21:30:55        all     16.67      0.00      0.00      0.00      0.00     83.33
21:30:56        all     16.67      0.00      0.08      0.00      0.00     83.25
21:30:57        all     16.68      0.00      0.00      0.00      0.00     83.32
21:30:58        all     16.67      0.00      0.00      0.00      0.00     83.33
21:30:59        all     16.65      0.00      0.08      0.00      0.00     83.26
21:31:00        all     16.68      0.00      0.00      0.00      0.00     83.32
21:31:01        all     16.67      0.00      0.00      0.00      0.00     83.33
21:31:02        all     16.58      0.00      0.08      0.00      0.00     83.33
21:31:03        all     16.65      0.00      0.08      0.00      0.00     83.26
21:31:04        all     16.69      0.00      0.00      0.00      0.00     83.31
Average:        all     16.66      0.00      0.03      0.00      0.00     83.31
3.
./matmul_pthread 3000 3 100 0
Matrix multiplication finished. N=3000, threads=3, mod=100
Elapsed time (multiplication only): 71.392753 seconds

pgrep -a matmul_pthread
638 ./matmul_pthread 3000 3 100 0

ps -T -p 638
    PID    SPID TTY          TIME CMD
    638     638 pts/0    00:00:00 matmul_pthread
    638     639 pts/0    00:00:11 matmul_pthread
    638     640 pts/0    00:00:11 matmul_pthread
    638     641 pts/0    00:00:11 matmul_pthread

sar 1 10
Linux 6.6.87.2-microsoft-standard-WSL2 (SOUGATA-SAHA)   09/12/25        _x86_64_    (12 CPU)

21:33:11        CPU     %user     %nice   %system   %iowait    %steal     %idle
21:33:12        all     24.92      0.00      0.08      0.00      0.00     75.00
21:33:13        all     25.06      0.00      0.00      0.00      0.00     74.94
21:33:14        all     24.96      0.00      0.17      0.00      0.00     74.88
21:33:15        all     25.02      0.00      0.00      0.00      0.00     74.98
21:33:16        all     25.08      0.00      0.00      0.00      0.00     74.92
21:33:17        all     25.02      0.00      0.00      0.00      0.00     74.98
21:33:18        all     25.00      0.00      0.00      0.00      0.00     75.00
21:33:19        all     25.00      0.00      0.00      0.00      0.00     75.00
21:33:20        all     25.00      0.00      0.08      0.00      0.00     74.92
21:33:21        all     25.02      0.00      0.00      0.00      0.00     74.98
Average:        all     25.01      0.00      0.03      0.00      0.00     74.96
4.
./matmul_pthread 3000 4 100 0
Matrix multiplication finished. N=3000, threads=4, mod=100
Elapsed time (multiplication only): 57.298793 seconds

pgrep -a matmul_pthread
651 ./matmul_pthread 3000 4 100 0
ps -T -p 651
    PID    SPID TTY          TIME CMD
    651     651 pts/0    00:00:00 matmul_pthread
    651     652 pts/0    00:00:08 matmul_pthread
    651     653 pts/0    00:00:08 matmul_pthread
    651     654 pts/0    00:00:08 matmul_pthread
    651     655 pts/0    00:00:08 matmul_pthread

sar 1 10
Linux 6.6.87.2-microsoft-standard-WSL2 (SOUGATA-SAHA)   09/12/25        _x86_64_    (12 CPU)

21:34:50        CPU     %user     %nice   %system   %iowait    %steal     %idle
21:34:51        all     33.28      0.00      0.00      0.00      0.00     66.72
21:34:52        all     33.31      0.00      0.00      0.00      0.00     66.69
21:34:56        all     33.28      0.00      0.25      0.00      0.00     66.47
21:34:57        all     33.31      0.00      0.08      0.00      0.00     66.61
21:34:58        all     33.33      0.00      0.00      0.00      0.00     66.67
21:34:59        all     33.33      0.00      0.00      0.00      0.00     66.67
21:35:00        all     33.33      0.00      0.08      0.00      0.00     66.58
21:35:01        all     33.33      0.00      0.00      0.33      0.00     66.33
21:35:02        all     33.33      0.00      0.08      0.00      0.00     66.58
21:35:03        all     33.33      0.00      0.00      0.00      0.00     66.67
Average:        all     33.32      0.00      0.05      0.03      0.00     66.60
5.
./matmul_pthread 3000 5 100 0
Matrix multiplication finished. N=3000, threads=5, mod=100
Elapsed time (multiplication only): 46.015766 seconds

pgrep -a matmul_pthread
670 ./matmul_pthread 3000 5 100 0

ps -T -p 670
    PID    SPID TTY          TIME CMD
    670     670 pts/0    00:00:00 matmul_pthread
    670     671 pts/0    00:00:14 matmul_pthread
    670     672 pts/0    00:00:14 matmul_pthread
    670     673 pts/0    00:00:14 matmul_pthread
    670     674 pts/0    00:00:14 matmul_pthread
    670     675 pts/0    00:00:14 matmul_pthread
 sar 1 10
Linux 6.6.87.2-microsoft-standard-WSL2 (SOUGATA-SAHA)   09/12/25        _x86_64_    (12 CPU)

21:36:28        CPU     %user     %nice   %system   %iowait    %steal     %idle
21:36:29        all     41.63      0.00      0.08      0.00      0.00     58.28
21:36:30        all     41.70      0.00      0.00      0.00      0.00     58.30
21:36:31        all     41.63      0.00      0.08      0.00      0.00     58.28
21:36:32        all     41.67      0.00      0.08      0.00      0.00     58.25
21:36:33        all     41.58      0.00      0.08      0.00      0.00     58.33
21:36:34        all     41.64      0.00      0.08      0.00      0.00     58.28
21:36:35        all     41.63      0.00      0.17      0.00      0.00     58.20
21:36:36        all     41.63      0.00      0.08      0.00      0.00     58.28
21:36:37        all     41.67      0.00      0.00      0.00      0.00     58.33
21:36:38        all     41.67      0.00      0.08      0.00      0.00     58.25
Average:        all     41.65      0.00      0.08      0.00      0.00     58.28
6.
./matmul_pthread 3000 6 100 0
Matrix multiplication finished. N=3000, threads=6, mod=100
Elapsed time (multiplication only): 40.343157 seconds

pgrep -a matmul_pthread
689 ./matmul_pthread 3000 6 100 0

ps -T -p 689
    PID    SPID TTY          TIME CMD
    689     689 pts/0    00:00:00 matmul_pthread
    689     690 pts/0    00:00:08 matmul_pthread
    689     691 pts/0    00:00:08 matmul_pthread
    689     692 pts/0    00:00:08 matmul_pthread
    689     693 pts/0    00:00:08 matmul_pthread
    689     694 pts/0    00:00:08 matmul_pthread
    689     695 pts/0    00:00:08 matmul_pthread

sar 1 10
Linux 6.6.87.2-microsoft-standard-WSL2 (SOUGATA-SAHA)   09/12/25        _x86_64_    (12 CPU)

21:38:32        CPU     %user     %nice   %system   %iowait    %steal     %idle
21:38:33        all     49.96      0.00      0.00      0.33      0.00     49.71
21:38:34        all     49.96      0.00      0.08      0.00      0.00     49.96
21:38:35        all     50.04      0.00      0.00      0.00      0.00     49.96
21:38:36        all     50.00      0.00      0.08      0.00      0.00     49.92
21:38:37        all     50.00      0.00      0.00      0.00      0.00     50.00
21:38:38        all     50.00      0.00      0.00      0.00      0.00     50.00
21:38:39        all     50.04      0.00      0.00      0.00      0.00     49.96
21:38:40        all     50.00      0.00      0.08      0.00      0.00     49.92
21:38:41        all     50.00      0.00      0.08      0.00      0.00     49.92
21:38:42        all     49.96      0.00      0.08      0.00      0.00     49.96
Average:        all     50.00      0.00      0.04      0.03      0.00     49.93
7.
./matmul_pthread 3000 7 100 0
Matrix multiplication finished. N=3000, threads=7, mod=100
Elapsed time (multiplication only): 36.333618 seconds

pgrep -a matmul_pthread
719 ./matmul_pthread 3000 7 100 0

ps -T -p 719
    PID    SPID TTY          TIME CMD
    719     719 pts/0    00:00:00 matmul_pthread
    719     720 pts/0    00:00:13 matmul_pthread
    719     721 pts/0    00:00:13 matmul_pthread
    719     722 pts/0    00:00:13 matmul_pthread
    719     723 pts/0    00:00:13 matmul_pthread
    719     724 pts/0    00:00:13 matmul_pthread
    719     725 pts/0    00:00:13 matmul_pthread
    719     726 pts/0    00:00:13 matmul_pthread

sar 1 10
Linux 6.6.87.2-microsoft-standard-WSL2 (SOUGATA-SAHA)   09/12/25        _x86_64_    (12 CPU)

21:41:10        CPU     %user     %nice   %system   %iowait    %steal     %idle
21:41:11        all     58.24      0.00      0.17      0.00      0.00     41.60
21:41:12        all     58.24      0.00      0.17      0.00      0.00     41.60
21:41:13        all     58.28      0.00      0.17      0.00      0.00     41.55
21:41:14        all     58.33      0.00      0.00      0.00      0.00     41.67
21:41:15        all     58.19      0.00      0.25      0.00      0.00     41.56
21:41:16        all     58.38      0.00      0.00      0.00      0.00     41.62
21:41:17        all     58.33      0.00      0.08      0.00      0.00     41.58
21:41:18        all     58.33      0.00      0.08      0.00      0.00     41.58
21:41:19        all     58.33      0.00      0.00      0.00      0.00     41.67
21:41:20        all     58.24      0.00      0.25      0.00      0.00     41.51
Average:        all     58.29      0.00      0.12      0.00      0.00     41.59
8.
./matmul_pthread 3000 8 100 0
Matrix multiplication finished. N=3000, threads=8, mod=100
Elapsed time (multiplication only): 33.905422 seconds

pgrep -a matmul_pthread
738 ./matmul_pthread 3000 8 100 0

ps -T -p 738
    PID    SPID TTY          TIME CMD
    738     738 pts/0    00:00:00 matmul_pthread
    738     739 pts/0    00:00:07 matmul_pthread
    738     740 pts/0    00:00:07 matmul_pthread
    738     741 pts/0    00:00:07 matmul_pthread
    738     742 pts/0    00:00:07 matmul_pthread
    738     743 pts/0    00:00:07 matmul_pthread
    738     744 pts/0    00:00:07 matmul_pthread
    738     745 pts/0    00:00:07 matmul_pthread
    738     746 pts/0    00:00:07 matmul_pthread

sar 1 10
Linux 6.6.87.2-microsoft-standard-WSL2 (SOUGATA-SAHA)   09/12/25        _x86_64_    (12 CPU)

21:43:04        CPU     %user     %nice   %system   %iowait    %steal     %idle
21:43:05        all     66.56      0.00      0.25      0.00      0.00     33.19
21:43:06        all     66.61      0.00      0.08      0.00      0.00     33.31
21:43:07        all     66.61      0.00      0.08      0.00      0.00     33.31
21:43:08        all     66.67      0.00      0.41      0.00      0.00     32.92
21:43:12        all     66.50      0.00      0.33      0.00      0.00     33.17
21:43:13        all     66.50      0.00      0.25      0.00      0.00     33.25
21:43:14        all     66.56      0.00      0.17      0.00      0.00     33.28
21:43:15        all     66.75      0.00      0.00      0.00      0.00     33.25
21:43:16        all     66.53      0.00      0.17      0.00      0.00     33.31
21:43:17        all     66.69      0.00      0.00      0.42      0.00     32.89
Average:        all     66.60      0.00      0.17      0.04      0.00     33.19

************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <pthread.h>
#include <time.h>


typedef struct {
    size_t tid;          
    size_t n;            
    size_t tcount;       
    unsigned char *A;    
    unsigned char *B;    
    unsigned int *C;     
} thread_arg_t;


static inline size_t idx(size_t r, size_t c, size_t n) {
    return r * n + c;
}


void *worker(void *argp) {
    thread_arg_t *arg = (thread_arg_t *)argp;
    size_t n = arg->n;
    size_t tid = arg->tid;
    size_t tcount = arg->tcount;
    unsigned char *A = arg->A;
    unsigned char *B = arg->B;
    unsigned int *C = arg->C;

    
    size_t rows_per = n / tcount;
    size_t extra = n % tcount;
    size_t start = tid * rows_per + (tid < extra ? tid : extra);
    size_t count = rows_per + (tid < extra ? 1 : 0);
    size_t end = start + count;

    for (size_t i = start; i < end; ++i) {
        for (size_t j = 0; j < n; ++j) {
            unsigned int sum = 0u;
            for (size_t k = 0; k < n; ++k) {
                sum += (unsigned int)A[idx(i,k,n)] * (unsigned int)B[idx(k,j,n)];
            }
            C[idx(i,j,n)] = sum;
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <N> <num_threads> <mod> <print_switch>\n", argv[0]);
        return EXIT_FAILURE;
    }

    errno = 0;
    char *endptr = NULL;

    long n_long = strtol(argv[1], &endptr, 10);
    if (errno || endptr == argv[1] || n_long <= 0) {
        perror("Invalid matrix dimension");
        return EXIT_FAILURE;
    }

    long threads_long = strtol(argv[2], &endptr, 10);
    if (errno || endptr == argv[2] || threads_long <= 0) {
        perror("Invalid number of threads");
        return EXIT_FAILURE;
    }

    long mod_long = strtol(argv[3], &endptr, 10);
    if (errno || endptr == argv[3] || mod_long <= 0) {
        perror("Invalid mod value");
        return EXIT_FAILURE;
    }

    long print_switch_long = strtol(argv[4], &endptr, 10);
    if (errno || endptr == argv[4] || (print_switch_long != 0 && print_switch_long != 1)) {
        perror("Invalid print_switch (use 0 or 1)");
        return EXIT_FAILURE;
    }

    size_t N = (size_t)n_long;
    size_t T = (size_t)threads_long;
    int modv = (int)mod_long;
    int print_switch = (int)print_switch_long;

    if (T > N) {
        fprintf(stderr, "Warning: num_threads > N, reducing effective threads to N\n");
        T = N;
    }

    unsigned char *A = malloc(N * N * sizeof(unsigned char));
    unsigned char *B = malloc(N * N * sizeof(unsigned char));
    unsigned int *C = malloc(N * N * sizeof(unsigned int));
    if (!A || !B || !C) {
        perror("malloc");
        free(A); free(B); free(C);
        return EXIT_FAILURE;
    }

    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < N * N; ++i) A[i] = (unsigned char)(rand() % modv);
    for (size_t i = 0; i < N * N; ++i) B[i] = (unsigned char)(rand() % modv);
    for (size_t i = 0; i < N * N; ++i) C[i] = 0u;

    pthread_t *threads = malloc(T * sizeof(pthread_t));
    thread_arg_t *targs = malloc(T * sizeof(thread_arg_t));
    if (!threads || !targs) {
        perror("malloc threads/targs");
        free(A); free(B); free(C); free(threads); free(targs);
        return EXIT_FAILURE;
    }

    struct timeval tstart, tend;
    gettimeofday(&tstart, NULL);

    for (size_t t = 0; t < T; ++t) {
        targs[t].tid = t; targs[t].n = N; targs[t].tcount = T;
        targs[t].A = A; targs[t].B = B; targs[t].C = C;
        pthread_create(&threads[t], NULL, worker, &targs[t]);
    }

    for (size_t t = 0; t < T; ++t) pthread_join(threads[t], NULL);

    gettimeofday(&tend, NULL);
    double elapsed = (tend.tv_sec - tstart.tv_sec) +
                     (tend.tv_usec - tstart.tv_usec) / 1e6;

    printf("Matrix multiplication finished. N=%zu, threads=%zu, mod=%d\n", N, T, modv);
    printf("Elapsed time (multiplication only): %.6f seconds\n", elapsed);

    if (print_switch) {
        printf("\nMatrix A:\n");
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < N; ++j) printf("%3u ", (unsigned)A[idx(i,j,N)]);
            printf("\n");
        }
        printf("\nMatrix B:\n");
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < N; ++j) printf("%3u ", (unsigned)B[idx(i,j,N)]);
            printf("\n");
        }
        printf("\nMatrix C:\n");
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < N; ++j) printf("%6u ", C[idx(i,j,N)]);
            printf("\n");
        }
    }

    free(A); free(B); free(C); free(threads); free(targs);
    return EXIT_SUCCESS;
}

