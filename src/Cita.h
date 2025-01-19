#ifndef CITA_H
#define CITA_H

#include <string>

class Cita {
private:
    int id;
    int idPaciente;
    int idMedico;
    std::string fecha;
    std::string hora;
    std::string motivo;

public:
    // Constructor por defecto
    Cita();

    // Constructor con parámetros
    Cita(int id, int idPaciente, int idMedico, const std::string &fecha, const std::string &hora, const std::string &motivo);

    // Métodos de acceso (getters y setters)
    int getId() const;
    void setId(int id);

    int getIdPaciente() const;
    void setIdPaciente(int idPaciente);

    int getIdMedico() const;
    void setIdMedico(int idMedico);

    std::string getFecha() const;
    void setFecha(const std::string &fecha);

    std::string getHora() const;
    void setHora(const std::string &hora);

    std::string getMotivo() const;
    void setMotivo(const std::string &motivo);

    // Método para comparar fechas
    bool esEnFecha(const std::string &fecha) const;

    // Método de serialización
    std::string serializar() const;

    // Método de deserialización
    void deserializar(const std::string& cadena);
};

#endif





















