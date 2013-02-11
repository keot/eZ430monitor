NAME=eZ430monitor
WRITER=mspdebug
REVISION=rf2500
CC=msp430-gcc
CFLAGS=-mmcu=cc430f6137

all: $(NAME)

$(NAME): main.c
	$(CC) $(CFLAGS) main.c -o $(NAME)

install:
	$(WRITER) $(REVISION) "prog $(NAME)"

clean:
	rm -rf main.o
