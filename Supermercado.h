//
// Created by Diego on 02/12/2025.
//

#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H
#include <fstream>
#include <string>
#include <vector>
#include "Producto.h"
#include "Cliente.h"

class Supermercado {
private:
  string nombre;
  Cliente clienteActual;
  vector<Producto> productos;
  int ventas;

public:
  Supermercado();
  Supermercado(const string &cNombre, const Cliente &cCLiente);

  void leerFichero(const string & fichero);
  void agregarProducto(const Producto &cProducto);
  void eliminarProducto(const string &ID);
  int buscarProducto(const string &ID);

  Cliente& getCliente();

  vector<Producto>& getProductos();
  void mostrarProductos() ;

  bool realizarVenta();
  int getVentas() const;


~Supermercado();
};

#endif /* SUPERMERCADO_H */

