#include "ServicioMedicos.h"
#include <iostream>
#include <algorithm>

ServicioMedicos::ServicioMedicos(const std::string& rutaArchivo)
    : archivoMedicos(rutaArchivo) {
    cargarMedicosDesdeArchivo(archivoMedicos);
}

void ServicioMedicos::agregarMedico(const Medico& medico) {
    medicos.push_back(medico);
    guardarMedicosEnArchivo(archivoMedicos);
}

Medico* ServicioMedicos::buscarMedicoPorId(int id) {
    for (auto& medico : medicos) {
        if (medico.getId() == id) {
            return &medico;
        }
    }
    return nullptr;
}

void ServicioMedicos::modificarMedico(int id, const Medico& nuevoMedico) {
    for (auto& medico : medicos) {
        if (medico.getId() == id) {
            medico = nuevoMedico;
            guardarMedicosEnArchivo(archivoMedicos);
            return;
        }
    }
    std::cerr << "Error: Médico con ID " << id << " no encontrado.\n";
}

void ServicioMedicos::eliminarMedico(int id) {
    auto it = std::remove_if(medicos.begin(), medicos.end(),
        [id](const Medico& medico) { return medico.getId() == id; });

    if (it != medicos.end()) {
        medicos.erase(it, medicos.end());
        guardarMedicosEnArchivo(archivoMedicos);
    } else {
        std::cerr << "Error: Médico con ID " << id << " no encontrado.\n";
    }
}

std::vector<Medico> ServicioMedicos::obtenerMedicos() const {
    return medicos;
}

void ServicioMedicos::cargarMedicosDesdeArchivo(const std::string& nombreArchivo) {
    std::vector<std::string> lineas = servicioArchivos.leerArchivo(nombreArchivo);
    medicos.clear();

    for (const std::string& linea : lineas) {
        Medico medico;
        medico.deserializar(linea);
        medicos.push_back(medico);
    }
}

void ServicioMedicos::guardarMedicosEnArchivo(const std::string& nombreArchivo) const {
    std::vector<std::string> lineas;
    for (const auto& medico : medicos) {
        lineas.push_back(medico.serializar());
    }
    servicioArchivos.escribirArchivo(nombreArchivo, lineas);
}
