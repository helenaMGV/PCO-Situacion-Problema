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
  vector<Producto>& getProductos();

public:
  //CONSTRUCTORES
  Supermercado();
  Supermercado(const string &cNombre, const Cliente &cCLiente);

  //  METODOS PRODUCTO
  void leerFichero(const string & fichero);
  void agregarProducto(const Producto & cProducto); //1. crear producto 2. pasar objeto directo
  void eliminarProducto(const string &ID);
  int buscarProducto(const string &ID);
  void restockProducto(const string &id, int unidades); //llama Metodo producto restock()
  void mostrarProductos() ; //usa metodo print de clase producto

    //METODOS CLIENTE
  Cliente& getCliente();
  void setCliente(Cliente &cCliente);


  //METODOS VENTA
  bool realizarVenta();
  int getVentas() const;
  void pagoSinContacto();

//DESTRUCTOR
~Supermercado();
};

#endif /* SUPERMERCADO_H */

