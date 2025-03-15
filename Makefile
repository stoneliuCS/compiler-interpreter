# BEGIN GLIB LINKING
CFLAGS = $(shell pkg-config --cflags glib-2.0) $(shell pkg-config --cflags cunit)
LFLAGS = $(shell pkg-config --libs glib-2.0) $(shell pkg-config --libs cunit)

# BEGIN USER DEFINED LINKS TO HEADERS
LIB_FLAGS = -I/$(CURDIR)/lib
FRONTEND_FLAGS = -I/$(CURDIR)/frontend
UFLAGS = $(LIB_FLAGS) $(FRONTEND_FLAGS)

# COMPILE TARGETS
LIB = $(CURDIR)/lib/*.c
FRONTEND = $(CURDIR)/frontend/*.c
SOURCE = main.c $(LIB) $(FRONTEND)
TEST = $(LIB) $(FRONTEND) $(CURDIR)/tests/harness.c

all: compile

compile:
	gcc $(CFLAGS) $(UFLAGS) $(SOURCE) -o main.o $(LFLAGS)

test:
	gcc $(CFLAGS) $(UFLAGS) $(TEST) -o test.o $(LFLAGS) && ./test.o

clean:
	rm -rf *.o
