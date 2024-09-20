#pragma once
using namespace std;
#include "fecha.h"

 class Producto
 {
   protected:
    int _id;
    char _nombre[30];
    char _categoria[30];
    int _proveedor;
    Fecha _vencimiento;
    int _stock;
    bool _estado;
    char _presentacion[30];
    int _cantidad;

   public:
    Producto(int id, const char *nombre, const char *categoria, int proveedor, Fecha vencimiento, bool estado, const char *presentacion, int cantidad);
    Producto();
    //SETS
    void setId(int id);
    void setNombre(const char *nombre);
    void setCategoria(const char *categoria);
    void setProveedor(int proveedor);
    void setVencimiento(Fecha vencimiento);
    void setStock(int stock);
    void setEstado(bool estado);
    void setPresentacion(const char *presentacion);
    void setCantidad(int cantidad);
    //GETS
    int getId();
    const char *getNombre(){return _nombre;}
    const char *getCategoria(){return _categoria;}
    int getProveedor();
    Fecha getVenciemiento(){return _vencimiento;}
    int getStock();
    bool getEstado();
    const char *getPresentacion(){return _presentacion;}
    int getCantidad();
 };
