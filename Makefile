CFLAGS = $(shell pkg-config --cflags glib-2.0)
LFLAGS = $(shell pkg-config --libs glib-2.0)
UFLAGS = -I$(CURDIR)/lib

all: compile

compile:
	gcc $(CFLAGS) $(UFLAGS) main.c lib/file.c -o main $(LFLAGS)

clean:
	rm -rf main.o
