// Basic Process Structure

typedef struct
{
    int PID;                    //Process Id, unique to a Process
    enum States State;          //Process current state
    int StartTime;              //Time when process entered the ready queue
    int ExpectedTime;           //Expected time until tasks are completed
    int RemainingTime;          //Amount of time until completion
    enum IOs IOType;            //IO operation type
    int IOStartTime;            //Time when process entered the IO queue
    int IOElapsedTime;          //Time process spent in IO queue
} Process;


Process* createProcess(int _PID){
    Process* p = (Process *) malloc(sizeof(Process));

    const char *ioTypes[] = {"PrinterIO", "MagneticTapeIO", "DiskIO"};
    
    p->PID = _PID;
    p->State = NewState;
    p->StartTime = rand() % 10;
    p->ExpectedTime = rand() % 10 + 3;
    p->RemainingTime = p->ExpectedTime;
    p->IOType = rand() % 3;
    p->IOStartTime = rand() % (p->ExpectedTime - 1) + 1;
    p->IOElapsedTime = 0;

    printf("_____________________\n");
    printf("Process %d created\n", p->PID);
    printf("Start time: %d\n", p->StartTime);
    printf("IO type: %s\n",ioTypes[p->IOType]);
    printf("IO start time: %d\n", p->IOStartTime);
    printf("_____________________\n");
    printf("\n");

    return p;
}