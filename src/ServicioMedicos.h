#ifndef SERVICIO_MEDICOS_H
#define SERVICIO_MEDICOS_H

#include <string>
#include <vector>
#include "Medico.h"
#include "ServicioArchivos.h"
#include "IServicioMedicos.h"

class ServicioMedicos : public IServicioMedicos {
private:
    std::vector<Medico> medicos;
    ServicioArchivos servicioArchivos;
    std::string archivoMedicos; 

public:
    ServicioMedicos(const std::string& rutaArchivo);

    void agregarMedico(const Medico& medico) override;
    Medico* buscarMedicoPorId(int id) override;
    void modificarMedico(int id, const Medico& nuevoMedico) override;
    void eliminarMedico(int id) override;
    std::vector<Medico> obtenerMedicos() const override;
    void cargarMedicosDesdeArchivo(const std::string& nombreArchivo) override;
    void guardarMedicosEnArchivo(const std::string& nombreArchivo) const override;
};

#endif












