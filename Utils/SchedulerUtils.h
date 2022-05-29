int getExecTime(Process* p){
    int IOTime = p->IOStartTime - (p->ExpectedTime - p->RemainingTime);
    if(IOTime < p->RemainingTime && IOTime < QUANTUM_TIME && IOTime > 0){
        return IOTime;
    }
    else if(p->RemainingTime < QUANTUM_TIME && p->RemainingTime > 0){
        return p->RemainingTime;
    }
    else{
        return QUANTUM_TIME;
    }
}