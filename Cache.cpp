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
#include <bitset>
#include <math.h>
#include <stdlib.h>

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
  int hit = 0;
  int miss = 0;
  int line_number;

  line_number = newCache_size / newBlock_size;

  int offset = log2(newBlock_size);
  int index = log2(line_number);
  int tag = 32 - offset - index;
  int tag_index = tag+index;
  //string tag_compare;
  //int
  cout << "line_number = " << line_number << endl;

  string cache_line[line_number] = { };
  int position;

  int dec_index;


  string line;
  ifstream myfile ("solomil.trace");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      string direccion = line.substr (0,8);

      stringstream ss(direccion);
      long direccion2;            //direccion2 es la que hay que usar
      ss >> hex >> direccion2;
      //char res = line[line.size()-1];
      //cout << "direccion: " << direccion2 << "\t read o write: " << res << '\n';
      // direccion2 el valor en decimal

      string s = direccion;
      stringstream s1;
      s1 << hex << s;
      unsigned n;
      s1 >> n;
      bitset<32> b(n);
      // outputs "00000000000000000000000000001010"
      cout << b << endl;
      //cout << b[0] << endl;
      //cout << b[1] << endl;
      //cout << b[2] << endl;
      //cout << b[30] << endl;
      //cout << b[31] << endl;
      //cout << b[32] << endl;
      //cout << b[33] << endl;
      //cout << offset << endl;
      //cout << index << endl;
      //cout << tag << endl;

      string a = b.to_string();
      string tag_compare = a.substr (0,tag);
      cout << tag_compare << endl;

      string c = b.to_string();
      string ssindexss = c.substr (tag,tag_index);
      cout << ssindexss << endl;

      string INDEX = ssindexss.substr (0,index);
      cout << INDEX << endl;

      dec_index = stoi (INDEX,nullptr,2);
      //dec_index = std::stoi( suma );
      //dec_index = atoi (INDEX.c_str());
      cout << dec_index << endl;
      //string tag_compare2 = "101111111110110111100010";
      /*

      if (tag_compare == tag_compare2)
      { 
        cout << "hola" << endl;
      }
      */
      //position = direccion2%line_number; // saco el index
      //cout << "position = " << position << endl;
      cout << "cache_line[dec_index] = " << cache_line[dec_index] << endl;

      if (cache_line[dec_index] == tag_compare)
      {
        hit = hit + 1;
      }
      else
      {
        cache_line[dec_index] = tag_compare;
        miss = miss + 1;
      }

      cout << "hits = " << hit << endl;
      cout << "misses= " << miss << endl;


      // HASTA ac'a tengo el line_number




      //cout << direccion2 << endl;

      //cout << "direccion:" << direccion2 << "direccion" << '\n';
      //------------------------------------------------------------------------------

      //int direccion_hex1 = 13;
      //int direccion_hex2 = 44;



      /*
      if (cache_line[position] == direccion2)
      {
        hit = hit + 1;
      }
      else
      {
        cache_line[position] = direccion2;
        miss = miss + 1;
      }

      cout << "hits = " << hit << endl;
      cout << "misses= " << miss << endl;

      //srand( time(NULL) );
      //int randNum = rand() % 2; // generar 0 'o 1 random // a'un no sirve
      //cout << "random = " << randNum << endl;
      */
      //----------------------------------------------------------------------------------
    }
    myfile.close();
  }

  else cout << "No se pudo abrir el archivo";

  return hit;

}
