CC=gcc
OUT=perlin
SRC=$(wildcard *.c)

all: bin perlin

perlin:
	$(CC) $(SRC) -o bin/$(OUT)

bin:
	mkdir -p bin

clean:
	rm -r bin