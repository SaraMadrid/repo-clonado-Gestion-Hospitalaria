#include "Cita.h"
#include <iostream>
#include <sstream>

// Constructor por defecto
Cita::Cita() : id(0), idPaciente(0), idMedico(0), fecha(""), hora(""), motivo("") {}

// Constructor con parámetros
Cita::Cita(int id, int idPaciente, int idMedico, const std::string &fecha, const std::string &hora, const std::string &motivo)
    : id(id), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), hora(hora), motivo(motivo) {}

// Métodos de acceso (getters y setters)
int Cita::getId() const {
    return id;
}

void Cita::setId(int id) {
    this->id = id;
}

int Cita::getIdPaciente() const {
    return idPaciente;
}

void Cita::setIdPaciente(int idPaciente) {
    this->idPaciente = idPaciente;
}

int Cita::getIdMedico() const {
    return idMedico;
}

void Cita::setIdMedico(int idMedico) {
    this->idMedico = idMedico;
}

std::string Cita::getFecha() const {
    return fecha;
}

void Cita::setFecha(const std::string &fecha) {
    this->fecha = fecha;
}

std::string Cita::getHora() const {
    return hora;
}

void Cita::setHora(const std::string &hora) {
    this->hora = hora;
}

std::string Cita::getMotivo() const {
    return motivo;
}

void Cita::setMotivo(const std::string &motivo) {
    this->motivo = motivo;
}

// Método para comparar fechas
bool Cita::esEnFecha(const std::string &fecha) const {
    return this->fecha == fecha;
}

// Método de serialización
std::string Cita::serializar() const {
    return "Cita ID: " + std::to_string(id) + ", Paciente ID: " + std::to_string(idPaciente) + 
           ", Medico ID: " + std::to_string(idMedico) + ", Fecha: " + fecha + ", Hora: " + hora +
           ", Motivo: " + motivo;
}

// Método de deserialización
void Cita::deserializar(const std::string& cadena) {
    size_t pos = 0;

    // Extraer ID
    pos = cadena.find("ID: ") + 4;
    id = std::stoi(cadena.substr(pos, cadena.find(",", pos) - pos));

    // Extraer idPaciente
    pos = cadena.find("Paciente ID: ") + 13;
    idPaciente = std::stoi(cadena.substr(pos, cadena.find(",", pos) - pos));

    // Extraer idMedico
    pos = cadena.find("Medico ID: ") + 11;
    idMedico = std::stoi(cadena.substr(pos, cadena.find(",", pos) - pos));

    // Extraer fecha
    pos = cadena.find("Fecha: ") + 7;
    fecha = cadena.substr(pos, cadena.find(",", pos) - pos);

    // Extraer hora
    pos = cadena.find("Hora: ") + 6;
    hora = cadena.substr(pos, cadena.find(",", pos) - pos);

    // Extraer motivo
    pos = cadena.find("Motivo: ") + 8;
    motivo = cadena.substr(pos);
}












