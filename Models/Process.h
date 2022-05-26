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
    enum Priorities Priority;   //Process priority
} Process;


Process* createProcess(int _PID, int _StartTime, int _ExpectedTime, int _IOStartTime, enum IOs _IOType){
    Process* p = (Process *) malloc(sizeof(Process));
    
    p->PID = _PID;
    p->State = NewState;
    p->StartTime = _StartTime;
    p->ExpectedTime = _ExpectedTime;
    p->RemainingTime = _ExpectedTime;
    p->IOType = _IOType;
    p->IOStartTime = _IOStartTime;
    p->IOElapsedTime = 0;
    p->Priority = HighPriority;

    return p;
}