#ifndef SERVICIOCITAS_H
#define SERVICIOCITAS_H

#include <vector>
#include <algorithm>
#include <fstream>
#include "Cita.h"
#include "ServicioArchivos.h"

class ServicioCitas {
private:
    std::vector<Cita> citas;
    ServicioArchivos servicioArchivos;

public:
    void agregarCita(const Cita& cita) {
        citas.push_back(cita);
    }

    void eliminarCita(int id) {
        citas.erase(std::remove_if(citas.begin(), citas.end(),
            [id](const Cita& cita) { return cita.getId() == id; }), citas.end());
    }

    Cita buscarCitaPorId(int id) const {
        auto it = std::find_if(citas.begin(), citas.end(),
            [id](const Cita& cita) { return cita.getId() == id; });
        if (it != citas.end()) {
            return *it;
        }
        throw std::runtime_error("Cita no encontrada");
    }

    const std::vector<Cita>& obtenerTodasLasCitas() const {
        return citas;
    }

    void cargarCitasDesdeArchivo(const std::string& ruta) {
        std::ifstream archivo(ruta);
        std::string linea;
        while (std::getline(archivo, linea)) {
            Cita cita;
            cita.deserializar(linea);
            agregarCita(cita);
        }
    }

    void guardarCitasEnArchivo(const std::string& ruta) const {
        std::ofstream archivo(ruta);
        for (const auto& cita : citas) {
            archivo << cita.serializar() << std::endl;
        }
    }


};

#endif















