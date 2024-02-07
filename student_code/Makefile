EXE = kshell
FLAGS = -g -Wall -Wextra -include stdbool.h
SRCS = kshell.c

all: $(EXE)

$(EXE) : $(SRCS)
	gcc $(SRCS) $(FLAGS) -o $@

clean:
	rm -f $(EXE)
