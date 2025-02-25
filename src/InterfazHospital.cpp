#include "InterfazHospital.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <regex>

// Rutas absoluta para los archivos que se duplicaban
const std::string rutaBase = "C:\\Proyectos\\ProyectoGestionHospitalaria\\build\\Debug\\";

InterfazHospital::InterfazHospital(
    std::unique_ptr<IServicioCitas> citas, 
    std::unique_ptr<IServicioPacientes> pacientes, 
    std::unique_ptr<IServicioMedicos> medicos,
    std::unique_ptr<IServicioArchivos> archivos
) : servicioCitas(std::move(citas)), 
    servicioPacientes(std::move(pacientes)), 
    servicioMedicos(std::move(medicos)),
    servicioArchivos(std::move(archivos)) {}


bool InterfazHospital::archivoExiste(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    return archivo.good();             
}

void InterfazHospital::iniciar() {
    
    // Crear archivos si no existen 
    if (!archivoExiste(rutaBase + "pacientes.txt")) {
        std::ofstream archivo(rutaBase + "pacientes.txt");
        archivo.close();
    }
    if (!archivoExiste(rutaBase + "medicos.txt")) {
        std::ofstream archivo(rutaBase + "medicos.txt");
        archivo.close();
    }
    if (!archivoExiste(rutaBase + "citas.txt")) {
        std::ofstream archivo(rutaBase + "citas.txt");
        archivo.close();
    }

    // Cargar datos desde los archivos correctos
    servicioPacientes->cargarPacientesDesdeArchivo(rutaBase + "pacientes.txt");
    servicioMedicos->cargarMedicosDesdeArchivo(rutaBase + "medicos.txt");
    servicioCitas->cargarCitasDesdeArchivo(rutaBase + "citas.txt");

    std::cout << "Servicios cargados correctamente.\n"; 

    int opcion;
    do {
        mostrarMenuPrincipal();
        std::cin >> opcion;
        switch (opcion) {
        case 1:
            gestionarPacientes();
            break;
        case 2:
            gestionarMedicos();
            break;
        case 3:
            gestionarCitas();
            break;
        case 4:
            generarReportes();
            break;
        case 0:
            // Guardar datos en los archivos correctos antes de salir
            servicioPacientes->guardarPacientesEnArchivo(rutaBase + "pacientes.txt");
            servicioMedicos->guardarMedicosEnArchivo(rutaBase + "medicos.txt");
            servicioCitas->guardarCitasEnArchivo(rutaBase + "citas.txt");
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

void InterfazHospital::mostrarMenuPrincipal() {
    std::cout << "\n--- Menú Principal ---\n";
    std::cout << "1. Gestionar Pacientes\n";
    std::cout << "2. Gestionar Médicos\n";
    std::cout << "3. Gestionar Citas\n";
    std::cout << "4. Generar Reportes\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opción: ";
}

// Función auxiliar para limpiar la entrada
void limpiarEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


// Gestión de pacientes
void InterfazHospital::gestionarPacientes() {
    int opcion;
    do {
        std::cout << "\n--- Gestión de Pacientes ---\n";
        std::cout << "1. Agregar Paciente\n";
        std::cout << "2. Buscar Paciente por ID\n";
        std::cout << "3. Modificar Paciente\n";
        std::cout << "4. Eliminar Paciente\n";
        std::cout << "5. Ver Todos los Pacientes\n";
        std::cout << "6. Volver al menú principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            limpiarEntrada();
            continue;
        }

        switch (opcion) {
            case 1: agregarPaciente(); break;
            case 2: {
                std::cout << "Ingrese ID del paciente a buscar: ";
                int id;
                std::cin >> id;
                Paciente* paciente = servicioPacientes->buscarPacientePorId(id);
                if (paciente) {
                    std::cout << "Paciente encontrado: " << paciente->getNombre() << "\n";
                } else {
                    std::cout << "Paciente no encontrado.\n";
                }
                break;
            }
            case 3: modificarPaciente(); break;
            case 4: eliminarPaciente(); break;
            case 5: listarPacientes(); break;
            case 6: return;
            default: std::cout << "Opción inválida.\n";
        }
    } while (opcion != 6);
}

void InterfazHospital::agregarPaciente() {
    int id, edad;
    std::string nombre, direccion, telefono;

    std::cout << "Ingrese ID del paciente: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Ingrese nombre del paciente: ";
    std::getline(std::cin, nombre);

    std::cout << "Ingrese edad del paciente: ";
    std::cin >> edad;
    std::cin.ignore();

    std::cout << "Ingrese dirección del paciente: ";
    std::getline(std::cin, direccion);

    std::cout << "Ingrese teléfono del paciente: ";
    std::getline(std::cin, telefono);

    Paciente nuevoPaciente(id, nombre);
    nuevoPaciente.setEdad(edad);
    nuevoPaciente.setDireccion(direccion);
    nuevoPaciente.setTelefono(telefono);

    servicioPacientes->agregarPaciente(nuevoPaciente);
    std::cout << "Paciente agregado con éxito.\n";
}


void InterfazHospital::modificarPaciente() {
    int id;
    std::cout << "Ingrese ID del paciente a modificar: ";
    std::cin >> id;

    Paciente* paciente = servicioPacientes->buscarPacientePorId(id);
    if (!paciente) {
        std::cout << "Paciente no encontrado.\n";
        return;
    }

    std::string nuevoNombre;
    std::cout << "Ingrese el nuevo nombre: ";
    std::cin.ignore();
    std::getline(std::cin, nuevoNombre);

    // Crear una copia del paciente con los datos modificados
    Paciente nuevoPaciente = *paciente;
    nuevoPaciente.setNombre(nuevoNombre);

    // Llamar a modificarPaciente para actualizar el archivo
    servicioPacientes->modificarPaciente(id, nuevoPaciente);

    std::cout << "Paciente actualizado con éxito.\n";
}


void InterfazHospital::eliminarPaciente() {
    int id;
    std::cout << "Ingrese ID del paciente a eliminar: ";
    std::cin >> id;

    if (servicioPacientes->eliminarPaciente(id)) {
        std::cout << "Paciente eliminado con éxito.\n";
    } else {
        std::cout << "No se encontró el paciente con ID " << id << ".\n";
    }
}

void InterfazHospital::listarPacientes() {
    auto pacientes = servicioPacientes->obtenerTodosLosPacientes();
    std::cout << "Lista de Pacientes:\n";
    for (const auto& p : pacientes) {
        std::cout << "ID: " << p.getId()
                  << " - Nombre: " << p.getNombre()
                  << " - Edad: " << p.getEdad()
                  << " - Dirección: " << p.getDireccion()
                  << " - Teléfono: " << p.getTelefono() << "\n";
    }
}



// Gestión de Médicos
void InterfazHospital::gestionarMedicos() {
    int opcion;
    do {
        std::cout << "\n--- Gestión de Médicos ---\n";
        std::cout << "1. Agregar Médico\n";
        std::cout << "2. Buscar Médico por ID\n";
        std::cout << "3. Modificar Médico\n";
        std::cout << "4. Eliminar Médico\n";
        std::cout << "5. Ver Todos los Médicos\n";
        std::cout << "6. Volver al menú principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cout << "Entrada no válida. Intente de nuevo.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1: agregarMedico(); break;
            case 2: {
                std::cout << "Ingrese ID del médico a buscar: ";
                int id;
                std::cin >> id;
                Medico* medico = servicioMedicos->buscarMedicoPorId(id);
                if (medico) {
                    std::cout << "Médico encontrado: " << medico->getNombre() << " - " << medico->getEspecialidad() << "\n";
                } else {
                    std::cout << "Médico no encontrado.\n";
                }
                break;
            }
            case 3: modificarMedico(); break;
            case 4: eliminarMedico(); break;
            case 5: listarMedicos(); break;
            case 6: return;
            default: std::cout << "Opción inválida.\n";
        }
    } while (opcion != 6);
}

void InterfazHospital::agregarMedico() {
    int id;
    std::string nombre, especialidad;

    std::cout << "Ingrese ID del médico: ";
    std::cin >> id;

    // Verificar si el ID ya existe
    if (servicioMedicos->buscarMedicoPorId(id) != nullptr) {
        std::cout << "Error: Ya existe un médico con este ID.\n";
        return;
    }

    std::cout << "Ingrese nombre del médico: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    std::cout << "Ingrese especialidad: ";
    std::getline(std::cin, especialidad);

    Medico nuevoMedico(id, nombre, especialidad);
    servicioMedicos->agregarMedico(nuevoMedico);
    
    // Guardar automáticamente después de agregar
    servicioMedicos->guardarMedicosEnArchivo("medicos.txt");

    std::cout << "Médico agregado con éxito.\n";
}

void InterfazHospital::modificarMedico() {
    int id;
    std::cout << "Ingrese ID del médico a modificar: ";
    std::cin >> id;

    Medico* medico = servicioMedicos->buscarMedicoPorId(id);
    if (!medico) {
        std::cout << "Error: Médico no encontrado.\n";
        return;
    }

    std::string nuevoNombre, nuevaEspecialidad;
    std::cout << "Nuevo nombre (actual: " << medico->getNombre() << "): ";
    std::cin.ignore();
    std::getline(std::cin, nuevoNombre);
    std::cout << "Nueva especialidad (actual: " << medico->getEspecialidad() << "): ";
    std::getline(std::cin, nuevaEspecialidad);

    // Modificar directamente el médico encontrado
    medico->setNombre(nuevoNombre);
    medico->setEspecialidad(nuevaEspecialidad);
    
    // Guardar automáticamente después de modificar
    servicioMedicos->guardarMedicosEnArchivo("medicos.txt");

    std::cout << "Médico modificado con éxito.\n";
}

void InterfazHospital::eliminarMedico() {
    int id;
    std::cout << "Ingrese ID del médico a eliminar: ";
    std::cin >> id;

    if (servicioMedicos->buscarMedicoPorId(id) == nullptr) {
        std::cout << "Error: Médico no encontrado.\n";
        return;
    }

    servicioMedicos->eliminarMedico(id);
    
    // Guardar automáticamente después de eliminar
    servicioMedicos->guardarMedicosEnArchivo("medicos.txt");

    std::cout << "Médico eliminado con éxito.\n";
}

void InterfazHospital::listarMedicos() {
    std::vector<Medico> medicos = servicioMedicos->obtenerMedicos();

    std::cout << "Lista de Médicos:\n";
    for (const auto& medico : medicos) {
        std::cout << "ID: " << medico.getId()
                  << ", Nombre: " << medico.getNombre()
                  << ", Especialidad: " << medico.getEspecialidad() << "\n";
    }
}


//Gestión de Citas
void InterfazHospital::gestionarCitas() {
    int opcion;
    do {
        std::cout << "\nGestión de Citas\n";
        std::cout << "1. Agregar Cita\n";
        std::cout << "2. Modificar Cita\n";
        std::cout << "3. Eliminar Cita\n";
        std::cout << "4. Listar Citas\n";
        std::cout << "5. Volver al menú principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: agregarCita(); break;
            case 2: modificarCita(); break;
            case 3: eliminarCita(); break;
            case 4: listarCitas(); break;
            case 5: std::cout << "Volviendo al menú principal...\n"; break;
            default: std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 5);
}

bool validarFormatoFechaHora(const std::string& fecha, const std::string& hora) {
    std::regex formatoFecha("^\\d{2}/\\d{2}/\\d{4}$");  
    std::regex formatoHora("^\\d{2}:\\d{2}$");          
    return std::regex_match(fecha, formatoFecha) && std::regex_match(hora, formatoHora);
}

void InterfazHospital::agregarCita() {
    int idPaciente, idMedico;
    std::string fecha, hora, motivo;

    std::cout << "Ingrese ID del paciente: ";
    std::cin >> idPaciente;
    std::cout << "Ingrese ID del médico: ";
    std::cin >> idMedico;
    std::cin.ignore(); 
    
    std::cout << "Ingrese el motivo de la cita: ";
    std::getline(std::cin, motivo);

    do {
        std::cout << "Ingrese la fecha (DD/MM/YYYY): ";
        std::cin >> fecha;
        std::cout << "Ingrese la hora (HH:MM): ";
        std::cin >> hora;
        if (!validarFormatoFechaHora(fecha, hora)) {
            std::cout << "Formato incorrecto. Intente nuevamente.\n";
        }
    } while (!validarFormatoFechaHora(fecha, hora));

    Cita nuevaCita(0, idPaciente, idMedico, fecha, hora, motivo);
    servicioCitas->agregarCita(nuevaCita);
    std::cout << "Cita agregada exitosamente.\n";
}

void InterfazHospital::modificarCita() {
    int idCita;
    std::string nuevaFecha, nuevaHora;

    std::cout << "Ingrese ID de la cita a modificar: ";
    std::cin >> idCita;

    // Buscar la cita existente
    Cita* citaExistente = servicioCitas->buscarCitaPorId(idCita);
    
    if (citaExistente == nullptr) {
        std::cout << "Error: No se encontró una cita con el ID proporcionado.\n";
        return;
    }

    do {
        std::cout << "Ingrese la nueva fecha (DD/MM/YYYY): ";
        std::cin >> nuevaFecha;
        std::cout << "Ingrese la nueva hora (HH:MM): ";
        std::cin >> nuevaHora;
        if (!validarFormatoFechaHora(nuevaFecha, nuevaHora)) {
            std::cout << "Formato incorrecto. Intente nuevamente.\n";
        }
    } while (!validarFormatoFechaHora(nuevaFecha, nuevaHora));

    // Crear un nuevo objeto Cita con los datos actualizados
    Cita nuevaCita(
        citaExistente->getId(),  
        citaExistente->getIdPaciente(),
        citaExistente->getIdMedico(),
        nuevaFecha,
        nuevaHora,
        citaExistente->getMotivo()
    );

    // Modificar la cita en el sistema
    servicioCitas->modificarCita(idCita, nuevaCita);
    std::cout << "Cita modificada con éxito.\n";
}


void InterfazHospital::listarCitas() {
    std::vector<Cita> citas = servicioCitas->obtenerTodasLasCitas();

    std::cout << "Lista de Citas:\n";
    for (const auto& cita : citas) {
        std::cout << "ID: " << cita.getId()
                  << ", Paciente: " << cita.getIdPaciente()
                  << ", Médico: " << cita.getIdMedico()
                  << ", Fecha: " << cita.getFecha()
                  << ", Hora: " << cita.getHora()
                  << ", Motivo: " << cita.getMotivo() << "\n";
    }
}


void InterfazHospital::eliminarCita() {
    int idCita;
    std::cout << "Ingrese el ID de la cita a eliminar: ";
    std::cin >> idCita;

    servicioCitas->eliminarCita(idCita);
    std::cout << "Cita eliminada con éxito.\n";
}


// Generar reportes
void InterfazHospital::generarReportes() {
    std::cout << "\n--- Generación de Reportes ---\n";
    auto pacientes = servicioPacientes->obtenerTodosLosPacientes();
    auto medicos = servicioMedicos->obtenerMedicos();
    auto citas = servicioCitas->obtenerTodasLasCitas();

    servicioArchivos->generarReportePacientes(pacientes);
    servicioArchivos->generarReporteMedicos(medicos);
    servicioArchivos->generarReporteCitas(citas);

    std::cout << "Reportes generados correctamente.\n";
}
