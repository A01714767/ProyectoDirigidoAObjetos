#include <iostream>
#include <vector>
using namespace std;

// ---------------------------------------------------------
// Clase Producto
// ---------------------------------------------------------
class Producto {
private:
    string nombre;
    double precio;
    double peso;

public:
    // Constructor vacío
    Producto() : nombre(""), precio(0.0), peso(0.0) {}

    // Constructor con parámetros
    Producto(string n, double p, double w)
        : nombre(n), precio(p), peso(w) {}

    // Getters
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    double getPeso() const { return peso; }

    // Setters
    void setNombre(string n) { nombre = n; }
    void setPrecio(double p) { precio = p; }
    void setPeso(double w) { peso = w; }
};

// ---------------------------------------------------------
// Clase CarritoAutocobro
// ---------------------------------------------------------
class CarritoAutocobro {
private:
    vector<Producto> carrito;
    double total;

public:
    // Constructor
    CarritoAutocobro() : total(0.0) {}

    // Método para agregar producto
    void agregarProducto(const Producto& p) {
        carrito.push_back(p);
        total += p.getPrecio();
        cout << "Producto agregado: " << p.getNombre() 
             << " | $" << p.getPrecio() << endl;
    }

    // Método para mostrar el total
    double getTotal() const { return total; }

    // Método para mostrar los productos del carrito
    void mostrarCarrito() const {
        cout << "\n--- Productos en el Carrito ---\n";
        for (const auto& p : carrito) {
            cout << p.getNombre() << " - $" << p.getPrecio() 
                 << " - " << p.getPeso() << " kg\n";
        }
        cout << "-------------------------------\n";
    }

    // Método para pagar
    void pagar() {
        cout << "\nTOTAL A PAGAR: $" << total << endl;
        cout << "Pago realizado con éxito. ¡Gracias por su compra!\n";
        carrito.clear();
        total = 0.0;
    }
};

// ---------------------------------------------------------
// Función principal
// ---------------------------------------------------------
int main() {
    // Crear algunos productos
    Producto manzana("Manzana", 5.0, 0.2);
    Producto leche("Leche", 22.5, 1.0);
    Producto pasta("Pasta", 14.0, 0.5);

    // Crear el sistema de autocobro
    CarritoAutocobro caja;

    // Agregar productos
    caja.agregarProducto(manzana);
    caja.agregarProducto(leche);
    caja.agregarProducto(pasta);

    // Mostrar carrito
    caja.mostrarCarrito();

    // Mostrar total
    cout << "\nTotal actual: $" << caja.getTotal() << endl;

    // Pagar
    caja.pagar();

    return 0;
}
