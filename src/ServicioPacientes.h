#ifndef SERVICIOPACIENTES_H
#define SERVICIOPACIENTES_H

#include <vector>
#include <string>
#include "Paciente.h"
#include "ServicioArchivos.h"


class ServicioPacientes {
private:
    std::vector<Paciente> pacientes;          
    ServicioArchivos servicioArchivos;        

public:
    
    ServicioPacientes(const std::string& rutaArchivo);
    void agregarPaciente(const Paciente& paciente);

    Paciente* buscarPacientePorId(int id);
    const std::vector<Paciente>& obtenerTodosLosPacientes() const;
    bool eliminarPaciente(int id);
    void cargarPacientesDesdeArchivo(const std::string& ruta);
    void guardarPacientesEnArchivo(const std::string& ruta) const;
    void generarReporteDePacientes(const std::string& rutaReporte) const;
};

#endif











