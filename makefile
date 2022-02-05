# red reader (rer) program
CC=gcc -Wall -Wextra
OUT=./bin/rer

all: build 
	${OUT} ./src/main.c

build: ${OUT}


${OUT}: ./obj/settings.o ./obj/reader.o ./obj/printer.o ./obj/main.o ./obj/array.o ./obj/token.o
	${CC} -o ${OUT} ./obj/*.o

./obj/main.o: ./src/main.c 
	${CC} -c -o ./obj/main.o ./src/main.c

./obj/array.o: ./src/array.c 
	${CC} -c -o ./obj/array.o ./src/array.c

./obj/token.o: ./src/token.c 
	${CC} -c -o ./obj/token.o ./src/token.c

./obj/printer.o: ./src/main.h ./src/printer.c 
	${CC} -c -o ./obj/printer.o ./src/printer.c

./obj/reader.o: ./src/reader.c 
	${CC} -c -o ./obj/reader.o ./src/reader.c

./obj/settings.o: ./src/settings.c 
	${CC} -c -o ./obj/settings.o ./src/settings.c




mk:
	mkdir obj bin

cyg: build
	chmod a+x ${OUT}

	cp ${OUT} /usr/bin/

linux: build
	sudo chown root:root ${OUT}
	sudo chmod a+x ${OUT}

	sudo cp ${OUT} /usr/bin/

clean:
	rm obj/*.o 

