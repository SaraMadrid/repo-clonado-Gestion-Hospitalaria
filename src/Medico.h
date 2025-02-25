#ifndef MEDICO_H
#define MEDICO_H

#include <string>

class Medico {
private:
    int id;
    std::string nombre;
    std::string especialidad;

public:
    // Constructores
    Medico();
    Medico(int id, const std::string& nombre, const std::string& especialidad);
    
    // Getters
    int getId() const;
    std::string getNombre() const;
    std::string getEspecialidad() const;

    // Setters
    void setId(int id);
    void setNombre(const std::string& nombre);
    void setEspecialidad(const std::string& especialidad);
    
    // Métodos de serialización
    std::string serializar() const;
    void deserializar(const std::string& datos);
};

#endif // MEDICO_H













