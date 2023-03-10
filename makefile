LINKS = -L./lib -lfftw3-3 -lfftw3f-3 -lfftw3l-3

APPLY_IR = $(wildcard ApplyIR/*.c)

UTILS = $(wildcard utils/*.c)

all:
	gcc $(LINKS) -o./bin/all

dbg:
	gcc $(LINKS) -Wall -o./bin/dbg -g

apply_ir:
	gcc $(UTILS) $(APPLY_IR) $(LINKS) -Wall -o./bin/apply_ir -g