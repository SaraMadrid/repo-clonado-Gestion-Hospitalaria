#ifndef SERVICIOPACIENTES_H
#define SERVICIOPACIENTES_H

#include <vector>
#include "Paciente.h"  
#pragma once

class ServicioPacientes {
private:
    std::vector<Paciente> pacientes;  

public:
 
    void agregarPaciente(const Paciente& paciente);

    Paciente* buscarPacientePorId(int id);
   
    std::vector<Paciente> obtenerTodosLosPacientes() const;
   
    bool eliminarPaciente(int id); 
};

#endif 






