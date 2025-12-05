// main.cpp
// Programa principal que simula un punto de autocobro de supermercado.
// Flujo general:
// 1) Se crea un `Inventario` con productos iniciales.
// 2) Se cargan clientes de ejemplo.
// 3) Bucle infinito que representa sesiones sucesivas de clientes:
//    - Seleccionar cliente por ID
//    - Crear un `Carrito` nuevo para la sesión
//    - Ofrecer menú para ver productos, agregar al carrito, ver carrito,
//      ver datos del cliente y finalizar compra
//    - Al finalizar la compra se actualizan puntos y stock

#include <iostream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <string>

#include "producto.h"
#include "inventario.h"
#include "carrito.h"
#include "cliente.h"

using namespace std;

// ================= MENU =================

void mostrarMenuPrincipal()
{
    system("cls");
    cout << "==========================================\n";
    cout << "  Supermercado \"LA CHAMBA\" - Autocobro   \n";
    cout << "==========================================\n";
    cout << "1. Ver productos\n";
    cout << "2. Agregar producto al carrito\n";
    cout << "3. Ver carrito\n";
    cout << "4. Ver datos del cliente\n";
    cout << "5. Finalizar compra\n";
    cout << "0. Cerrar sesion (cliente)\n" << endl;
}

int leerEntero(const string& mensajeEntrada, const string& mensajeError)
{
    int valor;

    while (true)
    {
        cout << mensajeEntrada;

        if (cin >> valor)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
        else
        {
            cout << mensajeError;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
        }
    }
}

// ================= MAIN =================

int main()
{
    // ===== Inventario compartido por todos los clientes =====
    Inventario inventario;
    inventario.agregarProducto(Producto(1, "Manzana", 5.5, 100));
    inventario.agregarProducto(Producto(2, "Leche", 22.0, 50));
    inventario.agregarProducto(Producto(3, "Pan", 15.0, 80));

    // ===== Clientes registrados (hardcodeados) =====
    vector<Cliente> clientesRegistrados;
    Cliente::cargarClientesEjemplo(clientesRegistrados);

    // ===== Ciclo infinito de sesiones de clientes =====
    while (true)
    {
        // ----- 1) Seleccionar cliente por ID -----
        Cliente clienteActual;
        bool clienteValido = false;

        system("cls");
        cout << "===== Autocobro Supermercado \"LA CHAMBA\" =====\n";
        cout << "Clientes de ejemplo:\n";
        for (size_t i = 0; i < clientesRegistrados.size(); ++i)
        {
            cout << "  ID: " << clientesRegistrados[i].getId()
                 << " | Nombre: " << clientesRegistrados[i].getNombre()
                 << " | Puntos: " << clientesRegistrados[i].getPuntos() << "\n";
        }
        cout << "\n";

        while (!clienteValido)
        {
            int idBuscado = leerEntero(
                "Pase su tarjeta (ingrese ID de cliente, por ejemplo 1001): ",
                "Entrada invalida, ingresa un numero...\n"
            );

            for (size_t i = 0; i < clientesRegistrados.size(); ++i)
            {
                if (clientesRegistrados[i].getId() == idBuscado)
                {
                    clienteActual = clientesRegistrados[i];
                    clienteValido = true;
                    break;
                }
            }

            if (!clienteValido)
            {
                cout << "ID de cliente no encontrado. Intente nuevamente.\n";
                system("pause");
            }
        }

        cout << "\nBienvenido/a, " << clienteActual.getNombre()
             << " (ID: " << clienteActual.getId() << ")\n";
        cout << "Puntos actuales: " << clienteActual.getPuntos() << "\n\n";
        system("pause");

        // ----- 2) Carrito NUEVO para este cliente -----
        Carrito carrito;
        int opcion = -1;

        // ----- 3) Menú de autocobro para este cliente -----
        do
        {
            mostrarMenuPrincipal();
            opcion = leerEntero("Opcion: ", "Entrada Invalida, ingresa un numero ...\n");
            cout << "\n";

            switch (opcion)
            {
            case 1:
                inventario.mostrarProductos();
                system("pause");
                break;

            case 2:
            {
                int id, cantidad;

                inventario.mostrarProductos();
                cout << "\n";

                id = leerEntero("Ingresa el ID del producto que deseas agregar: ",
                                "No es un ID numerico ... \n\n");

                Producto* productoEncontrado = inventario.buscarProductoPorId(id);

                if (productoEncontrado == nullptr)
                {
                    cout << "No se encontro un producto con ese ID.\n\n";
                    system("pause");
                    break;
                }

                cantidad = leerEntero("Ingresa la cantidad que deseas: ",
                                      "Entrada Invalida, ingresa un numero ...\n");

                if (cantidad <= 0)
                {
                    cout << "La cantidad debe ser mayor que cero.\n\n";
                    system("pause");
                    break;
                }

                if (cantidad > productoEncontrado->getStock())
                {
                    cout << "No hay suficiente stock. Stock disponible: "
                         << productoEncontrado->getStock() << "\n\n";
                    system("pause");
                    break;
                }

                carrito.agregarProducto(productoEncontrado, cantidad);
                productoEncontrado->reducirStock(cantidad);

                cout << "Producto agregado al carrito.\n\n";
                system("pause");
                break;
            }

            case 3:
                carrito.mostrarCarrito();
                system("pause");
                break;

            case 4:
            {
                system("cls");
                cout << "===== DATOS DEL CLIENTE =====\n";
                cout << "ID: " << clienteActual.getId() << "\n";
                cout << "Nombre: " << clienteActual.getNombre() << "\n";
                cout << "Puntos acumulados: " << clienteActual.getPuntos() << "\n";
                cout << "=============================\n\n";
                system("pause");
                break;
            }

            case 5:
            {
                if (carrito.estaVacio())
                {
                    cout << "El carrito esta vacio. No hay nada que pagar.\n\n";
                    system("pause");
                    break;
                }

                cout << "Cliente: " << clienteActual.getNombre()
                     << " (ID: " << clienteActual.getId() << ")\n";
                cout << "RESUMEN DE COMPRA:\n";
                carrito.mostrarCarrito();

                int confirmar = leerEntero(
                    "¿Confirmar compra? (1 = si, 0 = no): ",
                    "Entrada invalida, ingresa 1 o 0...\n"
                );

                if (confirmar == 1)
                {
                    double total = carrito.calcularTotal();
                    clienteActual.acumularPuntos(total);

                    cout << "Compra realizada con exito. ¡Gracias por su compra, "
                         << clienteActual.getNombre() << "!\n";
                    cout << "Total de la compra: $" << total << "\n";
                    cout << "Puntos acumulados ahora: " << clienteActual.getPuntos() << "\n\n";

                    // Actualizar el cliente en la lista de registrados
                    for (size_t i = 0; i < clientesRegistrados.size(); ++i)
                    {
                        if (clientesRegistrados[i].getId() == clienteActual.getId())
                        {
                            clientesRegistrados[i] = clienteActual;
                            break;
                        }
                    }

                    carrito.vaciar();
                }
                else
                {
                    cout << "Compra cancelada. El carrito se mantiene igual.\n\n";
                }

                system("pause");
                break;
            }

            case 0:
                cout << "Cerrando sesion de " << clienteActual.getNombre() << "...\n\n";
                system("pause");
                break;

            default:
                cout << "Opcion invalida, intenta de nuevo.\n\n";
                system("pause");
                break;
            }

        } while (opcion != 0);
        // Aquí termina la sesión de este cliente,
    }

    return 0;
}
