#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <string.h>

/**
 * [+4]
 * @param name
 * @param mode, append or empty-first
 * @param cont
 */
void write_in_file(char * path, char* mode, char* cont) {
    FILE *f = fopen(path, mode);
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    /* print some text */
    fprintf(f, "%s\n", cont);
    fclose(f);
}

/**
 * 
 * @param path
 * @param mode
 */
FILE * open_file(char * path, char* mode) {
    FILE *f = fopen(path, mode);
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    return f;
}

