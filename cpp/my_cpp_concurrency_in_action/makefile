CFLAGS= -g -O0 
LIBS = -lpthread
C_SRC = $(wildcard *.c)
C_OBJ = $(patsubst %c, %o, $(C_SRC))
CPP_SRC = $(wildcard *.cpp)
CPP_OBJ = $(patsubst %cpp, %o, $(CPP_SRC))

.PHONY:all clean

all:$(CPP_OBJ) $(C_OBJ)

.c.o:
	gcc $(CFLAGS) -o $@ $< $(LIBS) 
.cpp.o:
	g++ $(CFLAGS) -std=c++11 -o $@ $< $(LIBS)


clean:
	rm *~ *.o -f
	rm out -f

