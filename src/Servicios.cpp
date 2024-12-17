#include "Servicios.h"
#include <algorithm>
#include <iostream>

// Implementación de ServicioPacientes
void ServicioPacientes::altaPaciente(const Paciente& nuevo) {
    listaPacientes.push_back(nuevo);
    std::cout << "Paciente agregado.\n";
}

void ServicioPacientes::modificarDatos(int idPaciente, const std::string& nuevoNombre) {
    for (auto& paciente : listaPacientes) {
        if (paciente.getIdPaciente() == idPaciente) {
            paciente = Paciente(idPaciente, nuevoNombre, paciente.getDireccion(), paciente.getTelefono());
            std::cout << "Datos del paciente actualizados.\n";
            return;
        }
    }
    std::cout << "Paciente no encontrado.\n";
}

void ServicioPacientes::bajaPaciente(int idPaciente) {
    listaPacientes.erase(std::remove_if(listaPacientes.begin(), listaPacientes.end(),
        [idPaciente](const Paciente& p) { return p.getIdPaciente() == idPaciente; }), listaPacientes.end());
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


