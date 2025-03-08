# BEGIN GLIB LINKING
CFLAGS = $(shell pkg-config --cflags glib-2.0)
LFLAGS = $(shell pkg-config --libs glib-2.0)

# BEGIN USER DEFINED LINKS TO HEADERS
LIB_FLAGS = -I/$(CURDIR)/lib
FRONTEND_FLAGS = -I/$(CURDIR)/frontend
UFLAGS = $(LIB_FLAGS) $(FRONTEND_FLAGS)

# COMPILE TARGETS
LIB = $(CURDIR)/lib/*.c
FRONTEND = $(CURDIR)/frontend/*.c
SOURCE = main.c $(LIB) $(FRONTEND)

all: compile

compile:
	gcc $(CFLAGS) $(UFLAGS) $(SOURCE) -o main.o $(LFLAGS)

clean:
	rm -rf main.o
