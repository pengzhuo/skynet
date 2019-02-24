CC = gcc
CFLAGS = -O2 -fPIC -Wall -undefined dynamic_lookup
LUADIR = /Users/breeze/Documents/YYProj/skynet/3rd/lua
TARGET = protobuf.so

.PHONY : all clean

all : $(TARGET)

$(TARGET) : pbc-lua53.c
	$(CC) $(CFLAGS) -shared -o $@ -I../.. -I$(LUADIR) -L../../build $^ -lpbc

clean :
	rm -f $(TARGET)
