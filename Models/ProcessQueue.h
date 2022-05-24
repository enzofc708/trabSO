#include "Process.h"

#define QUEUE_SIZE 10

typedef struct{
    int count;
    Process queue[QUEUE_SIZE];
} ProcessQueue;

ProcessQueue createQueue(){
    ProcessQueue queue;
    queue.count = 0;
    return queue;
}

bool isEmpty(ProcessQueue queue){
    
}

Process popQueue(ProcessQueue* processQueue){
    if(processQueue->count > 0){
        Process popped = processQueue->queue[processQueue->count - 1];
        processQueue->count--;
        return popped;
    }
    else{
        return NULL;
    }
}

int pushQueue(ProcessQueue* processQueue, Process p){
    if(processQueue->count < QUEUE_SIZE){
        processQueue->queue[processQueue->count++] = p;
        return processQueue->count;
    }
    else{
        return -1;
    }
}