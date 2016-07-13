#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "process.h"

/**
 * 
 * @param k, number of processes to create
 * @param routine, routine that the pr
 * @param params,
 * @param gap_btw_proc 0 bulk arrival or >0 for  sequencial arrival 
 * @return 
 */
int start_system(int k, char* file_name, int nb_writes, int slp_tm_proc, int gap_btw_proc) {
    pid_t* processes = malloc(sizeof (pid_t) * k);
    int i;
    int first = 1;
    if (gap_btw_proc) {
        start_seq(k, file_name, nb_writes, slp_tm_proc, gap_btw_proc, processes);
    } else {
        start_bulk(k, file_name, nb_writes, slp_tm_proc, processes);
    }

}

int start_bulk(int k, char* file_name, int nb_writes, int slp_tm_proc, pid_t* processes) {
    int i;
    for (i = 0; i < k; i++) {
        pid_t this = fork();
        processes[i] = this;
        //        printf("this pid: %d\n", this);
        if (this) {// child
            routine(file_name, slp_tm_proc);
            return 0;
        } else {    
            //  if == 0 -> parent process
            // parent passes here k times
            if (i == k - 1) { // if bulk arrival and last iteration
                // call the coordinator process handling function
                handle_process(k);
                return 0;
            }
        }

    }
    return 0;
}

int start_seq(int k, char* file_name, int nb_writes, int slp_tm_proc, int gap_btw_proc, pid_t* processes) {
    int i, first = 1;
    for (i = 0; i < k; i++) {
        pid_t this = fork();
        processes[i] = this;
        if (first && this) {// primeiro processo filho

            handle_process(k);
            i--; // perde um pro coordenador
            first = 0;
            return 0;
        }
        //        printf("this pid: %d\n", this);
        if (this) {// child not coordenador
            routine(file_name, slp_tm_proc);
            return 0;
        }
    }
    return 0;
}

