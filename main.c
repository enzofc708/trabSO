#include "Constants/IO.h"
#include "Constants/States.h"
#include "Constants/Macros.h"
#include "Constants/Priorities.h"
#include "Models/Process.h"
#include "Models/ProcessQueue.h"
#include "Models/ProcessList.h"
#include "Models/ProcessScheduler.h"
#include "Examples/Example1.h"

#include <time.h>
#include <stdlib.h>


//Process Scheduler 
int main(int argc, char const *argv[])
{
    //Seed random generator
    srand(time(NULL));

    //Scheduler
    ProcessScheduler scheduler = createScheduler();

    while(!isEmpty(&scheduler))
    {
        
    }    

    return 0;
}
