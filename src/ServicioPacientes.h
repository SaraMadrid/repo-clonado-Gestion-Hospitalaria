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
    // Constructor que inicializa servicioArchivos
    ServicioPacientes(const std::string& rutaArchivo);

    // Agregar un paciente
    void agregarPaciente(const Paciente& paciente);

    // Buscar paciente por ID
    Paciente* buscarPacientePorId(int id);

    // Obtener todos los pacientes
    const std::vector<Paciente>& obtenerTodosLosPacientes() const;

    // Eliminar paciente por ID
    bool eliminarPaciente(int id);

    // Cargar pacientes desde archivo
    void cargarPacientesDesdeArchivo(const std::string& ruta);

    // Guardar pacientes en archivo
    void guardarPacientesEnArchivo(const std::string& ruta) const;

    // Generar reporte de pacientes
    void generarReporteDePacientes(const std::string& rutaReporte) const;
};

#endif 










