/* 
 * File:   main.c
 * Author: Jean-Loïc Mugnier <mugnier at polytech.unice.fr>
 *
 * Created on June 22, 2016, 9:47 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * The client and server program must include (#include "rpcprog.h"
compile the client code:
cc -c  rpcprog.c
compile the client stub:
cc -c  rpcprog_clnt.c
compile the XDR filter:
cc -c  rpcprog_xdr.c
build the client executable:
cc -o rpcprog rpcprog.o rpcprog_clnt.o rpcprog_xdr.c
compile the service procedures:
cc -c  rpcsvc.c
compile the server stub:
cc -c  rpcprog_svc.c
build the server executable:
cc -o rpcsvc rpcsvc.o rpcprog_svc.o rpcprog_xdr.c
Now simply run the programs rpcprog and rpcsvc on the client and server respectively.

 */
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

