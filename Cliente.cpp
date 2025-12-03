//
// Created by Karla on 03/12/2025.
//

#include "Cliente.h"
#include "Supermercado.h"
#include "Producto.h"
#include <iostream>
using namespace std;
#include <string>


Cliente::Cliente() {
    nombre = "";
    dinero = 0.0;
    total = 0.0;
}

Cliente::Cliente(string cNombre, float cDinero) {
    nombre = cNombre;
    dinero = cDinero;
    total = 0.0;
}

void Cliente::agregarProducto(Supermercado &cTienda) {
    string nombreProducto;
    int unidades;

    cout << "Ingrese el nombre del producto que desea agregar: ";
    cin >> nombreProducto;

    cout << "¿Cuántas unidades desea agregar? ";
    cin >> unidades;

    vector<Producto>& inventario = cTienda.getProductos();

    for (auto& p : inventario) {
        if (p.getNombre() == nombreProducto) {

            if (!p.hayExistencia(unidades)) {
                cout << "No hay inventario suficiente. Existencia: "
                     << p.getInventario() << endl;
                return;
            }

            p.quitar(unidades);

            for (int i = 0; i < unidades; i++) {
                carrito.push_back(p);
            }

            cout << "Se agregaron " << unidades
                 << " unidad(es) de " << nombreProducto
                 << " al carrito.\n";
            break;
        }
    }
    cout << "El producto '" << nombreProducto << "' no existe en el supermercado.\n";
}


void Cliente::quitarProducto(string cNombreProducto, Supermercado &cTienda) {
    int unidades;

    cout << "¿Cuántas unidades desea quitar? ";
    cin >> unidades;

    int contadorQuitados = 0;

    // 1Encontrar producto en inventario del Supermercado
    vector<Producto>& inventario = cTienda.getProductos();
    Producto* productoSuper = nullptr;

    for (auto& p : inventario) {
        if (p.getNombre() == cNombreProducto) {
            productoSuper = &p;
            break;
        }
    }

    if (productoSuper == nullptr) {
        cout << "Error: producto no encontrado en tienda." << endl;
        return;
    }

    // Quitar del carrito y regresar inventario
    for (int i = 0; i < carrito.size() && contadorQuitados < unidades; ) {
        if (carrito[i].getNombre() == cNombreProducto) {
            carrito.erase(carrito.begin() + i);
            contadorQuitados++;

            // Regresar inventario
            productoSuper->restock(1);

        } else {
            i++;
        }
    }

    // Resultados
    if (contadorQuitados == 0) {
        cout << "El producto '" << cNombreProducto
             << "' no está en el carrito." << endl;
    } else {
        cout << "Se quitaron " << contadorQuitados
             << " unidad(es) de " << cNombreProducto << "." << endl;
    }
}

void Cliente::vaciarCarrito() {
    carrito.clear();
}
void Cliente::mostrarCarrito() {
    for (int i = 0; i < carrito.size(); i++) {
        cout << carrito[i].getNombre()<< " - $" << carrito[i].getPrecio()<< endl;
    }
}


    float Cliente::calcularTotal() {
        total = 0.0;  // REINICIAR
        for (int i = 0; i < carrito.size(); i++) {
            total += carrito[i].getPrecio();
        }
        return total;
    }

bool Cliente::confirmarCompra() {
        float totalCompra = calcularTotal();
        return (dinero >= totalCompra);
    }

void Cliente::pagar() {
    cout << "Total a pagar:" << total << endl;
    dinero -= total;
    cout << "Dinero restante: " << dinero << endl;
}
vector<Producto>& Cliente::getCarrito() {
    return carrito;
}
