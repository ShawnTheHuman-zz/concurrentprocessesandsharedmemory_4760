# Shawn brown
# makefile


CC      = g++
CFLAGS  = -std=c++11 -g -Wall -Wshadow


EXEC1 := runsim
SRC1 := license.c runsim.c
OBJ1 := $(patsubst %.cpp, %.o, $(SRC1))

all: $(EXEC1)

$(EXEC1): $(OBJ1)
        $(CC) $(CFLAGS) -o $(EXEC1) $(OBJ1)

EXEC2 := testsim
SRC2 :=  license.ctestsim.c
OBJ2 := $(patsubst %.cpp, %.o, $(SRC2))

all: $(EXEC2)

$(EXEC2): $(OBJ2)
        $(CC) $(CFLAGS) -o $(EXEC2) $(OBJ2)


.PHONY: clean

clean:
        rm -f $(EXEC1) $(EXEC2) *.o logfile
