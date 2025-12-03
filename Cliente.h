//
// Created by Karla on 03/12/2025.
//

#ifndef PCO_SITUACION_PROBLEMA_CLIENTE_H
#define PCO_SITUACION_PROBLEMA_CLIENTE_H

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
    void agregarProducto (string cNombreProducto);
    void quitarProducto (string cNombreProducto);
    void vaciarCarrito();
    void mostrarCarrito();
    bool confirmarCompra();
    float calcularTotal();
    void pagar();
};



#endif //PCO_SITUACION_PROBLEMA_CLIENTE_H
