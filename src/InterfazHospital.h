#ifndef INTERFAZHOSPITAL_H
#define INTERFAZHOSPITAL_H

#include "ServicioCitas.h"
#include "ServicioPacientes.h"
#include "ServicioMedicos.h"
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"
#pragma once

class InterfazHospital {
private:
    ServicioCitas servicioCitas;
    ServicioPacientes servicioPacientes;
    ServicioMedicos servicioMedicos;

    void mostrarMenuPrincipal();
    void gestionarPacientes();
    void gestionarMedicos();
    void gestionarCitas();

    void agregarPaciente();
    void modificarPaciente();
    void eliminarPaciente();
    void listarPacientes();

    void agregarMedico();
    void modificarMedico();
    void eliminarMedico();
    void listarMedicos();

    void agregarCita();
    void modificarCita();
    void eliminarCita();
    void listarCitas();
    void validarFormatoFechaHora(const std::string& fecha, const std::string& hora);
    
public:
    void iniciar();
};

#endif
