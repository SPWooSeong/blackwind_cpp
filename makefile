GXX = g++

SRC = ./main.cpp

all: main

main: $(SRC)
	$(GXX) $(SRC) -o main 

clean:
	rm -f main