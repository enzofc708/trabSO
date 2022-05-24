// Basic Process Structure

typedef struct
{
    int PID;                    //Process Id, unique to a Process
    int State;                  //Process current state
    int ExpectedTime;           //Expected time until tasks are completed
    int StartTime;              //Time since the process entered into ready queue
    int Priority;               //Process priority
} Process;
