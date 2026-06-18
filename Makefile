VPATH %.c srcs 
VPATH %.h includes

CC = gcc
CFLAG = -Wall -Wextra -Werror 
DEBUG = -g

compile_gcc_v1_0 : main.c, shm-scanner.h utils.c parser.c component.c 
	$(CC) $(CFLAG) $? -o $@

compile_gdb : main.c shm-scanner.h utils.c parser.c component.c 
	$(CC) $(DEBUG) $(CFLAG) $? -o $@

clean:
	rm -rf *.o

info:
	exec 3 > "README.md"
	while IFS= read -r line;do
		echo "$(line) \n"
	done < &3
	exec 3>&-
