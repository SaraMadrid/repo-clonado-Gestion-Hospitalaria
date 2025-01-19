#ifndef SERVICIOPACIENTES_H
#define SERVICIOPACIENTES_H

#include <vector>
#include <algorithm>
#include <fstream>
#include "Paciente.h"
#include "ServicioArchivos.h"

class ServicioPacientes {
private:
    std::vector<Paciente> pacientes;
    ServicioArchivos servicioArchivos;

public:
    void agregarPaciente(const Paciente& paciente) {
        pacientes.push_back(paciente);
    }

    Paciente* buscarPacientePorId(int id) {
        auto it = std::find_if(pacientes.begin(), pacientes.end(),
            [id](const Paciente& paciente) { return paciente.getId() == id; });
        return it != pacientes.end() ? &(*it) : nullptr;
    }

    std::vector<Paciente> obtenerTodosLosPacientes() const {
        return pacientes;
    }

    bool eliminarPaciente(int id) {
        auto it = std::remove_if(pacientes.begin(), pacientes.end(),
            [id](const Paciente& paciente) { return paciente.getId() == id; });
        if (it != pacientes.end()) {
            pacientes.erase(it, pacientes.end());
            return true;
        }
        return false;
    }

    void cargarPacientesDesdeArchivo(const std::string& ruta) {
        std::ifstream archivo(ruta);
        std::string linea;
        while (std::getline(archivo, linea)) {
            Paciente paciente;
            paciente.deserializar(linea);
            agregarPaciente(paciente);
        }
    }

    void guardarPacientesEnArchivo(const std::string& ruta) const {
        std::ofstream archivo(ruta);
        for (const auto& paciente : pacientes) {
            archivo << paciente.serializar() << std::endl;
        }
    }

    
};

#endif









