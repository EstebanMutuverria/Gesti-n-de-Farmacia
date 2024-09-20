#include <iostream>
using namespace std;
#include "rlutil.h"
#include "funcionesGlobales.h"
#include "producto.h"
#include "productoManager.h"

 //CARGAR
 Producto ProductoManager::Cargar()
 {
   Producto aux;
   int id,proveedor, stock, cantidad;
   char nombre[30], categoria[30], presentacion[30];
   Fecha venci;

   cout << "ID de producto: ";
   cin >> id;
   aux.setId(id);

   cout << "Nombre de producto: ";
   cargarCadena(nombre, 29);
   aux.setNombre(nombre);

   cout << "Categoria de producto: ";
   cargarCadena(categoria, 29);
   aux.setCategoria(categoria);

   cout << "Proveedor(1 - Disval / 2 - Suizo): ";
   cin >> proveedor;
   if (aux.getProveedor() == 1 || aux.getProveedor() == 2)
   {
     aux.setProveedor(proveedor);
   }else
   {
     aux.setProveedor(0);
   }

   cout << "Fecha de vencimiento: " << endl;
   venci.Cargar();
   aux.setVencimiento(venci);

   cout << "Presentacion: ";
   cargarCadena(presentacion,29);
   aux.setPresentacion(presentacion);

   cout << "Cantidad: ";
   cin >> cantidad;
   aux.setCantidad(cantidad);

   if (cantidad > 0)
   {
     stock += cantidad;
   }
   aux.setStock(stock);

   if (aux.getProveedor() == 0)
   {
     cout << "SE LE SOLICITA QUE MODIFIQUE ESTE REGISTRO, YA QUE INGRESO UN NUMERO DE PROVEEDOR INEXISTENTE!" << endl;
   }
   return aux;
 }

