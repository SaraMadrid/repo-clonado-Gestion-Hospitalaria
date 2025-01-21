#include "ServicioArchivos.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"


ServicioArchivos::ServicioArchivos() : nombreArchivo("") {
   
}

ServicioArchivos::ServicioArchivos(const std::string& archivo) : nombreArchivo(archivo) {
    if (!archivo.empty()) {
        std::ofstream archivoInicial(archivo, std::ios::app);
        if (!archivoInicial) {
            throw std::runtime_error("No se pudo crear o abrir el archivo: " + archivo);
        }
    }
}

// Leer datos del archivo
std::string ServicioArchivos::leer() {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        throw std::runtime_error("No se pudo abrir el archivo para leer");
    }
    std::ostringstream contenido;
    contenido << archivo.rdbuf();
    return contenido.str();
}

// Limpiar el archivo
void ServicioArchivos::limpiar() {
    std::ofstream archivo(nombreArchivo, std::ios::trunc);
    if (!archivo) {
        throw std::runtime_error("No se pudo abrir el archivo para limpiar");
    }
}

// Leer líneas desde un archivo
std::vector<std::string> ServicioArchivos::leerLineasDesdeArchivo(const std::string& ruta) {
    std::vector<std::string> lineas;
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo para leer líneas.");
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        lineas.push_back(linea);
    }

    archivo.close();
    return lineas;
}

// Generar reporte de pacientes
void ServicioArchivos::generarReportePacientes(const std::vector<Paciente>& pacientes) const {
    std::ofstream archivo("reporte_pacientes.txt");
    if (!archivo) {
        std::cerr << "Error al crear el archivo de reporte de pacientes.\n";
        return;
    }

    archivo << "--- Reporte de Pacientes ---\n";
    for (const auto& paciente : pacientes) {
        archivo << "ID: " << paciente.getId() << "\n"
                << "Nombre: " << paciente.getNombre() << "\n"
                << "Edad: " << paciente.getEdad() << "\n"
                << "Dirección: " << paciente.getDireccion() << "\n"
                << "Teléfono: " << paciente.getTelefono() << "\n"
                << "-------------------------\n";
    }
}

// Generar reporte de médicos
void ServicioArchivos::generarReporteMedicos(const std::vector<Medico>& medicos) const {
    std::ofstream archivo("reporte_medicos.txt");
    if (!archivo) {
        std::cerr << "Error al crear el archivo de reporte de médicos.\n";
        return;
    }

    archivo << "--- Reporte de Médicos ---\n";
    for (const auto& medico : medicos) {
        archivo << "ID: " << medico.getId() << "\n"
                << "Nombre: " << medico.getNombre() << "\n"
                << "Especialidad: " << medico.getEspecialidad() << "\n"
                << "-------------------------\n";
    }
}

// Generar reporte de citas
void ServicioArchivos::generarReporteCitas(const std::vector<Cita>& citas) const {
    std::ofstream archivo("reporte_citas.txt");
    if (!archivo) {
        std::cerr << "Error al crear el archivo de reporte de citas.\n";
        return;
    }

    archivo << "--- Reporte de Citas ---\n";
    for (const auto& cita : citas) {
        archivo << "ID Cita: " << cita.getId() << "\n"
                << "ID Paciente: " << cita.getIdPaciente() << "\n"
                << "ID Médico: " << cita.getIdMedico() << "\n"
                << "Fecha: " << cita.getFecha() << "\n"
                << "Hora: " << cita.getHora() << "\n"
                << "-------------------------\n";
    }
}























