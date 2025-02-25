#include "Paciente.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>

// Constructor por defecto
Paciente::Paciente() 
    : id(0), nombre(""), edad(0), direccion("Desconocida"), telefono("N/A") {}

// Constructor con parámetros
Paciente::Paciente(int id, const std::string& nombre)
    : id(id), nombre(nombre), edad(0), direccion("Desconocida"), telefono("N/A") {
    if (nombre.empty()) {
        throw std::invalid_argument("El nombre no puede estar vacío.");
    }
}

// Getters y Setters
int Paciente::getId() const { return id; }
void Paciente::setId(int id) { this->id = id; }

std::string Paciente::getNombre() const { return nombre; }
void Paciente::setNombre(const std::string& nombre) { 
    this->nombre = nombre; 
}

int Paciente::getEdad() const { return edad; }
void Paciente::setEdad(int edad) { this->edad = edad; }

std::string Paciente::getDireccion() const { return direccion; }
void Paciente::setDireccion(const std::string& direccion) { 
    if (direccion.empty()) {
        throw std::invalid_argument("La dirección no puede estar vacía.");
    }
    this->direccion = direccion; 
}

std::string Paciente::getTelefono() const { return telefono; }
void Paciente::setTelefono(const std::string& telefono) { 
    if (telefono.empty()) {
        throw std::invalid_argument("El teléfono no puede estar vacío.");
    }
    this->telefono = telefono; 
}

// Serialización
std::string Paciente::serializar() const {
    return std::to_string(id) + "," + nombre + "," + std::to_string(edad) + "," + direccion + "," + telefono;
}

// Deserialización con validaciones
void Paciente::deserializar(const std::string& linea) {
    std::stringstream ss(linea);
    std::string idStr, edadStr;

    std::getline(ss, idStr, ',');
    std::getline(ss, nombre, ',');
    std::getline(ss, edadStr, ',');
    std::getline(ss, direccion, ',');
    std::getline(ss, telefono, ',');

    // Validar ID y edad
    auto esNumero = [](const std::string& str) {
        return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
    };

    if (!esNumero(idStr) || !esNumero(edadStr)) {
        throw std::runtime_error("Error: ID o edad no son válidos en " + linea);
    }

    id = std::stoi(idStr);
    edad = std::stoi(edadStr);

    // Validar dirección y teléfono
    if (direccion.empty()) {
        throw std::invalid_argument("Error: La dirección no puede estar vacía.");
    }
    if (telefono.empty()) {
        throw std::invalid_argument("Error: El teléfono no puede estar vacío.");
    }
}

