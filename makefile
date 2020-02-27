Lab4: main.o Executive.o binaryTree.o Movie.o
	g++ -g -std=c++11 -Wall binaryTree.o main.o Executive.o Movie.o -o Lab4

main.o: main.cpp node.h BNode.h Queue.h Executive.h binaryTree.h Movie.h
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -g -std=c++11 -Wall -c Executive.cpp

binaryTree.o: binaryTree.h binaryTree.cpp
	g++ -g -std=c++11 -Wall -c binaryTree.cpp

Movie.o: Movie.h Movie.cpp
	g++ -g -std=c++11 -Wall -c Movie.cpp

clean:
	rm *.o Lab4
