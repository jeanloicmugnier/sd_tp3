//
//#include "coordinator.h"
//#include "process.h"
//#include <string.h>
//#include <stdlib.h>
//#include "communication.h"
//#include "queue.h"
//
//int send(int* socket, char will, Queue* q) {
//    // send message to coordinator to get the right to write
//    // RPC -> coord
//    if (!strcmp(REQUEST, will)) {// different
//        add(q,get);
//    } else if (!strcmp(RELEASE, will)) {
//        pop(q);
//        // remove the process from the queue.
//    } else if (!strcmp(GRANT, will)) {
//
//    }
//    send(socket, will, strlen(will), 0);
//    return 0;
//}
//
///**
// * receive message from process
// * @return if receive a message return !=0
// * else return 0
// */
//int receive() {
//    Demand * d = malloc(sizeof (Demand));
//    d->process_id = 0;
//    d->will = "";
//    // RPC waiting to read the msg
//    return 0;
//}