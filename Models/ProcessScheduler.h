typedef struct
{
    //Process List
    ProcessList* processList;

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
    return !scheduler->processList->count;
}

ProcessList* getNewProcesses(ProcessScheduler* p){
    ProcessList* newProcesses = createList();
    for (int i = 0; i < p->processList->count; i++)
    {
        if(p->processList->processList[i]->State == NewState &&
           p->processList->processList[i]->StartTime <= p->currentIime &&
           p->processList->count < MAX_PROCESSES){
               p->processList->processList[i]->State = ReadyState;
               p->processList->processList[i]->Priority = HighPriority;
            add(newProcesses, p->processList->processList[i]);
        }
    }
    return newProcesses;
}  

void schedule(ProcessScheduler* p){

     //Add new processes to high priority queue
    ProcessList* newProcesses = getNewProcesses(p);
    
    if(newProcesses->count > 0){
        append(&p->highPriorityQueue, p->processList);
    }

    //Chooses process to gain CPU access
    Process* chosenProcess;
    if(p->highPriorityQueue.count > 0){
        chosenProcess = popQueue(&p->highPriorityQueue);
    }
    else if(p->lowPriorityQueue.count > 0){
        chosenProcess = popQueue(&p->lowPriorityQueue);
    }
    else{
        return;
    }

    printf("Process entered CPU: PID = {%d}", chosenProcess->PID);

    //Forward time
    int execTime = getExecTime(chosenProcess);
    chosenProcess->RemainingTime -= execTime;
    p->currentIime += execTime;

    //Process treatment
    if(chosenProcess->IOStartTime == (chosenProcess->ExpectedTime - chosenProcess->RemainingTime))
    {
        chosenProcess->State = BlockedState;
        switch(chosenProcess->IOType){
            case DiskIO:
                pushQueue(&p->diskQueue, chosenProcess);
                break;
            case PrinterIO:
                pushQueue(&p->printerQueue, chosenProcess);
                break;
            default:
                pushQueue(&p->magTapeQueue, chosenProcess);
                break;
        }
        printf("Process entered IO: PID = {%d}", chosenProcess->PID);
    }
    else if(chosenProcess->RemainingTime == 0){
        chosenProcess->State = ExitState;
        printf("Process finished: PID = {%d}, Time = {%d}", chosenProcess->PID, p->currentIime);
    }
    else{
        chosenProcess->State = ReadyState;
        printf("Process preempted: PID = {%d}, Remaining Time = {%d}", chosenProcess->PID, chosenProcess->RemainingTime);
    }

    //Treat IOs
    spendIOTime(&p->printerQueue, PrinterIO, execTime);
    spendIOTime(&p->magTapeQueue, MagneticTapeIO, execTime);
    spendIOTime(&p->diskQueue, DiskIO, execTime);

    

}
