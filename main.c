/* 
 * File:   main.c
 * Author: Jean-Loïc Mugnier <mugnier at polytech.unice.fr>
 *
 * Created on July 13, 2016, 11:03 AM
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "activity.h"

/*
 * 
 */
int main(int argc, char** argv) {

    srand(time(NULL));
    int K[8] = {1, 2, 4, 8, 16, 32, 64, 128}; // number of processes
    int X = 100; //numero de frases
    int Y[2] = {0, 1}; // intervalo de entrada
    char* file_name = "test.txt";
    //    int nb_proc = 2; // each process need to write 10 times.
    //    int gap_btw_proc = 4; // time between the arrival of 2 processes. bulk arrival.
    //    int slp_tm_proc = next_float(Y); // time between the arrival of 2 processes. bulk arrival.
    ExecParam * expa = malloc(sizeof (ExecParam));
    //    expa->nb_proc_arr = &K;
    memcpy(expa->nb_proc_arr, K, sizeof expa->nb_proc_arr);
    expa->filename = file_name;
    memcpy(expa->gap_btw_proc_arr, Y, sizeof expa->gap_btw_proc_arr);
    //    expa->gap_btw_proc_arr = &Y;
    expa->nb_wrtes = X;
    expa->proc_max_slp = 1;
    printf("bf run_experimental\n");
    run_experiment(expa);

    return (EXIT_SUCCESS);
}

