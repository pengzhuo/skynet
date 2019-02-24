CC = gcc
CFLAGS = -O2 -fPIC -Wall
LUADIR = /Users/breeze/Documents/YYProj/skynet/3rd/lua
TARGET = protobuf.so

.PHONY : all clean

all : $(TARGET)

$(TARGET) : pbc-lua.c
	$(CC) $(CFLAGS) -shared -o $@ -I../.. -I$(LUADIR) -L../../build $^ -lpbc

clean :
	rm -f $(TARGET)
