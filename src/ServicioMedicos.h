#ifndef SERVICIOMEDICOS_H
#define SERVICIOMEDICOS_H

#include <vector>
#include <algorithm>  
#include "Medico.h"  
#pragma once

class ServicioMedicos {
private:
    std::vector<Medico> medicos; 

public:
    void agregarMedico(const Medico& medico);  
    Medico* buscarMedicoPorId(int id);         
    std::vector<Medico> obtenerTodosLosMedicos() const;  
    void eliminarMedico(int id);  
};

#endif 






