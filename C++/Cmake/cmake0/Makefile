CC = gcc
NAME = main

$(NAME): pipes.o read_pipe.o write_pipe.o
	$(CC) pipes.o read_pipe.o write_pipe.o -o $(NAME)

pipes.o:
	$(CC) -c pipes.c -o pipes.o

read_pipe.o:
	$(CC) -c read_pipe.c -o read_pipe.o

write_pipe.o:
	$(CC) -c write_pipe.c -o write_pipe.o

clean:
	rm $(NAME) *.o