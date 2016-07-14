/* 
 * File:   sockets.h
 * Author: Jean-Loïc Mugnier <mugnier at polytech.unice.fr>
 *
 * Created on July 13, 2016, 10:12 PM
 */

#ifndef SOCKETS_H
#define	SOCKETS_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <sys/select.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>   //strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>   //close
#include <arpa/inet.h>    //close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <sys/time.h> 
    //    typdef struct sockaddr_in;
    int wait_event(int* master_socket, struct sockaddr_in * address, fd_set* readfds, int* client_socket, int max_clients);

    int initialize_sockets(int* master_socket, struct sockaddr_in* address, int nb_clients, int* client_socket);
    int initialize_socket();




#ifdef	__cplusplus
}
#endif

#endif	/* SOCKETS_H */

