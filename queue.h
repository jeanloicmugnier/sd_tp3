/* 
 * File:   queue.h
 * Author: Jean-Loïc Mugnier <mugnier at polytech.unice.fr>
 *
 * Created on July 5, 2016, 8:50 PM
 */

#ifndef QUEUE_H
#define	QUEUE_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>


#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct Queue {
        int capacity;
        pid_t* process_id;
        int first;
        int last;
        int nb;


    } Queue;

    void create_queue(struct Queue *q, int capacity);
    int add(struct Queue *q, int value);
    int pop(struct Queue *q);
    int empty(struct Queue *q);
    int full(struct Queue *q);
    void show(struct Queue *q);
    int head(struct Queue *q);


#ifdef	__cplusplus
}
#endif

#endif	/* QUEUE_H */

