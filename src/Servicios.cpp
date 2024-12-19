#include "Servicios.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

// ServicioPacientes
void ServicioPacientes::altaPaciente(const Paciente& nuevo) {
    listaPacientes.push_back(nuevo);
    std::cout << "Paciente agregado correctamente: " << nuevo.getNombre() << "\n";
    guardarDatos();  // Guardamos los datos después de agregar un paciente
}

void ServicioPacientes::bajaPaciente(int idPaciente) {
    listaPacientes.erase(std::remove_if(listaPacientes.begin(), listaPacientes.end(),
        [idPaciente](const Paciente& p) { return p.getIdPaciente() == idPaciente; }),
        listaPacientes.end());
    std::cout << "Paciente eliminado.\n";
    guardarDatos();  // Guardamos los datos después de eliminar un paciente
}

void ServicioPacientes::modificarDatos(int idPaciente, const std::string& nuevoNombre) {
    auto it = std::find_if(listaPacientes.begin(), listaPacientes.end(),
        [idPaciente](const Paciente& p) { return p.getIdPaciente() == idPaciente; });

    if (it != listaPacientes.end()) {
        *it = Paciente(idPaciente, nuevoNombre, it->getDireccion(), it->getTelefono());
        std::cout << "Datos del paciente actualizados.\n";
        guardarDatos();  // Guardamos los datos después de modificar
    } else {
        std::cout << "Error: Paciente no encontrado.\n";
    }
}

void ServicioPacientes::guardarDatos() {
    std::ofstream file("pacientes.txt");
    for (const auto& paciente : listaPacientes) {
        file << paciente.getIdPaciente() << "\n";
        file << paciente.getNombre() << "\n";
        file << paciente.getDireccion() << "\n";
        file << paciente.getTelefono() << "\n";
    }
    file.close();
}

void ServicioPacientes::cargarDatos() {
    std::ifstream file("pacientes.txt");
    if (file.is_open()) {
        int id;
        std::string nombre, direccion, telefono;
        while (file >> id) {
            std::getline(file, nombre);  // Saltar el salto de línea
            std::getline(file, nombre);
            std::getline(file, direccion);
            std::getline(file, telefono);
            listaPacientes.push_back(Paciente(id, nombre, direccion, telefono));
        }
    }
}

// Implementación de ServicioMedicos
void ServicioMedicos::altaMedico(const Medico& nuevo) {
    listaMedicos.push_back(nuevo);
    std::cout << "Médico agregado.\n";
    guardarDatos();  // Guardamos los datos después de agregar un médico
}

void ServicioMedicos::bajaMedico(int idMedico) {
    listaMedicos.erase(std::remove_if(listaMedicos.begin(), listaMedicos.end(),
        [idMedico](const Medico& m) { return m.getIdMedico() == idMedico; }), listaMedicos.end());
    std::cout << "Médico eliminado.\n";
    guardarDatos();  // Guardamos los datos después de eliminar un médico
}

void ServicioMedicos::guardarDatos() {
    std::ofstream file("medicos.txt");
    for (const auto& medico : listaMedicos) {
        file << medico.getIdMedico() << "\n";
        file << medico.getNombre() << "\n";
        file << medico.getDireccion() << "\n";
        file << medico.getTelefono() << "\n";
        file << medico.getEspecialidad() << "\n";
    }
    file.close();
}

void ServicioMedicos::cargarDatos() {
    std::ifstream file("medicos.txt");
    if (file.is_open()) {
        int id;
        std::string nombre, direccion, telefono, especialidad;
        while (file >> id) {
            std::getline(file, nombre);  // Saltar el salto de línea
            std::getline(file, nombre);
            std::getline(file, direccion);
            std::getline(file, telefono);
            std::getline(file, especialidad);
            listaMedicos.push_back(Medico(id, nombre, direccion, telefono, especialidad));
        }
    }
}

// Implementación de ServicioCitas
void ServicioCitas::agendarCita(int idPaciente, int idMedico, const std::string& fecha, const std::string& motivo) {
    listaCitas.push_back(Cita(listaCitas.size() + 1, idPaciente, idMedico, fecha, motivo));
    std::cout << "Cita agendada.\n";
    guardarDatos();  
}

void ServicioCitas::cancelarCita(int idCita) {
    listaCitas.erase(std::remove_if(listaCitas.begin(), listaCitas.end(),
        [idCita](const Cita& c) { return c.getIdCita() == idCita; }), listaCitas.end());
    std::cout << "Cita cancelada.\n";
    guardarDatos();  
}

void ServicioCitas::guardarDatos() {
    std::ofstream file("citas.txt");
    for (const auto& cita : listaCitas) {
        file << cita.getIdCita() << "\n";
        file << cita.getIdPaciente() << "\n";
        file << cita.getIdMedico() << "\n";
        file << cita.getFecha() << "\n";
        file << cita.getMotivo() << "\n";
    }
    file.close();
}

void ServicioCitas::cargarDatos() {
    std::ifstream file("citas.txt");
    if (file.is_open()) {
        int idCita, idPaciente, idMedico;
        std::string fecha, motivo;
        while (file >> idCita) {
            file >> idPaciente;
            file >> idMedico;
            file >> fecha;
            file >> motivo;
            listaCitas.push_back(Cita(idCita, idPaciente, idMedico, fecha, motivo));
        }
    }
}

// Implementación de ServicioArchivos
void ServicioArchivos::guardarDatos() {
    std::cout << "Guardando todos los datos...\n";

    ServicioPacientes().guardarDatos();
    ServicioMedicos().guardarDatos();
    ServicioCitas().guardarDatos();
}

void ServicioArchivos::cargarDatos() {
    std::cout << "Cargando todos los datos...\n";

    ServicioPacientes().cargarDatos();
    ServicioMedicos().cargarDatos();
    ServicioCitas().cargarDatos();
}

void ServicioArchivos::backup() {
    std::cout << "Realizando backup...\n";
    //Crear una copia de los archivos de datos actuales
}

void ServicioReportes::generarReporteAtencion(int idMedico) {
    
    std::cout << "Generando reporte de atención para el médico con ID: " << idMedico << std::endl;

    std::vector<std::string> atenciones = {
        "Atención 1: Consulta general",
        "Atención 2: Revisión de presión arterial",
        "Atención 3: Procedimiento quirúrgico menor"
    };

    std::cout << "Reporte de atención del médico con ID: " << idMedico << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    
    // Mostrar el reporte de atención
    for (const auto& atencion : atenciones) {
        std::cout << atencion << std::endl;
    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Reporte de atención generado con éxito." << std::endl;
}

void ServicioReportes::reporteCitasPendientes() {
   
    std::cout << "Generando reporte de citas pendientes..." << std::endl;

    // Simulación de datos
    std::vector<std::string> citasPendientes = {
        "Cita 1: 10:00 AM - Dr. Perez - Paciente: Sara Madrid",
        "Cita 2: 11:30 AM - Dr. Garcia - Paciente: Yolanda Pozo",
        "Cita 3: 2:00 PM - Dr. Martinez - Paciente: Adrian Calero"
    };

    std::cout << "Reporte de citas pendientes:" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    
    // Mostrar las citas pendientes
    for (const auto& cita : citasPendientes) {
        std::cout << cita << std::endl;
    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Reporte de citas pendientes generado con éxito." << std::endl;
}
