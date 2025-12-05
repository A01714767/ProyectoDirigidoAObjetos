#ifndef CARRITO_H
#define CARRITO_H

#include <iostream>
#include <vector>
#include "producto.h"


// carrito.h
// Tipos y operaciones relacionadas con el carrito de compras.
// `ItemCarrito` modela una linea del carrito (un producto y su cantidad)
// y `Carrito` contiene la colección de líneas y operaciones básicas
// como agregar, mostrar, calcular total y vaciar.

// Representa un renglón en el carrito (producto + cantidad)
struct ItemCarrito
{
    Producto* producto; // puntero al producto en el inventario
    int cantidad;
};

// Clase que representa el carrito de compras de un cliente
class Carrito
{
private:
    std::vector<ItemCarrito> items;

public:
    // Agregar un producto al carrito
    void agregarProducto(Producto* producto, int cantidad)
    {
        if (producto == nullptr || cantidad <= 0)
        {
            return;
        }

        // Si ya existe en el carrito, solo aumentamos la cantidad
        for (size_t i = 0; i < items.size(); ++i)
        {
            if (items[i].producto->getId() == producto->getId())
            {
                items[i].cantidad += cantidad;
                return;
            }
        }

        // Si no estaba en el carrito, lo agregamos nuevo
        ItemCarrito nuevo;
        nuevo.producto = producto;
        nuevo.cantidad = cantidad;
        items.push_back(nuevo);
    }

    bool estaVacio() const
    {
        return items.empty();
    }

    // Mostrar el contenido del carrito
    void mostrarCarrito() const
    {
        std::cout << "===== CARRITO DE COMPRAS =====\n";
        if (items.empty())
        {
            std::cout << "El carrito esta vacio.\n\n";
            return;
        }

        double total = 0.0;

        for (size_t i = 0; i < items.size(); ++i)
        {
            const Producto* p = items[i].producto;
            int cantidad = items[i].cantidad;
            double subtotal = p->getPrecio() * cantidad;

            std::cout << "ID: " << p->getId()
                 << " | Nombre: " << p->getNombre()
                 << " | Cantidad: " << cantidad
                 << " | Precio unitario: $" << p->getPrecio()
                 << " | Subtotal: $" << subtotal << "\n";

            total += subtotal;
        }

        std::cout << "Total a pagar: $" << total << "\n\n";
    }

    double calcularTotal() const
    {
        double total = 0.0;
        for (size_t i = 0; i < items.size(); ++i)
        {
            total += items[i].producto->getPrecio() * items[i].cantidad;
        }
        return total;
    }

    void vaciar()
    {
        items.clear();
    }
};

#endif // CARRITO_H
