CFLAGSS = -std=c++17 -02

LDFLAGS = 

makeProg: main.cpp
	g++ $(CFLAGS) -o execute main.cpp $(LDFLAGS)

.PHONY: test clean


test: makeProg
	./execute
	
clean:
	rm -f execute

