#include <iostream>
using namespace std;
#include "productoArchivo.h"
#include "producto.h"

ProductoArchivo::ProductoArchivo(const char *nombre)
 {
   strcpy(_nombre,nombre);
 }

 bool ProductoArchivo::guardarArchivo(Producto producto)
 {
   FILE *p = fopen(_nombre, "ab");
   if (p==nullptr)
   {
     return false;
   }

   bool escribio = fwrite(&producto, sizeof(Producto), 1,p);
   fclose(p);

   return escribio;
 }

 int ProductoArchivo::contarRegistros()
 {
   Producto producto;
   FILE *p = fopen(_nombre, "rb");
   if (p==nullptr)
   {
     return false;
   }
   int contador = 0;
   while (fread (&producto, sizeof(Producto), 1,p)==1)
   {
     contador++;
   }
   fclose(p);
   return contador;
 }

 Producto ProductoArchivo::leer(int numero)
 {
   FILE *p = fopen(_nombre, "rb");
   if (p==nullptr)
   {
     return Producto();
   }
   Producto aux;
   fseek(p,numero*sizeof(Producto), 0);
   fread(&aux, sizeof(Producto), 1,p);
   fclose(p);
   return aux;
 }

 int ProductoArchivo::buscar(int id) //Retorna ID si existe, sino -1
 {
   int cantidad = contarRegistros();
   for (int i=0; i<cantidad; i++)
   {
     Producto aux = leer(i);
     if (id == aux.getId())
     {
       return i;
     }
   }
   return -1;
 }

 bool ProductoArchivo::modificarProducto(Producto producto, int pos)
 {
   FILE *p = fopen(_nombre, "rb+");
   if (p==nullptr)
   {
     return false;
   }
   fseek(p,pos*sizeof(Producto), 0);
   bool escribio = fwrite(&producto, sizeof(Producto), 1,p);
   fclose(p);
   return escribio;
 }

