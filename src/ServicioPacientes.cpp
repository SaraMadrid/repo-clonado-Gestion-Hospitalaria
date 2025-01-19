#include "ServicioPacientes.h"
#include <algorithm>  


void ServicioPacientes::agregarPaciente(const Paciente& paciente) {
    pacientes.push_back(paciente);
}


Paciente* ServicioPacientes::buscarPacientePorId(int id) {
    for (auto& paciente : pacientes) {
        if (paciente.getId() == id) {
            return &paciente;
        }
    }
    return nullptr;
}


std::vector<Paciente> ServicioPacientes::obtenerTodosLosPacientes() const {
    return pacientes;
}

bool ServicioPacientes::eliminarPaciente(int id) {
    
    auto it = std::remove_if(pacientes.begin(), pacientes.end(),
                             [id](const Paciente& paciente) { return paciente.getId() == id; });

    
    if (it != pacientes.end()) {
        pacientes.erase(it, pacientes.end());
        return true; // El paciente fue eliminado
    }

    return false; // El paciente no se pudo eliminar
}








