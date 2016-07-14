/* 
 * File:   coordinator.h
 * Author: Jean-Loïc Mugnier <mugnier at polytech.unice.fr>
 *
 * Created on July 5, 2016, 8:48 PM
 */
#ifndef COORDINATOR_H
#define	COORDINATOR_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <unistd.h>
#include <sys/types.h> 
#include <semaphore.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h> 
#include <time.h>
#include "file_handler.h"
#include "process.h"
#include "queue.h"
#include "communication.h"

    typedef struct {
        pid_t process_id;
        char* will;
    } Demand;

    static const char * GRANT = "GRANT";


    int write_in_log(char* file_name, char* data);
    int handle_process(int nb_processes);

#ifdef	__cplusplus
}
#endif

#endif	/* COORDINATOR_H */

