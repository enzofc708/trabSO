typedef struct
{
    //Process List
    ProcessList* processList;

    // Priority Queues
    ProcessList* lowPriorityQueue;
    ProcessList* highPriorityQueue;

    //IO Queues
    ProcessList* printerQueue;
    ProcessList* diskQueue;
    ProcessList* magTapeQueue;

    //Scheduler properties
    int currentIime;
} ProcessScheduler;


ProcessScheduler createScheduler(){
    ProcessScheduler p;

    p.processList = createList();

    p.lowPriorityQueue = createList();
    p.highPriorityQueue = createList();
    p.printerQueue = createList();
    p.diskQueue = createList();
    p.magTapeQueue = createList();

    p.currentIime = 0;
    return p;
}

int isEmpty(ProcessScheduler* scheduler){
    return !scheduler->processList->count;
}

int hasAvailableProcess(ProcessScheduler* scheduler){
    for (int i = 0; i < scheduler->processList->count; i++)
    {
        if(scheduler->processList->processList[i]->State != ExitState){
            return TRUE;
        }
    }
    return FALSE;
    
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

void spendIOTime(ProcessScheduler* scheduler, enum IOs IOType, int time){
    int ioTime;
    Process* chosenProcess;
    ProcessList* IOqueue;
    ProcessList* priorityQueue;

    switch (IOType){
        case DiskIO:
            ioTime = 5;
            IOqueue = scheduler->diskQueue;
            priorityQueue = scheduler->lowPriorityQueue;
            break;
        case PrinterIO:
            ioTime = 10;
            IOqueue = scheduler->printerQueue;
            priorityQueue = scheduler->highPriorityQueue;
            break;
        default:
            ioTime = 15;
            IOqueue = scheduler->magTapeQueue;
            priorityQueue = scheduler->highPriorityQueue;
            break;
    }

    if(!isEmptyList(IOqueue)){

        chosenProcess = popHead(IOqueue);

        if(chosenProcess->IOElapsedTime + time >= ioTime){
            chosenProcess->IOElapsedTime = ioTime;
            chosenProcess->State = ReadyState;
            add(priorityQueue, chosenProcess);
            printf("Process left IO: PID = {%d}", chosenProcess->PID);
        }
        else{
            chosenProcess->IOElapsedTime += time;
            add(IOqueue, chosenProcess);
        }
    }
}

void schedule(ProcessScheduler* p){

     //Add new processes to high priority queue
    ProcessList* newProcesses = getNewProcesses(p);
    
    if(newProcesses->count > 0){
        append(p->highPriorityQueue, newProcesses);
    }

    //Chooses process to gain CPU access
    Process* chosenProcess;
    if(p->highPriorityQueue->count > 0){
        chosenProcess = popHead(p->highPriorityQueue);
    }
    else if(p->lowPriorityQueue->count > 0){
        chosenProcess = popHead(p->lowPriorityQueue);
    }
    else{
        p->currentIime++;

        spendIOTime(p, PrinterIO, 1);
        spendIOTime(p, MagneticTapeIO, 1);
        spendIOTime(p, DiskIO, 1);
        return;
    }

    printf("Process entered CPU: PID = {%d}", chosenProcess->PID);

    //Forward time
    int execTime = getExecTime(chosenProcess);
    chosenProcess->RemainingTime -= execTime;
    p->currentIime += execTime;

    //Treat IOs
    spendIOTime(p, PrinterIO, execTime);
    spendIOTime(p, MagneticTapeIO, execTime);
    spendIOTime(p, DiskIO, execTime);

    //Process treatment
    if(chosenProcess->IOStartTime == (chosenProcess->ExpectedTime - chosenProcess->RemainingTime))
    {
        chosenProcess->State = BlockedState;
        switch(chosenProcess->IOType){
            case DiskIO:
                add(p->diskQueue, chosenProcess);
                break;
            case PrinterIO:
                add(p->printerQueue, chosenProcess);
                break;
            default:
                add(p->magTapeQueue, chosenProcess);
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
        chosenProcess->Priority = LowPriority;
        add(p->lowPriorityQueue, chosenProcess);
        printf("Process preempted: PID = {%d}, Remaining Time = {%d}", chosenProcess->PID, chosenProcess->RemainingTime);
    }



    

}
