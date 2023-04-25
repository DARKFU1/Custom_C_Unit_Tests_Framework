.PHONY: all init build clean

.DEFAULT_GOAL := build

DOBJ = obj
DSRC = src
DTEST = test
DBIN = bin

COMPILER_FLAGS = -g -DCOLOR_LOGS
# COMPILER_FLAGS = -g

SRC = main.c\

OBJ = $(patsubst %.c, ${DOBJ}/%.o, $(SRC))

all: init build

init:
	-@mkdir obj/
	-@mkdir test/
	-@mkdir bin/

build: $(OBJ)
	@printf "\033[1;92m"
	gcc $(COMPILER_FLAGS) $^ -o $(DBIN)/out
	@printf "\033[0m"

$(DOBJ)/%.o: $(DSRC)/%.c
	@printf "\033[0;32m"
	gcc -c $(COMPILER_FLAGS) $< -o $@

clean:
	-@rm -f obj/*
	-@rm -f test/*
	-@rm -f bin/*
