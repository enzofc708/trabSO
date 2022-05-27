void spendIOTime(ProcessList* list, enum IOs IOType, int time){
    int ioTime;
    Process* chosenProcess;

    if(!isEmptyList(list)){
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
        chosenProcess = popHead(list);

        if(chosenProcess->IOElapsedTime + time > ioTime){
            chosenProcess->IOElapsedTime = ioTime;
            chosenProcess->State = ReadyState;
            printf("Process left IO: PID = {%d}", chosenProcess->PID);
        }
        else{
            chosenProcess->IOElapsedTime += time;
            add(list, chosenProcess);
        }
    }
}