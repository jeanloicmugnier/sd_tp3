#include "coordinator.h"
#include "process.h"
#include <string.h>
#include <stdlib.h>

int send(Demand * d) {
    // send message to coordinator to get the right to write
    // RPC -> coord
    if (!strcmp(request, d->will)) {// different
        // send request msg
    } else if (!strcmp(release, d->will)) {
        // send release msg
    }
    return 0;
}

Demand * receive() {
    Demand * d = malloc(sizeof (Demand));
    d->process_id = 0;
    d->will = "";
    // RPC waiting to read the msg
    return d;
}