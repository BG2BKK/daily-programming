CC = g++
LD = g++
CFLAGS = -Wall -c 
LDFLAGS = -lpthread

SRCS = $(wildcard *.cpp ./*.cpp)
OBJS = $(patsubst %cpp, %o, $(SRCS))
TARGET = main

.PHONY: all clean

all: $(TARGET)

.o.cpp:
	$(CC) $(CFLAGS) -o $@ $<

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGET)
