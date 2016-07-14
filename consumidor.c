#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SENDER_PORT 3490
#define SENDER_IP "127.0.0.1"

bool is_prime(int nb) {
    /*Checks if number nb is prime or not*/
    int i;
    for (i = 2; i <= nb / 2; ++i) {
        // if is divisible for any number rather than 1 or itself, then
        // it is not prime
        if (nb % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {

    int sockfd;
    int rcv_num = 1;
    int num_to_check;
    bool check_result;
    struct sockaddr_in sender_addr;
    // Checks errors
    if( (sockfd = socket(PF_INET, SOCK_STREAM, 0)) ==-1){
        perror("socket error"); 
        exit(1);
    }
    // Opening communication on TCP protocol
    sender_addr.sin_family = AF_INET;
    sender_addr.sin_port = htons(SENDER_PORT);
    sender_addr.sin_addr.s_addr = inet_addr(SENDER_IP);
    memset(sender_addr.sin_zero, '\0', sizeof(sender_addr.sin_zero));
    // Checks errors
    if ((connect(sockfd,(struct sockaddr *)&sender_addr,sizeof(sender_addr))) ==-1){
        perror("connect error"); 
        exit(1);
    }
    // Communication between two processes
    while (rcv_num !=0){
        printf("Listening...\n");    
        rcv_num = recv(sockfd,&num_to_check,sizeof(int),0);
        if(rcv_num!=0) {
            printf("Computing if received value is prime...\n");
            check_result = is_prime(num_to_check);
            send(sockfd,&check_result,sizeof(bool),0);
        }
        else{ 
            close(sockfd);
            exit(0);
        }
    }
}
