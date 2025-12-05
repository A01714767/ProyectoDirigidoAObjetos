#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "persona.h"

// cliente.h
// Clase `Cliente` que hereda de `Persona` y agrega comportamiento
// específico de clientes (puntos, acumulación de puntos, utilidades
// para crear clientes de ejemplo). Utilizar esta clase para llevar
// información adicional del cliente en las sesiones de compra.

class Cliente : public Persona   // HEREDA de Persona
{
private:
    int puntos; // algo extra del cliente

public:
    // Constructor por defecto
    Cliente()
        : Persona(0, "Invitado"), puntos(0)
    {
    }

    // Constructor con parámetros
    Cliente(int _id, const std::string& _nombre, int _puntos = 0)
        : Persona(_id, _nombre), puntos(_puntos)
    {
    }

    // Getter específico de Cliente
    int getPuntos() const
    {
        return puntos;
    }

    void setPuntos(int _puntos)
    {
        puntos = _puntos;
    }

    // Acumular puntos según el total de la compra
    void acumularPuntos(double totalCompra)
    {
        // Ejemplo: 1 punto por cada $10
        puntos += static_cast<int>(totalCompra / 10.0);
    }

    // ====== MÉTODO ESTÁTICO: CARGAR CLIENTES DE EJEMPLO ======
    static void cargarClientesEjemplo(std::vector<Cliente>& clientes)
    {
        clientes.clear();
        clientes.push_back(Cliente(1001, "Juan Perez", 20));
        clientes.push_back(Cliente(1002, "Maria Lopez", 50));
        clientes.push_back(Cliente(1003, "Carlos Sanchez", 0));
    }
};

#endif // CLIENTE_H
