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
*	Descripción: Este archivo es la clase, aquí se
*	definen las funciones, este archivo puede leer
* todo lo que está en el header
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Cache.h"

using namespace std;

//Aquí se define la clase, se usa ::Cache para poder llamar al Constructor
//que está en el header(llamado Cache también), hecho esto ya se pueden usar las
//variables del objeto ya que como estan privadas solo los objetos con el
//constructor Cache que está declarado en el .h pueden modificar estas variables
Cache::Cache(int asociatividad, int cache_size, int block_size)
{
  newAsociatividad = asociatividad; //esto es para que las variables que se reciben
  newCache_size = cache_size;       //en el main se envien al objeto Cache
  newBlock_size = block_size;
}

Cache::~Cache()  //Se define el deconstructor, se deja vacío
{

}

int Cache::getAsociatividad() const
{
  return newAsociatividad;
}

int Cache::getCache_size() const
{
  return newCache_size;
}

int Cache::getBlock_size() const
{
  return newBlock_size;
}

double Cache::MapeoDirecto() const
{

  //int cache_size = 256;
  //int block_size = 32;

  string line;
  ifstream myfile ("solomil.trace");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      string direccion = line.substr (0,8);
      stringstream ss(direccion);
      long direccion2;
      ss >> hex >> direccion2;
      char res = line[line.size()-1];
      cout << "direccion: " << direccion2 << "\t read o write: " << res << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file";
  int block_number;

  block_number = newCache_size / newBlock_size;

  cout << "block_number = " << block_number << endl;

  int cache_blocks[block_number - 1];

  int direccion_hex1 = 13;
  //int direccion_hex2 = 44;
  int position;

  position = direccion_hex1%block_number;
  cout << "position = " << position<< endl;

  int hit = 0;
  int miss = 0;

  if (direccion_hex1 == cache_blocks[position])
  {
    hit = hit + 1;
  }
  else
  {
    cache_blocks[position] == direccion_hex1;
    miss = miss + 1;
  }

  cout << "hits = " << hit << endl;
  cout << "misses= " << miss << endl;

  //int randNum = 0;
  srand( time(NULL) );
  int randNum = rand() % 2; // generar 0 'o 1 random // a'un no sirve
  cout << "random = " << randNum << endl;

  return hit;

}
