#ifndef INTERFAZ_HOSPITAL_H
#define INTERFAZ_HOSPITAL_H

#include "Servicios.h"

class InterfazHospital {
private:
    ServicioPacientes servicioPacientes;
    ServicioMedicos servicioMedicos;
    ServicioCitas servicioCitas;
    ServicioReportes servicioReportes;
    ServicioArchivos servicioArchivos;

public:
    void gestionarPacientes();
    void gestionarMedicos();
    void gestionarCitas();
    void generarReportes();
    void gestionarArchivos();
};

#endif
