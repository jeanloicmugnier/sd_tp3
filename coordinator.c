#include <semaphore.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>
#include "file_handler.h"
#include "process.h"
#include "queue.h"
#include "coordinator.h"
#include "communication.h"
#include <time.h>

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
    Demand * d = malloc(sizeof (Demand));
    d->process_id = 0;
    d->will = "";
    create_queue(q, nb_processes);
    while (1) {
        d = receive();
        if (!strcmp(request, d->will)) {
            if (empty(q)) {
                d->will = GRANT;
                send(d);
            }
            add(q, d->process_id);
        } else if (!strcmp(release, d->will)) {
            pop(q);
            if (!empty(q)) {

                d->process_id = head(q);
                d->will = GRANT;
                send(d);
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