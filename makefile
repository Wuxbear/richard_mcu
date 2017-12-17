
CC = gcc
CFLAGS +=

INC = -I.
LIB = -pthread
#OBJ = $(patsubst %.c,%.o,$(wildcard *.c))
OBJ = driver.o mid.o server_mult.o
TTT = $(wildcard driver/*.c mid/*.c app/*.c)
OOO = $(patsubst %.c, %.o, $(TTT))


.SUFFIXES:
.SUFFIXES: .c .o
.PHONY: clean install server_mult server client

all : client server_mult
#all : test

$(OOO): %.o: %.c
	$(CC) $(CFLAGS) $(INC) $(LIB) -c $< -o $@

test: $(OOO)
	@echo "show VARS"
	@echo "TTT: $(TTT)"
	@echo "OOO: $(OOO)"
	$(CC) $(CFLAGS) $(INC) $(LIB) $(OOO) -o $@ 

#server_mult: $(OBJ) 
server_mult: $(OOO) 
	@echo "build daemon"
	$(CC) $(CFLAGS) $(INC) $(LIB) $(OOO) -o $@ 

server:
	@echo "build daemon"
	$(CC) server.c -o $@

client:
	@echo "build daemon"
	$(CC) client.c -o $@

install:
	@echo "copy lib and daemon to rootfs folder."

clean:
	-rm -f driver/*.o mid/*.o app/*.o client server_mult

