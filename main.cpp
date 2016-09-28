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
#include <fstream>
#include <string>
#include <sstream>
#include "Cache.h"

using namespace std;  //el namespace standar(std) sirve para muchas cosas
                      //pero en este caso se usa sólo para imprimir de manera
int main(int argc, char* argv[])            //simplificada utilizando solamente cout
{

  //estas seran las variables del objeto cache
  int asociatividad = atoi(argv[1]);
  int cache_size = atoi(argv[2]);
  int block_size = atoi(argv[3]);

  //Por ahora hagamoslo así, ingresando por consola los valores
/*  cout << "Ingrese la asociatividad " << endl << "\n Ingrese 1 para mapeo directo, " <<
  " \n 2 para 2-way associative, " << "\n y 4 para 4-way associative " << endl << "\n Asociatividad: ";
  cin >> asociatividad;
  cout << "Ingrese el tamaño del cache: ";
  cin >> cache_size;
  cout << "Ingrese el tamaño del bloque: ";
  cin >> block_size;*/


  //Aquí se instancia el objeto, utilizando el nombre de la clase, que es Cache
  Cache MyCache(asociatividad, cache_size, block_size);

//Se debe llamar a la funcion getAsociatividad() y las demás ya que como las variables
//son privadas solo las funciones definidas en la clase Cache las pueden accesar
//puede intentar imprimir asociatividad de un solo para que vea que tira un error
//ya que el main por si solo no puede accesar a la variable

if (MyCache.getAsociatividad()==1) {
  cout << endl << "La asociatividad es Directa " << endl <<
    "El tamaño del cache es: " << MyCache.getCache_size() << endl <<
    "El tamaño del bloque es: " << MyCache.getBlock_size() << endl
    << "El número de hits es: " << MyCache.MapeoDirecto()  << endl;
}
else {
  cout << endl << "La asociatividad es: " << MyCache.getAsociatividad() << "-way asociative" << endl <<
    "El tamaño del cache es: " << MyCache.getCache_size() << endl <<
    "El tamaño del bloque es: " << MyCache.getBlock_size() << endl
    << "El número de hits es: " << MyCache.Asociativa()  << endl;

}

  return 0;
}
