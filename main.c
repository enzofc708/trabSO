#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "Constants/IO.h"
#include "Constants/States.h"
#include "Constants/Macros.h"
#include "Constants/Priorities.h"
#include "Models/Process.h"
#include "Models/ProcessQueue.h"
#include "Models/ProcessList.h"
#include "Utils/SchedulerUtils.h"
#include "Models/ProcessScheduler.h"
#include "Utils/ProcessUtils.h"

//Process Scheduler 
int main(int argc, char const *argv[])
{
    //Seed random generator
    srand(time(NULL));

    //Scheduler
    ProcessScheduler scheduler = createScheduler();

    //Get arguments from console
    if(argc < 2){
        printf("Usage: %s <number_of_processes>\n", argv[0]);
        return 1;
    }

    int num_processes = atoi(argv[1]);

    if(num_processes > 20){
        printf("Number of processes should not be greater than 20.\n");
        return 1;
    }
    else if (num_processes < 0)
    {
        printf("Number of processes should not be less than 0.\n");
        return 1;
    }
    

    createProcesses(&scheduler, atoi(argv[1]));

    while(hasAvailableProcess(&scheduler))
    {
        schedule(&scheduler);
    }    

    return 0;
}
