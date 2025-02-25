#include "ServicioCitas.h"
#include "ServicioArchivos.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <iostream>

// Constructor que inicializa la ruta del archivo
ServicioCitas::ServicioCitas(const std::string& rutaArchivo)
    : archivoCitas(rutaArchivo) {}

// Agregar una nueva cita
void ServicioCitas::agregarCita(const Cita& cita) {
    int nuevoId = citas.empty() ? 1 : citas.back().getId() + 1;  // Generar ID basado en la última cita
    Cita nuevaCita = cita;
    nuevaCita.setId(nuevoId);  // Asignar nuevo ID

    citas.push_back(nuevaCita);
    guardarCitasEnArchivo(archivoCitas);  // Guardar en el archivo
}

// Modificar una cita existente
void ServicioCitas::modificarCita(int id, const Cita& nuevaCita) {
    bool encontrada = false;
    for (auto& cita : citas) {
        if (cita.getId() == id) {
            cita = nuevaCita;  // Actualizar la cita
            encontrada = true;
            break;
        }
    }
    if (!encontrada) {
        throw std::runtime_error("Cita no encontrada.");
    }

    guardarCitasEnArchivo(archivoCitas);  // Guardar toda la lista actualizada en el archivo
}

// Eliminar una cita por ID
void ServicioCitas::eliminarCita(int id) {
    auto it = std::remove_if(citas.begin(), citas.end(),
        [id](const Cita& cita) { return cita.getId() == id; });

    if (it != citas.end()) {
        citas.erase(it, citas.end());
        guardarCitasEnArchivo(archivoCitas);  // Guardar los cambios en el archivo
    } else {
        throw std::runtime_error("No se encontró la cita con el ID proporcionado.");
    }
}

// Buscar una cita por ID
Cita* ServicioCitas::buscarCitaPorId(int id) {
    auto it = std::find_if(citas.begin(), citas.end(),
        [id](const Cita& cita) { return cita.getId() == id; });
    return it != citas.end() ? &(*it) : nullptr;
}

// Obtener todas las citas
std::vector<Cita> ServicioCitas::obtenerTodasLasCitas() const {
    return citas;
}

// Cargar citas desde un archivo
void ServicioCitas::cargarCitasDesdeArchivo(const std::string& rutaArchivo) {
    std::ifstream archivo(rutaArchivo);

    if (!archivo.is_open()) {
        std::cerr << "El archivo de citas no existe. Creando un nuevo archivo: " << rutaArchivo << std::endl;

        std::ofstream archivo_creado(rutaArchivo);
        if (!archivo_creado.is_open()) {
            throw std::runtime_error("No se pudo crear el archivo de citas.");
        }

        return;  // Salir ya que el archivo ha sido creado
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        Cita cita;
        cita.deserializar(linea);
        citas.push_back(cita);
    }

    archivo.close();
}

// Guardar todas las citas en un archivo
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


















    




