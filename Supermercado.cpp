#include "Supermercado.h"
#include "Cliente.h"
#include <iostream>
#include <fstream>

using namespace std;

Supermercado::Supermercado() { 
nombre = "";
ventas = 0; }

Supermercado::Supermercado(const string &cNombre, const Cliente &cCliente) {
nombre = cNombre;
clienteActual = cCliente;
ventas = 0;
}

void Supermercado::agregarProducto(const Producto &cProducto) {
    productos.push_back(cProducto);
}

void Supermercado::eliminarProducto(const string &ID) {
    int index = buscarProducto(ID);
        // index -1 : No existe: Producto no encontrado
    if (index != -1) {
        //eliminar producto con (inicio + index = index) pasado por parametro
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

void Supermercado::restockProducto(const string & ID, int unidades) {
    int index = buscarProducto(ID);
    if (index != -1) {
        productos[index].restock(unidades);
    }
}

vector<Producto>& Supermercado::getProductos() {
    return productos;
}

Cliente& Supermercado::getCliente() {
    return clienteActual;
}

void Supermercado::mostrarProductos(){
    cout << endl << "--- Inventario del Supermercado ---" << endl;
    for (auto & cProducto : productos){
        cProducto.print();
        cout << "   Inventario: " << cProducto.getInventario() << endl;
        cout << "------------------------------" << endl;
    }
}

bool Supermercado::realizarVenta() {

    float total = clienteActual.calcularTotal();

    if (total <= 0) {
        cout << "El carrito esta vacio" << endl;
        return false;
    }

    if (!clienteActual.confirmarCompra()) {
        cout << "El cliente no prosiguio la compra" << endl;
        return false;
    }

    // Descontar inventario
    for (const auto &prodCarrito : clienteActual.getCarrito()) {

        int index = buscarProducto(prodCarrito.getID());
        if (index != -1) {
            productos[index].quitar(1);  // 1 unidad
        }
    }

    clienteActual.pagar();
    pagoSinContacto(); // Implementacion de pago sin contacto
    
    ventas++;

    cout << "Venta realizada con éxito" << endl;
    return true;
}

int Supermercado::getVentas() const {
    return ventas;
}

Supermercado::~Supermercado() {
    // Nada especial aquí
}

void Supermercado::leerFichero(const string & fichero) {
    ifstream archivo(fichero);
    if (!archivo.is_open()) {
        cout << "Error al abrir archivo.\n";
        return;
    }

    string id, nombre, tipo, precioStr;
    float precio;

    while (true) {
        // Leer las 4 líneas por producto
        if (!getline(archivo, id)) break;
        if (!getline(archivo, nombre)) break;
        if (!getline(archivo, tipo)) break;
        if (!getline(archivo, precioStr)) break;

        // Convertir precio string -> float
        precio = stof(precioStr);

        // Crear producto y agregarlo al vector
        Producto p(nombre, id, precio, tipo);
        productos.push_back(p);
    }

    archivo.close();
    cout << "Productos importados correctamente.\n";
}

// Metodo para simular pago con contacto
void Supermercado::pagoSinContacto(){
    cout << "Pago sin contacto procesado exitosamente"; 
}

