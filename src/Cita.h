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
        // Constructores
        Cita();
        Cita(int id, int idPaciente, int idMedico, const std::string& fecha, const std::string& hora, const std::string& motivo);
    
        // Getters
        int getId() const;
        int getIdPaciente() const;
        int getIdMedico() const;
        std::string getFecha() const;
        std::string getHora() const;
        std::string getMotivo() const;
    
        // Setters
        void setId(int nuevoId);
        void setIdPaciente(int nuevoIdPaciente);
        void setIdMedico(int nuevoIdMedico);
        void setFecha(const std::string& nuevaFecha);
        void setHora(const std::string& nuevaHora);
        void setMotivo(const std::string& nuevoMotivo);
    
        // Métodos de utilidad
        bool esEnFecha(const std::string& fechaConsulta) const;
    
        // Métodos de serialización
        std::string serializar() const;
        void deserializar(const std::string& datos);
    };
    
    #endif

   





















