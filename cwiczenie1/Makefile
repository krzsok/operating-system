TARGET=target
SRCS=$(shell ls *.c)
OBJS=$(SRCS:.c=.o)
CFLAGS = 
LIBS= -lm # <stdio.h> <sys/types.h> <unistd.h> <stdlib.h>

all: clean main

main: $(TARGET)
	${CC} ${CFLAGS} ${OBJS} -o 3.out
run1: 3
	./3.out
$(TARGET):$(OBJS)
clean:
	rm -f *.o $(TARGET)

.PHONY: all clean
