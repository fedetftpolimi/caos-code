#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 8
#define MAX_FILES     4

// ---------------- Process Control Block ----------------
typedef struct PCB {
    int pid;
    int state;              // 0=ready, 1=running, 2=waiting
    int pc;                 // fake program counter
} PCB;

// -------------- Global process table ---------------
PCB *ptable[MAX_PROCESSES];
int process_count = 0;

// -------------- Utility ----------------
PCB *create_process() {
    if (process_count >= MAX_PROCESSES) {
        printf("Process table full!\n");
        return NULL;
    }

    PCB *p = malloc(sizeof(PCB));
    p->pid = process_count;
    p->state = 0;   // ready
    p->pc = 0;

    ptable[process_count++] = p;

    printf("Created process PID %d\n", p->pid);
    return p;
}

void list_processes() {
    printf("\nActive Processes:\n");
    for (int i = 0; i < process_count; i++) {
        PCB *p = ptable[i];
        printf("\nPID %d | state=%d | PC=%d", p->pid, p->state, p->pc);
    }
}

int main() {
    PCB *p1 = create_process();
    PCB *p2 = create_process();
    list_processes();

    return 0;
}

