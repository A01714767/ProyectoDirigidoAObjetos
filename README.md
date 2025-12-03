# ProyectoDirigidoAObjetos
"El supermercado llamado la chamba quiere actualizarse y busca un sistema de autocobro y me lo encargaron a mi un estudiante del tec"
Este documento describe las correcciones realizadas en el proyecto del sistema de supermercado, así como la relación de cada ajuste con los indicadores y sub-competencias solicitados en los avances 1, 2 y 3.
El propósito es demostrar la mejora progresiva del diseño, la implementación orientada a objetos y la calidad del código.

1. Corrección y estandarización de constructores y métodos

Se revisaron y corrigieron los constructores de varias clases para asegurar que coincidieran con la forma en que se instancian los objetos dentro del programa.
También se verificó que todos los métodos esenciales estuvieran implementados correctamente (getters, setters, y comportamiento básico).

Sub-competencia relacionada:
Codifico métodos y atributos de clase correctamente (constructores, getters, setters). — Avance 1

Dónde impacta:
En todas las clases que requieren inicialización de datos.

2. Encapsulamiento adecuado y acceso seguro a atributos

Se corrigió el acceso directo a atributos para garantizar el uso de métodos públicos como getters y setters.
Este ajuste asegura el uso correcto del encapsulamiento y evita malas prácticas de manipulación directa de datos internos.

Sub-competencia relacionada:
Compruebo el acceso a los atributos y métodos de la clase (encapsulamiento correcto). — Avance 1

Dónde impacta:
En las clases principales del sistema.

3. Implementación correcta de composición

Se reforzó el modelo de composición en el cual un objeto forma parte integral de otro y no puede existir de manera independiente.
Ejemplo de ello es la relación entre un cliente y su carrito, y la relación entre un carrito y la lista de productos que contiene.

Sub-competencia relacionada:
Implemento composición siguiendo mi diagrama de clases. — Avance 3

Dónde impacta:
En la estructura interna de las clases que contienen a otras como parte de su funcionamiento esencial.

4. Implementación de agregación

Se corrigió el uso del concepto de agregación, que se da cuando una clase utiliza objetos externos sin tener propiedad total sobre ellos.
Este concepto se aplicó para representar elementos que son gestionados pero no “poseídos” por completo.

Sub-competencia relacionada:
Utilizo el concepto de composición (o agregación) en el diagrama de clases. — Avance 3

Dónde impacta:
En las relaciones entre clases que administran colecciones externas.

5. Integración adecuada del concepto de herencia

Se añadió herencia útil para extender funcionalidades del sistema sin duplicar código.
Esto permitió modelar tipos específicos de productos que comparten comportamiento común pero tienen características particulares.

Sub-competencia relacionada:
Utilizo el concepto de herencia en el diagrama de clases de manera adecuada. — Avance 2 y 3

Dónde impacta:
En la jerarquía de clases derivadas a partir de una clase base.

6. Mejoras en el diagrama UML

Se rediseñó el diagrama UML para que representara de manera clara y profesional:

Herencia

Composición

Agregación

Métodos y atributos de cada clase

El diagrama actualizado refleja con precisión la estructura real del proyecto.

Sub-competencia relacionada:
Modelo un diagrama de clases útil para solucionar un problema utilizando UML. — Avance 2

Dónde impacta:
En la documentación visual del sistema.

7. Correcciones en el uso de objetos dentro del programa

Se verificó que la creación y el uso de objetos coincidiera con los constructores y la estructura interna del proyecto.
Además, se añadieron pruebas y llamadas directas a métodos para comprobar el funcionamiento del diseño implementado.

Sub-competencia relacionada:
Compruebo el acceso a los atributos y métodos de la clase mandando a llamar los objetos de forma útil. — Avance 1

Dónde impacta:
En la lógica que utiliza las clases.

8. Limpieza y estandarización del código

Se revisaron nombres, indentaciones, estilo, convenciones y comentarios.
Se eliminó redundancia, se mejoró la claridad y se aplicó un estilo uniforme.

Sub-competencia relacionada:
Sigo estándares en todo mi código fuente. — Avance 3

Dónde impacta:
En toda la base de código del proyecto.

9. Organización y estándares del repositorio

Se organizaron los recursos del proyecto, se limpiaron elementos innecesarios, y se dejó únicamente lo esencial para su ejecución y lectura.
Se añadió documentación sobre propósito, uso y alcance del proyecto.

Sub-competencia relacionada:
Cumplo con estándares en mi repositorio: README claro, sin archivos basura, explicación correcta. — Avance 1

Dónde impacta:
En la estructura general del repositorio.

10. Control de versiones y commits significativos

Se registraron los cambios principales del desarrollo utilizando una herramienta de control de versiones.
Cada corrección mayor quedó asociada a un commit representativo para demostrar el progreso.

Sub-competencia relacionada:
Uso una herramienta para control de versiones y guardo avances en commits. — Avances 1 y 3

Dónde impacta:
En el historial del repositorio.
