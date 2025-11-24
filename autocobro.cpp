#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// =============================
//         CLASE PRODUCTO
// =============================
class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    // Constructor
    Producto(string n, double p, int c) {
        nombre = n;
        precio = p;
        cantidad = c;
    }

    // Getters
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }

    // Setters
    void setNombre(string n) { nombre = n; }
    void setPrecio(double p) { precio = p; }
    void setCantidad(int c) { cantidad = c; }

    // Método para reducir inventario
    void vender() {
        if (cantidad > 0)
            cantidad--;
    }
};

// =============================
//        CLASE SUPERMERCADO
// =============================
class Supermercado {
private:
    vector<Producto> inventario;
    vector<Producto> carrito;
    double total;

public:

    // Constructor
    Supermercado() {
        total = 0;

        // Crear inventario inicial
        inventario.push_back(Producto("pan", 1.00, 20));
        inventario.push_back(Producto("leche", 1.50, 15));
        inventario.push_back(Producto("arroz", 2.00, 10));
        inventario.push_back(Producto("huevos", 2.50, 30));
        inventario.push_back(Producto("manzana", 0.75, 25));
    }

    // Buscar producto
    Producto* buscarProducto(string nombre) {
        for (auto &p : inventario)
            if (p.getNombre() == nombre)
                return &p;
        return nullptr;
    }

    // Agregar al carrito
    void agregarProducto(string nombre) {
        Producto* p = buscarProducto(nombre);
        if (p != nullptr && p->getCantidad() > 0) {
            carrito.push_back(*p);
            total += p->getPrecio();
            p->vender();
            cout << nombre << " agregado. Precio: $" << fixed << setprecision(2) 
                 << p->getPrecio() << endl;
        } else {
            cout << "Producto no disponible o sin existencias." << endl;
        }
    }

    // Aplicar descuento
    void aplicarDescuentoTerceraEdad() {
        double descuento = total * 0.10;
        total -= descuento;
        cout << "Se aplicó un descuento de $" << fixed << setprecision(2) 
             << descuento << endl;
    }

    // Mostrar ticket
    void mostrarTicket() {
        cout << "\n--- Ticket de compra ---\n";
        for (auto &p : carrito) {
            cout << p.getNombre() << " - $" 
                 << fixed << setprecision(2) << p.getPrecio() << endl;
        }
        cout << "Total a pagar: $" << fixed << setprecision(2) << total << endl;
        cout << "------------------------\n";
    }

    // Mostrar inventario
    void mostrarInventario() {
        cout << "\nInventario actual:\n";
        for (auto &p : inventario) {
            cout << p.getNombre()
                 << " - Precio: $" << fixed << setprecision(2) << p.getPrecio()
                 << " - Cantidad: " << p.getCantidad() << endl;
        }
    }
};

// =============================
//           MAIN
// =============================
int main() {
    Supermercado store;

    cout << "Bienvenido al autocobro del supermercado.\n";
    cout << "Escribe los productos uno por uno.\nEscribe 'fin' para terminar.\n\n";

    store.mostrarInventario();

    string producto;

    while (true) {
        cout << "Producto: ";
        cin >> producto;

        if (producto == "fin")
            break;

        store.agregarProducto(producto);
    }

    string respuesta;
    cout << "¿Es usted de la tercera edad? (si/no): ";
    cin >> respuesta;

    if (respuesta == "si") {
        store.aplicarDescuentoTerceraEdad();
    }

    store.mostrarTicket();
    store.mostrarInventario();

    return 0;
}

