int getExecTime(Process* p){
    if(p->RemainingTime < QUANTUM_TIME){
        p->State = ExitState;
        return p->RemainingTime;
    }
    else{
        return QUANTUM_TIME;
    }
}