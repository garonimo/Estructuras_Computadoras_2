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
*	Descripción: En este archivo se hace el calculo de los 500000
* primeros números primos sin utilizar paralelismo
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdio>


using namespace std;
typedef unsigned int uInt;


int main()
{
  bool is_prime;

	uInt count = 1;
	uInt my_prime = 2; //Se empieza en el primer número primo
  uInt N = 500000;        //Cantidad de numeros primos a encontrar
  int contador = 0;

  clock_t begin = clock();  //Se empieza a medir el tiempo

	for(uInt i = 3; count < (N+1); i += 2) {

		is_prime = true;

		for(uInt j = 3; j * j <= i && is_prime; j += 2)  //Se saltan los multiplos de los
			if(i % j == 0)                                 //numeros ya descartados
      is_prime = false;

		if(is_prime) {
			++count;
			my_prime = i;
      contador += 1;
      //cout << my_prime << endl;    //Se imprimen los números
		}
	}

  clock_t end = clock();                   //Se termina de medir el tiempo

  double difference = double(end - begin);

  cout << "La cantidad de números primos es: " << contador << endl;
  cout << "El tiempo de ejecución fue: " << difference << " \t Ciclos de reloj" << endl;

  return 0;
}
