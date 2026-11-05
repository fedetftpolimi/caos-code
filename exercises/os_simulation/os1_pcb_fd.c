
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    //*NEW*/
    p->fd_count = 0;
    for (int i = 0; i < MAX_FILES; i++) p->fd_table[i] = NULL;
    //*END*/

    ptable[process_count++] = p;

    printf("Created process PID %d\n", p->pid);
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

void list_processes() {
  printf("\nActive Processes:\n");
  for (int i = 0; i < process_count; i++) {
    PCB *p = ptable[i];
    printf("PID %d | state=%d | PC=%d | files=%d\n", p->pid, p->state, p->pc,
           p->fd_count);
  }
}

int main() {
  PCB *p1 = create_process();
  PCB *p2 = create_process();

  open_file(p1, "data.txt", 0);
  open_file(p1, "out.log", 1);
  open_file(p2, "config.ini", 0);

  list_processes();

  return 0;
}
