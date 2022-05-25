// Basic Process Structure

typedef struct
{
    int PID;                    //Process Id, unique to a Process
    enum States State;          //Process current state
    int StartTime;              //Time since the process entered into ready queue
    int ExpectedTime;           //Expected time until tasks are completed
    int ExecutedTime;           //Amount of time already executed
    enum IOs IOType;            //IO operation type
    int IOStartTime;            //Time since the process entered into IO queue
    enum Priorities Priority;   //Process priority
} Process;


Process createProcess(int _PID, int _StartTime, int _ExpectedTime, int _IOStartTime, enum IOs _IOType){
    Process p;
    
    p.PID = _PID;
    p.State = NewState;
    p.StartTime = _StartTime;
    p.ExpectedTime = _ExpectedTime;
    p.ExecutedTime = 0;
    p.IOType = _IOType;
    p.IOStartTime = _IOStartTime;
    p.Priority = HighPriority;

    return p;
}