/* 
 * File:   main.c
 * Author: Jean-Loïc Mugnier <mugnier at polytech.unice.fr>
 *
 * Created on July 13, 2016, 11:03 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "activity.h"

/*
 * 
 */
int main(int argc, char** argv) {

    char* file_name = "test.txt";
    int nb_writes = 10; // each process need to write 10 times.
    int nb_proc = 2; // each process need to write 10 times.
    int gap_btw_proc = 4; // time between the arrival of 2 processes. bulk arrival.
    int slp_tm_proc = 2; // time between the arrival of 2 processes. bulk arrival.
    //    void * routine;
    //    void * params;
    create_processes(nb_proc, file_name, nb_writes, slp_tm_proc, gap_btw_proc);

    return (EXIT_SUCCESS);
}

