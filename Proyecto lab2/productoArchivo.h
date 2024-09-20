#pragma once
using namespace std;
#include "producto.h"
#include <cstring>

 class ProductoArchivo
 {
   private:
    char _nombre[30];

   public:
    ProductoArchivo(const char *nombre);
    bool guardarArchivo(Producto producto);
    int contarRegistros();
    Producto leer(int numero);
    int buscar(int id);
    bool modificarProducto(Producto producto, int pos);
 };
