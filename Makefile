CFLAGS = $(shell pkg-config --cflags glib-2.0)
LFLAGS = $(shell pkg-config --libs glib-2.0)

all: compile

compile:
	gcc $(CFLAGS) main.c -o main.o
