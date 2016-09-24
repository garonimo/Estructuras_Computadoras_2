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
*	Descripción: Este archivo es el header, aquí se
*	declaran las funciones
*/

#include <iostream>
#include <string>

using namespace std;

#ifndef Cache_H
#define Cache_H

class Cache
{
public:
  //Esta funcion llamada Cache es el constructor, se usa para crear la clase
  Cache(int, int, int);

  //Esta otra funcion es el destructor, creo que lo vamos a necesitar por que esto
  //borra un objeto, así podemos borrar un objeto con cierta asociatividad y
  //tamaño y luego se genera otro con otros valores, para que así trabajemos
  //con un solo objeto
  ~Cache();

  int getAsociatividad() const;
     //Para poder retornar el dato de asociatividad
  int getCache_size() const;
  int getBlock_size() const;

  //Esta funcion multiplica dos valores y divide otro, es sólo para probar algo random
  double pruebaCache() const;

//Así se encapsulan las variables del objeto, poniendolas como private, esto
//se hace para que ninguna funcion que no esta definida arriba en public
//pueda cambiar las variables del objeto Cache
private:
  int newAsociatividad;
  int newCache_size;
  int newBlock_size;
};

#endif
