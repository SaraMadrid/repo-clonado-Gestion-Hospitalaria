#include "ServicioMedicos.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

// Constructor que inicializa archivoMedicos y servicioArchivos
ServicioMedicos::ServicioMedicos(const std::string& rutaArchivo)
    : archivoMedicos(rutaArchivo), servicioArchivos(rutaArchivo) { }

// Agregar un médico al vector, verificando duplicados
void ServicioMedicos::agregarMedico(const Medico& medico) {
    if (buscarMedicoPorId(medico.getId()) != nullptr) {
        throw std::runtime_error("Ya existe un médico con el mismo ID.");
    }
    medicos.push_back(medico);
}

// Buscar un médico por su ID
Medico* ServicioMedicos::buscarMedicoPorId(int id) {
    auto it = std::find_if(medicos.begin(), medicos.end(),
        [id](const Medico& medico) { return medico.getId() == id; });
    return it != medicos.end() ? &(*it) : nullptr;
}

// Obtener todos los médicos (referencia constante para evitar copias)
const std::vector<Medico>& ServicioMedicos::obtenerTodosLosMedicos() const {
    return medicos;
}

// Eliminar un médico por su ID
void ServicioMedicos::eliminarMedico(int id) {
    auto it = std::remove_if(medicos.begin(), medicos.end(),
        [id](const Medico& medico) { return medico.getId() == id; });
    if (it == medicos.end()) {
        throw std::runtime_error("No se encontró un médico con el ID proporcionado.");
    }
    medicos.erase(it, medicos.end());
}

// Cargar médicos desde un archivo de texto
void ServicioMedicos::cargarMedicosDesdeArchivo(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo para leer.");
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        Medico medico;
        medico.deserializar(linea);
        agregarMedico(medico); // Verifica duplicados al agregar
    }

    archivo.close();
}

// Guardar médicos en un archivo de texto
void ServicioMedicos::guardarMedicosEnArchivo(const std::string& ruta) const {
    std::ofstream archivo("medicos.txt");
    if (!archivo.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo para escribir.");
    }

    for (const auto& medico : medicos) {
        archivo << medico.serializar() << std::endl;
    }

    archivo.close();
}










