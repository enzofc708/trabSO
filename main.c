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
#include "Examples/Examples.h"


//Process Scheduler 
int main(int argc, char const *argv[])
{
    //Seed random generator
    srand(time(NULL));

    //Scheduler
    ProcessScheduler scheduler = createScheduler();

    //segundo parâmetro é a quantidade de processos
    createExample1(&scheduler, 5);

    while(hasAvailableProcess(&scheduler))
    {
        schedule(&scheduler);
    }    

    return 0;
}
