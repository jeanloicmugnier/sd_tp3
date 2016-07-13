#include "process.h"
#include "file_handler.h"
#include <stdlib.h>
#include "communication.h"

int request() {
    Demand * d = malloc(sizeof (Demand));
    d->process_id = getpid();
    d->will = REQUEST;
    send(d);
    return 0;
}

int release() {
    Demand * d = malloc(sizeof (Demand));
    d->process_id = getpid();
    d->will = RELEASE;
    send(d);
    return 0;
}

char* get_sentence(char* thread_id) {
    char* string = malloc(50);
    char* mario = "It's me, Mario: ";
    strcat(string, mario);
    strcat(string, thread_id);
    return string;
}

/**
 * process routine. 
 * Send request to coordinator
 * (NOT IMPLEMENTED) wait for the grant from the coordinator
 * write in the file the sentence from sentence and its pid
 * sleeps after 
 * @param file_name
 * @param sleep_time
 * @return 
 */
char* routine(char * file_name, int sleep_time) {
    // get coord id (parent)
    sleep(sleep_time);
    pid_t this_pid = getpid();
    //    printf("pid %lu", this_pid);
    //
    Demand * d = malloc(sizeof (Demand));
    d->process_id = this_pid;
    d->will = REQUEST;
    //    d.process_id = getpid();
    //    //    d->will = request;
    send(d);
    //    printf("after sending routine");
    //
    char * id = malloc(sizeof (long unsigned) + 1);
    long l = (long) getpid();
    //
    snprintf(id, 10, "%lu", l);
    //    printf("snprintf %s",id);
    id = get_sentence(id);
    //    printf("before write in file");
    write_in_file(file_name, "a", id);
    //    printf("after write in file");
    return 0;
}

//int main() {
//    char* file_name = "test.txt";
//    printf("before routine");
//    routine(file_name, 5);
//
//}