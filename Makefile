
CC = g++
MAINSRCS = p5.cpp
OTHSRCS =
HEADERS = p5.h
SRCS = $(MAINSRCS) $(OTHSRCS)
OBJS = $(SRCS:.cpp=.o)
TARGETS = $(MAINSRCS:.cpp=)
MEMCHECKARGS = < files/g1.in

CFLAGS = -g -Wall

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $< 

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGETS) $(OBJS)

memcheck: $(TARGETS)
	valgrind --leak-check=full ./$(TARGETS) $(MEMCHECKARGS) 
	
clean:
	rm -f $(OBJS) $(TARGETS)

.PHONY: all memcheck clean
