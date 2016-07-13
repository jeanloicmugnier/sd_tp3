#include "queue.h"

void create_queue(Queue *q, int capacity) {

    q->capacity = capacity;
    q->process_id = (pid_t*) malloc(q->capacity * sizeof (pid_t));
    q->first = 0;
    q->last = -1;
    q->nb = 0;

}

int add(Queue *q, int value) {
    int cap = q->nb;
    if (cap == q->capacity) {
        perror("Queue is full");
        return -1;
    } else {
        q->last++;
        q->process_id[q->last] = value;
        q->nb++;
    }
    return 0;
}

int pop(Queue *q) {

    int tmp = q->process_id[q->first];

    for (int i = 1; i < q->nb; i++) {
        q->process_id[i - 1] = q->process_id[i];
    }
    
    q->nb--;
    return tmp;

}

int head(Queue *q) {
    return q->process_id[q->first];
}

int empty(Queue *q) {
    return (q->nb == 0);

}

int full(Queue *q) {

    return (q->nb == q->capacity);
}

void show(Queue *q) {

    int count, i;

    for (count = 0, i = q->first; count < q->nb; count++) {

        printf("%.2d\t", q->process_id[i++]);

        if (i == q->capacity)
            i = 0;

    }
    printf("\n\n");

}

//int main() {
//    Queue* q = (Queue*) malloc(sizeof (Queue));
//    create_queue(q, 5);
//    printf("empty %d\n", empty(q));
//    add(q, 1000);
//    add(q, 500);
//    add(q, 3);
//    add(q, 4);
//    add(q, 5);
//    printf("full %d", full(q));
//    add(q, 2);
//    show(q);
//    int d = head(q);
//    printf("head %d\n", d);
//    printf("pop %d\n", pop(q));
//    printf("pop %d\n", pop(q));
//    printf("pop %d\n", pop(q));
//
//
//}
