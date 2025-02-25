#ifndef INTERFAZHOSPITAL_H
#define INTERFAZHOSPITAL_H

#include <memory>
#include "IServicioCitas.h"
#include "IServicioPacientes.h"
#include "IServicioMedicos.h"
#include "IServicioArchivos.h"
#include "Cita.h"
#include "Paciente.h"
#include "Medico.h"

class InterfazHospital {
private:
    std::unique_ptr<IServicioCitas> servicioCitas;
    std::unique_ptr<IServicioPacientes> servicioPacientes;
    std::unique_ptr<IServicioMedicos> servicioMedicos;
    std::unique_ptr<IServicioArchivos> servicioArchivos;

    bool archivoExiste(const std::string& nombreArchivo);

public:
InterfazHospital(std::unique_ptr<IServicioCitas> citas, 
    std::unique_ptr<IServicioPacientes> pacientes, 
    std::unique_ptr<IServicioMedicos> medicos,
    std::unique_ptr<IServicioArchivos> archivos);

        
    InterfazHospital() = default;                 

    void iniciar();
    void mostrarMenuPrincipal();
    void gestionarPacientes();
    void gestionarMedicos();
    void gestionarCitas();
    void generarReportes();

    // Funciones de gestión de médicos
    void agregarMedico();
    void modificarMedico();
    void eliminarMedico();
    void listarMedicos();

    // Funciones de gestión de citas
    void agregarCita();
    void modificarCita();
    void eliminarCita();
    void listarCitas();

    //Funciones de gestión de pacientes
    void agregarPaciente();
    void modificarPaciente(); 
    void eliminarPaciente(); 
    void listarPacientes(); 
     
};

#endif 

