void createExample1(ProcessScheduler* scheduler){
    Process p1 = createProcess(1, 0, 10, 4, DiskIO);
    Process p2 = createProcess(2, 8, 10, 6, DiskIO);
    Process p3 = createProcess(3, 10, 8, 7, DiskIO);

    add(&scheduler->processList, p1);
    add(&scheduler->processList, p2);
    add(&scheduler->processList, p3);
}