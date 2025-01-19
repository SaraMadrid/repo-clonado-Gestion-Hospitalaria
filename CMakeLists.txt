cmake_minimum_required(VERSION 3.10)
project(GestionHospitalaria)

# Establece el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Directorio donde se encuentran los encabezados
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Todos los archivos fuente
set(SOURCES
    src/main.cpp
    src/InterfazHospital.cpp
    src/Cita.cpp
    src/Medico.cpp
    src/Paciente.cpp
    src/ServicioCitas.cpp
    src/ServicioMedicos.cpp
    src/ServicioPacientes.cpp
    src/ServicioArchivos.cpp

)

# Incluye los encabezados
include_directories(${INCLUDE_DIR})

# Crea el ejecutable
add_executable(GestionHospitalaria ${SOURCES})
