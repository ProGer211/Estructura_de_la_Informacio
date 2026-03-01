OPCIONS = -O0 -g -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -ansi

program.exe: main.o mcj_enters.o
	g++ -o program.exe main.o mcj_enters.o
	rm *.o

solution.exe: main.o mcj_enters.o
	g++ -o solution.exe main.o mcj_enters.o
	rm *.o

main.o: main.cpp phone.hpp phone.rep
	g++ -c main.cpp $(OPCIONS)

phone.o: phone.cpp phone.hpp phone.rep
	g++ -c mcj_enters.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
