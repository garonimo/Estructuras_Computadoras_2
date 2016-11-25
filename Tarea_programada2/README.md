Para compilar el programa es suficiente con correr el makefile. En terminal: $ make
Si desea borrar los archivos generados es suficiente correr el clean del makefile. En terminal: $ make clean

Para ejecutar el programa se trabaja de la siguiente forma. 
En terminal:
	./cache.o (Asociatividad) (Tamaño del caché) (Tamaño del bloque)

, donde se pondrá un 1 en Asociatividad para mapeo directo, un 2 para 2-way associative y 4 para 4-way associative.
Los tamaños del caché y del bloque se colocan en bytes. Cuidado! Si se desea ingresar como tamaño un valor
como '64 kB' NO funciona. Es necesario escribir el resultado de 64*1024, o bien, 65536.

El archivo 'aligned.trace' debe estar en la misma carpeta que el ejecutable generado 'cache.o'.

Descripción del proyecto:
	Se implementó un caché que funciona con mapeo directo, 2-way associative y 4-way associative según se desee.
El tamaño del caché y de los bloques también es un valor a escoger por el usuario. Para el proyecto, se tomaron
4 diferentes valores de tamaños de caché y de bloques y, junto con las diferentes asociatividades, se realizaron
todas las posibles combinaciones para analizar los datos y así, finalmente, desarrollar los conceptos relacionados
al caché que es el objetivo que se esperaba alcanzar.
