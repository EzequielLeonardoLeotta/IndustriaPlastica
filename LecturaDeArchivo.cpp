
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include"string.h"
#include<string>
#include "LecturaDeArchivo.h"
using namespace std;

void leerArchivo(const char* filename) {

   FILE *stream;
   char buffer[500];
   int  i, ch;

   // Open file to read line from:
   fopen_s( &stream, filename, "r" );
   if( stream == NULL ){
       printf("No se pudo abrir el lote de figuras");
      exit( 0 );
   }

   // Read in first 80 characters and place them in "buffer":
   ch = fgetc( stream );
   for( i=0; (i < 500 ) && ( feof( stream ) == 0 ); i++ )
   {
      buffer[i] = (char)ch;
      ch = fgetc( stream );
   }

   // Add null to end string
   buffer[i] = '\0';
   printf( "%s\n", buffer );
   fclose( stream );
};