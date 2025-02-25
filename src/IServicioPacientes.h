#ifndef ISERVICIOPACIENTES_H
#define ISERVICIOPACIENTES_H

#include <vector>
#include <string>
#include "Paciente.h"

class IServicioPacientes {
public:
    virtual ~IServicioPacientes() = default;

    virtual void agregarPaciente(const Paciente& paciente) = 0;
    virtual Paciente* buscarPacientePorId(int id) = 0;
    virtual void modificarPaciente(int id, const Paciente& nuevoPaciente) = 0;
    virtual bool eliminarPaciente(int id) = 0;
    virtual const std::vector<Paciente>& obtenerTodosLosPacientes() const = 0; 
    virtual void cargarPacientesDesdeArchivo(const std::string& nombreArchivo) = 0;
    virtual void guardarPacientesEnArchivo(const std::string& nombreArchivo) const = 0;
};

#endif


