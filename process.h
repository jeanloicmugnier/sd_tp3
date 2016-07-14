/* 
 * File:   process.h
 * Author: Jean-Loïc Mugnier <mugnier at polytech.unice.fr>
 *
 * Created on July 5, 2016, 8:25 PM
 */

#ifndef PROCESS_H
#define	PROCESS_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <unistd.h>
#include <stdio.h>
#include <string.h> 
#include <sys/types.h>
#include "coordinator.h"
#include "file_handler.h"

    static const char* REQUEST = "REQUEST";
    static const char* RELEASE = "RElEASE";

    char* get_sentence(char* thread_id);
    char* routine(char * file_name, int sleep_time);

#ifdef	__cplusplus
}
#endif

#endif	/* PROCESS_H */

