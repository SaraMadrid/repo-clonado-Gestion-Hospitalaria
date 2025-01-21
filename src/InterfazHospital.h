#ifndef INTERFAZHOSPITAL_H
#define INTERFAZHOSPITAL_H

#include "ServicioCitas.h"
#include "ServicioPacientes.h"
#include "ServicioMedicos.h"
#include "ServicioArchivos.h"
#include <iostream>
#include <string>
#include <regex>

class InterfazHospital {
private:
    ServicioCitas servicioCitas;
    ServicioPacientes servicioPacientes;
    ServicioMedicos servicioMedicos;
    ServicioArchivos nombreArchivo;
    ServicioArchivos servicioArchivos;

public:
    InterfazHospital(); 

    bool archivoExiste(const std::string& nombreArchivo); 

    void mostrarMenuPrincipal();
    void gestionarPacientes();
    void gestionarMedicos();
    void gestionarCitas();
    void generarReportes();

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


    void iniciar();
};

#endif 


