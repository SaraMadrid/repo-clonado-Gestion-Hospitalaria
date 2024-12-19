#include "Servicios.h"
#include <algorithm>
#include <iostream>


void ServicioPacientes::altaPaciente(const Paciente& paciente) {
    listaPacientes.push_back(paciente);
    std::cout << "Paciente agregado correctamente: " << paciente.getNombre() << "\n";
}

void ServicioPacientes::modificarDatos(int idPaciente, const std::string& nuevoNombre) {
    auto it = std::find_if(listaPacientes.begin(), listaPacientes.end(),
        [idPaciente](const Paciente& p) { return p.getIdPaciente() == idPaciente; });

    if (it != listaPacientes.end()) {
        *it = Paciente(idPaciente, nuevoNombre, it->getDireccion(), it->getTelefono());
        std::cout << "Datos del paciente actualizados.\n";
    } else {
        std::cout << "Error: Paciente no encontrado.\n";
    }
}

void ServicioPacientes::bajaPaciente(int idPaciente) {
    listaPacientes.erase(std::remove_if(listaPacientes.begin(), listaPacientes.end(),
        [idPaciente](const Paciente& p) { return p.getIdPaciente() == idPaciente; }),
        listaPacientes.end());
    std::cout << "Paciente eliminado.\n";
}

// ServicioMedicos
void ServicioMedicos::altaMedico(const Medico& nuevo) {
    listaMedicos.push_back(nuevo);
    std::cout << "Médico agregado.\n";
}

void ServicioMedicos::bajaMedico(int idMedico) {
    listaMedicos.erase(std::remove_if(listaMedicos.begin(), listaMedicos.end(),
        [idMedico](const Medico& m) { return m.getIdMedico() == idMedico; }), listaMedicos.end());
    std::cout << "Médico eliminado.\n";
}

// ServicioCitas
void ServicioCitas::agendarCita(int idPaciente, int idMedico, const std::string& fecha, const std::string& motivo) {
    listaCitas.push_back(Cita(listaCitas.size() + 1, idPaciente, idMedico, fecha, motivo));
    std::cout << "Cita agendada.\n";
}

void ServicioCitas::cancelarCita(int idCita) {
    listaCitas.erase(std::remove_if(listaCitas.begin(), listaCitas.end(),
        [idCita](const Cita& c) { return c.getIdCita() == idCita; }), listaCitas.end());
    std::cout << "Cita cancelada.\n";
}

// ServicioReportes
void ServicioReportes::generarReporteAtencion(int idMedico) {
    std::cout << "Generando reporte de atención para el médico con ID: " << idMedico << std::endl;
}

void ServicioReportes::reporteCitasPendientes() {
    std::cout << "Generando reporte de citas pendientes..." << std::endl;
}

// ServicioArchivos
void ServicioArchivos::guardarDatos() {
    std::cout << "Guardando datos..." << std::endl;
}

void ServicioArchivos::cargarDatos() {
    std::cout << "Cargando datos..." << std::endl;
}

void ServicioArchivos::backup() {
    std::cout << "Realizando backup..." << std::endl;
}
