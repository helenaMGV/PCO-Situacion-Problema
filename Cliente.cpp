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
    getline(cin, nombreProducto);

    cout << "¿Cuantas unidades desea agregar? ";
    cin >> unidades;
    cin.ignore();

    vector<Producto>& inventario = cTienda.getProductos();
    bool encontrado = false;

    for (auto& p : inventario) {
        if (p.getNombre() == nombreProducto) {
            if (!p.hayExistencia(unidades)) {
                cout << "No hay inventario suficiente. Existencia: " << p.getInventario() << endl;
                return;
            }

            p.quitar(unidades);

            for (int i = 0; i < unidades; i++) {
                carrito.push_back(p);
            }

            cout << "Se agregaron " << unidades << " unidad(es) de " << nombreProducto << " al carrito"<< endl;

            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "El producto '" << nombreProducto << "' no existe en el supermercado"<< endl;
    }
}


void Cliente::quitarProducto(string cNombreProducto, Supermercado &cTienda) {
    int unidades;

    cout << "¿Cuantas unidades desea quitar? ";
    cin >> unidades;

    int contadorQuitados = 0;

    // 1Encontrar producto en inventario del Supermercado
    vector<Producto>& inventario = cTienda.getProductos();
    Producto* productoSuper = nullptr;

    //designar objeto por referencia a producto buscado
    for (auto& p : inventario) {
        if (p.getNombre() == cNombreProducto) {
            productoSuper = &p;
            break;
        }
    }

    //Si el producto a eliminar no existe
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
            productoSuper->restock(contadorQuitados);

        } else {
            i++;
        }
    }

    // Resultados
    if (contadorQuitados == 0) {
        cout << "El producto '" << cNombreProducto << "' no esta en el carrito." << endl;
    } else {
        cout << "Se quitaron " << contadorQuitados << " unidad(es) de " << cNombreProducto << "." << endl;
    }
}

void Cliente::vaciarCarrito() {
    carrito.clear();
}
void Cliente::mostrarCarrito() {
    if (carrito.size() == 0) {
        cout << "Su carrito esta vacio" << endl;
    }
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
