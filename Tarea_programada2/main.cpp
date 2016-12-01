/*
*	Universidad de Costa Rica
*	Escuela de Ingeniería Eléctrica
*	IE-0521 Estructuras de Computadoras Digitales II
*
*	Tarea programada I
*
*	Autores:
* Andrey Pérez Salazar - B25084
* Andrés Sánchez López - B26214
*
*	Descripción: Este archivo es el main, aquí se
*	instancia el caché y se obtienen los datos
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Cache.h"

using namespace std;

int main()
{

  // estas serán las variables del objeto caché
  int L1_size = 8000; 
  int L2_size = 64000;
  int block_size = 16;

  srand( time(NULL) ); // semilla para generar el número random de la función Asociativa()


  // aquí se instancia el objeto utilizando el nombre de la clase
  Cache MyCache(L1_size, L2_size, block_size);

//PARA LLAMAR:
  MyCache.MESI();

  return 0;
}
