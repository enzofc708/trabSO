int getExecTime(Process* p){
    //ToDo: Alterar esse cara pra detectar se tem processo querendo sair de IO
    if(p->IOStartTime - (p->ExpectedTime - p->RemainingTime) > 0 && 
       p->IOStartTime - (p->ExpectedTime - p->RemainingTime) < QUANTUM_TIME){
           return p->IOStartTime - (p->ExpectedTime - p->RemainingTime);
    }
    else if(p->RemainingTime < QUANTUM_TIME){
        return p->RemainingTime;
    }
    else{
        return QUANTUM_TIME;
    }
}