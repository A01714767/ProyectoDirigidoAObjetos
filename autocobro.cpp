#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// ---------------------------------------------------------
// Clase Producto
// ---------------------------------------------------------
class Producto {
private:
    string nombre;
    double precio;
    double peso;

public:
    // Constructor por defecto
    Producto() : nombre(""), precio(0.0), peso(0.0) {}

    // Constructor con parámetros
    Producto(const string& nombre, double precio, double peso)
        : nombre(nombre), precio(precio), peso(peso) {}

    // Getters
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    double getPeso() const { return peso; }

    // Setters
    void setNombre(const string& nombre) { this->nombre = nombre; }
    void setPrecio(double precio) { this->precio = precio; }
    void setPeso(double peso) { this->peso = peso; }

    // Método extra
    void mostrarInfo() const {
        cout << "Producto: " << nombre 
             << " | Precio: $" << precio
             << " | Peso: " << peso << " kg" << endl;
    }
};

// ---------------------------------------------------------
// Clase CarritoAutocobro
// ---------------------------------------------------------
class CarritoAutocobro {
private:
    vector<Producto> productos;
    double total;

public:
    // Constructor
    CarritoAutocobro() : total(0.0) {}

    // Método para agregar productos
    void agregarProducto(const Producto& producto) {
        productos.push_back(producto);
        total += producto.getPrecio();
        cout << "Agregado al carrito: " << producto.getNombre() << endl;
    }

    // Mostrar lista de productos
    void mostrarCarrito() const {
        cout << "\n--- Carrito Actual ---\n";
        for (const auto& p : productos) {
            p.mostrarInfo();
        }
    }

    // Obtener total
    double getTotal() const { return total; }

    // Método de pago
    void pagar() {
        cout << "\nTotal a pagar: $" << total << endl;
        cout << "Pago exitoso. Gracias por su compra.\n";
    }
};

// ---------------------------------------------------------
// Función principal
// ---------------------------------------------------------
int main() {
    // Crear objetos de cada clase
    Producto producto1("Manzana", 5.0, 0.2);
    Producto producto2("Leche", 22.5, 1.0);
    Producto producto3;

    // Probar setters en producto3
    producto3.setNombre("Pasta");
    producto3.setPrecio(14.0);
    producto3.setPeso(0.5);

    // Mostrar información para demostrar getters y método extra
    producto1.mostrarInfo();
    producto2.mostrarInfo();
    producto3.mostrarInfo();

    // Crear objeto de autocobro
    CarritoAutocobro caja;

    // Llamar métodos para demostrar su funcionamiento
    caja.agregarProducto(producto1);
    caja.agregarProducto(producto2);
    caja.agregarProducto(producto3);

    caja.mostrarCarrito();
    cout << "\nTotal actual: $" << caja.getTotal() << endl;

    // Procesar pago
    caja.pagar();

    return 0;
}
