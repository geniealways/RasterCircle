CC=g++
CPPFLAGS=-std=c++11 -I.
DEPS = Raster.h 

%.o: %.c %.cpp $(DEPS)
	$(CC) -cpp -o $@ $< $(CPPFLAGS)

main: Raster.o main.o 
	g++ -o main main.o Raster.o -I.
clean:
	rm -f  *.o
