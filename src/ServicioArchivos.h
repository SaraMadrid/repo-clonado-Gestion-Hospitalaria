#ifndef SERVICIO_ARCHIVOS_H
#define SERVICIO_ARCHIVOS_H

#include <string>
#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

class ServicioArchivos {
private:
    std::string nombreArchivo; 

public:
    // Constructor
    explicit ServicioArchivos(const std::string& archivo);

    // Métodos
    void guardar(const std::string& datos);
    std::string leer();
    void limpiar();
    std::vector<std::string> leerLineasDesdeArchivo(const std::string& ruta);

    // Métodos para generar reportes
    void generarReportePacientes(const std::vector<Paciente>& pacientes) const;
    void generarReporteMedicos(const std::vector<Medico>& medicos) const;
    void generarReporteCitas(const std::vector<Cita>& citas) const;
};

#endif // SERVICIO_ARCHIVOS_H












