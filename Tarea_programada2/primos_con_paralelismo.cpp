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

int main()
{
  bool esPrimo1, esPrimo2, esPrimo3, esPrimo4;

	int contador1 = 1;
  int contador2 = 125002;
  int contador3 = 250002;
  int contador4 = 375002;
	int numero_primo1 = 2; //Se empieza en el primer número primo
  int numero_primo2, numero_primo3, numero_primo4;
  int N = 500000;        //Cantidad de numeros primos a encontrar
  int process, id;

  clock_t begin = clock();  //Se empieza a medir el tiempo
  MPI_Init(NULL, NULL);     //Se instancia la librería para el paralelismo

  process = MPI_Comm_rank ( MPI_COMM_WORLD, &id );  //En la variable id se guarda el número
                                                    //de cada procesador

  if (id == 0) {  //Aquí por ejemplo si el id es cero quiere decir que es el primer CPU
  	for(int i1 = 3; contador1 < ((N/4) +1); i1 += 2) { //Por lo tanto lo que esta dentro del if
                                                       //es ejecutado únicamente por el CPU0
  		esPrimo1 = true;

  		for(int j1 = 3; j1 * j1 <= i1 && esPrimo1; j1 += 2)  //Se saltan los multiplos de los
  			if(i1 % j1 == 0)                                 //numeros ya descartados
        esPrimo1 = false;

  		if(esPrimo1) {
  			++contador1;
  			numero_primo1 = i1;
  		}
  	}
  }

  if (id == 1) {
  	for(int i2 = 1655153; contador2 < ((N/2) +1); i2 += 2) {

  		esPrimo2 = true;

  		for(int j2 = 3; j2 * j2 <= i2 && esPrimo2; j2 += 2)  //Se saltan los multiplos de los
  			if(i2 % j2 == 0)                                 //numeros ya descartados
        esPrimo2 = false;

  		if(esPrimo2) {
  			++contador2;
  			numero_primo2 = i2;
  		}
  	}
  }

  if (id == 2) {
  	for(int i3 = 3497873; contador3 < 375001; i3 += 2) {

  		esPrimo3 = true;

  		for(int j3 = 3; j3 * j3 <= i3 && esPrimo3; j3 += 2)  //Se saltan los multiplos de los
  			if(i3 % j3 == 0)                                 //numeros ya descartados
        esPrimo3 = false;

  		if(esPrimo3) {
  			++contador3;
  			numero_primo3 = i3;
  		}
  	}
  }

  if (id == 3) {
  	for(int i4 = 5410201; contador4 < (N+1); i4 += 2) {

  		esPrimo4 = true;

  		for(int j4 = 3; j4 * j4 <= i4 && esPrimo4; j4 += 2)  //Se saltan los multiplos de los
  			if(i4 % j4 == 0)                                 //numeros ya descartados
        esPrimo4 = false;

  		if(esPrimo4) {
  			++contador4;
  			numero_primo4 = i4;
  		}
  	}
  }

  clock_t end = clock();                   //Se termina de medir el tiempo

  MPI_Finalize();                          //Fin del paralelismo

  double difference = double(end - begin);


  cout << "La cantidad de números primos es: " << (contador1-1) << endl;
  cout << "El tiempo de ejecución fue: " << difference << " \t Ciclos de reloj" << endl;

  return 0;
}
