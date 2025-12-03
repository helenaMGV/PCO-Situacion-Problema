#include <iostream>
using namespace std;
#include "Producto.h"
#include "Supermercado.h"
#include "Cliente.h"

int main() {
    Supermercado OXXO;
    string archivo = "Productos.txt";
    OXXO.leerFichero(archivo);
    Cliente ClienteInicial("Sasha", 100);

}


