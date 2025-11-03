/***********************************************************************
 *
 * Name       : Sougata Saha, Soham Chakraborty
 * Roll       : 002311001037, 002311001042
 * Section    : A3
 * Team No    : 10
 * Date       : 21/09/2025
 *
 * Assignment : Multithreading with Deadlock Avoidance
 *
 * Description:
 *   Three totals (Total_1, Total_2, Total_3) start at 100000 each.
 *   - Thread 1 transfers random (≤10) from Total_1 to Total_2 or Total_3
 *   - Thread 2 transfers random (≤20) from Total_2 to Total_1 or Total_3
 *   - Thread 3 transfers random (≤30) from Total_3 to Total_1 or Total_2
 *   - Thread 4 displays all totals and the grand total.
 *
 * Input  : No manual input, random values generated internally.
 * Output : Continuous prints showing chosen values, transfers, and totals.
 *
 * Compilation:
 *   gcc -o A3_10_7 A3_10_7.c -lpthread
 *
 * Execution:
 *   ./A3_10_7
 *
 * NOTE ON DEADLOCK AVOIDANCE:
 *   Deadlock is avoided by enforcing a single global lock order.
 *   In this program, the chosen order is:
 *       m1 → m2 → m3
 *   All threads follow this same rule:
 *       - If multiple locks are needed, they are always acquired in this order.
 *       - Locks are always released in the reverse order.
 *   Because every thread respects the same sequence,
 *   circular waiting cannot occur, so deadlock is impossible.
 *   If any thread were to acquire locks in a different order, deadlock could occur.
 *
 * Sample Output:
 *   TH1: move 5 from T1 to T2 | T1=99995 T2=100005 T3=100000
 *   TH2: move 8 from T2 to T3 | T1=99995 T2=99997 T3=100008
 *   TH3: move 17 from T3 to T1 | T1=100012 T2=99997 T3=99991
 *   TH4: Display Totals | T1=100012 T2=99997 T3=99991 | Grand=300000
 *   TH2: move 5 from T2 to T3 | T1=100012 T2=99992 T3=99996
 *   TH1: move 10 from T1 to T3 | T1=100002 T2=99992 T3=100006
 *   TH3: move 30 from T3 to T2 | T1=100002 T2=100022 T3=99976
 *   TH4: Display Totals | T1=100002 T2=100022 T3=99976 | Grand=300000
 *   TH2: move 3 from T2 to T3 | T1=100002 T2=100019 T3=99979
 *   TH1: move 3 from T1 to T3 | T1=99999 T2=100019 T3=99982
 *   TH3: move 20 from T3 to T2 | T1=99999 T2=100039 T3=99962
 *   TH4: Display Totals | T1=99999 T2=100039 T3=99962 | Grand=300000
 *   TH1: move 1 from T1 to T2 | T1=99998 T2=100040 T3=99962
 *   TH3: move 30 from T3 to T2 | T1=99998 T2=100070 T3=99932
 *   TH2: move 20 from T2 to T1 | T1=100018 T2=100050 T3=99932
 *   TH4: Display Totals | T1=100018 T2=100050 T3=99932 | Grand=300000
 *   TH1: move 8 from T1 to T2 | T1=100010 T2=100058 T3=99932
 *   TH3: move 16 from T3 to T2 | T1=100010 T2=100074 T3=99916
 *
 ***********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

long Total_1 = 100000, Total_2 = 100000, Total_3 = 100000;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m3 = PTHREAD_MUTEX_INITIALIZER;

void lock_in_order(pthread_mutex_t* a, pthread_mutex_t* b) {
    if (a == &m1 && b == &m2) {
        pthread_mutex_lock(&m1);
        pthread_mutex_lock(&m2);
    } else if (a == &m1 && b == &m3) {
        pthread_mutex_lock(&m1);
        pthread_mutex_lock(&m3);
    } else if (a == &m2 && b == &m3) {
        pthread_mutex_lock(&m2);
        pthread_mutex_lock(&m3);
    }
}

void unlock_in_order(pthread_mutex_t* a, pthread_mutex_t* b) {
    if (a == &m1 && b == &m2) {
        pthread_mutex_unlock(&m2);
        pthread_mutex_unlock(&m1);
    } else if (a == &m1 && b == &m3) {
        pthread_mutex_unlock(&m3);
        pthread_mutex_unlock(&m1);
    } else if (a == &m2 && b == &m3) {
        pthread_mutex_unlock(&m3);
        pthread_mutex_unlock(&m2);
    }
}

void* thread1(void* arg) {
    while (1) {
        int qty = rand() % 10 + 1;
        int choice = rand() % 2;
        if (choice == 0) {
            lock_in_order(&m1, &m2);
            if (Total_1 >= qty) {
                Total_1 -= qty;
                Total_2 += qty;
                printf("TH1: move %d from T1 to T2 | T1=%ld T2=%ld T3=%ld\n", qty, Total_1, Total_2, Total_3);
            }
            unlock_in_order(&m1, &m2);
        } else {
            lock_in_order(&m1, &m3);
            if (Total_1 >= qty) {
                Total_1 -= qty;
                Total_3 += qty;
                printf("TH1: move %d from T1 to T3 | T1=%ld T2=%ld T3=%ld\n", qty, Total_1, Total_2, Total_3);
            }
            unlock_in_order(&m1, &m3);
        }
        usleep(500000);
    }
    return NULL;
}

void* thread2(void* arg) {
    while (1) {
        int qty = rand() % 20 + 1;
        int choice = rand() % 2;
        if (choice == 0) {
            lock_in_order(&m1, &m2);
            if (Total_2 >= qty) {
                Total_2 -= qty;
                Total_1 += qty;
                printf("TH2: move %d from T2 to T1 | T1=%ld T2=%ld T3=%ld\n", qty, Total_1, Total_2, Total_3);
            }
            unlock_in_order(&m1, &m2);
        } else {
            lock_in_order(&m2, &m3);
            if (Total_2 >= qty) {
                Total_2 -= qty;
                Total_3 += qty;
                printf("TH2: move %d from T2 to T3 | T1=%ld T2=%ld T3=%ld\n", qty, Total_1, Total_2, Total_3);
            }
            unlock_in_order(&m2, &m3);
        }
        usleep(500000);
    }
    return NULL;
}

void* thread3(void* arg) {
    while (1) {
        int qty = rand() % 30 + 1;
        int choice = rand() % 2;
        if (choice == 0) {
            lock_in_order(&m1, &m3);
            if (Total_3 >= qty) {
                Total_3 -= qty;
                Total_1 += qty;
                printf("TH3: move %d from T3 to T1 | T1=%ld T2=%ld T3=%ld\n", qty, Total_1, Total_2, Total_3);
            }
            unlock_in_order(&m1, &m3);
        } else {
            lock_in_order(&m2, &m3);
            if (Total_3 >= qty) {
                Total_3 -= qty;
                Total_2 += qty;
                printf("TH3: move %d from T3 to T2 | T1=%ld T2=%ld T3=%ld\n", qty, Total_1, Total_2, Total_3);
            }
            unlock_in_order(&m2, &m3);
        }
        usleep(500000);
    }
    return NULL;
}

void* thread4(void* arg) {
    while (1) {
        pthread_mutex_lock(&m1);
        pthread_mutex_lock(&m2);
        pthread_mutex_lock(&m3);
        long grand = Total_1 + Total_2 + Total_3;
        printf("TH4: Display Totals | T1=%ld T2=%ld T3=%ld | Grand=%ld\n", Total_1, Total_2, Total_3, grand);
        pthread_mutex_unlock(&m3);
        pthread_mutex_unlock(&m2);
        pthread_mutex_unlock(&m1);
        usleep(500000);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t th1, th2, th3, th4;
    pthread_create(&th1, NULL, thread1, NULL);
    pthread_create(&th2, NULL, thread2, NULL);
    pthread_create(&th3, NULL, thread3, NULL);
    pthread_create(&th4, NULL, thread4, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);
    pthread_join(th4, NULL);
    return 0;
}
