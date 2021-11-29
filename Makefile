all:
	gcc main.c -o tf -Wall -Wpedantic -lm
win:
	winegcc main.c -o tf -Wall -Wpedantic -lm
clear:
	rm tf.* tf
