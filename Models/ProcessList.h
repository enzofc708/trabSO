typedef struct{
    Process* processList[MAX_PROCESSES];
    int count;
} ProcessList;

ProcessList* createList(){
    ProcessList* list = (ProcessList *) malloc(sizeof(ProcessList));
    list->count = 0;
    return list;
}

int isEmptyList(ProcessList* list){
    return list->count;   
}

void add(ProcessList* list, Process* p){
    list->processList[list->count++] = p;
}

void removeFromIndex(ProcessList* list, int index){
    for (int i = index; i < list->count - 1; i++)
    {
         list->processList[i] = list->processList[i+1];
    }
    list->count--;
}

int hasNotDoneProcess(ProcessList* list){
    for (int i = 0; i < list->count; i++)
    {
        if(list->processList[i]->State != ExitState){
            return TRUE;
        }
    }
    return FALSE;
}

void append(ProcessQueue* p1, ProcessList* p2){
    for (int i = 0; i < p2->count; i++)
    {
        pushQueue(p1, p2->processList[i]);
    }    
}