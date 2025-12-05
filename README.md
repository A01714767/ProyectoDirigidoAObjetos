# Supermercado 

Pequeña aplicación en C++ que simula un punto de autocobro en un supermercado.

Estructura de archivos

- `main.cpp`         : Programa principal y menú de interacción.
- `producto.h`       : Clase `Producto` (id, nombre, precio, stock).
- `persona.h`        : Clase base `Persona` (id, nombre).
- `cliente.h`        : Clase `Cliente` que hereda de `Persona` y maneja puntos.
- `carrito.h`        : `Carrito` y `ItemCarrito` para gestionar artículos en compra.
- `inventario.h`     : `Inventario` con búsqueda y listado de productos.

Compilar y ejecutar (Windows)

Opción A — Usando `g++` (MinGW/MSYS2):

1. Abre `PowerShell` en la carpeta del proyecto (`supermercado_v2`).
2. Compila con:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o supermercado.exe
```

3. Ejecuta:

```powershell
./supermercado.exe
```

Opción B — Usando Visual Studio (Developer Command Prompt / cl):

1. Abre "Developer Command Prompt for VS" o ejecuta las herramientas de compilador con las variables de entorno.
2. Compila:

```powershell
cl /EHsc /std:c++17 main.cpp
```

3. Ejecuta el `.exe` generado.

Notas

- El proyecto es de tipo pequeño y todos los archivos fuente/headers están en la misma carpeta; no hay Makefile por defecto.
- Si falta `g++`, puedes instalar MinGW-w64 o MSYS2, o usar Visual Studio Community.
- Si quieres, puedo generar un `Makefile` o un proyecto de Visual Studio (.vcxproj) para facilitar la compilación.

Siguientes pasos sugeridos

- Añadir documentación detallada (Doxygen) si quieres generar documentación HTML.
- Añadir un `Makefile` o `CMakeLists.txt` para facilitar compilación multiplataforma.
- Añadir pruebas unitarias pequeñas para validar comportamiento del carrito e inventario.