//MOSTRAR
 void ProductoManager::Mostrar(Producto producto)
 {
   if (producto.getEstado() && producto.getProveedor() == 1 || producto.getProveedor() == 2)
   {
     cout << "ID de producto: " << producto.getId() << endl;
     cout << "Nombre de producto: " << producto.getNombre() << endl;
     cout << "Categoria de producto: " << producto.getCategoria() << endl;
     cout << "proveedor(1 - Disval / 2 - Suizo): " << producto.getProveedor() << endl;
     cout << "Fecha de vencimiento: " << producto.getVenciemiento().toString() << endl;
     cout << "Presentacion: " << producto.getPresentacion() << endl;
     cout << "Cantidad que ingresa: " << producto.getCantidad() << endl;
     cout << endl;
     cout << "-------------------------------" << endl;
   }
 }


 void ProductoManager::mostrarTodos()
 {
   for (int i=0; i<_archivo.contarRegistros(); i++)
   {
     Mostrar(_archivo.leer(i));
   }
 }

 void ProductoManager::mostrarPorId()
 {
   Producto aux;
   int id;

   cout << "Ingresar el ID: ";
   cin >> id;
   cout << endl;

   int posicion = _archivo.buscar(id);
   if (posicion >= 0 && aux.getProveedor() != 0)
   {
     aux = _archivo.leer(posicion);
     Mostrar(aux);
     cout << "STOCK ACTUAL: " << aux.getStock() << endl;
     if (aux.getStock() == 0)
     {
       cout << "REPONER STOCK!" << endl;
     }
   }else
   {
     cout << "NO EXISTE EL NUMERO DE ID INGRESADO" << endl;
   }

 }

 void ProductoManager::bajaPoducto()
 {
   Producto producto;
   int id;
   cout << "Ingresar el ID: ";
   cin >> id;
   cout << endl;

   int cantidad = _archivo.contarRegistros();
   int posicion = _archivo.buscar(id);
   if (posicion >= 0 && producto.getProveedor() != 0)
   {
     Producto aux = _archivo.leer(posicion);
     Mostrar(aux);
   }else
   {
     cout << "NO EXISTE EL NUMERO DE ID INGRESADO" << endl;
     return;
   }
   int respuesta;
   cout << "¿ESTA SEGURO QUE QUIERE ELIMINAR EL REGISTRO?(1 - SI / 0 - NO)" << endl;
   cin >> respuesta;
   cout << endl;

   if (respuesta == 1)
   {
     producto.setEstado(false);
     if (_archivo.modificarProducto(producto, posicion))
     {
       cout << "REGISTRO ELIMINADO CON EXITO!" << endl;
       pausa();
     }else
     {
       cout << "NO SE PUDO ELIMINAR EL REGISTRO!" << endl;
       pausa();
     }
   }
 }

 void ProductoManager::modificarRegistro()
 {
   Producto producto;
   int id;
   cout << "Ingresar el ID: ";
   cin >> id;
   cout << endl;

   int cantidad = _archivo.contarRegistros();
   int posicion = _archivo.buscar(id);
   if (posicion >= 0)
   {
     Producto aux = _archivo.leer(posicion);
     Mostrar(aux);
   }else
   {
     cout << "NO EXISTE EL NUMERO DE ID INGRESADO" << endl;
     return;
   }
   int respuesta;
   cout << "¿ESTA SEGURO QUE QUIERE MODIFICAR EL REGISTRO?(1 - SI / 0 - NO)" << endl;
   cout << "RESPUESTA: ";
   cin >> respuesta;
   cout << endl;

   int _id,_proveedor, _stock, _cantidad;
   char _nombre[30], _categoria[30], _presentacion[30];
   Fecha _venci;

   if (respuesta == 1)
   {
     cout << "INGRESE NUEVAMENTE LOS CAMPOS DEL PRODUCTO A MODIFICAR..." << endl;

     cout << "ID de producto: ";
     cin >> _id;
     producto.setId(_id);

     cout << "Nombre de producto: ";
     cargarCadena(_nombre, 29);
     producto.setNombre(_nombre);

     cout << "Categoria de producto: ";
     cargarCadena(_categoria, 29);
     producto.setCategoria(_categoria);

     cout << "Proveedor(1 - Disval / 2 - Suizo): ";
     cin >> _proveedor;
     producto.setProveedor(_proveedor);

     cout << "Fecha de vencimiento: " << endl;
     _venci.Cargar();
     producto.setVencimiento(_venci);

     cout << "Presentacion: ";
     cargarCadena(_presentacion,29);
     producto.setPresentacion(_presentacion);

     cout << "Cantidad: ";
     cin >> _cantidad;
     producto.setCantidad(_cantidad);

     _stock += cantidad;
     producto.setStock(_stock);

     if (_archivo.modificarProducto(producto, posicion))
     {
       cout << "REGISTRO MODIFICADO CON EXITO!" << endl;
     }else
     {
       cout << "NO SE PUDO MODIFICAR EL REGISTRO!" << endl;
     }
   }
 }

 void ProductoManager::modificarProveedores()
 {
   Producto producto;
   int cantidad = _archivo.contarRegistros();
   cout << "LOS PRODUCTOS A MODIFICAR EL APARTADO DE ""PROVEEDORES"" SON LOS SIGUIENTES: " << endl;
   cout << endl;
   for (int i=0; i<cantidad; i++)
   {
     producto = _archivo.leer(i);
     if (producto.getProveedor() == 0)
     {
       cout << "ID de producto: " << producto.getId() << endl;
       cout << "Nombre de producto: " << producto.getNombre() << endl;
       cout << "Categoria de producto: " << producto.getCategoria() << endl;
       cout << "proveedor(1 - Disval / 2 - Suizo): " << producto.getProveedor() << endl;
       cout << "Fecha de vencimiento: " << producto.getVenciemiento().toString() << endl;
       cout << "Presentacion: " << producto.getPresentacion() << endl;
       cout << "Cantidad que ingresa: " << producto.getCantidad() << endl;
       cout << endl;
       cout << "-------------------------------" << endl;
     }
   }
 }

 void ProductoManager::menuProducto()
 {
   int opcion;
    while(true)
    {
      rlutil::cls();
      cout << "PRODUCTOS" << endl;
      cout << "----------------" << endl;
      cout << "1 - ALTA PRODUCTO" << endl;
      cout << "2 - LISTAR PRODUCTOS A LA VENTA" << endl;
      cout << "3 - BUSCAR PRODUCTO POR ID" << endl;
      cout << "4 - BAJA PRODUCTO" << endl;
      cout << "5 - MODIFICAR PRODUCTO" << endl;
      cout << "6 - LISTAR PRODUCTOS A MODIFICAR POR X ERROR DE CARGA" << endl;
      cout << endl;
      cout << "0 - PARA SALIR" << endl;
      cout << "----------------" << endl;

      cout << "INGRESE UNA OPCION: ";
      cin >> opcion;
      rlutil::cls();
      switch (opcion)
      {
       case 1:
        {
          Producto aux = Cargar();
          _archivo.guardarArchivo(aux);
        }
        break;
       case 2:
        {
          mostrarTodos();
        }
        break;
       case 3:
        {
          mostrarPorId();
        }
        break;
       case 4:
        {
          bajaPoducto();
        }
        break;
       case 5:
        {
         modificarRegistro();
        }
        break;
       case 6:
        {
          modificarProveedores();
        }
        break;
       case 0:
        {
          return;
        }
        break;
       default:
        {
          cout << "OPCION INCORRECTA" << endl;
        }
      }
      pausa();
      rlutil::cls();
    }
   return;
 }
