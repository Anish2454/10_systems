all: 10.c
	gcc -g -o processes 10.c

run: all
	./processes
