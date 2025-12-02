//
// Created by helen on 01/12/2025.
//

#ifndef PCO_SITUACION_PROBLEMA_PRODUCTO_H
#define PCO_SITUACION_PROBLEMA_PRODUCTO_H
#include <iostream>
using namespace std;
#include <string>

class Producto {
private:
    string ID;
    string nombre;
    float precio;
    string tipo;
    int inventario;
    int descuento;
    bool promocion; //No se si manejarlo como bool o string "2x1","3x2"
public:
    Producto();
    Producto(string cNombre, string cID, float cPrecio, string cTipo);

    void agregarDescuento(int porcentaje);
    void agregarPromocion();

    double precioDescontado();
    void aplicarDescuento(); //creo que este sería metodo de Super (agregar otro articulo si promocion = true)y7

    void restock(int unidades); //usar para rehabastecer inventario o regresar cantidad si se cancela compra
    void quitar(int unidades); //usar al momento de comprar

    void print();
};


#endif //PCO_SITUACION_PROBLEMA_PRODUCTO_H