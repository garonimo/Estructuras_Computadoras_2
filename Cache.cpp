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

#include "Cache.h"

//Aquí se crea la clase, se usa ::Cache para poder llamar al Constructor
//que está en el header(llamado Cache también), hecho esto ya se pueden usar las
//variables del objeto ya que como estan prrivadas solo los objetos con el
//constructor Cache que está declarado en el .h pueden modificar estas variables
Cache::Cache(int asociatividad, int cache_size, int block_size)
{
  newAsociatividad = asociatividad; //esto es para que las variables que se reciben
  newCache_size = cache_size;       //en el main se envien al objeto Cache
  newBlock_size = block_size;
}

Cache::~Cache()  //Se define el constructor, se deja vacío
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

double Cache::pruebaCache() const
{
  return (newAsociatividad*newCache_size)+(newBlock_size); //es un calculo random

}
