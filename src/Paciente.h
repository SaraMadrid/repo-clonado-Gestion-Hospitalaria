#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <sstream> // Para serialización y deserialización

class Paciente {
private:
    int id;
    std::string nombre;
    int edad;
    std::string direccion;
    std::string telefono;

public:
    // Constructores
    Paciente() : id(0), edad(0) {}
    Paciente(int id, const std::string& nombre, int edad, const std::string& direccion, const std::string& telefono)
        : id(id), nombre(nombre), edad(edad), direccion(direccion), telefono(telefono) {}

    // Getters y Setters
    int getId() const { return id; }
    void setId(int id) { this->id = id; }

    std::string getNombre() const { return nombre; }
    void setNombre(const std::string& nombre) { this->nombre = nombre; }

    int getEdad() const { return edad; }
    void setEdad(int edad) { this->edad = edad; }

    std::string getDireccion() const { return direccion; }
    void setDireccion(const std::string& direccion) { this->direccion = direccion; }

    std::string getTelefono() const { return telefono; }
    void setTelefono(const std::string& telefono) { this->telefono = telefono; }

    // Métodos de serialización y deserialización
    std::string serializar() const {
        return std::to_string(id) + "," + nombre + "," + std::to_string(edad) + "," + direccion + "," + telefono;
    }

    void deserializar(const std::string& linea) {
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
};

#endif












