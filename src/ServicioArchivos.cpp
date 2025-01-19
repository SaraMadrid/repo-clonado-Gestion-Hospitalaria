#ifndef SERVICIOARCHIVOS_H 
#define SERVICIOARCHIVOS_H

#include <fstream>
#include "Cita.h"
#include "Paciente.h"
#include "Medico.h"
#include <string>
#include <vector>

class ServicioArchivos {
public:
    // Método para guardar cualquier lista de cadenas en un archivo
    void guardarReporteEnArchivo(const std::vector<std::string>& lineas, const std::string& ruta) const {
        std::ofstream archivo(ruta);
        if (archivo.is_open()) {
            for (const auto& linea : lineas) {
                archivo << linea << std::endl;
            }
        } else {
            throw std::runtime_error("No se pudo abrir el archivo para guardar el reporte.");
        }
    }

    // Método para generar un reporte de citas
    void generarReporteCitas(const std::vector<Cita>& citas, const std::string& ruta) const {
        std::vector<std::string> lineasReporte;
        for (const auto& cita : citas) {
            lineasReporte.push_back(cita.serializar());
        }
        guardarReporteEnArchivo(lineasReporte, ruta);
    }

    // Método para generar un reporte de pacientes
    void generarReportePacientes(const std::vector<Paciente>& pacientes, const std::string& ruta) const {
        std::vector<std::string> lineasReporte;
        for (const auto& paciente : pacientes) {
            lineasReporte.push_back(paciente.serializar());
        }
        guardarReporteEnArchivo(lineasReporte, ruta);
    }

    // Método para generar un reporte de médicos
    void generarReporteMedicos(const std::vector<Medico>& medicos, const std::string& ruta) const {
        std::vector<std::string> lineasReporte;
        for (const auto& medico : medicos) {
            lineasReporte.push_back(medico.serializar());
        }
        guardarReporteEnArchivo(lineasReporte, ruta);
    }
};

#endif









