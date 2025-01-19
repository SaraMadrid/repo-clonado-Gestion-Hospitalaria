#include "ServicioMedicos.h"

void ServicioMedicos::agregarMedico(const Medico& medico) {
    medicos.push_back(medico);
}


Medico* ServicioMedicos::buscarMedicoPorId(int id) {
    for (auto& medico : medicos) {
        if (medico.getId() == id) {
            return &medico;
        }
    }
    return nullptr;
}


std::vector<Medico> ServicioMedicos::obtenerTodosLosMedicos() const {
    return medicos;
}


void ServicioMedicos::eliminarMedico(int id) {
    medicos.erase(std::remove_if(medicos.begin(), medicos.end(),
                    [id](const Medico& medico) { return medico.getId() == id; }),
                    medicos.end());
}





