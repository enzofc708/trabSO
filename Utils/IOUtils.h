void spendIOTime(ProcessQueue* queue, enum IOs IOType, int time){
    int ioTime;
    Process* chosenProcess;

    if(!isEmptyQueue(queue)){
        switch (IOType){
            case DiskIO:
                ioTime = 5;
                break;
            case PrinterIO:
                ioTime = 10;
            default:
                ioTime = 15;
                break;
        }
        chosenProcess = popQueue(queue);

        if(chosenProcess->IOElapsedTime + time > ioTime){
            chosenProcess->IOElapsedTime = ioTime;
            chosenProcess->State = ReadyState;
            printf("Process left IO: PID = {%d}", chosenProcess->PID);
        }
        else{
            chosenProcess->IOElapsedTime += time;
            pushQueue(queue, chosenProcess);
        }
    }
}