CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -g

OBJDIR = obj
SRCDIR = src
LIB_DIR = libmx
LIB_NAME = $(LIB_DIR)/libmx.a
LIB = $(LIB_NAME)
PATHFINDER = pathfinder

SRC = $(SRCDIR)/*.c
OBJS = $(OBJDIR)/*.o

all: $(LIB) $(PATHFINDER)

$(PATHFINDER):
	mkdir $(OBJDIR)
	$(CC) $(CFLAGS) -c $(SRC)
	mv *.o $(OBJDIR)
	$(CC) -o $(PATHFINDER) $(OBJS) -L$(LIB_DIR) $(LIB_NAME)

$(LIB):
	make -sC $(LIB_DIR)

clean:
	rm -f $(OBJS)
	rm -df $(OBJDIR)

uninstall:
	make -sC $(LIB_DIR) $@
	make clean
	rm -f $(PATHFINDER)

reinstall:
	make uninstall
	make all
