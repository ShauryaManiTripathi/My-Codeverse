#include <stdio.h>
#include <stdlib.h>

#define maximum_processes 1000
typedef struct
{
    char *name;
    int arrival;
    int cpu_burst;
    int turnaround;
    int wait;
    int time_received;
    int finished;
    int timeCompleted;

} Process;

typedef struct
{
    Process **processes;
    int numberOfProcesses;
} ProcessArray;

ProcessArray *readProcessesFromFile(const char *filename)
{
    // Opening the file to read
    FILE *file = fopen(filename, "r");

    // Initialising the Processes Array
    ProcessArray *pa = (ProcessArray *)malloc(sizeof(ProcessArray));
    pa->processes = (typeof(pa->processes))calloc(maximum_processes, sizeof(Process));
    pa->numberOfProcesses = 0;

    char input[25];

    while (fgets(input, 25, file))
    {
        char *processName = (typeof(char *))malloc(5 * sizeof(char));
        int arrival, cpuBurst;
        sscanf(input, "%s %d %d\n", processName, &arrival, &cpuBurst);
        printf("%s %d %d\n", processName, arrival, cpuBurst);
        Process *p = (Process *)malloc(sizeof(Process));
        p->name = processName;
        p->arrival = arrival;
        p->cpu_burst = cpuBurst;
        p->wait = 0;
        p->turnaround = -1;
        p->time_received = 0;
        p->finished = 0;
        p->timeCompleted = -1;
        pa->processes[pa->numberOfProcesses++] = p; // Adding the process to the array
    }
    return pa;
};

void printProcessTable(ProcessArray *pa)
{
    for (int i = 0; i < pa->numberOfProcesses; i++)
    {
        printf("Process Name: %s\n", pa->processes[i]->name);
        printf("Arrival: %d || ", pa->processes[i]->arrival);
        printf("CPU Burst: %d || ", pa->processes[i]->cpu_burst);
        printf("Turnaround: %d || ", pa->processes[i]->turnaround);
        printf("Wait: %d || ", pa->processes[i]->wait);
        printf("Time Completed: %d \n", pa->processes[i]->timeCompleted);
    }
}

void SRBF(ProcessArray *pa)
{
    int proc_count = pa->numberOfProcesses;
    printf("Assuming the processes are in order of their arrival time\n");
    int active_procs_remaining_bTime[proc_count];
    int has_been_run[proc_count];
    int start_time[proc_count];
    int end_time[proc_count];
    for (int i = 0; i < proc_count; i++)
    {
        active_procs_remaining_bTime[i] = 0;
        has_been_run[i] = 0;
        start_time[i] = 0;
        end_time[i] = 0;
    }
    int next_to_be_initialized = 0;
    int curr_time = -1;
    int active = -1;
    int finished_proc_count = 0;
    printf("%d\n", proc_count);
    int t = 50;
    while (++curr_time || 1)
    {
        if (0 > (t--))
            break;
        // printing current stats------------------------------------------
        printf("Active: %d, BTime of Active: %d, Total Completed Processes: %d, Current Time: %d\n", active, active_procs_remaining_bTime[active], finished_proc_count, curr_time);
        // breaking on completion of all processes-------------------------
        if (proc_count == finished_proc_count)
            break;
        // doing something when the active is finished---------------------
        if (active >= 0)
            if (active_procs_remaining_bTime[active] == 0)
            {
                if (end_time[active] == 0)
                {
                    end_time[active] = curr_time;
                    pa->processes[active]->timeCompleted = end_time[active];
                    pa->processes[active]->turnaround = end_time[active] - start_time[active];
                    finished_proc_count++;
                    active = -1;
                }
            }
        // if something is going to be initialized-------------------------
        while (next_to_be_initialized < proc_count)
            if (pa->processes[next_to_be_initialized]->arrival == curr_time)
            {
                active_procs_remaining_bTime[next_to_be_initialized] = pa->processes[next_to_be_initialized]->cpu_burst;
                next_to_be_initialized++;
            }
            else{
                break;
            }
        // finding the next active process--------------------------------
        for (int i = 0; i < proc_count; i++)
        {

            if (active_procs_remaining_bTime[i] > 0)
            {
                if (active < 0)
                    active = i;
                else
                {
                    if (active_procs_remaining_bTime[active] > active_procs_remaining_bTime[i])
                    {
                        active = i;
                    }
                }
            }
        }
        // if a process is not running->wait time is incremented---------
        for (int i = 0; i < proc_count; i++)
        {
            if (i != active && active_procs_remaining_bTime[i] != 0)
                pa->processes[i]->wait++;
        }
        // setting has_been_run and start_time for the active process----
        if (has_been_run[active] == 0)
        {
            start_time[active] = curr_time;
            has_been_run[active] = 1;
        }
        // decrementing the remaining burst time of the active process---
        active_procs_remaining_bTime[active]--;
        // printing the active process-----------------------------------
    }
}

int main()
{
    int currentTime = 0, completed_process = 0;
    ProcessArray *pa = readProcessesFromFile("processes.txt");
    printProcessTable(pa);
    SRBF(pa);
    printProcessTable(pa);
}