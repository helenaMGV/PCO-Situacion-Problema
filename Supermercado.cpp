#include "Supermercado.h"
#include "Cliente.h"
#include <iostream>
#include <fstream>
using namespace std;

//                  CONSTRUCTORES
Supermercado::Supermercado() { 
nombre = "";
ventas = 0; }

Supermercado::Supermercado(const string &cNombre, const Cliente &cCliente) {
nombre = cNombre;
clienteActual = cCliente;
ventas = 0;
}

//                  METODOS PRODUCTO
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

void Supermercado::mostrarProductos(){
    cout << endl << "--- Inventario del Supermercado ---" << endl;
    for (auto & cProducto : productos){
        cProducto.print();
        cout << "   Inventario: " << cProducto.getInventario() << endl;
        cout << "------------------------------" << endl;
    }
}

void Supermercado::leerFichero(const string & fichero) {
    ifstream archivo(fichero);
    if (!archivo.is_open()) {
        cout << "Error al abrir archivo" << endl;
        return;
    }

    string id, nombre, tipo, precioStr;
    float precio;

    // Ignorar encabezado
    getline(archivo, id);

    while (true) {
        if (!getline(archivo, id, ',')) break;
        if (!getline(archivo, nombre, ',')) break;
        if (!getline(archivo, tipo, ',')) break;
        if (!getline(archivo, precioStr)) break; // Último campo

        precio = stof(precioStr);

        Producto p(nombre, id, precio, tipo);
        productos.push_back(p);
    }

    archivo.close();
    cout << "Productos importados correctamente" << endl;
}




//              METODOS CLIENTE
Cliente& Supermercado::getCliente() {
    return clienteActual;
}
void Supermercado::setCliente(Cliente &cCliente) {
    clienteActual = cCliente;
}



//              METODOS VENTA
bool Supermercado::realizarVenta() {
    // Calcular total del carrito y actualizar el atributo total del cliente
    float total = clienteActual.calcularTotal();

    // Verificar si el cliente tiene suficiente dinero
    if (!clienteActual.confirmarCompra()) {
        cout << "El cliente no tiene dinero suficiente" << endl;
        return false;
    }

    // Mostrar ticket
    cout << endl << "========== TICKET DE COMPRA ==========" << endl;

    vector<Producto> carrito = clienteActual.getCarrito();
    vector<string> productosEscaneados; // Para no repetir productos en el ticket

    //BUCLE REGISTRAR NOMBRE Y TOTAL Por cada producto
    for (int i = 0; i < carrito.size(); i++) {
        string nombre = carrito[i].getNombre();
        // Saltar proceso si ya se registro este producto
        bool yaRegistrado = false;
        for (int k = 0; k < productosEscaneados.size(); k++) {
            if (productosEscaneados[k] == nombre) {
                yaRegistrado = true;
                break;
            }
        }
        if (yaRegistrado) continue;

        // REGISTRAR UNIDADES de cada producto  en el carrito
        int unidades = 0;
        for (int j = 0; j < carrito.size(); j++) {
            if (carrito[j].getNombre() == nombre) unidades++;
        }
        //CALCULAR TOTAL POR PRODUCTO
        float subtotal = carrito[i].getPrecio() * unidades;
        cout << nombre << " x" << unidades << "  $" << subtotal << endl;

        //AGREGAR PRODUCTO A TICKET
        productosEscaneados.push_back(nombre);
    }

    cout << "--------------------------------------" << endl;
    cout << "TOTAL A PAGAR: $" << total << endl;
    cout << "--------------------------------------" << endl;

    // Procesar pago
    clienteActual.pagar();
    // Vaciar carrito para la próxima compra
    clienteActual.vaciarCarrito();
    // Incrementar ventas
    ventas++;
    cout << "Venta realizada con exito" << endl;
    return true;
}


int Supermercado::getVentas() const {
    return ventas;
}

// Metodo para simular pago con contacto
void Supermercado::pagoSinContacto(){
    cout << "Pago sin contacto procesado exitosamente";
}


//              DESTRUCTOR
Supermercado::~Supermercado() {
    // Nada especial aquí
}



