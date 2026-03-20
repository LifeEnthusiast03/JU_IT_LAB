/****************************************************************************************
 * Name             : Sougata Saha, Soham Chakraborty
 * Roll Numbers     : 002311001037, 002311001042
 * Team Number      : 10
 * Date             : 23/08/2025
 *
 * Assignment Number: 4
 * Assignment Title : Using mmap() system call and observing page-faults with `sar`
 *
 * Objective:
 *   - Create a large 8GB file using `fallocate`.
 *   - Map it into memory using `mmap()`.
 *   - Randomly write bytes at different offsets at 1-second intervals.
 *   - Flush changes to disk using `msync()`.
 *   - Read back the values to verify correctness.
 *   - Automatically delete the large file after completion to save storage.
 *   - Use `sar -B 1` in parallel to monitor page-fault statistics.
 *
 * Input Description:
 *   1. A large (~8GB) file created using `fallocate`.
 *   2. File name passed as a command-line argument.
 *
 * Output Description:
 *   1. Prints the written and read byte values along with their memory offsets.
 *   2. Displays mismatch errors (if any).
 *   3. Page-fault statistics observed via `sar -B 1`.
 *
 * Compilation Command:
 *   gcc -o mmap_demo A3_10_4.c
 *
 * Execution Command:
 *   ./mmap_demo bigfile.bin
 *
 * Sample Input:
 *   fallocate -l 8G bigfile.bin
 *   gcc -o mmap_demo A3_10_4.c
 *   ./mmap_demo bigfile.bin
 * 
 * Sample output :
 * >> Wrote 0x3F @ 0x000000004680A665
>> Read  0x3F @ 0x000000004680A665
>> Wrote 0x4E @ 0x000000005E6A40A1
>> Read  0x4E @ 0x000000005E6A40A1
>> Wrote 0x27 @ 0x00000000528B5A81
>> Read  0x27 @ 0x00000000528B5A81
>> Wrote 0x3B @ 0x00000001728CB805
>> Read  0x3B @ 0x00000001728CB805
>> Wrote 0x2D @ 0x000000005A6435E9
>> Read  0x2D @ 0x000000005A6435E9
>> Wrote 0x98 @ 0x000000007D8C7782
>> Read  0x98 @ 0x000000007D8C7782
>> Wrote 0x7A @ 0x000000013600E301
>> Read  0x7A @ 0x000000013600E301
>> Wrote 0x31 @ 0x0000000150166596
>> Read  0x31 @ 0x0000000150166596
>> Wrote 0x0A @ 0x00000000093EB7BB
>> Read  0x0A @ 0x00000000093EB7BB
>> Wrote 0x88 @ 0x00000000497859AD
>> Read  0x88 @ 0x00000000497859AD
>> Wrote 0xED @ 0x0000000033A9CEC9
>> Read  0xED @ 0x0000000033A9CEC9
>> Wrote 0x8F @ 0x0000000140ACC891
>> Read  0x8F @ 0x0000000140ACC891
>> Wrote 0x10 @ 0x0000000056186E22
>> Read  0x10 @ 0x0000000056186E22
>> Wrote 0x15 @ 0x0000000165BDA745
>> Read  0x15 @ 0x0000000165BDA745
>> Wrote 0xFE @ 0x0000000162518EA8
>> Read  0xFE @ 0x0000000162518EA8
>> Wrote 0x80 @ 0x000000003209D8EA
>> Read  0x80 @ 0x000000003209D8EA
>> Wrote 0x81 @ 0x0000000012C50A0D
>> Read  0x81 @ 0x0000000012C50A0D
>> Wrote 0x17 @ 0x000000015CF3346B
>> Read  0x17 @ 0x000000015CF3346B
>> Wrote 0xD2 @ 0x0000000007775991
>> Read  0xD2 @ 0x0000000007775991
>> Wrote 0x7F @ 0x0000000037221837
>> Read  0x7F @ 0x0000000037221837
>> Wrote 0x48 @ 0x000000006144ADEB
>> Read  0x48 @ 0x000000006144ADEB
>> Wrote 0xDA @ 0x000000006025FADF
>> Read  0xDA @ 0x000000006025FADF
>> Wrote 0xFC @ 0x000000012E9DA321
>> Read  0xFC @ 0x000000012E9DA321
>> Wrote 0x41 @ 0x000000014804F78A
>> Read  0x41 @ 0x000000014804F78A
>> Wrote 0xE9 @ 0x00000000026E792F
>> Read  0xE9 @ 0x00000000026E792F
>> Wrote 0xD3 @ 0x0000000040148C02
>> Read  0xD3 @ 0x0000000040148C02
>> Wrote 0xE1 @ 0x0000000036157D6C
>> Read  0xE1 @ 0x0000000036157D6C
>> Wrote 0x4C @ 0x00000001445E2651
>> Read  0x4C @ 0x00000001445E2651
>> Wrote 0xDD @ 0x000000012E352667
>> Read  0xDD @ 0x000000012E352667
>> Wrote 0x15 @ 0x000000016F7AEC88
>> Read  0x15 @ 0x000000016F7AEC88
>> Wrote 0x00 @ 0x0000000100424F30
>> Read  0x00 @ 0x0000000100424F30
>> Wrote 0xDF @ 0x00000001270BF4C6
>> Read  0xDF @ 0x00000001270BF4C6
>> Wrote 0x00 @ 0x0000000142421DEB
>> Read  0x00 @ 0x0000000142421DEB
>> Wrote 0x8B @ 0x0000000124702520
>> Read  0x8B @ 0x0000000124702520
>> Wrote 0xBA @ 0x000000014022C26A
>> Read  0xBA @ 0x000000014022C26A
>> Wrote 0xBC @ 0x000000006FBE2BB2
>> Read  0xBC @ 0x000000006FBE2BB2
>> Wrote 0x29 @ 0x0000000030CED87A
>> Read  0x29 @ 0x0000000030CED87A
>> Wrote 0x7A @ 0x000000013955ABC4
>> Read  0x7A @ 0x000000013955ABC4
^C
[INFO] File 'bigfile.bin' deleted (signal 2).

Sample sar output-

Linux 6.6.87.2-microsoft-standard-WSL2 (SOUGATA-SAHA)   08/23/25        _x86_64_        (12 CPU)

17:56:04     pgpgin/s pgpgout/s   fault/s  majflt/s  pgfree/s pgscank/s pgscand/s pgsteal/s    %vmeff
17:56:05         0.00     20.00      7.00      1.00     34.00      0.00      0.00      0.00      0.00
17:56:06         0.00    132.00      1.00      1.00      1.00      0.00      0.00      0.00      0.00
17:56:11         0.00     20.00     29.00      1.00      6.00      0.00      0.00      0.00      0.00
17:56:12         0.00     32.00      1.00      1.00      1.00      0.00      0.00      0.00      0.00
17:56:13         0.00     20.00      1.00      1.00      1.00      0.00      0.00      0.00      0.00
17:56:14         0.00     20.00      1.00      1.00      1.00      0.00      0.00      0.00      0.00
17:56:15         0.00     20.00      1.00      1.00      2.00      0.00      0.00      0.00      0.00
17:56:16         0.00     20.00      1.00      1.00      1.00      0.00      0.00      0.00      0.00
17:56:17         0.00     20.00      1.00      1.00      1.00      0.00      0.00      0.00      0.00
17:56:18         0.00     20.00      1.00      1.00      1.00      0.00      0.00      0.00      0.00
17:56:19         0.00     20.00      1.00      1.00      1.00      0.00      0.00      0.00      0.00
17:56:20         0.00     19.80      0.99      0.99      0.99      0.00      0.00      0.00      0.00
17:56:21         0.00    148.00      2.00      1.00      1.00      0.00      0.00      0.00      0.00
17:56:22         0.00     20.00      1.00      1.00      1.00      0.00      0.00      0.00      0.00
17:56:23         0.00     20.00      1.00      1.00      1.00      0.00      0.00      0.00      0.00
17:56:24         0.00     20.00      1.00      1.00      1.00      0.00      0.00      0.00      0.00
17:56:25         0.00     20.00      1.00      1.00      1.00      0.00      0.00      0.00      0.00
17:56:26         0.00    424.00      1.00      1.00      8.00      0.00      0.00      0.00      0.00
17:56:27         0.00     20.00      1.00      1.00      1.00      0.00      0.00      0.00      0.00
^C
Average:         0.00     54.50      2.84      1.00      3.42      0.00      0.00      0.00      0.00
 ****************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <signal.h>
#include <time.h>
#include <errno.h>

#define FILESIZE (8ULL << 30)  

static int           g_fd    = -1;
static unsigned char *g_map  = NULL;
static const char   *g_fname = NULL;


static void cleanup_and_exit(int signo) {
    if (g_map && g_map != MAP_FAILED) {
        munmap(g_map, FILESIZE);
    }
    if (g_fd >= 0) {
        close(g_fd);
    }
    if (g_fname) {
        if (unlink(g_fname) == 0) {
            if (signo)
                printf("\n[INFO] File '%s' deleted (signal %d).\n", g_fname, signo);
            else
                printf("[INFO] File '%s' deleted successfully.\n", g_fname);
        } else if (errno != ENOENT) {
            perror("unlink");
        }
    }
    exit(0);
}

static void sig_handler(int signo) {
    cleanup_and_exit(signo);
}


static inline uint64_t random_offset(void) {
    return ((((uint64_t)rand()) << 32) | (uint64_t)rand()) % FILESIZE;
}


static void do_step(void) {
    uint64_t off = random_offset();
    unsigned char val = (unsigned char)(rand() & 0xFF);

        if (pwrite(g_fd, &val, 1, off) != 1) {
            perror("pwrite");
            cleanup_and_exit(0);
        }

    unsigned char got = g_map[off];


    printf(">> Wrote 0x%02X @ 0x%016" PRIX64 "\n", val, off);
    printf(">> Read  0x%02X @ 0x%016" PRIX64 "\n", got, off);
    fflush(stdout);

    if (got != val) {
        fprintf(stderr, "[ERROR] Mismatch at 0x%016" PRIX64 " (expected 0x%02X, got 0x%02X)\n",
                off, val, got);
        cleanup_and_exit(0);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <bigfile>\n", argv[0]);
        return 1;
    }

    g_fname = argv[1];

  
    g_fd = open(g_fname, O_RDWR);
    if (g_fd < 0) {
        perror("open");
        return 1;
    }

  
    struct stat st;
    if (fstat(g_fd, &st) == 0) {
        if ((uint64_t)st.st_size < FILESIZE) {
            fprintf(stderr, "[ERROR] File is smaller than expected (have %zu bytes, need %zu).\n",
                    (size_t)st.st_size, (size_t)FILESIZE);
            close(g_fd);
            return 1;
        }
    }

    
    g_map = (unsigned char *)mmap(NULL, FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, g_fd, 0);
    if (g_map == MAP_FAILED) {
        perror("mmap");
        close(g_fd);
        return 1;
    }

  
    srand((unsigned)time(NULL) ^ (unsigned)getpid());


    signal(SIGINT,  sig_handler);
    signal(SIGTERM, sig_handler);

  
    for (;;) {
        do_step();
    }

    
    cleanup_and_exit(0);
    return 0;
}