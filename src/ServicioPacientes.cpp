#include "ServicioPacientes.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <iostream>


ServicioPacientes::ServicioPacientes(const std::string& rutaArchivo)
    : servicioArchivos(rutaArchivo) {}

void ServicioPacientes::agregarPaciente(const Paciente& paciente) {
    pacientes.push_back(paciente);
    guardarPacientesEnArchivo("pacientes.txt");
}

void ServicioPacientes::guardarPacientesEnArchivo(const std::string& ruta) const {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo para escribir.");
    }

    for (const auto& paciente : pacientes) {
        archivo << paciente.serializar() << '\n';  
    }

    archivo.close();
}

Paciente* ServicioPacientes::buscarPacientePorId(int id) {
    auto it = std::find_if(pacientes.begin(), pacientes.end(),
        [id](const Paciente& paciente) { return paciente.getId() == id; });
    return it != pacientes.end() ? &(*it) : nullptr;
}

const std::vector<Paciente>& ServicioPacientes::obtenerTodosLosPacientes() const {
    return pacientes;
}

bool ServicioPacientes::eliminarPaciente(int id) {
    auto it = std::remove_if(pacientes.begin(), pacientes.end(),
        [id](const Paciente& paciente) { return paciente.getId() == id; });
    if (it != pacientes.end()) {
        pacientes.erase(it, pacientes.end());
        guardarPacientesEnArchivo("pacientes.txt");
        return true;
    }
    return false;
}

void ServicioPacientes::cargarPacientesDesdeArchivo(const std::string& ruta) {
    
    std::ifstream archivo(ruta);  

    if (!archivo.is_open()) {
        std::cerr << "El archivo no existe. Creando un archivo nuevo en la ruta: " << ruta << std::endl;
        
        std::ofstream archivo_creado(ruta);  
        if (!archivo_creado.is_open()) {
            throw std::runtime_error("No se pudo crear el archivo para escribir.");
        }

        // Ejemplos
        archivo_creado << "1,Juan Pérez,30,Calle Ficticia 123,555-1234\n";
        archivo_creado << "2,María López,25,Calle Ejemplo 456,555-5678\n";
        archivo_creado << "3,Carlos García,40,Calle Real 789,555-9101\n";
        archivo_creado.close();  
        
        
        archivo.open(ruta);  
        if (!archivo.is_open()) {
            throw std::runtime_error("No se pudo abrir el archivo para leer después de crearlo.");
        }
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        Paciente paciente;
        paciente.deserializar(linea);  
        pacientes.push_back(paciente);  
    }

    archivo.close();  
}