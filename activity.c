#include <sys/types.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/wait.h>


#include "activity.h"

/**
 * 
 * @param k, number of processes to create
 * @param routine, routine that the pr
 * @param params,
 * @param gap_btw_proc 0 bulk arrival or >0 for  sequencial arrival 
 * @return 
 */
int start_system(int k, char* file_name, int nb_writes, int slp_tm_proc, int gap_btw_proc) {
    printf("activity start system\n");

    printf("before malloc processes\n");
    pid_t* processes = malloc(sizeof (pid_t) * k);
    printf("aftermalloc processes\n");

    if (gap_btw_proc) {
        start_seq(k, file_name, nb_writes, slp_tm_proc, gap_btw_proc, processes);
    } else {
        //        start_bulk(k, file_name, nb_writes, slp_tm_proc, processes);
    }
    return 0;
}

int start_bulk(int k, char* file_name, int nb_writes, int slp_tm_proc, pid_t* processes) {
    int i;
    for (i = 0; i < k; i++) {
        pid_t this = fork();
        processes[i] = this;
        //        printf("this pid: %d\n", this);
        if (this) {// child
            routine(file_name, slp_tm_proc);
            kill_em_all(processes);
            return 0;
            if (i == k - 1) { // if bulk arrival and last iteration
                // call the coordinator process handling function
                handle_process(k);
                return 0;
            }
        } else {
            wait(-1);

        }

    }
    return 0;
}

int start_seq(int k, char* file_name, int nb_writes, int slp_tm_proc, int gap_btw_proc, pid_t* processes) {
    int i, first = 1;
    for (i = 0; i < k; i++) {
        sleep(gap_btw_proc);
        pid_t this = fork();
        printf("pid %d\n", getpid());

        processes[i] = this;
        if (first && this) {// primeiro processo filho

            printf("pid %d handle processs\n", getpid());
            handle_process(k);
            i--; // perde um pro coordenador
            first = 0;
            return 0;
        }
        //        printf("this pid: %d\n", this);
        if (this) {// child not coordenador
            printf("pid %lu ROUTINE\n", (long) getpid());
            while (nb_writes--) {
                printf("pid %lu STILL %d", (long) getpid(), nb_writes);
                routine(file_name, slp_tm_proc);
            }
            return 0;
        }
        if (!this) {//parent process
            wait(-1);
        }
    }
    return 0;
}

int kill_em_all(pid_t* processes) {
    int i;
    int size = sizeof (processes) / sizeof (processes[0]);
    for (i = 0; i < size; i++) {
        kill(processes[i], SIGKILL);
    }
    return 0;
}

float next_float(int max) {
    float f = (float) rand() / (float) (RAND_MAX / max);
    return f;
}

int run_experiment(ExecParam * expar) {
    int ind_nb_proc;
    int nb_proc_length = sizeof (expar->nb_proc_arr) / sizeof (expar->nb_proc_arr[0]);
    int nb_pr; // PARAM
    int gap_btw_pr; // PARAM
    int gap_btw_proc_length = sizeof (expar->gap_btw_proc_arr) / sizeof (expar->gap_btw_proc_arr[0]);
    int ind_tm_btw_proc;
    printf("bf loop\n");

    for (ind_nb_proc = 0; ind_nb_proc < nb_proc_length; ind_nb_proc++) {
        nb_pr = expar->nb_proc_arr[ind_nb_proc];

        for (ind_tm_btw_proc = 0; gap_btw_proc_length > ind_tm_btw_proc; ind_tm_btw_proc++) {
            gap_btw_pr = expar->gap_btw_proc_arr[ind_tm_btw_proc];
            printf("bf start system, last in activity\n");

            start_system(nb_pr, (expar->filename), (expar->nb_wrtes), next_float(expar->proc_max_slp), gap_btw_pr);
            break; // remove
        }
        break; // remove

    }
    return 0;

}
