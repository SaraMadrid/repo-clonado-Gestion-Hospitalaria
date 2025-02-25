#ifndef SERVICIO_ARCHIVOS_H
#define SERVICIO_ARCHIVOS_H

#include "IServicioArchivos.h"

class ServicioArchivos : public IServicioArchivos {
public:
    ServicioArchivos() = default;

    std::vector<std::string> leerArchivo(const std::string& rutaArchivo) override;
    void escribirArchivo(const std::string& rutaArchivo, const std::vector<std::string>& lineas) const override;

    void generarReportePacientes(const std::vector<Paciente>& pacientes) const override;
    void generarReporteMedicos(const std::vector<Medico>& medicos) const override;
    void generarReporteCitas(const std::vector<Cita>& citas) const override;
};

#endif














