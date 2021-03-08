default:
	make build

build:
	gcc -o curdit src/*.c -lncurses 

docs:
	doxygen Doxyfile
