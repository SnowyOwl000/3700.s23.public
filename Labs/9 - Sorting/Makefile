all: bsort ssort isort msort qsort hsort

qsort: qsort.o main.o Print.o Read.o
	g++ -o qsort qsort.o main.o Print.o Read.o

hsort: hsort.o main.o Print.o Read.o
	g++ -o hsort hsort.o main.o Print.o Read.o

msort: msort.o main.o Print.o Read.o
	g++ -o msort msort.o main.o Print.o Read.o

isort: isort.o main.o Print.o Read.o
	g++ -o isort isort.o main.o Print.o Read.o

ssort: ssort.o main.o Print.o Read.o
	g++ -o ssort ssort.o main.o Print.o Read.o

bsort: bsort.o main.o Print.o Read.o
	g++ -o bsort bsort.o main.o Print.o Read.o

bsort.o: bsort.cc
	g++ -c bsort.cc

ssort.o: ssort.cc
	g++ -c ssort.cc

isort.o: isort.cc
	g++ -c isort.cc

msort.o: msort.cc
	g++ -c msort.cc

qsort.o: qsort.cc
	g++ -c qsort.cc

hsort.o: hsort.cc
	g++ -c hsort.cc

main.o: main.cc
	g++ -c main.cc

Print.o: Print.cc
	g++ -c Print.cc

Read.o: Read.cc
	g++ -c Read.cc
