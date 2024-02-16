#include <stdio.h>
#include <stdlib.h>

#define maximum_processes 1000
typedef struct {
    char *name;
    int arrival;
    int cpu_burst;
    int turnaround;
    int wait;
    int time_received;
    int finished;
    int timeCompleted;


} Process;

typedef struct {
    Process **processes;
    int numberOfProcesses;
} ProcessArray;

ProcessArray *readProcessesFromFile(char *filename) {
    //Opening the file to read
    FILE *file = fopen(filename, "r");

    //Initialising the Processes Array
    ProcessArray *pa = malloc(sizeof(ProcessArray));
    pa->processes = calloc(maximum_processes, sizeof(Process));
    pa->numberOfProcesses = 0;


    char input[25];

    while (fgets(input, 25, file)) {
        char *processName = malloc(5 * sizeof(char));
        int arrival, cpuBurst;
        sscanf(input, "%s %d %d\n", processName, &arrival, &cpuBurst);
        printf("%s %d %d\n", processName, arrival, cpuBurst);
        Process *p = malloc(sizeof(Process));
        p->name = processName;
        p->arrival = arrival;
        p->cpu_burst = cpuBurst;
        p->wait = -1;
        p->turnaround = -1;
        p->time_received=0;
        p->finished=0;
        p->timeCompleted=-1;
        pa->processes[pa->numberOfProcesses++] = p; // Adding the process to the array
    }
    return pa;


};

void printProcessTable(ProcessArray *pa) {
    for (int i = 0; i < pa->numberOfProcesses; i++) {
        printf("Process Name: %s\n", pa->processes[i]->name);
        printf("Arrival: %d || ", pa->processes[i]->arrival);
        printf("CPU Burst: %d || ", pa->processes[i]->cpu_burst);
        printf("Turnaround: %d || ", pa->processes[i]->turnaround);
        printf("Wait: %d || ", pa->processes[i]->wait);
        printf("Time Completed: %d \n", pa->processes[i]->timeCompleted);

    }
}
/*
int main() {
    ProcessArray *pa = readProcessesFromFile("/Users/georgerahul/Desktop/OS-Lab/Scheduling Algorithms/processes.txt");
    printProcessTable(pa);

    return 0;
}
 */

void FCFS() {
    int currentTime = 0, current_process_number = 0;
    ProcessArray *process_table = readProcessesFromFile("processes.txt");

    while (current_process_number < process_table->numberOfProcesses) {
        Process *current_process = process_table->processes[current_process_number];
        if (currentTime > current_process->arrival) {
            //This means that the process has already arrived
            current_process->wait = currentTime - current_process->arrival;
            current_process->turnaround = current_process->wait + current_process->cpu_burst;


        } else {
            // This means that we have to increase the current time to match the next arrival time.
            //This is because process arrive in order
            currentTime=current_process->arrival;
            current_process->wait = 0;
            current_process->turnaround = current_process->cpu_burst;
        }
        current_process_number++;
        currentTime += current_process->cpu_burst;
        current_process->timeCompleted=currentTime;
    }
    printProcessTable(process_table);


}

int main() {
    FCFS();
    return 0;
}