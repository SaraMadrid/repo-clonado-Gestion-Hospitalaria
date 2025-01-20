#ifndef SERVICIO_MEDICOS_H
#define SERVICIO_MEDICOS_H

#include <string>
#include <vector>
#include "Medico.h"
#include "ServicioArchivos.h"

class ServicioMedicos {
private:
    std::vector<Medico> medicos;
    ServicioArchivos servicioArchivos;
    std::string archivoMedicos; 

public:
    ServicioMedicos(const std::string& rutaArchivo);

    void agregarMedico(const Medico& medico);
    Medico* buscarMedicoPorId(int id);
    const std::vector<Medico>& obtenerTodosLosMedicos() const;
    void eliminarMedico(int id);
    void cargarMedicosDesdeArchivo(const std::string& ruta);
    void guardarMedicosEnArchivo(const std::string& ruta) const;
};

#endif 











