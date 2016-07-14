/* 
 * File:   activity.h
 * Author: Jean-Loïc Mugnier <mugnier at polytech.unice.fr>
 *
 * Created on July 13, 2016, 11:05 AM
 */

#ifndef ACTIVITY_H
#define	ACTIVITY_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "process.h"
#include "coordinator.h"
#include <sys/types.h>
#include <signal.h>

    typedef struct ExecParam {
        char* filename;
        int nb_proc_arr[8];
        int nb_wrtes;
        int proc_max_slp;
        int gap_btw_proc_arr[2];
    } ExecParam;
#include <unistd.h>


    float next_float(int max);
    int start_bulk(int k, char* file_name, int nb_writes, int slp_tm_proc, pid_t* processes);
    int start_system(int k, char* file_name, int nb_writes, int slp_tm_proc, int gap_btw_proc);
    int run_experiment(ExecParam * expar);
    int start_seq(int k, char* file_name, int nb_writes, int slp_tm_proc, int gap_btw_proc, pid_t* processes);

#ifdef	__cplusplus
}
#endif

#endif	/* ACTIVITY_H */

