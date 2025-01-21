#include "Cita.h"
#include <sstream>
#include <stdexcept>

// Constructor con parámetros
Cita::Cita(int id, int idPaciente, int idMedico, const std::string& fecha, const std::string& hora, const std::string& motivo)
    : id(id), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), hora(hora), motivo(motivo) {}


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

void Cita::setFecha(const std::string& fecha) {
    this->fecha = fecha;
}

std::string Cita::getHora() const {
    return hora;
}

void Cita::setHora(const std::string& hora) {
    this->hora = hora;
}

std::string Cita::getMotivo() const {
    return motivo;
}

void Cita::setMotivo(const std::string& motivo) {
    this->motivo = motivo;
}


bool Cita::esEnFecha(const std::string& fecha) const {
    return this->fecha == fecha;
}


std::string Cita::serializar() const {
    
    return std::to_string(id) + "," + std::to_string(idPaciente) + "," + std::to_string(idMedico) + "," +
           fecha + "," + hora + "," + motivo;
}


void Cita::deserializar(const std::string& cadena) {
    std::istringstream stream(cadena);
    std::string token;

    try {
        if (std::getline(stream, token, ',')) id = std::stoi(token);
        if (std::getline(stream, token, ',')) idPaciente = std::stoi(token);
        if (std::getline(stream, token, ',')) idMedico = std::stoi(token);
        if (std::getline(stream, token, ',')) fecha = token;
        if (std::getline(stream, token, ',')) hora = token;
        if (std::getline(stream, token, ',')) motivo = token;
    } catch (const std::exception&) { 
        throw std::runtime_error("Error al deserializar la cadena: formato inválido.");
    }
}

// Función auxiliar para extraer valores
std::string Cita::extraerValor(const std::string& cadena, const std::string& clave) const {
    size_t pos = cadena.find(clave);
    if (pos == std::string::npos) {
        throw std::runtime_error("Clave no encontrada en la cadena: " + clave);
    }
    pos += clave.size();
    size_t end = cadena.find(",", pos);
    return cadena.substr(pos, end - pos);
}