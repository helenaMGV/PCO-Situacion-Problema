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
public:
    Producto();
    Producto(string cNombre, string cID, float cPrecio, string cTipo);

//Getters 
    string getID() const;
    string getNombre() const;
    float getPrecio() const;
    int getInventario() const;
    
    bool hayExistencia(int unidades);
    void restock(int unidades); //usar para rehabastecer inventario o regresar cantidad si se cancela compra
    void quitar(int unidades); //usar al momento de comprar

    void print();
};


#endif //PCO_SITUACION_PROBLEMA_PRODUCTO_H
