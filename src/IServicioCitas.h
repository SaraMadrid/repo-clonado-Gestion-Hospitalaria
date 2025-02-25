#ifndef ISERVICIOCITAS_H
#define ISERVICIOCITAS_H

#include <vector>
#include <string>
#include "Cita.h"

class IServicioCitas {
public:
    virtual ~IServicioCitas() = default;

    virtual void agregarCita(const Cita& cita) = 0;
    virtual Cita* buscarCitaPorId(int id) = 0;
    virtual void modificarCita(int id, const Cita& nuevaCita) = 0;
    virtual void eliminarCita(int id) = 0;
    virtual std::vector<Cita> obtenerTodasLasCitas() const = 0;
    virtual void cargarCitasDesdeArchivo(const std::string& nombreArchivo) = 0;
    virtual void guardarCitasEnArchivo(const std::string& nombreArchivo) const = 0;
};

#endif

