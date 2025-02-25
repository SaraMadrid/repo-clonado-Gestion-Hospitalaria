#include "Cita.h"
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>

// Constructor por defecto
Cita::Cita() : id(0), idPaciente(0), idMedico(0), fecha(""), hora(""), motivo("") {}

// Constructor con parámetros
Cita::Cita(int id, int idPaciente, int idMedico, const std::string& fecha, const std::string& hora, const std::string& motivo)
    : id(id), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), hora(hora), motivo(motivo) {}

// Getters
int Cita::getId() const { return id; }
int Cita::getIdPaciente() const { return idPaciente; }
int Cita::getIdMedico() const { return idMedico; }
std::string Cita::getFecha() const { return fecha; }
std::string Cita::getHora() const { return hora; }
std::string Cita::getMotivo() const { return motivo; }

// Setters
void Cita::setId(int nuevoId) { id = nuevoId; }
void Cita::setIdPaciente(int nuevoIdPaciente) { idPaciente = nuevoIdPaciente; }
void Cita::setIdMedico(int nuevoIdMedico) { idMedico = nuevoIdMedico; }
void Cita::setFecha(const std::string& nuevaFecha) { fecha = nuevaFecha; }
void Cita::setHora(const std::string& nuevaHora) { hora = nuevaHora; }
void Cita::setMotivo(const std::string& nuevoMotivo) { motivo = nuevoMotivo; }

// Método para verificar si la cita es en una fecha específica
bool Cita::esEnFecha(const std::string& fechaConsulta) const {
    return fecha == fechaConsulta;
}

// Serializar Cita a cadena de texto
std::string Cita::serializar() const {
    return std::to_string(id) + "," + std::to_string(idPaciente) + "," +
           std::to_string(idMedico) + "," + fecha + "," + hora + "," + motivo;
}

// Deserializar con validaciones
void Cita::deserializar(const std::string& datos) {
    std::istringstream stream(datos);
    std::string token;
    std::vector<std::string> valores;

    while (std::getline(stream, token, ',')) {
        valores.push_back(token);
    }

    // Validar que haya exactamente 6 valores
    if (valores.size() != 6) {
        throw std::runtime_error("Error al deserializar cita: formato inválido. Se esperaban 6 valores, pero se recibieron " +
                                 std::to_string(valores.size()) + " -> " + datos);
    }

    try {
        // Validar que los tres primeros valores sean numéricos antes de convertirlos
        if (valores[0].empty() || valores[1].empty() || valores[2].empty() ||
            !std::all_of(valores[0].begin(), valores[0].end(), ::isdigit) ||
            !std::all_of(valores[1].begin(), valores[1].end(), ::isdigit) ||
            !std::all_of(valores[2].begin(), valores[2].end(), ::isdigit)) {
            throw std::runtime_error("Error: ID, ID del paciente o ID del médico no son válidos. Datos: " + datos);
        }

        // Validar que fecha, hora y motivo no estén vacíos
        if (valores[3].empty() || valores[4].empty() || valores[5].empty()) {
            throw std::runtime_error("Error: Fecha, hora o motivo no pueden estar vacíos. Datos: " + datos);
        }

        // Asignar valores después de validar
        id = std::stoi(valores[0]);
        idPaciente = std::stoi(valores[1]);
        idMedico = std::stoi(valores[2]);
        fecha = valores[3];
        hora = valores[4];
        motivo = valores[5];
    } catch (const std::exception& e) {
        throw std::runtime_error("Error al convertir datos en deserialización de cita. Datos: " + datos + " | Detalle: " + e.what());
    }
}





