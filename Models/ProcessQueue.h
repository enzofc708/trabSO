#include "../Constants/Macros.h"

typedef struct{
    int count;
    Process queue[QUEUE_SIZE];
} ProcessQueue;

ProcessQueue createQueue(){
    ProcessQueue queue;
    queue.count = 0;
    return queue;
}

int isEmptyQueue(ProcessQueue* queue){
    return queue->count;                                                 
}

int isFullQueue(ProcessQueue* queue){
    return (queue->count == QUEUE_SIZE);                                
}

Process popQueue(ProcessQueue* processQueue){
    Process popped = processQueue->queue[processQueue->count - 1];
    processQueue->count--;
    return popped;
}

int pushQueue(ProcessQueue* processQueue, Process p){
    processQueue->queue[processQueue->count++] = p;
}