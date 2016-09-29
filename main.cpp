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

int main(int argc, char* argv[])
{

  // estas serán las variables del objeto caché
  int asociatividad = atoi(argv[1]);
  int cache_size = atoi(argv[2]);
  int block_size = atoi(argv[3]);

  srand( time(NULL) ); // semilla para generar el número random de la función Asociativa()


  // aquí se instancia el objeto utilizando el nombre de la clase
  Cache MyCache(asociatividad, cache_size, block_size);

  // según la asociatividad tomada desde la terminal se escoge una función
  if (MyCache.getAsociatividad()==1)
  {
      cout << endl << "La asociatividad es directa " << endl <<
      "El tamaño del cache es: " << MyCache.getCache_size() << endl <<
      "El tamaño del bloque es: " << MyCache.getBlock_size() << endl
      << "El miss rate es: " << MyCache.MapeoDirecto() << " %" << endl;
  }
  else
  {
      cout << endl << "La asociatividad es " << MyCache.getAsociatividad() << "-way" << endl <<
      "El tamaño del cache es: " << MyCache.getCache_size() << endl <<
      "El tamaño del bloque es: " << MyCache.getBlock_size() << endl
      << "El miss rate es: " << MyCache.Asociativa()  << " %" << endl;
  }
  return 0;
}
