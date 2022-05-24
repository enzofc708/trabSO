#include "Process.h"
#include "../Constants/Settings.h"

typedef struct{
    int count = 0;
    Process queue[QUEUE_SIZE];
} ProcessQueue;

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