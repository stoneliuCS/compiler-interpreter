CFLAGS = $(shell pkg-config --cflags glib-2.0)
LFLAGS = $(shell pkg-config --libs glib-2.0)
UFLAGS = -I$(CURDIR)/lib

LIB = $(CURDIR)/lib/file.c
SOURCE = main.c $(LIB)

all: compile

compile:
	gcc $(CFLAGS) $(UFLAGS) $(SOURCE) -o main $(LFLAGS)

clean:
	rm -rf main.o
