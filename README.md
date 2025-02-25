# Proyecto de Gestión Hospitalaria 

Este proyecto es un simulador de gestión hospitalaria desarrollado en C++. Permite gestionar pacientes, médicos, citas y generar reportes.

## Estructura del Proyecto

- `src/`: Código fuente del proyecto.
- `Datos/`: Almacenamiento de datos.
- `Documentos/`: Documentación del proyecto.
- `Makefile`: Archivo para compilar el proyecto.

## Compilación y Ejecución

Sigue estos pasos para compilar el proyecto correctamente:

### 1. Clonar el repositorio  
Abre la terminal y ejecuta:  

```sh
git clone https://github.com/usuario/proyecto.git
cd proyecto

### 2. Crear la carpeta build y generar los archivos con CMake

mkdir build
cd build
cmake ..

### 3. Compilar el proyecto
cmake --build .

### 4.  Ejecutar el programa
./Debug/GestionHospitalaria.exe
