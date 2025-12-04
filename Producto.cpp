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
}
Producto::Producto(string cNombre, string cID, float cPrecio, string cTipo):nombre(cNombre), ID(cID), precio(cPrecio), tipo(cTipo) {
    inventario = 5;
}

void Producto::restock(int unidades) {
    this -> inventario += unidades;
}

void Producto::quitar(int unidades) {
    this -> inventario -= unidades;
}

bool Producto::hayExistencia( int unidades){
    return (inventario >= unidades);
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
}
