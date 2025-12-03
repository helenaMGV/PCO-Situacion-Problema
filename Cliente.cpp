//
// Created by Karla on 03/12/2025.
//

#include "Cliente.h"
Cliente::Cliente() {
    nombre = "";
    carrito = {};
    dinero = 0.0;
    total = 0.0;
}

Cliente::Cliente(string cNombre, float cDinero) {
    nombre = cNombre;
    dinero = cDinero;
    dinero = 0.0;
    total = 0.0;
}

void Cliente::agregarProducto(Supermercado &cTienda) {
    string nombreProducto;
    int unidades;

    cout << "Ingrese el nombre del producto que desea agregar: ";
    cin >> nombreProducto;

    cout << "¿Cuántas unidades desea agregar? ";
    cin >> unidades;

    // Obtener inventario del supermercado
    vector<Producto>& inventario = tienda.getProductos();

    // Buscar el producto
    for (auto& p : inventario) {
        if (p.getNombre() == nombreProducto) {

            // Agregar N unidades
            for (int i = 0; i < unidades; i++) {
                carrito.push_back(p);
            }

            cout << "Se agregaron " << unidades << " unidad(es) de "
                 << p.getNombre() << " al carrito." << endl;
            return;
        } else
            cout << "El producto '" << nombreProducto << "' no existe en el supermercado." << endl;
    }


    void Cliente::quitarProducto() {
        string nombreProducto;
        int unidades;

        cout << "Ingrese el nombre del producto que desea quitar: ";
        cin >> nombreProducto;

        cout << "¿Cuántas unidades desea quitar? ";
        cin >> unidades;

        int contadorQuitados = 0;

        // Recorrer el carrito y eliminar los productos por nombre
        for (int i = 0; i < carrito.size() && contadorQuitados < unidades; ) {
            if (carrito[i].getNombre() == nombreProducto) {
                carrito.erase(carrito.begin() + i);
                contadorQuitados++;
            } else {
                i++; // solo avanzamos si NO borramos
            }
        }

        if (contadorQuitados == 0) {
            cout << "El producto '" << nombreProducto
                 << "' no está en el carrito." << endl;
        }
        else {
            cout << "Se quitaron " << contadorQuitados
                 << " unidad(es) de " << nombreProducto << "." << endl;
        }
    }

void Cliente::vaciarCarrito() {
    carrito.clear();
}
void Cliente::mostrarCarrito() {
    for (int i = 0; i < carrito.size(); i++) {
        cout << carrito[i].getNombre() << carrito endl;
}

void Cliente::confirmarCompra() {
    return (dinero > calcularTotal())
}
void Cliente::calcularTotal() {
for (int i = 0; i < carrito.size(); i++) {
total += carrito[i].getPrecio();
}
void Cliente::pagar() {
    cout << "Total a pagar:" << total << endl;
    dinero -= total;
    cout << "Dinero restante: " << dinero << endl;
}
