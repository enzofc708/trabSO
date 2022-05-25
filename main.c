#include "Constants/IO.h"
#include "Constants/States.h"
#include "Models/Process.h"
#include "Models/ProcessQueue.h"
#include "Models/ProcessList.h"

#define MAX_PROCESSES 20

//Process Scheduler 
int main(int argc, char const *argv[])
{

    //Process List
    ProcessList processList = createList();
    

    //Priority Queues
    ProcessQueue priorityQueue1 = createQueue();
    ProcessQueue priorityQueue2 = createQueue();
    ProcessQueue priorityQueue3 = createQueue();
    ProcessQueue priorityQueue4 = createQueue();
    ProcessQueue priorityQueue5 = createQueue();

    //IO Queues
    ProcessQueue printerQueue = createQueue();
    ProcessQueue diskQueue = createQueue();
    ProcessQueue magTapeQueue = createQueue();

    //Scheduler Properties
    int currentTime = 0; 

    //Scheduler
    while(!isEmptyList(&processList))
    {
        
    }
    

    return 0;
}
