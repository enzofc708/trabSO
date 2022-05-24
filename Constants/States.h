//Process States

const char* newState = "New";               //Process has just been submitted
const char* readyState = "Ready";           //Process is ready for execution
const char* runningState = "Running";       //Process is currently running
const char* blockedState = "Blocked";       //Process is awaiting an I/O operation
const char* exitState = "Exit";             //Process has completed