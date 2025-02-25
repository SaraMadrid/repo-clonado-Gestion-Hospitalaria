#ifndef SERVICIOPACIENTES_H
#define SERVICIOPACIENTES_H

#include <vector>
#include <string>
#include "Paciente.h"
#include "ServicioArchivos.h"
#include "IServicioPacientes.h"

class ServicioPacientes : public IServicioPacientes {
private:
    std::vector<Paciente> pacientes;
    ServicioArchivos servicioArchivos;

public:
    explicit ServicioPacientes(const std::string& rutaArchivo);
    
    void agregarPaciente(const Paciente& paciente) override;
    Paciente* buscarPacientePorId(int id) override;
    void modificarPaciente(int id, const Paciente& nuevoPaciente) override;
    bool eliminarPaciente(int id) override;
    const std::vector<Paciente>& obtenerTodosLosPacientes() const override;
    void cargarPacientesDesdeArchivo(const std::string& ruta) override;
    void guardarPacientesEnArchivo(const std::string& ruta) const override;
};

#endif

 
