#include <iostream>
using namespace std;
#include "Producto.h"
#include "Supermercado.h"
#include "Cliente.h"

int main() {
    Supermercado Abarrotes;
    Abarrotes.leerFichero("Productos.txt");

    Cliente clienteA("Sasha", 100);
    Abarrotes.setCliente(clienteA);

    cout << "--------- Bienvenido a Abarrotes 'Doña Maria' ---------" << endl;

    bool salir = false;
    int opcion;

    while (!salir) {

        cout << "-------- MENU -------" << endl;
        cout << "1. Mostrar productos disponibles" << endl;
        cout << "2. Agregar producto al carrito" << endl;
        cout << "3. Quitar producto del carrito" << endl;
        cout << "4. Mostrar carrito" << endl;
        cout << "5. Pagar" << endl;
        cout << "6. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                Abarrotes.mostrarProductos();
                break;

            case 2: {
                clienteA.agregarProducto(Abarrotes);
                break;
            }

            case 3: {
                cout << "Ingrese el nombre del producto a eliminar: ";
                string nombreEliminar;
                getline(cin, nombreEliminar);
                clienteA.quitarProducto(nombreEliminar, Abarrotes);
                break;
            }

            case 4:
                clienteA.mostrarCarrito();
                break;

            case 5:
                if (clienteA.confirmarCompra()) {
                    cout << "Desea pagar sin contacto o regularmente?: (S: Sin Contacto, R: Regularmente) ";
                    char opcionPago;
                    cin >> opcionPago;

                    switch (opcionPago) {
                        case 'S':
                            Abarrotes.pagoSinContacto();
                            Abarrotes.realizarVenta();
                            cout << "\nGracias por su compra" << endl;
                            salir = true;
                            break;

                        case 'R':
                            Abarrotes.realizarVenta();
                            cout << "\nGracias por su compra" << endl;
                            salir = true;
                            break;

                        default:
                            cout << "Opción inválida" << endl;
                            break;
                    }
                } else {
                    cout << "No tiene dinero suficiente" << endl;
                }
                break;

            case 6:
                cout << "Saliendo de Abarrotes 'Doña Maria'" << endl;
                salir = true;
                break;

            default:
                cout << "Opción inválida. Intente de nuevo" << endl;
                break;
        }
    }

    // TESTEO DE SUPERMERCADO Y PRODUCTO
    Producto huevo("huevo", "H123", 34.00, "Producto Animal");
    Abarrotes.agregarProducto(huevo);
    Abarrotes.mostrarProductos();
    Abarrotes.restockProducto("H123", 20);
    Abarrotes.mostrarProductos();

    cout << "Ventas realizadas: " << Abarrotes.getVentas() << endl;
    return 0;
}
