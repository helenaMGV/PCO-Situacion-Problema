//
// Created by Karla on 03/12/2025.
//

#ifndef PCO_SITUACION_PROBLEMA_CLIENTE_H
#define PCO_SITUACION_PROBLEMA_CLIENTE_H
#include "Producto.h"

#include <string>
#include <vector>
using namespace std;
class Supermercado;

class Cliente {
private:
    string nombre;
    vector <Producto> carrito;
    float dinero;
    float total;

public:
    //CONSTRUCTOR
    Cliente();
    Cliente(string cNombre, float cDinero);

    //SETTER
    void setTotal(float cTotal);

    //METODOS PRODUCTO
    int buscarProducto (string cNombreProducto);
    void agregarProducto (Supermercado & cTienda);
    void quitarProducto(string cNombreProducto, Supermercado &cTienda);

    //METODOS CARRITO
    void vaciarCarrito();
    void mostrarCarrito();

    struct ProductoResumen {
        string nombre;
        float precio;
        int cantidad;
    };
    vector<ProductoResumen> getResumenCarrito() const;

    //METODOS COMPRA
    bool confirmarCompra();
    float calcularTotal();
    void pagar();

    ~Cliente();
};



#endif //PCO_SITUACION_PROBLEMA_CLIENTE_H
