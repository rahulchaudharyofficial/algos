CC=gcc
CFLAG=-Wall -g
LIB_COMMAND=ar -rc

SRCDIR=src
OBJDIR=obj
LIBDIR=lib
BINDIR=bin

TEST=tests
TESTBIN=$(TEST)/bin
TESTS=$(wildcard $(TEST)/*.c)
TESTBINS=$(patsubst $(TEST)/%.c,$(TESTBIN)/%, $(TESTS))



BIN=$(BINDIR)/main
LIB=$(LIBDIR)/algos.a

VPATH=$(SRCDIR)

SOURCE=$(wildcard $(SRCDIR)/*.c)
OBJECT=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o, $(SOURCE))



all: $(LIB)

$(BIN): $(OBJECT)
#	$(CC) $(CFLAG) $(OBJECT) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAG) -c $< -o $@

$(LIB): $(BIN)
	$(LIB_COMMAND) $(LIB) $(OBJECT)

.PHONY: run
.PHONY: clean

run: $(BIN)
	./$(BIN)


clean:
	rm $(OBJDIR)/* $(LIBDIR)/* $(TESTBIN)/* $(BINDIR)/*

$(TESTBIN)/%: $(TEST)/%.c
	$(CC) $(CFLAG) $< $(LIB) -o $@ -lcriterion

test: $(LIB) $(TESTBIN) $(TESTBINS)
	for t in $(TESTBINS) ; do ./$$t --verbose ; done

$(TESTBIN):
	mkdir $@

