CC=gcc
CFLAG=-Wall -g
LIB_COMMAND=ar -rc

SRCDIR=src
OBJDIR=obj
LIBDIR=lib
BINDIR=bin

BIN=$(BINDIR)/main
LIB=$(LIBDIR)/algos.a

VPATH=$(SRCDIR)

SOURCE=$(wildcard $(SRCDIR)/*.c)
OBJECT=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o, $(SOURCE))

all: $(BIN)

$(BIN): $(OBJECT)
	$(CC) $(CFLAG) $(OBJECT) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAG) -c $< -o $@

lib: $(BIN)
	$(LIB_COMMAND) $(LIB) $(OBJECT)

.PHONY: run
.PHONY: clean

run: $(BIN)
	./$(BIN)
clean:
	rm ./obj/* ./bin/*

