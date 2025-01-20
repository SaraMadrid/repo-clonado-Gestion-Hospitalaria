#include "Paciente.h"

// Constructor por defecto
Paciente::Paciente() : id(0), nombre(""), edad(0), direccion(""), telefono("") {}

// Constructor con parámetros
Paciente::Paciente(int id, const std::string& nombre, int edad, const std::string& direccion, const std::string& telefono)
    : id(id), nombre(nombre), edad(edad), direccion(direccion), telefono(telefono) {}

// Getters y Setters
int Paciente::getId() const { return id; }
void Paciente::setId(int id) { this->id = id; }

std::string Paciente::getNombre() const { return nombre; }
void Paciente::setNombre(const std::string& nombre) { this->nombre = nombre; }

int Paciente::getEdad() const { return edad; }
void Paciente::setEdad(int edad) { this->edad = edad; }

std::string Paciente::getDireccion() const { return direccion; }
void Paciente::setDireccion(const std::string& direccion) { this->direccion = direccion; }

std::string Paciente::getTelefono() const { return telefono; }
void Paciente::setTelefono(const std::string& telefono) { this->telefono = telefono; }

// Métodos de serialización y deserialización
std::string Paciente::serializar() const {
    return std::to_string(id) + "," + nombre + "," + std::to_string(edad) + "," + direccion + "," + telefono;
}

void Paciente::deserializar(const std::string& linea) {
    std::stringstream ss(linea);
    std::string campo;

    std::getline(ss, campo, ',');
    id = std::stoi(campo);

    std::getline(ss, nombre, ',');

    std::getline(ss, campo, ',');
    edad = std::stoi(campo);

    std::getline(ss, direccion, ',');

    std::getline(ss, telefono, ',');
}






