#ifndef SERVICIO_MEDICOS_H
#define SERVICIO_MEDICOS_H

#include "Medico.h"
#include <vector>
#include <string>

class ServicioMedicos {
private:
    std::vector<Medico> medicos;  // Aquí guardas los médicos

public:
    void agregarMedico(const Medico& medico);
    Medico* buscarMedicoPorId(int id);
    std::vector<Medico> obtenerTodosLosMedicos() const;
    void eliminarMedico(int id);

    // Métodos para cargar y guardar en archivos
    void cargarMedicosDesdeArchivo(const std::string& ruta);
    void guardarMedicosEnArchivo(const std::string& ruta) const;
};

#endif









