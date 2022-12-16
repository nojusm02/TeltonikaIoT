CFLAGS := -fPIC -shared -g -Wall
LIB:=liblog.so
DB:=liblog.db
LDFLAGS:=-lsqlite3
SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:.c=.o)

.PHONY: clean all install uninstall

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	$(RM) $(LIB) $(OBJS)


install: all
	sudo cp $(LIB) /usr/lib

uninstall: clean
	sudo $(RM) /usr/lib/$(LIB)
	sudo $(RM) /var/log/$(DB)
