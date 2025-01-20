#ifndef CITA_H
#define CITA_H

#include <string>

class Cita {
private:
    int id = 0;
    int idPaciente = 0;
    int idMedico = 0;
    std::string fecha;
    std::string hora;
    std::string motivo;

public:
    // Constructores
    Cita() = default;
    Cita(int id, int idPaciente, int idMedico, const std::string& fecha, const std::string& hora, const std::string& motivo);

    // Métodos de acceso (getters y setters)
    int getId() const;
    void setId(int id);

    int getIdPaciente() const;
    void setIdPaciente(int idPaciente);

    int getIdMedico() const;
    void setIdMedico(int idMedico);

    std::string getFecha() const;
    void setFecha(const std::string& fecha);

    std::string getHora() const;
    void setHora(const std::string& hora);

    std::string getMotivo() const;
    void setMotivo(const std::string& motivo);

    // Métodos funcionales
    bool esEnFecha(const std::string& fecha) const;

    // Serialización y deserialización
    std::string serializar() const;
    void deserializar(const std::string& cadena);

private:
    // Función auxiliar para extraer valores de una cadena
    std::string extraerValor(const std::string& cadena, const std::string& clave) const;
};

#endif






















