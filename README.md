# Proyecto Básico en C++

Este es un proyecto simple en C++ que demuestra la estructura de una aplicación básica utilizando funciones de utilidad.

## Estructura del Proyecto

```
basic-cpp-project
├── src
│   ├── main.cpp
│   └── utils.cpp
├── include
│   └── utils.h
├── Makefile
└── README.md
```

## Descripción de Archivos

- **src/main.cpp**: El punto de entrada de la aplicación. Inicializa el programa y llama a funciones del módulo `utils`.
- **src/utils.cpp**: Implementa funciones de utilidad declaradas en el archivo de encabezado `utils.h`.
- **include/utils.h**: Declara las funciones de utilidad que se implementan en `utils.cpp`.
- **Makefile**: Contiene las instrucciones de compilación para el proyecto.

## Instrucciones de Compilación

Para compilar el proyecto, navega al directorio del proyecto y ejecuta el siguiente comando:

```
make
```

Esto compilará los archivos fuente y creará el ejecutable.

## Ejecutar la Aplicación

Después de compilar el proyecto, puedes ejecutar la aplicación con el siguiente comando:

```
./app
```

## Licencia

Este proyecto es de código abierto y está disponible bajo la Licencia MIT.