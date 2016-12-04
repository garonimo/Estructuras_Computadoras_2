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
  int Cache_size = 8000;
  int Block_size = 16;

  // aquí se instancia el objeto utilizando el nombre de la clase
  Cache MyCache1(Cache_size, Block_size);
  Cache MyCache2(Cache_size+1, Block_size);

  //PARA LLAMAR:
  MyCache1.MESI();
  MyCache2.MESI();

  return 0;
}
