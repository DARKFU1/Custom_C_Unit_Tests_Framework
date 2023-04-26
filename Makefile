.PHONY: all init build clean

.DEFAULT_GOAL := build

DOBJ = obj
DSRC = src
DTEST = test
DBIN = bin

COMPILER_FLAGS = -g -DCOLOR_LOGS

SRC = main.c\
      log.c\

OBJ = $(patsubst %.c, ${DOBJ}/%.o, $(SRC))

all: init build

init:
	-@mkdir obj/
	-@mkdir test/
	-@mkdir bin/

build: $(OBJ)
	gcc $(COMPILER_FLAGS) $^ -o out

$(DOBJ)/%.o: $(DSRC)/%.c
	gcc -c $(COMPILER_FLAGS) $< -o $@

clean:
	-@rm -f obj/*
	-@rm -f test/*
	-@rm -f bin/*
