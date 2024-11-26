#include "Modelos.h"

// Implementación de Persona
Persona::Persona(const std::string& nombre, const std::string& direccion, const std::string& telefono)
    : nombre(nombre), direccion(direccion), telefono(telefono) {}

// Implementación de Paciente
Paciente::Paciente(int id, const std::string& nombre, const std::string& direccion, const std::string& telefono)
    : Persona(nombre, direccion, telefono), idPaciente(id) {}

int Paciente::getIdPaciente() const { return idPaciente; }

// Implementación de Medico
Medico::Medico(int id, const std::string& nombre, const std::string& direccion, const std::string& telefono, const std::string& especialidad)
    : Persona(nombre, direccion, telefono), idMedico(id), especialidad(especialidad) {}

int Medico::getIdMedico() const {
    return idMedico;
}

std::string Medico::getEspecialidad() const {
    return especialidad;
}

void Medico::setEspecialidad(const std::string& nuevaEspecialidad) {
    especialidad = nuevaEspecialidad;
}

// Implementación de Cita
Cita::Cita(int idCita, int idPaciente, int idMedico, const std::string& fecha, const std::string& motivo)
    : idCita(idCita), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), motivo(motivo) {}

int Cita::getIdCita() const {
    return idCita;
}

int Cita::getIdPaciente() const {
    return idPaciente;
}

int Cita::getIdMedico() const {
    return idMedico;
}

std::string Cita::getFecha() const {
    return fecha;
}

std::string Cita::getMotivo() const {
    return motivo;
}

void Cita::setFecha(const std::string& nuevaFecha) {
    fecha = nuevaFecha;
}

void Cita::setMotivo(const std::string& nuevoMotivo) {
    motivo = nuevoMotivo;
}
