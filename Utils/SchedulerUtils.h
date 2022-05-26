int getExecTime(Process* p, int currentTime){
    if(p->IOStartTime > currentTime && 
       p->IOStartTime - currentTime < p->RemainingTime &&
       p->IOStartTime - currentTime < QUANTUM_TIME){
           p->State = BlockedState;
           return (p->IOStartTime - currentTime);
    }
    else if(p->RemainingTime < QUANTUM_TIME){
        p->State = ExitState;
        return p->RemainingTime;
    }
    else{
        return QUANTUM_TIME;
    }
}