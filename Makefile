cc = g++
cflags = -Wall -g
clibs = -lstdc++ -lm
src = src/
objects = $(src)mytest.o $(src)myUtils.o

mytest : $(objects)
	$(cc) $(cflags) -o myTest.exe $(objects) $(clibs)
myUtils.o : $(src)primes.h