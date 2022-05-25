// Basic Process Structure

typedef struct
{
    int PID;                    //Process Id, unique to a Process
    enum States State;          //Process current state
    int StartTime;              //Time since the process entered into ready queue
    int ExpectedTime;           //Expected time until tasks are completed
    int ExecutedTime;           //Amount of time already executed
    enum IOs IOType;            //IO operation type
    int ExecutedIOTime;         //Amount of time already executed on I/O operations (??)
    enum Priorities Priority;   //Process priority
} Process;


Process createProcess(int _PID, int _StartTime, int _ExpectedTime, enum IOs _IOType){
    Process p;
    
    p.PID = _PID;
    p.State = NewState;
    p.StartTime = _StartTime;
    p.ExpectedTime = _ExpectedTime;
    p.ExecutedTime = 0;
    p.IOType = _IOType;
    p.ExecutedIOTime = 0;
    p.Priority = HighPriority;

    return p;
}