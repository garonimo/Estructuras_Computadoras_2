Para compilar hay que usar:

g++ -std=c++11 -o cache main.cpp Cache.h Cache.cpp

Lo anterior creará un archivo ejecutable llamado cache. Para ejecutarlo se hace de la siguiente manera:

./cache <Asociatividad> <Tamaño del caché> <Tamaño del bloque>

Donde Asociatividad puede ser 1 para mapeo directo, 2 para 2-way associative y 4 para 4-way associative

El archivo 'aligned.trace' debe estar en la misma carpeta en la que se ejecuta
