//Process States

enum States {
    NewState,                               //Process has just been submitted
    ReadyState,                             //Process is ready for execution
    RunningState,                           //Process is currently running
    BlockedState,                           //Process is awaiting an I/O operation
    ExitState                               //Process has completed
};