void createProcesses(ProcessScheduler* scheduler, int n){
    
    for(int i = 1; i <= n; i++){
        Process* p = createProcess(i);
        add(scheduler->processList, p);
    }
}