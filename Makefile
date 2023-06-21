version=c++17
gxx=g++
include_path=./include/

main: main.cpp
	$(gxx) -std=$(version) -I$(include_path) main.cpp ./src/* -o main
	./main.exe

clean:
	rm -f *.o main.exe