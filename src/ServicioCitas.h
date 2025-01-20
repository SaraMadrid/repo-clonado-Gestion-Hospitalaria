#ifndef SERVICIO_CITAS_H
#define SERVICIO_CITAS_H

#include <vector>
#include <string>
#include "Cita.h"
#include "ServicioArchivos.h"

class ServicioCitas {
private:
    std::vector<Cita> citas;
    ServicioArchivos servicioArchivos;
    std::string archivoCitas;

public:
    // Constructor que inicializa archivoCitas y servicioArchivos
    ServicioCitas(const std::string& rutaArchivo);

    void agregarCita(const Cita& cita);
    void eliminarCita(int id);
    Cita* buscarCitaPorId(int id);
    const std::vector<Cita>& obtenerTodasLasCitas() const;
    void cargarCitasDesdeArchivo(const std::string& ruta);
    void guardarCitasEnArchivo(const std::string& ruta) const;
};

#endif 















