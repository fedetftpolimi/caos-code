
all:
	gcc -Wall -fsanitize=address -O2 -o hello hello.c
	gcc -Wall -fsanitize=address -O2 -o args args.c
	gcc -Wall -fsanitize=address -O2 -o filesize filesize.c
	gcc -Wall -fsanitize=address -O2 -o redirect redirect.c
	gcc -Wall -fsanitize=address -O2 -o cwd cwd.c
	gcc -Wall -fsanitize=address -O2 -o dirlist dirlist.c

clean:
	rm hello args filesize redirect cwd dirlist
