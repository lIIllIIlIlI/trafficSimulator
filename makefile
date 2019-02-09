CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=
SOURCES=main.cpp Fahrzeug.cpp PKW.cpp Fahrrad.cpp AktivesVO.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Verkehrsnetz

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(binaries) *.o
