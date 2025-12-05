#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include "producto.h"


// inventario.h
// Clase `Inventario` mantiene una lista de `Producto` y ofrece
// operaciones de consulta y listado. `buscarProductoPorId` devuelve
// un puntero al producto dentro del vector para permitir modificaciones
// directas de stock desde el código que usa el inventario.

// Clase que representa el inventario de la tienda
class Inventario
{
private:
    std::vector<Producto> productos;

public:
    // Agregar un producto al inventario
    void agregarProducto(const Producto& p)
    {
        productos.push_back(p);
    }

    // Mostrar todos los productos
    void mostrarProductos() const
    {
        std::cout << "==== INVENTARIO DE PRODUCTOS ====\n";
        if (productos.empty())
        {
            std::cout << "No hay productos en el inventario.\n";
            return;
        }

        for (size_t i = 0; i < productos.size(); ++i)
        {
            std::cout << "ID: " << productos[i].getId() << " | "
                 << "Nombre: " << productos[i].getNombre() << " | "
                 << "Precio: $" << productos[i].getPrecio() << " | "
                 << "Stock: " << productos[i].getStock() << "\n";
        }
        std::cout << "=================================\n\n";
    }

    // Buscar un producto por ID (devuelve puntero o nullptr si no existe)
    Producto* buscarProductoPorId(int idBuscado)
    {
        for (size_t i = 0; i < productos.size(); ++i)
        {
            if (productos[i].getId() == idBuscado)
            {
                return &productos[i]; // dirección del producto en el vector
            }
        }
        return nullptr; // no se encontró
    }
};

#endif // INVENTARIO_H
