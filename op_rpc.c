#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <string.h>
#include <clock.h>

int exp(double *vec, int vec size) {
    return 0;
}

int inverse(double *vec, int vec size) {
    return 0;
}

int mult(double a, double *vec, int vec size) {
    return 0;
}

int create_threads() {

}


#define MAX = 100;
#define MIN = -100;
#define N8 100000000
#define N9 1000000000
#define N10 10000000000 // must use long!!!




char * list; // list of random number 
int *acc; // sum of the numbers in the list
char* sum_lock;
char* lock_index;

//long * med;

/**
 * Aquire the lock, allow the thread to execute the CZ
 * however, no one else can access it
 * @return 
 */
void acquire(char* lock) {
    while (test_and_set2(
            lock));
}

char* concat(char *s1, char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1); //+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

/**
 * 
 * Release the lock, so another thread can enter the CZ
 * @return 
 */
void release(char* lock) {
    *lock = 0;
}

/**
 * 
 * @param flag
 * @return 
 */
int test_and_set2(char* flag) {
    int anterior = *flag;
    *flag = 1;
    return anterior;
}

/**
 * fill the vector 
 * @param n, size of the vector
 * @return 
 */
int fill_vector(long *n) {
    int rnd;
    for (int i = 0; i < *n; i++) {
        //        rnd = get_rand();
        rnd = 0;
        list[i] = rnd;
    }
    return 0;
}

/**
 *NÃO ROLA
 */
int fill_with_threads(long *n, int *k) {
    //    printf("fill\n");

    long med = *n / (*k);
    int rest = *n - (med * *k);
    pthread_t *thread = malloc(sizeof (pthread_t) * *k);
    for (int i = 0; i < *k; i++) {

        sum_args *args = malloc(sizeof (sum_args));
        args->index = med*i;
        args->nb = med;
        if (pthread_create(&thread[i], NULL, &add, (void *) args)) { // 3 arg = func to exec 4 arg = arg passed to func
            //            printf("thread : %d \n", i);
            printf("Error while creating threds. \n");
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < *k; i++) {
        pthread_join(thread[i], NULL);
    }

    pthread_t *lon_th = malloc(sizeof (pthread_t));
    // only enter the loop if rest>0
    if (rest) {
        sum_args * args = malloc(sizeof (sum_args));
        args->index = *k*med;
        args->nb = rest;
        if (pthread_create(&lon_th[0], NULL, &add, (void *) args)) { // 3 arg = func to exec 4 arg = arg passed to func
            printf("Error while creating threds. \n");
            exit(EXIT_FAILURE);
        }
        pthread_join(thread[0], NULL);
    }
    return 0;
}


/**
 * rand number between -100 and 100
 * @return  -100 <int <100
 */
char get_rand() {
    char rnd = rand() % 200 - 100;
    return rnd;
}

/**
 * se a divisão de numero pelo numero de numeros a serem lidos, 
 * não for divisível pelo numeor de threads, algum thread terá que ler mais
 * numeros que os outros
 * 
 * criar as k threads
 * 
 * @param n, quantidade de numeros total
 * @param k, quantidade de threads
 * @return 
 */
int manage_threads(long *n, int *k) {
    long med = *n / (*k);
    int rest = *n - (med * *k);
    //    printf("DEBUG");
    pthread_t *thread = malloc(sizeof (pthread_t) * *k);
    for (int i = 0; i < *k; i++) {
        sum_args *args = malloc(sizeof (sum_args));
        args->index = med*i;
        args->nb = med;
        pthread_create(&thread[i], NULL, &sum, (void *) args);
    }
    for (int i = 0; i < *k; i++) {
        pthread_join(thread[i], NULL);
    }



    // only enter the loop if rest>0
    if (rest) {
        //        pthread_t *lon_th = malloc(sizeof (pthread_t));
        sum_args * args = malloc(sizeof (sum_args));
        args->index = *k*med;
        args->nb = rest;
        if (pthread_create(&thread[0], NULL, &sum, (void *) args)) { // 3 arg = func to exec 4 arg = arg passed to func
            printf("Error while creating threds. \n");
            exit(EXIT_FAILURE);
        }
        pthread_join(thread[0], NULL);
    }
    return 0;
}

/*
 * 
 */
int main(int argc, char** argv) {
    printf("1st arg:  how many numbers 2nd arg: number of threads\n");
    if (argc != 3) {
        printf("wrong number of arguments [2 args needed] \n");
        return -1;
    }
    run_all();
    return (EXIT_SUCCESS);
}
//

