#include "Medico.h"
#include <sstream>  // Para utilizar std::istringstream

// Constructor por defecto
Medico::Medico() : id(0), nombre(""), especialidad("") {}

// Constructor con parámetros
Medico::Medico(int id, const std::string& nombre, const std::string& especialidad)
    : id(id), nombre(nombre), especialidad(especialidad) {}

// Métodos de acceso (getters y setters)
int Medico::getId() const { return id; }
void Medico::setId(int id) { this->id = id; }

std::string Medico::getNombre() const { return nombre; }
void Medico::setNombre(const std::string& nombre) { this->nombre = nombre; }

std::string Medico::getEspecialidad() const { return especialidad; }
void Medico::setEspecialidad(const std::string& especialidad) { this->especialidad = especialidad; }

// Serializar el objeto Medico a un string para guardar en archivo
std::string Medico::serializar() const {
    return std::to_string(id) + "," + nombre + "," + especialidad;
}

// Deserializar un string para convertirlo en un objeto Medico
void Medico::deserializar(const std::string& datos) {
    std::istringstream ss(datos);
    std::getline(ss, nombre, ',');
    std::getline(ss, especialidad, ',');
    std::string idStr;
    std::getline(ss, idStr);
    id = std::stoi(idStr);  // Convierte el ID a entero
}





