#ifndef SERVICIO_ARCHIVOS_H
#define SERVICIO_ARCHIVOS_H

#include <string>
#include <vector>
#include "Cita.h"
#include "Medico.h"
#include "Paciente.h"

class ServicioArchivos {
public:
    // Métodos para médicos
    static void guardarMedicos(const std::vector<Medico>& medicos, const std::string& archivo);
    static std::vector<Medico> cargarMedicos(const std::string& archivo);

    // Métodos para pacientes
    static void guardarPacientes(const std::vector<Paciente>& pacientes, const std::string& archivo);
    static std::vector<Paciente> cargarPacientes(const std::string& archivo);

    // Métodos para citas
    static void guardarCitas(const std::vector<Cita>& citas, const std::string& archivo);
    static std::vector<Cita> cargarCitas(const std::string& archivo);
    
    // Métodos de lectura y escritura de líneas desde/hacia archivo
    static void escribirLineasAArchivo(const std::vector<std::string>& lineas, const std::string& archivo);
    static std::vector<std::string> leerLineasDesdeArchivo(const std::string& archivo);

    static void generarReporteCitas();
    static void generarReportePacientes();
    void generarReportePacientes(const std::vector<Paciente>& pacientes, const std::string& rutaReporte);
};

#endif









