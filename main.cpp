#include <iostream>
using namespace std;
#include "Producto.h"
#include "Supermercado.h"
#include "Cliente.h"

int main() {
    Supermercado superDonaMary;
    superDonaMary.leerFichero("Productos.txt");

    Cliente clienteA("Sasha", 100);
    superDonaMary.setCliente(clienteA);


    //TESTEO CLASE CLIENTE
    cout << "--------- Bienvenido a Super Dona Mary ---------" << endl;
    bool salir = false;
    int opcion;

    while (!salir) {

        cout << "--------MENU-------"<< endl;
        cout << "1. Mostrar productos disponibles"<< endl;;
        cout << "2. Agregar producto al carrito" << endl;;
        cout << "3. Quitar producto del carrito" << endl;
        cout << "4. Mostrar carrito" << endl;
        cout << "5. Pagar" << endl;
        cout << "6. Salir" << endl;
        cout << "Elige una opcion: " << endl;
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                superDonaMary.mostrarProductos();
                break;

            case 2: {
                clienteA.agregarProducto(superDonaMary);
                break;
            }

            case 3: {
                cout << "Ingrese el nombre del producto a eliminar: ";
                string nombreEliminar;
                getline(cin, nombreEliminar);
                clienteA.quitarProducto(nombreEliminar, superDonaMary);
                break;
            }

            case 4:
                clienteA.mostrarCarrito();
                break;

            case 5:
                if (clienteA.confirmarCompra()) {
                    cout << "Desea pagar sin contacto o regularmente?: (S: Sin Contacto, R:Regularmente) "<<endl;
                    char opcionPago;
                    cin >> opcionPago;
                    switch (opcionPago) {
                        //PAGAR SIN CONTACTO
                        case 'S':
                        superDonaMary.pagoSinContacto();
                            superDonaMary.realizarVenta();
                            cout << "Gracias por su compra"<<endl;
                            salir = true;
                            break;

                        //PAGAR REGULARMENTE
                        case 'R':
                            superDonaMary.realizarVenta();
                            cout << "Gracias por su compra"<<endl;
                            salir = true;
                            break;
                    }

                } else {
                    cout << "No tiene dinero suficiente"<<endl;
                }
                break;

            case 6:
                cout << "Saliendo del Super Dona Mary"<<endl;
                salir = true;
                break;

            default:
                cout << "Opcion inválida. Intente de nuevo"<<endl;
                break;
        }
    }

    //TESTEO DE CLASE SUPERMERCADO Y PRODUCTO
    Producto huevo("huevo","H123", 34.00, "Producto Animal");
    superDonaMary.agregarProducto(huevo);
    superDonaMary.mostrarProductos();
    superDonaMary.restockProducto("H123", 20);
    superDonaMary.mostrarProductos();
    cout << "Ventas realizadas: " << superDonaMary.getVentas() << endl;
    return 0;
}
