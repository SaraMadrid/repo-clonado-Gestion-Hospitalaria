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
    Paciente();
    Paciente(int id, const std::string& nombre, int edad, const std::string& direccion, const std::string& telefono);

    // Getters y Setters
    int getId() const;
    void setId(int id);

    std::string getNombre() const;
    void setNombre(const std::string& nombre);

    int getEdad() const;
    void setEdad(int edad);

    std::string getDireccion() const;
    void setDireccion(const std::string& direccion);

    std::string getTelefono() const;
    void setTelefono(const std::string& telefono);

    // Métodos de serialización y deserialización
    std::string serializar() const;
    void deserializar(const std::string& linea);
};

#endif













