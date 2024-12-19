#ifndef SERVICIOS_H
#define SERVICIOS_H

#include "Modelos.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// Declaración de servicios
class ServicioPacientes {
private:
    std::vector<Paciente> listaPacientes;

public:
    void altaPaciente(const Paciente& nuevo);
    void bajaPaciente(int idPaciente);
    void modificarDatos(int idPaciente, const std::string& nuevoNombre);
    void guardarDatos();
    void cargarDatos();
};

class ServicioMedicos {
private:
    std::vector<Medico> listaMedicos;

public:
    void altaMedico(const Medico& nuevo);
    void bajaMedico(int idMedico);
    void guardarDatos();
    void cargarDatos();
};

class ServicioCitas {
private:
    std::vector<Cita> listaCitas;

public:
    void agendarCita(int idPaciente, int idMedico, const std::string& fecha, const std::string& motivo);
    void cancelarCita(int idCita);
    void guardarDatos();
    void cargarDatos();
};

class ServicioArchivos {
private:
    std::string nombreArchivoPacientes = "pacientes.txt";
    std::string nombreArchivoMedicos = "medicos.txt";
    std::string nombreArchivoCitas = "citas.txt";

public:
    void guardarDatos();
    void cargarDatos();
    void backup();
};

class ServicioReportes {
public:
    void generarReporteAtencion(int idMedico);
    void reporteCitasPendientes();
    
};

#endif