#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MYPORT 3490
#define SIZE_TO_SEND 1000
#define MY_IP "127.0.0.1"

int main(int argc, char *argv[]) {

    struct sockaddr_in my_addr,rcvr_addr;
    struct timeval start,end;
    int sockfd, sockfd2;
    int rand_number = 1;
    int sin_size = sizeof(my_addr),optval;
    bool prime_check;
    long n_to_generate;
    // Retrieving number of random numbers to be generated. 5 by default
    if (argc >= 2){
        n_to_generate = strtol(argv[1], NULL, 10);
    }
    else
        n_to_generate = 5;
    // Setting socket
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(MYPORT);
    my_addr.sin_addr.s_addr = inet_addr(MY_IP);
    memset(my_addr.sin_zero, '\0', sizeof(my_addr.sin_zero));
    // Checks for errors 
    optval = 1;
    if( (sockfd = socket(PF_INET, SOCK_STREAM, 0)) ==-1){
        perror("socket error");
        exit(1);
    }
    if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr) == -1) {
        perror("bind");
        exit(1);
    }
    listen(sockfd,10);
    sockfd2 = accept(sockfd, (struct sockaddr *)&rcvr_addr, &sin_size);
    // Implementing communication between two proccesses
    while(n_to_generate>0){
        n_to_generate--;
        rand_number += (rand() % 100);
        printf("Submiting random number for analysis\n");
        send(sockfd2,&rand_number,sizeof(int),0);
        optval=recv(sockfd2,&prime_check,sizeof(bool),0);
        if (prime_check)
            printf("%d is prime\n", rand_number);
        else
            printf("%d is not prime\n", rand_number);
    }
    // Closing sockets
    shutdown(sockfd2,2);
    shutdown(sockfd,2);
    exit(0);
}
