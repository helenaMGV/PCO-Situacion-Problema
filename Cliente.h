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
    Cliente();
    Cliente(string cNombre, float cDinero);

    int buscarProducto (string cNombreProducto);
    void agregarProducto (Supermercado & cTienda);
    void quitarProducto(string cNombreProducto, Supermercado &cTienda);
    void vaciarCarrito();
    void mostrarCarrito();

    vector<Producto>& getCarrito();

    bool confirmarCompra();
    float calcularTotal();
    void pagar();
};



#endif //PCO_SITUACION_PROBLEMA_CLIENTE_H
