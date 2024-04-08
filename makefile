final: main.o showMenu.o showMainMenu.o
	gcc -o final.exe main.o showMenu.o showMainMenu.o

main.o: main.c
	gcc -c main.c

showMenu.o: ./include/src/showMenu.c ./include/lib/showMenu.h
	gcc -c ./include/src/showMenu.c

showMainMenu.o: ./include/src/showMainMenu.c ./include/lib/showMainMenu.h
	gcc -c ./include/src/showMainMenu.c

clean:
	del *.o final.exe