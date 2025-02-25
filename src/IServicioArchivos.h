#ifndef ISERVICIOARCHIVOS_H
#define ISERVICIOARCHIVOS_H

#include <vector>
#include <string>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

class IServicioArchivos {
public:
    virtual ~IServicioArchivos() = default;

    virtual std::vector<std::string> leerArchivo(const std::string& rutaArchivo) = 0;
    virtual void escribirArchivo(const std::string& rutaArchivo, const std::vector<std::string>& lineas) const = 0;
    virtual void generarReportePacientes(const std::vector<Paciente>& pacientes) const = 0;
    virtual void generarReporteMedicos(const std::vector<Medico>& medicos) const = 0;
    virtual void generarReporteCitas(const std::vector<Cita>& citas) const = 0;
};

#endif
