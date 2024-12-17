#ifndef MODELOS_H
#define MODELOS_H

#include <string>
#include <vector>
#include <ctime>

// Clase Persona
class Persona {
protected:
    std::string nombre;
    std::string direccion;
    std::string telefono;

public:
    Persona(const std::string& nombre, const std::string& direccion, const std::string& telefono);
    virtual ~Persona() = default;

//Getters nuevos añadidos
    std::string getNombre() const;
    std::string getDireccion() const; 
    std::string getTelefono() const; 
};

// Clase Paciente
class Paciente : public Persona {
private:
    int idPaciente;

public:
    Paciente(int id, const std::string& nombre, const std::string& direccion, const std::string& telefono);
    int getIdPaciente() const;
};

// Clase Medico
class Medico : public Persona {
private:
    int idMedico;
    std::string especialidad;

public:
    Medico(int id, const std::string& nombre, const std::string& direccion, const std::string& telefono, const std::string& especialidad);
    int getIdMedico() const;
    std::string getEspecialidad() const;
    void setEspecialidad(const std::string& nuevaEspecialidad);
};

// Clase Cita
class Cita {
private:
    int idCita;
    int idPaciente;
    int idMedico;
    std::string fecha; // Fecha en formato "YYYY-MM-DD"
    std::string motivo;

public:
    Cita(int idCita, int idPaciente, int idMedico, const std::string& fecha, const std::string& motivo);
    int getIdCita() const;
    int getIdPaciente() const;
    int getIdMedico() const;
    std::string getFecha() const;
    std::string getMotivo() const;

    void setFecha(const std::string& nuevaFecha);
    void setMotivo(const std::string& nuevoMotivo);
};

#endif
