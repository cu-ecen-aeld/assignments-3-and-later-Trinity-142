COMPILER = gcc

ifdef CROSS_COMPILE
	COMPILER = $(CROSS_COMPILE)gcc
endif

FLAGS = -g -Wall

all: writer 

writer: writer.o 
	$(COMPILER) $(FLAGS) -o $@ $^ 

writer.o: writer.c
	$(COMPILER) $(FLAGS) -c $^ -o $@

clean:
	rm -f writer writer.o 

.PHONY: all clean
