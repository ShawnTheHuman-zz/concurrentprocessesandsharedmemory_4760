# Shawn brown
# makefile


CC      = g++
CFLAGS  = -std=c++11 -g -Wall -Wshadow


EXEC2 := testsim
SRC2 := testsim.c license.c
OBJ2 := $(patsubst %.cpp, %.o, $(SRC2))	

all: $(EXEC2)

$(EXEC2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(EXEC2) $(OBJ2)

EXEC1 := runsim
SRC1 := runsim.c license.c
OBJ1 := $(patsubst %.cpp, %.o, $(SRC1))	

all: $(EXEC1)

$(EXEC1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(EXEC1) $(OBJ1)



.PHONY: clean

clean:
	rm -f $(EXEC1) $(EXEC2) *.o logfile
