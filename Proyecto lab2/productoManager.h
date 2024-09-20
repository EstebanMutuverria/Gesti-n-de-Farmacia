#pragma once
using namespace std;
#include "productoArchivo.h"

 class ProductoManager
 {
   private:
    ProductoArchivo _archivo = ProductoArchivo("producto.dat");
    void mostrarTodos();
    void mostrarPorId();
    void modificarRegistro();
    void modificarProveedores();

   public:
    void menuProducto();
    Producto Cargar();
    Producto CargarNuevo();
    void Mostrar (Producto producto);
    void bajaPoducto();

 };
