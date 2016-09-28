//pruebas.cpp
// g++ -std=c++11 pruebas.cpp


#include <iostream>
//#include <iomanip>
//#include <sstream>
//#include <random>
#include <cstdlib>
int main()
{
  //mapeo directo
  int cache_size = 256;
  int block_size = 32;
  int block_number;

  block_number = cache_size / block_size;

  std::cout << "block_number = " << block_number << std::endl;

  int cache_blocks[block_number - 1];

  int direccion_hex1 = 13;
  //int direccion_hex2 = 44;
  int position;

  position = direccion_hex1%block_number;
  std::cout << "position = " << position<< std::endl;

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

  std::cout << "hits = " << hit << std::endl;
  std::cout << "misses= " << miss << std::endl;

  //int randNum = 0;
  srand( time(NULL) );
  int randNum = rand() % 85; // generar 0 'o 1 random // a'un no sirve
  std::cout << "random = " << randNum << std::endl;

  return 0;

}
