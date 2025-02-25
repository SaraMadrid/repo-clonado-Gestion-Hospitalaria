#ifndef SERVICIO_CITAS_H
#define SERVICIO_CITAS_H

#include <vector>
#include <string>
#include "Cita.h"
#include "ServicioArchivos.h"
#include "IServicioCitas.h"

class ServicioCitas : public IServicioCitas {
private:
    std::vector<Cita> citas;
    ServicioArchivos servicioArchivos;
    std::string archivoCitas;
    

public:
    explicit ServicioCitas(const std::string& rutaArchivo);

    void agregarCita(const Cita& cita) override;
    Cita* buscarCitaPorId(int id) override;
    void modificarCita(int id, const Cita& nuevaCita) override;
    void eliminarCita(int id) override;
    std::vector<Cita> obtenerTodasLasCitas() const override;
    void cargarCitasDesdeArchivo(const std::string& ruta) override;
    void guardarCitasEnArchivo(const std::string& ruta) const override;
};

#endif
