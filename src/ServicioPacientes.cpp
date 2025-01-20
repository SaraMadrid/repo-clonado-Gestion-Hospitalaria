#include "ServicioPacientes.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>

// Constructor que inicializa servicioArchivos
ServicioPacientes::ServicioPacientes(const std::string& rutaArchivo)
    : servicioArchivos(rutaArchivo) {}

void ServicioPacientes::agregarPaciente(const Paciente& paciente) {
    pacientes.push_back(paciente);
    guardarPacientesEnArchivo("pacientes.txt");
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
        throw std::runtime_error("No se pudo abrir el archivo para leer.");
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        Paciente paciente;
        paciente.deserializar(linea);
        pacientes.push_back(paciente);
    }

    archivo.close();
}

void ServicioPacientes::guardarPacientesEnArchivo(const std::string& ruta) const {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo para escribir.");
    }

    for (const auto& paciente : pacientes) {
        archivo << paciente.serializar() << std::endl;
    }

    archivo.close();
}

void ServicioPacientes::generarReporteDePacientes(const std::string& rutaReporte) const {
    servicioArchivos.generarReportePacientes(pacientes);
}











