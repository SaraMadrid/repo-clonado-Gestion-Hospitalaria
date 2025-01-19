#ifndef MEDICO_H
#define MEDICO_H

#include <string>

class Medico {
private:
    int id;
    std::string nombre;
    std::string especialidad;

public:
    // Constructor por defecto
    Medico();

    // Constructor con parámetros
    Medico(int id, const std::string& nombre, const std::string& especialidad);

    // Métodos de acceso (getters y setters)
    int getId() const;
    void setId(int id);

    std::string getNombre() const;
    void setNombre(const std::string& nombre);

    std::string getEspecialidad() const;
    void setEspecialidad(const std::string& especialidad);

    // Métodos para serializar y deserializar
    std::string serializar() const;  // Convierte a string para guardar
    void deserializar(const std::string& datos);  // Convierte de string a objeto
};

#endif












