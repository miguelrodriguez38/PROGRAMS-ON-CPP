# Prácticas de Computabilidad y Algoritmia

Este repositorio reúne una serie de ejercicios y proyectos desarrollados en C++ para la asignatura de Computabilidad y Algoritmia. A lo largo de las prácticas se trabajan conceptos fundamentales como contenedores, cadenas, alfabetos, lenguajes, expresiones regulares, autómatas finitos deterministas, gramáticas regulares y el entorno de programación básico.

La finalidad del proyecto es aplicar de forma práctica los fundamentos teóricos de la asignatura mediante programas que implementan algoritmos y estructuras relacionadas con la teoría de lenguajes formales y los autómatas.

## Objetivo del repositorio

El objetivo principal es consolidar conocimientos sobre:

- Estructuras de datos y contenedores en C++.
- Manipulación de cadenas y alfabetos.
- Definición y operación de lenguajes formales.
- Procesamiento de expresiones regulares.
- Simulación de autómatas finitos deterministas (DFA).
- Conversión entre autómatas y gramáticas regulares.
- Entorno de desarrollo y primeros programas en C++.

## Estructura del repositorio

### 1. IB-P0-EntornoIaaS

Carpeta dedicada a la introducción al entorno de trabajo de la asignatura. En ella se realizan ejercicios básicos para familiarizarse con el compilador, el entorno de ejecución y la creación de programas sencillos.

Incluye:

- `hello_world.cc`: programa mínimo de ejemplo.
- `hello_world`: ejecutable generado.
- `pell`: programa relacionado con la secuencia o cálculo de Pell.

Este bloque sirve como punto de partida para aprender a compilar y ejecutar programas en C++ dentro del entorno de la asignatura.

### 2. P01-Containers

Práctica centrada en el uso de contenedores y gestión de información asociada a alumnos y notas.

Incluye:

- `alumnos.h` y `alumnos.cc`: definición y lógica para gestionar alumnos.
- `p01_single_grades.cc`: manejo de una sola nota por alumno.
- `p01_multiple_grades.cc`: gestión de múltiples calificaciones.
- `grades.txt` y `grades2.txt`: ficheros de entrada con datos de ejemplo.

En esta práctica se trabaja la organización y almacenamiento de datos usando estructuras de tipo contenedor, así como la lectura de información desde archivos.

### 3. P02-CadenasyLenguajes

En esta práctica se introducen conceptos básicos de cadenas, alfabetos y lenguajes formales.

Se trabaja con:

- `Alfabeto.h` / `Alfabeto.cc`: representación de alfabetos.
- `Cadena.h` / `Cadena.cc`: manipulación de cadenas y operaciones elementales.
- `Lenguaje.h` / `Lenguaje.cc`: definición de lenguajes como conjuntos de cadenas.
- `Cliente.cc`: programa principal para probar las operaciones.

Esta práctica es una base esencial para comprender cómo se modelan lenguajes y cómo se representan formalmente cadenas dentro de la teoría de la computación.

### 4. P02-CadenasyLenguajesModificacion

Versión modificada o ampliada de la práctica anterior. Su propósito es reforzar la misma temática con ajustes, extensiones o mejoras en la implementación.

Permite ver cómo evolucionan los conceptos de alfabetos, cadenas y lenguajes cuando se añade funcionalidad adicional o se reorganiza la estructura del código.

### 5. P03-ExpresionesRegulares

Práctica orientada al tratamiento de expresiones regulares y análisis de documentos HTML.

Incluye clases como:

- `Tag.h` / `Tag.cc`: representación de etiquetas HTML.
- `Attribute.h` / `Attribute.cc`: atributos de etiquetas.
- `Comment.h` / `Comment.cc`: comentarios dentro del código HTML.
- `Link.h` / `Link.cc`: gestión de enlaces.
- `Html.h` / `Html.cc`: análisis global del documento HTML.

También se incluyen archivos de ejemplo como:

- `entrada.html`
- `modificacion.html`
- `salida.txt`

Aquí se aplican expresiones regulares para reconocer patrones estructurales en documentos HTML, como etiquetas, atributos, enlaces y comentarios.

### 6. P06_DFA_Simulator

Práctica dedicada a la simulación de un Autómata Finito Determinista (DFA).

Los archivos principales son:

- `Dfa.h` / `Dfa.cc`: definición del autómata.
- `Estado.h` / `Estado.cc`: representación de estados.
- `Alfabeto.h` / `Alfabeto.cc`: definición del alfabeto.
- `cliente.cc`: programa principal que ejecuta la simulación.
- `input.dfa` y `input.txt`: ejemplos de entrada.

La práctica muestra cómo un DFA procesa cadenas y decide si una secuencia es aceptada o rechazada según su estado final y la función de transición.

### 7. P08-GramaticaRegular

Esta práctica se centra en gramáticas regulares y en su relación con autómatas finitos.

Contiene elementos como:

- `Automata.h` / `Automata.cc`: representación del autómata.
- `Gramatica.h` / `Gramatica.cc`: definición de la gramática regular.
- `Produccion.h` / `Produccion.cc`: representación de producciones.
- `Estado.h` / `Estado.cc`: gestión de estados.
- `Cliente.cc`: programa de prueba.
- `input.dfa` y `output.gra`: ejemplos de entrada y salida.

El objetivo es convertir o relacionar un autómata con una gramática regular, demostrando la equivalencia entre ambos formalismos.

## Cómo ejecutar los programas

La mayoría de las carpetas incluyen un archivo `Makefile` para compilar fácilmente los ejercicios.

Ejemplo:

```bash
cd P06_DFA_Simulator
make
./cliente
```

También puede ejecutarse desde cada carpeta individual siguiendo la estructura del proyecto y el nombre del programa principal.

## Observación sobre la estructura

El repositorio presenta copias de algunas prácticas tanto en la raíz como dentro de la carpeta `C++PROGRAMS/`. Esto suele deberse a una organización de entrega o duplicado del material. En cualquier caso, las prácticas y su contenido principal son equivalentes.

## Conclusión

Este conjunto de ejercicios permite recorrer de forma práctica la teoría de la computabilidad y los lenguajes formales, combinando C++ con conceptos esenciales como cadenas, lenguajes, expresiones regulares, autómatas y gramáticas. Es un repositorio útil tanto para estudiar como para revisar la implementación de los principios fundamentales de la asignatura.

## Autor

Repositorio desarrollado para prácticas de Computabilidad y Algoritmia.
