//
// Created by Diego on 02/12/2025.
//

#infdef SUPERMERCADO_H
#define SUPERMERCADO_H

#include <string>
#include <vector>
#include "Producto.h"
#include "Cliente.h"

class Supermercado {
private:
  string nombre;
  Cliente clientes;
  vector<Producto> productos;
  int ventas;
public:
  Supermercado();
  Supermercado(const string &cNombre, const Cliente &cCLiente);
  void agregarProducto(const Producto &cProducto);
  void eliminarProducto(const string &ID);
  int buscarProducto(const string &ID);
  Cliente& getCliente();
  void mostrarProductos() const;
  bool realizarVenta();
  int getVentas() const;

~Supermercado();
};

#endif /* SUPERMERCADO_H */

