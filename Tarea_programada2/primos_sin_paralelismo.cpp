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


int main()
{
  bool esPrimo;

	int contando = 1;
	int numero_primo = 2; //Se empieza en el primer número primo
  int N = 500000;        //Cantidad de numeros primos a encontrar
  int contador = 0;

  clock_t begin = clock();  //Se empieza a medir el tiempo

	for(int i = 3; contando < (N+1); i += 2) {

		esPrimo = true;

		for(int j = 3; j * j <= i && esPrimo; j += 2)  //Se saltan los multiplos de los
			if(i % j == 0)                                 //numeros ya descartados
      esPrimo = false;

		if(esPrimo) {
			++contando;
			numero_primo = i;
      contador += 1;
		}
	}

  clock_t end = clock();                   //Se termina de medir el tiempo

  double difference = double(end - begin);

  cout << "La cantidad de números primos es: " << contador << endl;
  cout << "El tiempo de ejecución fue: " << difference << " \t Ciclos de reloj" << endl;

  return 0;
}
