# Exercises

Exercises grouped by topic, one folder per topic.

Compile with `gcc file.c -o file.out` (add `-pthread` for the threads
exercises, and `-lm` for `mandelbrot.c`). Some exercises expect the `.out`
name, e.g. `exec_ex.c` runs `./args_printing.out`.

## C recap ([`c/`](c))

### Flowcharts and control flow
1. [Comparison](c/comparison.c)
2. [Repeated comparison](c/comparison_loop.c)
3. [Average](c/average.c)
4. [Repeated average](c/average_loop.c)
5. [Square of a number](c/square.c)
6. [Return value of `main`](c/main_return.c)
7. [Command-line arguments](c/args.c)

### Arrays and functions
1. [Max and min](c/max_min.c)
2. [Max and min with functions](c/max_min_functions.c)
3. [Fibonacci](c/fibonacci.c)

### Pointers and strings
1. [Pointers](c/pointers.c)
2. [`void*` pointers](c/pointers2.c)
3. [String compare](c/string_compare.c)
4. [String split with `strtok`](c/string_split.c)

### Structs
1. [Student](c/struct_student.c)
2. [Student with pointers](c/struct_student_pointers.c)
3. [Student with courses](c/struct_student_pointers_courses.c)
4. [PCB and TCB](c/struct_pcb_tcb.c)

## OS simulation ([`os_simulation/`](os_simulation))
Each step extends the previous one.
1. [Process table with PCBs](os_simulation/os0_pcb.c)
2. [+ File descriptors](os_simulation/os1_pcb_fd.c)
3. [+ Round-robin scheduler](os_simulation/os2_pcb_fd_rr.c)
4. [+ Ready queue and time quantum](os_simulation/os3_pcb_fd_rr.c)

## File system ([`filesystem/`](filesystem))

### Intro
Run in order: each one uses the files created by the previous ones.
1. [Symbolic link](filesystem/symlinks.c)
2. [Unlink](filesystem/unlink.c)
3. [Write to file](filesystem/file_write.c)
4. [Read from file](filesystem/file_read.c)
5. [Remove directory](filesystem/rmdir.c)
6. [Change working directory](../lessons/filesystem/cwd.c)

### Directories
1. [Create directory](filesystem/createdir.c)
2. [Check if a directory exists](filesystem/direxists.c)
3. [Create a file inside a directory](filesystem/createfileindir.c)
4. [Files inside directory](filesystem/filesindir.c)
5. [Count files](filesystem/countfiles.c)
6. [List files by extension](filesystem/listextension.c)

## Processes ([`processes/`](processes))

### Fork
1. [Observe a process with htop](processes/simple.c)
2. [Fork and pid](processes/forkpid.c)
3. [Fork tree 1](processes/fork_tree1.c)
4. [Fork tree 2](processes/fork_tree2.c)
5. [Fork tree 3](processes/fork_tree3.c)
6. [Fork tree 3, visualized](processes/fork_tree3_visualize.c)
7. [Memory sharing](processes/var_sharing.c)

### Exec
1. [Print arguments](processes/args_printing.c) (build as `args_printing.out`)
2. [`execl`](processes/exec_ex.c)
3. [`execl` vs `execlp`](processes/exec_ex2.c)

### Wait and zombies
1. [`wait`, `waitpid` and exit status](processes/fork_wait.c)
2. [Zombie](processes/zombie.c)
3. [Zombies from a loop](processes/zombie2.c)

### Putting it together
1. [Shell (with bugs)](processes/shell_bugous.c)
2. [Shell](processes/shell.c)
3. [Parallel search in chunks](processes/chunk_search.c)

## Threads ([`threads/`](threads))
1. [Thread IDs](threads/pthread_ids.c)
2. [Estimating π with a mutex](threads/pi.c)
3. [Charging station, bug 1](threads/charging_bug1.c)
4. [Charging station, bug 2](threads/charging_bug2.c)
5. [Charging station, fixed with a condition variable](threads/charging_fix.c)
6. [Condition variable](threads/cond_ex.c)
7. [Parallel Mandelbrot](threads/mandelbrot.c)
