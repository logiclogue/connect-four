CC=gcc
CFLAGS=-Wall -c
BUILDFLAGS=
LDFLAGS=
DIRBUILD=build
DIRSRC=src
DIRTESTS=tests
SOURCES=$(shell ls $(DIRSRC)/*.c $(DIRTESTS)/*.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLES=$(DIRBUILD)/main $(DIRBUILD)/tests

all: BUILDFLAGS=-DBUILD_MAIN 
all: $(SOURCES) $(DIRBUILD)/main

$(EXECUTABLES): $(OBJECTS)
	mkdir -p $(DIRBUILD)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(BUILDFLAGS) $(CFLAGS) $< -o $@

install:
	clib install jeradesign/minunit

tests: BUILDFLAGS=-DBUILD_TESTS
tests: $(SOURCES) $(DIRBUILD)/tests

clean:
	rm $(OBJECTS) $(EXECUTABLE) $(TEST_OBJECTS) $(TEST_EXECUTABLE)

.PHONY: clean tests all install $(DIRSRC)/main.c $(DIRTESTS)/main.c
