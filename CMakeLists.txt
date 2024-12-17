cmake_minimum_required(VERSION 3.10)
project(GestionHospitalaria)

# Establece el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Todos los archivos fuente
set(SOURCES
    main.cpp
    InterfazHospital.cpp
    Modelos.cpp
    Servicios.cpp
)

# Incluye los encabezados
include_directories(${CMAKE_SOURCE_DIR})

# Crea el ejecutable
add_executable(GestionHospitalaria ${SOURCES})
