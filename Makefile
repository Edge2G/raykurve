LDFLAGS = -lraylib -lm
LIBS = ui.c player.c

Compile: main.c
	gcc -o a.out main.c $(LIBS) $(LDFLAGS) -g

test: a.out
	./a.out

clean:
	rm -f a.out