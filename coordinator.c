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
#include "coordinator.h"
#include "sockets.h"
#include <sys/socket.h>


#define MYPORT 3490
#define SIZE_TO_SEND 1025
#define MY_IP "127.0.0.1"

int write_in_log(char* file_name, char* data) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char* content = malloc(100);
    snprintf(content, 30, "%d:%d:%d %d-%d-%d ", tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    strcat(content, data);
    printf("[+] %s\n", content);
    write_in_file(file_name, "a", content);

    return 0;
}

//int send(pid_t process_id, const char* will) {
//
//    return 0;
//}

//int grant() {
//    return 0;
//}



/**
 * 
 * TODO 
 * receive method with rpc
 * send the msg
 * 
 */

/**
 * 
 * @param nb_processes
 * @return 
 */
int handle_process(int nb_processes) {
    Queue* q = malloc(sizeof (Queue));
    create_queue(q, nb_processes);
    //    Demand * d = malloc(sizeof (Demand));
    //    d->process_id = 0;
    char* will = malloc(10);
    char* data = malloc(14);
    int* socket = 0;
    int* master_socket = (int*) malloc(sizeof (int));
    int* client_socket = malloc(sizeof (int)*nb_processes);
    fd_set *readfds = (fd_set *) malloc(sizeof (fd_set));
    struct sockaddr_in* address = malloc(sizeof (struct sockaddr_in));
    create_queue(q, nb_processes);
    initialize_sockets(master_socket, address, nb_processes, client_socket);
    while (1) {
        *will = wait_event(master_socket, address, readfds, client_socket, nb_processes);
        //        receive(socket, will); // 
        //        if (received) {
        //            data = "";
        //            snprintf(data, 0, "%d %s", d->process_id, d->will);
        //            write_in_log("log.txt", data);
        //        }
        if (!strcmp(REQUEST, will)) {
            if (empty(q)) {
                will = GRANT;
                send(* master_socket, will, strlen(will), 0);
                data = "";
                snprintf(data, 0, "%s %s", "COORD", GRANT);
                write_in_log("log.txt", data);
            }
            add(q, *socket);
        } else if (!strcmp(RELEASE, will)) {
            pop(q);
            if (!empty(q)) {
                //                d->process_id = head(q);
                //                d->will = GRANT;
                //                send(d);
                //                data = "";
                snprintf(data, 0, "%s %s", "COORD", GRANT);
                send(head(q), GRANT, strlen(GRANT), 0);
                write_in_log("log.txt", data);


            }
        }
    }
    return 0;
}
//
//int main() {
//    //    printf("output: %s", get_sentence("Thread 2"));
//    //        handle_process(10);
////    char* data = malloc(10);
////    data = "data";
////    char* file = "test.txt";
////    for (int i = 0; i < 10; i++) {
////        printf("inloop");
//////        snprintf(data, 5, "%d", i);
////        write_in_log(file, data);
////    }
//
//}