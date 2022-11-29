compiler:=gcc
Flags:=-Wall -I.
OBJS:=main.o math_functions.o
DEPS = math_functions.h
BIN:=calculator

all: $(BIN)

%.o: %.c $(DEPS)
	$(compiler) -c -o $@ $< $(Flags)

$(BIN): $(OBJS)
	$(compiler) -o $@ $^ $(Flags)

clean:
	rm -f $(BIN) $(OBJS)


