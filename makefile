CC=gcc
CFLAGS= -g -Wall -Wshadow
DEPS= license.c config.h runsim.c testsim.c
OBJ= runsim.o testsim.o license.o
EXEC= runsim testsim

ass2: $(EXEC)

$(EXEC): %: %.o license.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ): %.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	 rm -f $(EXEC) *.o logfile
