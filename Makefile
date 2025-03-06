all: compile

compile:
	gcc $(pkg-config --cflags --libs glib-2.0) main.c
