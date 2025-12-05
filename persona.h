#ifndef PERSONA_H
#define PERSONA_H

#include <string>

// persona.h
// Clase base `Persona` que contiene campos comunes a todas las
// personas que interactúan con el sistema (por ejemplo clientes).
// Los miembros `id` y `nombre` son protegidos para que las clases
// derivadas puedan acceder a ellos.

class Persona
{
protected:
    int id;              // protected: accesible en las clases hijas
    std::string nombre;  // pero no desde fuera

public:
    // Constructor por defecto
    Persona()
        : id(0), nombre("Sin nombre")
    {
    }

    // Constructor con parámetros
    Persona(int _id, const std::string& _nombre)
        : id(_id), nombre(_nombre)
    {
    }

    // Getters
    int getId() const
    {
        return id;
    }

    std::string getNombre() const
    {
        return nombre;
    }

    // Setters
    void setId(int _id)
    {
        id = _id;
    }

    void setNombre(const std::string& _nombre)
    {
        nombre = _nombre;
    }
};

#endif // PERSONA_H
