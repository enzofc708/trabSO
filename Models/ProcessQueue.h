#include "../Constants/Macros.h"

typedef struct{
    int count;
    Process* queue[QUEUE_SIZE];
} ProcessQueue;

ProcessQueue* createQueue(){
    ProcessQueue* queue = (ProcessQueue *) malloc(sizeof(ProcessQueue));
    queue->count = 0;
    return queue;
}

int isEmptyQueue(ProcessQueue* queue){
    return !queue->count;                                                 
}

int isFullQueue(ProcessQueue* queue){
    return (queue->count == QUEUE_SIZE);                                
}

Process* popQueue(ProcessQueue* processQueue){
    Process* popped = processQueue->queue[processQueue->count - 1];
    processQueue->count--;
    return popped;
}

void pushQueue(ProcessQueue* processQueue, Process* p){
    processQueue->queue[processQueue->count++] = p;
}