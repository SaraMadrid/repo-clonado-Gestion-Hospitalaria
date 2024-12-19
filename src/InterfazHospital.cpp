#include "InterfazHospital.h"
#include <iostream>
#include <limits>


void InterfazHospital::gestionarPacientes() {
    int opcion = 0;
    while (opcion != 4) {
        std::cout << "\nGestión de Pacientes\n";
        std::cout << "1. Alta de Paciente\n";
        std::cout << "2. Modificar Datos de Paciente\n";
        std::cout << "3. Baja de Paciente\n";
        std::cout << "4. Volver\n";
        std::cout << "Seleccione una opción: ";
        if (!(std::cin >> opcion)) {
            std::cout << "Error: Entrada no válida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1: {
                int id;
                std::string nombre, direccion, telefono;
                std::cout << "ID: ";
                if (!(std::cin >> id)) {
                    std::cout << "Error: Entrada no válida.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                std::cin.ignore();
                std::cout << "Nombre: ";
                std::getline(std::cin, nombre);
                std::cout << "Dirección: ";
                std::getline(std::cin, direccion);
                std::cout << "Teléfono: ";
                std::getline(std::cin, telefono);
                servicioPacientes.altaPaciente(Paciente(id, nombre, direccion, telefono));
                break;
            }
            case 2: {
                int id;
                std::string nuevoNombre;
                std::cout << "ID del paciente: ";
                if (!(std::cin >> id)) {
                    std::cout << "Error: Entrada no válida.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                std::cin.ignore();
                std::cout << "Nuevo Nombre: ";
                std::getline(std::cin, nuevoNombre);
                servicioPacientes.modificarDatos(id, nuevoNombre);
                break;
            }
            case 3: {
                int id;
                std::cout << "ID del paciente a eliminar: ";
                if (!(std::cin >> id)) {
                    std::cout << "Error: Entrada no válida.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                servicioPacientes.bajaPaciente(id);
                break;
            }
            case 4:
                std::cout << "Volviendo al menú principal...\n";
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    }
}


void InterfazHospital::gestionarMedicos() {
    int opcion = 0;
    while (opcion != 3) {
        std::cout << "\nGestión de Médicos\n";
        std::cout << "1. Alta de Médico\n";
        std::cout << "2. Baja de Médico\n";
        std::cout << "3. Volver\n";
        std::cout << "Seleccione una opción: ";
        if (!(std::cin >> opcion)) {
            std::cout << "Error: Entrada no válida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1: {
                int id;
                std::string nombre, direccion, telefono, especialidad;
                std::cout << "ID: ";
                if (!(std::cin >> id)) {
                    std::cout << "Error: Entrada no válida.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                std::cin.ignore();
                std::cout << "Nombre: ";
                std::getline(std::cin, nombre);
                std::cout << "Dirección: ";
                std::getline(std::cin, direccion);
                std::cout << "Teléfono: ";
                std::getline(std::cin, telefono);
                std::cout << "Especialidad: ";
                std::getline(std::cin, especialidad);
                servicioMedicos.altaMedico(Medico(id, nombre, direccion, telefono, especialidad));
                break;
            }
            case 2: {
                int id;
                std::cout << "ID del médico a eliminar: ";
                if (!(std::cin >> id)) {
                    std::cout << "Error: Entrada no válida.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                servicioMedicos.bajaMedico(id);
                break;
            }
            case 3:
                std::cout << "Volviendo al menú principal...\n";
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    }
}


void InterfazHospital::gestionarCitas() {
    int opcion = 0;
    while (opcion != 3) {
        std::cout << "\nGestión de Citas\n";
        std::cout << "1. Agendar Cita\n";
        std::cout << "2. Cancelar Cita\n";
        std::cout << "3. Volver\n";
        std::cout << "Seleccione una opción: ";
        if (!(std::cin >> opcion)) {
            std::cout << "Error: Entrada no válida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1: {
                int idPaciente, idMedico;
                std::string fecha, motivo;
                std::cout << "ID del Paciente: ";
                if (!(std::cin >> idPaciente)) {
                    std::cout << "Error: Entrada no válida.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                std::cout << "ID del Médico: ";
                if (!(std::cin >> idMedico)) {
                    std::cout << "Error: Entrada no válida.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                std::cin.ignore();
                std::cout << "Fecha (YYYY-MM-DD): ";
                std::getline(std::cin, fecha);
                std::cout << "Motivo: ";
                std::getline(std::cin, motivo);
                servicioCitas.agendarCita(idPaciente, idMedico, fecha, motivo);
                break;
            }
            case 2: {
                int idCita;
                std::cout << "ID de la cita a cancelar: ";
                if (!(std::cin >> idCita)) {
                    std::cout << "Error: Entrada no válida.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                servicioCitas.cancelarCita(idCita);
                break;
            }
            case 3:
                std::cout << "Volviendo al menú principal...\n";
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    }
}


void InterfazHospital::generarReportes() {
    int opcion = 0;
    while (opcion != 3) {
        std::cout << "\nGeneración de Reportes\n";
        std::cout << "1. Generar reporte de atención por médico\n";
        std::cout << "2. Generar reporte de citas pendientes\n";
        std::cout << "3. Volver\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int idMedico;
                std::cout << "Ingrese el ID del médico: ";
                std::cin >> idMedico;
                servicioReportes.generarReporteAtencion(idMedico); 
                break;
            }
            case 2:
                servicioReportes.reporteCitasPendientes();  
                break;
            case 3:
                std::cout << "Volviendo al menú principal...\n";
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    }
}

void InterfazHospital::gestionarArchivos() {
    int opcion = 0;
    while (opcion != 4) {
        std::cout << "\nGestión de Archivos\n";
        std::cout << "1. Guardar Datos\n";
        std::cout << "2. Cargar Datos\n";
        std::cout << "3. Realizar Respaldo\n";
        std::cout << "4. Volver\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                servicioArchivos.guardarDatos();
                break;
            case 2:
                servicioArchivos.cargarDatos();
                break;
            case 3:
                servicioArchivos.backup();
                break;
            case 4:
                std::cout << "Volviendo al menú principal...\n";
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    }
}
