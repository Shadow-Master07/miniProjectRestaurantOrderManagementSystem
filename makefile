Compiler = gcc


final: main.o showMenu.o showMainMenu.o structDefinitions.o
	$(Compiler) -o final.exe structDefinitions.o main.o showMenu.o showMainMenu.o

main.o: main.c
	$(Compiler) -c main.c

showMenu.o: ./include/src/showMenu.c ./include/lib/showMenu.h
	$(Compiler) -c ./include/src/showMenu.c

showMainMenu.o: ./include/src/showMainMenu.c ./include/lib/showMainMenu.h
	$(Compiler) -c ./include/src/showMainMenu.c

structDefinitions.o: ./include/src/structDefinitions.c ./include/lib/structDefinitions.h
	$(Compiler) -c ./include/src/structDefinitions.c

clean:
	del *.o
	del final.exe
