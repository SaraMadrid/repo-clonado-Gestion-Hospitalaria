#ifndef SERVICIOS_H
#define SERVICIOS_H

#include "Modelos.h"
#include <vector>
#include <string>

// Declaración de servicios
class ServicioPacientes {
private:
    std::vector<Paciente> listaPacientes;

public:
    void altaPaciente(const Paciente& nuevo);
    void bajaPaciente(int idPaciente);
    void modificarDatos(int idPaciente, const std::string& nuevoNombre);
};

class ServicioMedicos {
private:
    std::vector<Medico> listaMedicos;

public:
    void altaMedico(const Medico& nuevo);
    void bajaMedico(int idMedico);
    void asignarEspecialidad(int idMedico, const std::string& especialidad);
};

class ServicioCitas {
private:
    std::vector<Cita> listaCitas;

public:
    void agendarCita(int idPaciente, int idMedico, const std::string& fecha);
    void cancelarCita(int idCita);
};

class ServicioReportes {
public:
    void generarReporteAtencion(int idMedico);
    void reporteCitasPendientes();
};

class ServicioArchivos {
private:
    std::string nombreArchivo;

public:
    void guardarDatos();
    void cargarDatos();
    void backup();
};

#endif

