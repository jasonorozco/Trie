CC=g++ -std=c++11
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp Trie.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=PA01

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


