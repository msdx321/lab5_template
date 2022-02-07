CC      = gcc
CFLAGS  = -g -Wall -Wextra -Werror

all: test

pipe: pipe_answer.c
	@$(CC) $(CFLAGS) -o pipe pipe.c

parsing: parsing_answer.c
	@$(CC) $(CFLAGS) -o parsing parsing.c

test_parsing: parsing
	@echo "Testing parsing"
	@./parsing	

test_pipe: pipe
	@echo "Testing pipe"
	@./pipe

test: test_parsing test_pipe

clean:
	rm -rf ./*.o
	rm -rf ./pipe ./parsing

.PHONY: clean all
