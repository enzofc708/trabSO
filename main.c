#include "Constants/IO.h"
#include "Constants/States.h"
#include "Models/Process.h"
#include "Models/ProcessQueue.h"

#define MAX_PROCESSES 20

//Process Scheduler 
int main(int argc, char const *argv[])
{

    //Process List
    Process processList[MAX_PROCESSES];
    

    //Priority Queues
    ProcessQueue priorityQueue1;
    ProcessQueue priorityQueue2;
    ProcessQueue priorityQueue3;
    ProcessQueue priorityQueue4;
    ProcessQueue priorityQueue5;

    //IO Queues
    ProcessQueue printerQueue;
    ProcessQueue diskQueue;
    ProcessQueue magTapeQueue;

    //Scheduler Properties
    int currentTime = 0;



    return 0;
}
