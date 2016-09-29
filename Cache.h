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

// librerías utilizadas
#include <iostream>
#include <string>

using namespace std;

// definiciones
#ifndef Cache_H
#define Cache_H

// clase Cache. Aquí se declaran las funciones
class Cache
{
public:

  Cache(int, int, int); // constructor

  ~Cache(); // deconstructor

  // retorna asociatividad y tamaños
  int getAsociatividad() const;
  int getCache_size() const;
  int getBlock_size() const;

  // se definan las funciones MapeoDirecto() y Asociativa()
  double MapeoDirecto() const;
  double Asociativa() const;

private:
  int newAsociatividad;
  int newCache_size;
  int newBlock_size;
};

#endif
