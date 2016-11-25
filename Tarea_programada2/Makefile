all:
	g++ -std=c++11 -o cache.o main.cpp Cache.h Cache.cpp
	
prime:
	g++ -o prueba primos_sin_paralelismo.cpp
	./prueba
	
parallel:
	mpic++ primos_con_paralelismo.cpp
	mpirun -np 4 ./a.out 

clean:
	rm *.o
	
	
