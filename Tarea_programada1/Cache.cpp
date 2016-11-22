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
*	Descripción: Este archivo contiene la clase. Aquí
* se definen las funciones
*/

// librerías y headers necesarios
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Cache.h"
#include <bitset>
#include <math.h>
#include <stdlib.h>

using namespace std; // namespace estándar

// función que recibe los parámetros de la terminal y los asigna al objeto
Cache::Cache(int asociatividad, int cache_size, int block_size)
{
  newAsociatividad = asociatividad;
  newCache_size = cache_size;
  newBlock_size = block_size;
}

Cache::~Cache() // deconstructor
{

}

int Cache::getAsociatividad() const // retorna asociatividad
{
  return newAsociatividad;
}

int Cache::getCache_size() const // retorna el tamaño del caché
{
  return newCache_size;
}

int Cache::getBlock_size() const // retorna el tamaño del bloque
{
  return newBlock_size;
}

double Cache::Asociativa() const // función para los cachés con asociatividad 2 ó 4
{
  // variables utilizadas

  int hit = 0; // variable para la cantidad de hits
  int miss = 0; // variable para la cantidad de misses
  int line_number; // variable para la cantidad de líneas del caché

  line_number = newCache_size / (newAsociatividad*newBlock_size); // cantidad de líneas

  int offset = log2(newBlock_size); // variable para los bits del offset
  int index = log2(line_number); // variable para los bits del index
  int tag = 32 - offset - index; // variable para los bits del tag
  int tag_index = tag+index; // variable con la cantidad de bits entre el tag y el index

  string matriz[line_number][newAsociatividad] = {}; // matriz para simular la asociatividad del caché

  int dec_index; // variable para obtener el index de la dirección en decimal
  double contador; // contador de miss rate

  string line; // variable línea de entrada del archivo

  // acá se reciben los datos del archivo y se operan sobre cada uno de ellos

  ifstream myfile ("aligned.trace");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      string direccion = line.substr (0,8);

      // se toma la dirección y se pasa de hexadecimal a binario, como string
      string s = direccion;
      stringstream s1;
      s1 << hex << s;
      unsigned n;
      s1 >> n;
      bitset<32> b(n);

      // se recorta la palabra según los datos de tag, index y offset; para
      // obtener el index y el tag por aparte
      string a = b.to_string();
      string tag_compare = a.substr (0,tag);
      string c = b.to_string();
      string ssindexss = c.substr (tag,tag_index);
      string INDEX = ssindexss.substr (0,index);

      // se pasa el index string a un número en base 10
      dec_index = stoi (INDEX,nullptr,2);

      // se genera un número random de acuerdo a la asociatividad ingresada
      int randNum = rand() % newAsociatividad;

      // se entra en un if según la asociatividad escogida
      if (newAsociatividad == 2)
      {
        // Asociatividad = 2. Se comparan cada uno de los sets simulados con la matriz,
        // con los tags de cada palabra y se decide si hay un miss o un hit según se
        // cumplan las condiciones

        if (matriz[dec_index][0] == tag_compare)
        {
          hit = hit + 1;
        }
        else
          if (matriz[dec_index][1] == tag_compare)
          {
            hit = hit + 1;
          }
          else
          {
            matriz[dec_index][randNum] = tag_compare;
            miss = miss + 1;
          }
      }
      else
      {
        // Asociatividad = 4. Se comparan cada uno de los sets simulados con la matriz,
        // con los tags de cada palabra y se decide si hay un miss o un hit según se
        // cumplan las condiciones

        if (matriz[dec_index][0] == tag_compare)
        {
          hit = hit + 1;
        }
        else
          if (matriz[dec_index][1] == tag_compare)
          {
            hit = hit + 1;
          }
          else
            if (matriz[dec_index][2] == tag_compare)
            {
              hit = hit + 1;
            }
            else
              if (matriz[dec_index][3] == tag_compare)
              {
                hit = hit + 1;
              }
              else
              {
                matriz[dec_index][randNum] = tag_compare;
                miss = miss + 1;
              }
      }
    }
    myfile.close(); // termina el documento
    contador = ( miss / (double)(miss + hit)) * 100; // se genera el miss rate
    cout << endl;
    cout << "Cantidad de hits = " << hit << endl;
    cout << "Cantidad de misses = " << miss << endl;
  }

  else cout << "No se pudo abrir el archivo";

  return contador; // devuelve el miss rate
}

//---------------------------------------------------------------------------------

double Cache::MapeoDirecto() const
{
  // variables utilizadas

  int hit = 0; // variable para la cantidad de hits
  int miss = 0; // variable para la cantidad de misses
  int line_number; // variable para la cantidad de líneas del cache

  line_number = newCache_size / (newAsociatividad*newBlock_size); // cantidad de líneas

  int offset = log2(newBlock_size); // variable para los bits del offset
  int index = log2(line_number); // variable para los bits del index
  int tag = 32 - offset - index; // variable para los bits del tag
  int tag_index = tag+index; // variable con la cantidad de bits entre el tag y el index

  string cache_line[line_number] = { }; // arreglo para simular las líneas del caché

  int dec_index; // variable para obtener el index de la dirección en decimal
  double contador; // contador de miss rate

  //int position; // variable para posición del array

  string line; // variable línea de entrada del archivo

  // acá se reciben los datos del archivo y se operan sobre cada uno de ellos

  ifstream myfile ("aligned.trace");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      string direccion = line.substr (0,8);

      // se toma la dirección y se pasa de hexadecimal a binario, como string
      string s = direccion;
      stringstream s1;
      s1 << hex << s;
      unsigned n;
      s1 >> n;
      bitset<32> b(n);

      // se recorta la palabra según los datos de tag, index y offset; para
      // obtener el index y el tag por aparte
      string a = b.to_string();
      string tag_compare = a.substr (0,tag);
      string c = b.to_string();
      string ssindexss = c.substr (tag,tag_index);
      string INDEX = ssindexss.substr (0,index);

      // se pasa el index string a un número en base 10
      dec_index = stoi (INDEX,nullptr,2);

      // se entra a una posición del array y se opera según la condición que se
      // de, y se define si hay un miss o hit
      if (cache_line[dec_index] == tag_compare)
      {
        hit = hit + 1;
      }
      else
      {
        cache_line[dec_index] = tag_compare;
        miss = miss + 1;
      }
    }
    myfile.close(); // termina el documento
    contador = ( miss / (double)(miss + hit)) * 100; // se genera el miss rate
    cout << endl;
    cout << "Cantidad de hits = " << hit << endl;
    cout << "Cantidad de misses = " << miss << endl;
  }
  else cout << "No se pudo abrir el archivo";
  return contador; // devuelve el miss rate
}
