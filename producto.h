#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <string>

// producto.h
// Definición de la clase `Producto` que modela un artículo vendible
// en el supermercado. Contiene identificador, nombre, precio y stock.
// Se usan métodos sencillos para consultar propiedades y para reducir
// el stock cuando se realiza una compra.

// Clase que representa un producto del supermercado
class Producto
{
private:
    int id;
    std::string nombre;
    double precio;
    int stock;

public:
    // Constructor
    Producto(int _id, const std::string& _nombre, double _precio, int _stock)
    {
        id = _id;
        nombre = _nombre;
        precio = _precio;
        stock = _stock;
    }

    // Getters
    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getStock() const { return stock; }

    // Para modificar el stock cuando alguien compra
    void reducirStock(int cantidad)
    {
        stock -= cantidad;
    }
};

#endif // PRODUCTOS_H
