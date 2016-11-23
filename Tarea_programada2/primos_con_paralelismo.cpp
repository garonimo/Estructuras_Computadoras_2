/*
*	Universidad de Costa Rica
*	Escuela de Ingeniería Eléctrica
*	IE-0521 Estructuras de Computadoras Digitales II
*
*	Tarea programada II
*
*	Autores:
* Andrey Pérez Salazar - B25084
* Andrés Sánchez López - B26214
*
*	Descripción: En este archivo se hace el cálculo de los 500000 primeros números primos
* con la criba de Eratóstenes, utilizando paralelismo
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include "mpi.h"


using namespace std;
typedef unsigned int uInt;


int main()
{
  bool is_prime1, is_prime2, is_prime3, is_prime4;

	uInt count1 = 1;
  uInt count2 = 125002;
  uInt count3 = 250002;
  uInt count4 = 375002;
	uInt my_prime1 = 2; //Se empieza en el primer número primo
  uInt my_prime2, my_prime3, my_prime4;
  uInt N = 500000;        //Cantidad de numeros primos a encontrar
  int contador1, contador2, contador3, contador4 = 0;
  int process, id;

  clock_t begin = clock();  //Se empieza a medir el tiempo
  MPI_Init(NULL, NULL);
  process = MPI_Comm_rank ( MPI_COMM_WORLD, &id );

  if (id == 0) {
  	for(uInt i1 = 3; count1 < 125001; i1 += 2) {

  		is_prime1 = true;

  		for(uInt j1 = 3; j1 * j1 <= i1 && is_prime1; j1 += 2)  //Se saltan los multiplos de los
  			if(i1 % j1 == 0)                                 //numeros ya descartados
        is_prime1 = false;

  		if(is_prime1) {
  			++count1;
  			my_prime1 = i1;
        ++contador1;
        //cout << my_prime << endl;    //Se imprimen los números
  		}
  	}
  }

  if (id == 1) {
  	for(uInt i2 = 125002; count2 < 250001; i2 += 2) {

  		is_prime2 = true;

  		for(uInt j2 = 3; j2 * j2 <= i2 && is_prime2; j2 += 2)  //Se saltan los multiplos de los
  			if(i2 % j2 == 0)                                 //numeros ya descartados
        is_prime2 = false;

  		if(is_prime2) {
  			++count2;
  			my_prime2 = i2;
        ++contador1;
        //cout << my_prime << endl;    //Se imprimen los números
  		}
  	}
  }

  if (id == 2) {
  	for(uInt i3 = 250002; count3 < 375001; i3 += 2) {

  		is_prime3 = true;

  		for(uInt j3 = 3; j3 * j3 <= i3 && is_prime3; j3 += 2)  //Se saltan los multiplos de los
  			if(i3 % j3 == 0)                                 //numeros ya descartados
        is_prime3 = false;

  		if(is_prime3) {
  			++count3;
  			my_prime3 = i3;
        ++contador1;
        //cout << my_prime << endl;    //Se imprimen los números
  		}
  	}
  }

  if (id == 3) {
  	for(uInt i4 = 375002; count4 < (N+1); i4 += 2) {

  		is_prime4 = true;

  		for(uInt j4 = 3; j4 * j4 <= i4 && is_prime4; j4 += 2)  //Se saltan los multiplos de los
  			if(i4 % j4 == 0)                                 //numeros ya descartados
        is_prime4 = false;

  		if(is_prime4) {
  			++count4;
  			my_prime4 = i4;
        ++contador1;
        //cout << my_prime4 << endl;    //Se imprimen los números
  		}
  	}
  }
  MPI_Finalize();
  clock_t end = clock();                   //Se termina de medir el tiempo

  double difference = double(end - begin);
  //int contador = contador1 + contador2 + contador3 + contador4;

  cout << "La cantidad de números primos es: " << contador1 << endl;
  cout << "El tiempo de ejecución fue: " << difference << " \t Ciclos de reloj" << endl;

  return 0;
}
