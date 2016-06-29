CC = gcc
LD = gcc
CFLAGS = -Wall -c -g -O0
LDFLAGS = -lpthread

SRCS = $(wildcard *.c source/*.c)
OBJS = $(patsubst %c, %o, $(SRCS))

TARGET=main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

%o: %c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *~ *.o $(TARGET)
