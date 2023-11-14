
all:
	gcc -Wall -fsanitize=address -O2 -o args args.c
	gcc -Wall -fsanitize=address -O2 -o fork1 fork1.c
	gcc -Wall -fsanitize=address -O2 -o fork2 fork2.c
	gcc -Wall -fsanitize=address -O2 -o fork3 fork3.c
	gcc -Wall -fsanitize=address -O2 -o fork4 fork4.c
	gcc -Wall -fsanitize=address -O2 -o exec1 exec1.c
	gcc -Wall -fsanitize=address -O2 -o exec2 exec2.c
	gcc -Wall -fsanitize=address -O2 -o forkexec1 forkexec1.c

clean:
	rm args fork1 fork2 fork3 fork4 exec1 exec2 forkexec1
