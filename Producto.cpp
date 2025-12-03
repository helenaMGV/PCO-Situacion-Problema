//
// Created by helen on 01/12/2025.
//

#include "Producto.h"

Producto::Producto() {
    //TODOS OBJETOS EMPIEZAN VACIOS, CON 5 EN INVENTARIO, SIN DESCUENTO O PROMOCION
    ID = " ";
    nombre = " ";
    precio = 0.0;
    tipo = " ";
    inventario = 5;
    descuento = 0;
    promocion = false;
}
Producto::Producto(string cNombre, string cID, float cPrecio, string cTipo):nombre(cNombre), ID(cID), precio(cPrecio), tipo(cTipo) {
    inventario = 5;
    descuento = 0;
    promocion = false;
}
void Producto::agregarDescuento(int porcentaje) {
    this -> descuento = porcentaje;
}
void Producto::agregarPromocion() {
    this -> promocion = true;
}

double Producto::precioDescontado() {
   double descuento = precio * (this -> descuento/100);
    return precio - descuento;
}
double Producto::precioPromocion(){
    return precio/2;
}

void Producto::restock(int unidades) {
    this -> inventario += unidades;
}
void Producto::quitar(int unidades) {
    this -> inventario -= unidades;
}
string Producto::getID() const { 
    return ID; 
}
string Producto::getNombre() const { 
    return nombre; 
}
float Producto::getPrecio() const { 
    return precio; 
}
int Producto:: getInventario() const { 
    return inventario; 
}
void Producto::print() {
    cout << "Producto: "<< nombre << ", $" << precio << endl;
    cout << "   Tipo: " << tipo << endl;
    if (descuento > 0) {
        cout << "Descuento: " << descuento << endl;
    }
    if (promocion) {
        cout << "El producto tiene 2x1" << endl;
    }
}
