CC = g++
CFLAGS = -std=c++17
SRCS = main.cpp

execute: $(SRCS)
	$(CC) $(CFLAGS) -o run $(SRCS)

test: execute
	./run

clean:
	rm -f run
