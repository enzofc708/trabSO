#include "Process.h"
#include "../Constants/Settings.h"

typedef struct{
    int count = 0;
    Process queue[QUEUE_SIZE];
} ProcessQueue;

Process queuePop(ProcessQueue* processQueue){
    if(processQueue->count > 0){
        Process popped = processQueue->queue[processQueue->count - 1];
        processQueue->count--;
        return popped;
    }
    else{
        
    }
}

void pushQueue(ProcessQueue* processQueue, Process p){
    processQueue->queue[processQueue->count] = p;
    processQueue->count++;
}