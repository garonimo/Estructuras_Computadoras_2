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
*	instancia el cache y se obtienen los datos
*/

#include <iostream>
#include "Cache.h"

using namespace std;  //el namespace standar sirve para muchas cosas
                      //pero en este caso se usa sólo para imprimir de manera
int main()            //simplificada utilizando solamente cout
{
  //estas seran las variables del objeto cache
  int asociatividad;
  int cache_size;
  int block_size;

  //Por ahora hagamoslo así, ingresando por consola los valores
  cout << "Ingrese la asociatividad: ";
  cin >> asociatividad;
  cout << "Ingrese el tamaño del cache: ";
  cin >> cache_size;
  cout << "Ingrese el tamaño del bloque: ";
  cin >> block_size;


  //Aquí se instancia el objeto, utilizando el nombre de la clase, que es Cache
  Cache MyCache(asociatividad, cache_size, block_size);

//Se debe llamar a la funcion getAsociatividad() y las demás ya que como las variables
//son privadas solo las funciones definidas en la clase Cache las pueden accesar
//puede intentar imprimir asociatividad de un solo para que vea que tira un error
//ya que el main por si solo no puede accesar a la variable
  cout << endl << "La asociatividad es: " << MyCache.getAsociatividad() << endl <<
    "El tamaño del cache es: " << MyCache.getCache_size() << endl <<
    "El tamaño del bloque es: " << MyCache.getBlock_size() << endl
    << "El Calculo random es: " << MyCache.pruebaCache()  << endl;

  return 0;
}
