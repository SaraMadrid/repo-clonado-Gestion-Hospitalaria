#include "ServicioPacientes.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <unordered_set>

ServicioPacientes::ServicioPacientes(const std::string& rutaArchivo) {
    cargarPacientesDesdeArchivo(rutaArchivo);
}

void ServicioPacientes::agregarPaciente(const Paciente& paciente) {
    if (paciente.getDireccion().empty() || paciente.getTelefono().empty()) {
        throw std::runtime_error("La dirección y el teléfono no pueden estar vacíos.");
    }
    
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
}

Paciente* ServicioPacientes::buscarPacientePorId(int id) {
    auto it = std::find_if(pacientes.begin(), pacientes.end(),
        [id](const Paciente& paciente) { return paciente.getId() == id; });
    return it != pacientes.end() ? &(*it) : nullptr;
}

const std::vector<Paciente>& ServicioPacientes::obtenerTodosLosPacientes() const {
    return pacientes;
}

void ServicioPacientes::modificarPaciente(int id, const Paciente& nuevoPaciente) {
    if (nuevoPaciente.getDireccion().empty() || nuevoPaciente.getTelefono().empty()) {
        throw std::runtime_error("La dirección y el teléfono no pueden estar vacíos.");
    }

    bool encontrado = false;
    for (auto& paciente : pacientes) {
        if (paciente.getId() == id) {
            paciente = nuevoPaciente;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        throw std::runtime_error("Paciente no encontrado");
    }

    guardarPacientesEnArchivo("pacientes.txt");
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
        std::ofstream archivo_creado(ruta);
        if (!archivo_creado.is_open()) {
            throw std::runtime_error("No se pudo crear el archivo de pacientes.");
        }
        archivo_creado.close();
        return;
    }

    pacientes.clear(); // Evita duplicaciones al recargar los datos

    std::unordered_set<int> idsUnicos; 
    std::string linea;
    
    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue;

        Paciente paciente;
        try {
            paciente.deserializar(linea);

            if (idsUnicos.count(paciente.getId()) > 0) {
                std::cerr << "Advertencia: Paciente con ID duplicado encontrado y omitido: " 
                          << paciente.getId() << "\n";
                continue;
            }

            idsUnicos.insert(paciente.getId());
            pacientes.push_back(paciente);
        } catch (const std::exception& e) {
            std::cerr << "Error al cargar paciente: " << e.what() << "\n";
        }
    }
}




