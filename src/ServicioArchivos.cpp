#include "ServicioArchivos.h"
#include <fstream>
#include <iostream>
#include <vector>

// Leer líneas de un archivo y devolverlas como un vector de cadenas
std::vector<std::string> ServicioArchivos::leerArchivo(const std::string& rutaArchivo) {
    std::vector<std::string> lineas;
    std::ifstream archivo(rutaArchivo);

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << rutaArchivo << "\n";
        return lineas;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        lineas.push_back(linea);
    }

    archivo.close();
    return lineas;
}

// Escribir líneas en un archivo
void ServicioArchivos::escribirArchivo(const std::string& rutaArchivo, const std::vector<std::string>& lineas) const {
    std::ofstream archivo(rutaArchivo);

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escritura: " << rutaArchivo << "\n";
        return;
    }

    for (const std::string& linea : lineas) {
        archivo << linea << "\n";
    }

    archivo.close();
}

// Generar un reporte de pacientes en un archivo
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

// Generar un reporte de médicos en un archivo
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

// Generar un reporte de citas en un archivo
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

























