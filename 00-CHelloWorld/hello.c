/* hello.c
 * Emite "Hola Mundo" en archivo .txt
 * Juan Manuel Rama
 * 01/04/24
*/
#include <stdio.h>


int main (){
   FILE *fl;
   fl=fopen("output.txt", "w");
   fprintf(fl, "Hola Mundo");
   fclose(fl);
   return 0;
    }
