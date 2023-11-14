
all:
	gcc -Wall -fsanitize=address -O2 -o thread1 thread1.c
	gcc -Wall -fsanitize=address -O2 -o thread2 thread2.c
	gcc -Wall -fsanitize=address -O2 -o thread3 thread3.c
	gcc -Wall -fsanitize=address -O2 -o thread4 thread4.c
	gcc -Wall -fsanitize=address -O2 -o thread5 thread5.c
	gcc -Wall -fsanitize=address -O2 -o semaphore1 semaphore1.c
	gcc -Wall -fsanitize=address -O2 -o semaphore2 semaphore2.c
	gcc -Wall -fsanitize=address -O2 -o mutex1 mutex1.c
	gcc -Wall -fsanitize=address -O2 -o prodconsumer1 prodconsumer1.c
	#gcc -Wall -fsanitize=address -O2 -o prodconsumer2 prodconsumer2.c

clean:
	rm -f thread1 thread2 thread3 thread4 thread5 semaphore1 semaphore2 mutex1 prodconsumer1 prodconsumer2
