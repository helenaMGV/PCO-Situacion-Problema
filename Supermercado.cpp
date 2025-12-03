#include "Supermercado.h"
#include <iostream>

using namespace std>;

Supermercado::Supermercado() { 
nombre = "";
ventas = 0; }

Supermercado::Supermercado(const string &cNombre, const Cliente &cCliente) {
nombre = cNombre;
cliente = cCliente;
ventas = 0;
}
void Supermercado::agregarProducto(const Producto &cProducto) {
    productos.push_back(cProducto);
}

void Supermercado::eliminarProducto(const string &ID) {
    int index = buscarProducto(ID);
    if (index != -1) {
        productos.erase(productos.begin() + index);
        cout << "Producto eliminado.\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}

int Supermercado::buscarProducto(const string &ID) {
    for (int i = 0; i < productos.size(); i++) {
        if (productos[i].getID() == ID) {
            return i;
        }
    }
    return -1;
}

Cliente& Supermercado::getCliente() {
    return cliente;
}

void Supermercado::mostrarProductos() const {
    cout << "\n--- Inventario del Supermercado ---\n";
    for (const auto &p : productos) {
        p.print();
        cout << "   Inventario: " << p.getInventario() << endl;
        cout << "------------------------------\n";
    }
}

bool Supermercado::realizarVenta() {

    float total = cliente.calcularTotal();

    if (total <= 0) {
        cout << "El carrito está vacío.\n";
        return false;
    }

    if (!cliente.confirmarCompra()) {
        cout << "El cliente no tiene suficiente dinero.\n";
        return false;
    }

    // Descontar inventario
    for (const auto &prodCarrito : cliente.getCarrito()) {

        int index = buscarProducto(prodCarrito.getID());
        if (index != -1) {
            productos[index].quitar(1);  // 1 unidad
        }
    }

    cliente.pagar();
    ventas++;

    cout << "Venta realizada con éxito.\n";
    return true;
}

int Supermercado::getVentas() const {
    return ventas;
}

Supermercado::~Supermercado() {
    // No necesitas hacer nada especial aquí
}
