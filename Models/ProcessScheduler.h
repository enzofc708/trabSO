typedef struct
{
    //Process List
    ProcessList processList;

    // Priority Queues
    ProcessQueue lowPriorityQueue;
    ProcessQueue highPriorityQueue;

    //IO Queues
    ProcessQueue printerQueue;
    ProcessQueue diskQueue;
    ProcessQueue magTapeQueue;

    //Scheduler properties
    int currentIime;
} ProcessScheduler;


ProcessScheduler createScheduler(){
    ProcessScheduler p;

    p.processList = createList();

    p.lowPriorityQueue = createQueue();
    p.highPriorityQueue = createQueue();
    p.printerQueue = createQueue();
    p.diskQueue = createQueue();
    p.magTapeQueue = createQueue();

    p.currentIime = 0;
    return p;
}

int isEmpty(ProcessScheduler* scheduler){
    return scheduler->processList.count;
}

void schedule(ProcessScheduler* p){

}
