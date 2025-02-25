#include "Medico.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>

// Constructor por defecto
Medico::Medico() : id(0), nombre(""), especialidad("") {}

// Constructor con parámetros
Medico::Medico(int id, const std::string& nombre, const std::string& especialidad)
    : id(id), nombre(nombre), especialidad(especialidad) {}

// Getters
int Medico::getId() const { return id; }
std::string Medico::getNombre() const { return nombre; }
std::string Medico::getEspecialidad() const { return especialidad; }

// Setters
void Medico::setId(int id) { this->id = id; }
void Medico::setNombre(const std::string& nombre) { this->nombre = nombre; }
void Medico::setEspecialidad(const std::string& especialidad) { this->especialidad = especialidad; }

// Serialización del objeto
std::string Medico::serializar() const {
    return std::to_string(id) + "," + nombre + "," + especialidad;
}

// Deserialización del objeto
void Medico::deserializar(const std::string& datos) {
    std::istringstream ss(datos);
    std::string idStr;

    if (!std::getline(ss, idStr, ',') || 
        !std::getline(ss, nombre, ',') || 
        !std::getline(ss, especialidad, ',')) {
        throw std::runtime_error("Error en el formato de datos del médico: " + datos);
    }

    if (!std::all_of(idStr.begin(), idStr.end(), ::isdigit)) {
        throw std::runtime_error("Error: ID del médico no es válido -> " + idStr);
    }

    id = std::stoi(idStr);
}

