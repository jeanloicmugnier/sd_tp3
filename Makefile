#Para escrever comentários ##
############################# Makefile ##########################
all: activity
activity: main.o coordinator.o process.o activity.o file_handler.o communication.o queue.o
        # O compilador faz a ligação entre os dois objetos
        gcc -o activity coordinator.o process.o activity.o file_handler.o communication.o queue.o
#-----> Distancia com o botão TAB ### e não com espaços
coordinator.o: coordinator.c
        gcc -o coordinator.o -c queue.c communication.c file_handler.c coordinator.c -W -Wall -std=c99 -pedantic
main.o: main.c 
        gcc -o main.o -c main.c activity.c process.c file_handler.c  -W -Wall -ansi -pedantic
clean:
        rm -rf *.o
mrproper: clean
        rm -rf teste