#include "ServicioCitas.h"
#include "Cita.h"
#include <algorithm>
#include <stdexcept>

void ServicioCitas::agregarCita(const Cita& cita) {
    citas.push_back(cita);
}

void ServicioCitas::eliminarCita(int id) {
    citas.erase(std::remove_if(citas.begin(), citas.end(),
        [id](const Cita& cita) { return cita.getId() == id; }), citas.end());
}

Cita ServicioCitas::buscarCitaPorId(int id) const {
    auto it = std::find_if(citas.begin(), citas.end(),
        [id](const Cita& cita) { return cita.getId() == id; });
    if (it != citas.end()) {
        return *it;
    }
    throw std::runtime_error("Cita no encontrada");
}

const std::vector<Cita>& ServicioCitas::obtenerTodasLasCitas() const {
    return citas;
}

void ServicioCitas::cargarCitasDesdeArchivo(const std::string& ruta) {
    auto lineas = servicioArchivos.leerLineasDesdeArchivo(ruta);
    for (const auto& linea : lineas) {
        Cita cita;
        cita.deserializar(linea);
        agregarCita(cita);
    }
}

void ServicioCitas::guardarCitasEnArchivo(const std::string& ruta) const {
    std::vector<std::string> lineas;
    for (const auto& cita : citas) {
        lineas.push_back(cita.serializar());
    }
}













    




