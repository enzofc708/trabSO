// Basic Process Structure

typedef struct
{
    int PID;                    //Process Id, unique to a Process
    int State;                  //Process current state
    int StartTime;              //Time since the process entered into ready queue
    int ExpectedTime;           //Expected time until tasks are completed
    int ExecutedTime;           //Amount of time already executed
    int ExpectedIOTime;         //Expected time spent on I/O operations
    int Priority;               //Process priority
} Process;
