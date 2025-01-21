#include "ServicioCitas.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <iostream>


ServicioCitas::ServicioCitas(const std::string& rutaArchivo)
    : archivoCitas(rutaArchivo), servicioArchivos(rutaArchivo) {}

void ServicioCitas::agregarCita(const Cita& cita) {
    citas.push_back(cita);
    guardarCitasEnArchivo(archivoCitas);
}

void ServicioCitas::eliminarCita(int id) {
    auto it = std::remove_if(citas.begin(), citas.end(),
        [id](const Cita& cita) { return cita.getId() == id; });
    if (it != citas.end()) {
        citas.erase(it, citas.end());
        guardarCitasEnArchivo(archivoCitas);
    } else {
        throw std::runtime_error("No se encontró una cita con el ID proporcionado.");
    }
}

Cita* ServicioCitas::buscarCitaPorId(int id) {
    auto it = std::find_if(citas.begin(), citas.end(),
        [id](const Cita& cita) { return cita.getId() == id; });
    return it != citas.end() ? &(*it) : nullptr;
}

const std::vector<Cita>& ServicioCitas::obtenerTodasLasCitas() const {
    return citas;
}

void ServicioCitas::cargarCitasDesdeArchivo(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "El archivo no existe. Creando un archivo nuevo en la ruta: " << ruta << std::endl;
        std::ofstream archivo_creado(ruta);
        if (!archivo_creado.is_open()) {
            throw std::runtime_error("No se pudo crear el archivo para escribir.");
        }
        archivo_creado.close();
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        Cita cita;
        cita.deserializar(linea);
        citas.push_back(cita);
    }

    archivo.close();
}

void ServicioCitas::guardarCitasEnArchivo(const std::string& ruta) const {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo para escribir.");
    }

    for (const auto& cita : citas) {
        archivo << cita.serializar() << std::endl;
    }

    archivo.close();
}
















    




