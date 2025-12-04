#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 256

typedef struct ProcessControlBlock {
  int pid;
  int ppid;
  int state;             // 0=ready, 1=running, 2=waiting
  int pc;                // fake program counter
  int stack[STACK_SIZE]; // Fake stack memory
  int sp;                // Stack pointer as an index
} PCB;

typedef struct ThreadControlBlock {
  int tid;             // Thread ID
  int tgid;            // Thread ID
  int state;           // Running, ready, blocked
} TCB;

int main(int argc, char *argv[]) {
  PCB *p1 = malloc(sizeof(PCB));
  TCB *t1 = malloc(sizeof(TCB));

  // P1 created by INIT (PPID = 1)
  p1->pid = 2;
  p1->ppid = 1;
  p1->state = 0;
  p1->pc = 0;
  p1->sp = STACK_SIZE - 1; // Stack grows downward

  printf("PID: %d, PPID: %d, state: %d, PC=%d, SP=%d\n", p1->pid, p1->ppid, p1->state,
         p1->pc, p1->sp);

  // T1 created by P1 (TGID = PID creating process)
  t1->tid = 3;
  t1->tgid = 2;
  t1->state = 0;
  printf("PID: %d, PPID: %d, state: %d\n", t1->tid, t1->tgid, t1->state);

  return 0;
}
