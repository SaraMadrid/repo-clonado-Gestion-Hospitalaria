#include "Servicios.h"
#include <iostream>

// Implementación de ServicioPacientes
void ServicioPacientes::altaPaciente(const Paciente& nuevo) {
    listaPacientes.push_back(nuevo);
    std::cout << "Paciente agregado.\n";
}

void ServicioPacientes::bajaPaciente(int idPaciente) {
    listaPacientes.erase(std::remove_if(listaPacientes.begin(), listaPacientes.end(),
        [idPaciente](const Paciente& p) { return p.getIdPaciente() == idPaciente; }), listaPacientes.end());
    std::cout << "Paciente eliminado.\n";
}



