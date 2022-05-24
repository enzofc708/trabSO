#include "Process.h"
#include "../Constants/Settings.h"

typedef struct{
    int count = 0;
    Process queue[QUEUE_SIZE];
} ProcessQueue;

Process queuePop(Processqueue* processQueue){
    Process popped = processQueue->queue[processQueue->count - 1];
    processQueue->count--;
    return popped;
}

Process pushQueue(ProcessQueu)