#ifndef ISERVICIOMEDICOS_H
#define ISERVICIOMEDICOS_H

#include <vector>
#include <string>
#include "Medico.h"

class IServicioMedicos {
public:
    virtual ~IServicioMedicos() = default;

    virtual void agregarMedico(const Medico& medico) = 0;
    virtual Medico* buscarMedicoPorId(int id) = 0;
    virtual void modificarMedico(int id, const Medico& nuevoMedico) = 0;
    virtual void eliminarMedico(int id) = 0;
    virtual std::vector<Medico> obtenerMedicos() const = 0;
    virtual void cargarMedicosDesdeArchivo(const std::string& nombreArchivo) = 0;
    virtual void guardarMedicosEnArchivo(const std::string& nombreArchivo) const = 0;
};

#endif

