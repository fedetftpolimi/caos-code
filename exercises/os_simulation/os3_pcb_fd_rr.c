#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 8
#define MAX_FILES     4

// ---------------- File Descriptor ----------------
typedef struct FileDescriptor {
  int fd;                 // ID
  char filename[32];      // File name
  int flags;              // 0 = read, 1 = write
  long position;          // Offset
} FileDescriptor;

// ---------------- Process Control Block ----------------
typedef struct PCB {
  int pid;
  int state;              // 0=ready, 1=running, 2=waiting
  int pc;                 // fake program counter
  FileDescriptor *fd_table[MAX_FILES];
  int fd_count;

  /* NEW*/
  int time_quantum;
  int remaining_time;
  /* END*/
} PCB;

// -------------- Global process table ---------------
PCB *ptable[MAX_PROCESSES];
int process_count = 0;

/* NEW, Running Process*/
PCB *running = NULL;
PCB *ready_queue[MAX_PROCESSES];
int rq_head = 0;
int rq_tail = 0;
int SYSTEM_TIME = 0;
/* END*/

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

  p->fd_count = 0;
  for (int i = 0; i < MAX_FILES; i++) p->fd_table[i] = NULL;
  ptable[process_count++] = p;

  p->time_quantum = 3;   // each process gets 3 seconds
  p->remaining_time = 3; // start full

  printf("Created process PID %d\n", p->pid);
  return p;
}

void enqueue(PCB *p) {
  ready_queue[rq_tail] = p;
  rq_tail = (rq_tail + 1) % MAX_PROCESSES;
}

PCB *dequeue() {
  if (rq_head == rq_tail)
    return NULL; // empty
  PCB *p = ready_queue[rq_head];
  rq_head = (rq_head + 1) % MAX_PROCESSES;
  return p;
}

FileDescriptor *open_file(PCB *p, const char *name, int flags) {
  if (p->fd_count >= MAX_FILES) {
    printf("Process %d file table full!\n", p->pid);
    return NULL;
  }

  FileDescriptor *fd = malloc(sizeof(FileDescriptor));
  fd->fd = p->fd_count;
  strcpy(fd->filename, name);
  fd->flags = flags;
  fd->position = 0;

  p->fd_table[p->fd_count] = fd;
  p->fd_count++;

  printf("Process %d opened file '%s' (fd=%d)\n", p->pid, name, fd->fd);
  return fd;
}

// Very simple round-robin scheduler
void schedule() {
  printf("\n--- Scheduler invoked ---\n");

  // Put old running process back in queue (if exists)
  if (running != NULL) {
    running->state = 0;                              // ready
    running->remaining_time = running->time_quantum; // reset
    enqueue(running);
    printf("Process %d moved to back of queue.\n", running->pid);
  }

  // Select next ready process
  running = dequeue();

  if (running != NULL) {
    running->state = 1; // running
    printf("Process %d is now running.\n", running->pid);
  }
  else{
    // Select INIT process
  }
  // print all the processes in RQ
  for (int i = 0; i < process_count; i++) {
    PCB *p = ptable[i];
    printf("PID %d, state: %d, PC=%d\n", p->pid, p->state, p->pc);
  }
}

void list_processes() {
  printf("\nActive Processes:\n");
  for (int i = 0; i < process_count; i++) {
    PCB *p = ptable[i];
    printf("PID %d | state=%d | PC=%d | files=%d\n", p->pid, p->state, p->pc, p->fd_count);
  }
}

int main() {
  PCB *p1 = create_process();
  PCB *p2 = create_process();
  PCB *p3 = create_process();
  PCB *p4 = create_process();
  PCB *p5 = create_process();

  // We put all processes in the runqueue
  for (int i = 0; i < process_count; i++) {
    PCB *p = ptable[i];
    enqueue(p);
  }

  open_file(p1, "data.txt", 0);
  open_file(p1, "out.log", 1);
  open_file(p2, "config.ini", 0);

  list_processes();
  while (1) {
    sleep(2);
    SYSTEM_TIME++;

    printf("\n[TIME %d]\n", SYSTEM_TIME);

    // If no running process, schedule one
    if (running == NULL) {
      printf("No running process, scheduling\n");
      schedule();
      continue;
    }

    // Running process executes
    running->pc++;
    running->remaining_time--;

    // Quantum expired?
    if (running->remaining_time <= 0) {
      printf("PID %d quantum expired.\n", running->pid);
      schedule();
    }
  }

  return 0;
}
