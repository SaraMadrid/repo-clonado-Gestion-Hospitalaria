#include "ServicioMedicos.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

// Agregar un médico al vector
void ServicioMedicos::agregarMedico(const Medico& medico) {
    medicos.push_back(medico);
}

// Buscar un médico por su ID
Medico* ServicioMedicos::buscarMedicoPorId(int id) {
    auto it = std::find_if(medicos.begin(), medicos.end(),
        [id](const Medico& medico) { return medico.getId() == id; });
    return it != medicos.end() ? &(*it) : nullptr;
}

// Obtener todos los médicos
std::vector<Medico> ServicioMedicos::obtenerTodosLosMedicos() const {
    return medicos;
}

// Eliminar un médico por su ID
void ServicioMedicos::eliminarMedico(int id) {
    medicos.erase(std::remove_if(medicos.begin(), medicos.end(),
        [id](const Medico& medico) { return medico.getId() == id; }), medicos.end());
}

// Cargar médicos desde un archivo de texto
void ServicioMedicos::cargarMedicosDesdeArchivo(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para leer." << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        Medico medico;
        medico.deserializar(linea);  // Deserializa cada línea del archivo
        agregarMedico(medico);  // Agrega el médico a la lista
    }

    archivo.close();
}

// Guardar médicos en un archivo de texto
void ServicioMedicos::guardarMedicosEnArchivo(const std::string& ruta) const {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
        return;
    }

    for (const auto& medico : medicos) {
        archivo << medico.serializar() << std::endl;  // Escribe la serialización del médico
    }

    archivo.close();
}








