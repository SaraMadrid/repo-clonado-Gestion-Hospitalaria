#include "InterfazHospital.h"
#include "Cita.h"
#include "ServicioCitas.h"
#include "ServicioPacientes.h"
#include "ServicioMedicos.h"
#include "ServicioArchivos.h"
#include "Paciente.h"
#include "Medico.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <regex>

using namespace std;


InterfazHospital::InterfazHospital()
    : servicioPacientes("pacientes.txt"),
      servicioMedicos("medicos.txt"),
      servicioCitas("citas.txt") {
}

void InterfazHospital::iniciar() {
    
    servicioPacientes.cargarPacientesDesdeArchivo("pacientes.txt");
    servicioMedicos.cargarMedicosDesdeArchivo("medicos.txt");
    servicioCitas.cargarCitasDesdeArchivo("citas.txt");

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
        case 0:
        
            // Guardar los datos en los archivos antes de salir
            servicioPacientes.guardarPacientesEnArchivo("pacientes.txt");
            servicioMedicos.guardarMedicosEnArchivo("medicos.txt");
            servicioCitas.guardarCitasEnArchivo("citas.txt");
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
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opción: ";
}

// Gestión de Médicos
void InterfazHospital::gestionarMedicos() {
    int opcion;
    do {
        std::cout << "\n--- Gestión de Médicos ---\n";
        std::cout << "1. Agregar Médico\n";
        std::cout << "2. Modificar Médico\n";
        std::cout << "3. Eliminar Médico\n";
        std::cout << "4. Listar Médicos\n";
        std::cout << "0. Regresar\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            agregarMedico();
            break;
        case 2:
            modificarMedico();
            break;
        case 3:
            eliminarMedico();
            break;
        case 4:
            listarMedicos();
            break;
        case 0:
            break;
        default:
            std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

void InterfazHospital::agregarMedico() {
    int id;
    std::string nombre, especialidad;

    std::cout << "Ingrese ID del médico: ";
    while (!(std::cin >> id)) {
        std::cout << "ID inválido. Ingrese un número entero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore();

    std::cout << "Ingrese nombre del médico: ";
    std::getline(std::cin, nombre);

    std::cout << "Ingrese especialidad del médico: ";
    std::getline(std::cin, especialidad);

    Medico medico(id, nombre, especialidad);  
    servicioMedicos.agregarMedico(medico);    

    std::cout << "Médico agregado con éxito.\n";
}

void InterfazHospital::modificarMedico() {
    int id;
    std::cout << "Ingrese ID del médico a modificar: ";
    while (!(std::cin >> id)) {
        std::cout << "ID inválido. Ingrese un número entero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    Medico* medico = servicioMedicos.buscarMedicoPorId(id);  
    if (medico) {
        std::string nombre, especialidad;
        std::cin.ignore();  
        std::cout << "Ingrese nuevo nombre: ";
        std::getline(std::cin, nombre);
        std::cout << "Ingrese nueva especialidad: ";
        std::getline(std::cin, especialidad);

        medico->setNombre(nombre);      
        medico->setEspecialidad(especialidad); 

        std::cout << "Médico modificado con éxito.\n";
    } else {
        std::cout << "Médico no encontrado.\n";
    }
}

void InterfazHospital::eliminarMedico() {
    int id;
    std::cout << "Ingrese ID del médico a eliminar: ";
    while (!(std::cin >> id)) {
        std::cout << "ID inválido. Ingrese un número entero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    servicioMedicos.eliminarMedico(id);
    std::cout << "Médico eliminado con éxito (si existía).\n";
}

void InterfazHospital::listarMedicos() {
    auto medicos = servicioMedicos.obtenerTodosLosMedicos();
    for (const auto& medico : medicos) {
        std::cout << "ID: " << medico.getId()
                  << ", Nombre: " << medico.getNombre()
                  << ", Especialidad: " << medico.getEspecialidad() << "\n";
    }
}

// Gestión de Pacientes
void InterfazHospital::gestionarPacientes() {
    int opcion;
    do {
        cout << "\n--- Gestión de Pacientes ---\n";
        cout << "1. Agregar Paciente\n";
        cout << "2. Modificar Paciente\n";
        cout << "3. Eliminar Paciente\n";
        cout << "4. Listar Pacientes\n";
        cout << "0. Regresar\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarPaciente();
                break;
            case 2:
                modificarPaciente();
                break;
            case 3:
                eliminarPaciente();
                break;
            case 4:
                listarPacientes();
                break;
            case 0:
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

void InterfazHospital::agregarPaciente() {
    int id, edad;
    string nombre, direccion, telefono;

    cout << "Ingrese el ID del paciente: ";
    while (!(cin >> id)) {
        cout << "ID inválido. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore();
    cout << "Ingrese el nombre del paciente: ";
    getline(cin, nombre);

    cout << "Ingrese la edad del paciente: ";
    while (!(cin >> edad)) {
        cout << "Edad inválida. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore();
    cout << "Ingrese la dirección del paciente: ";
    getline(cin, direccion);

    cout << "Ingrese el teléfono del paciente: ";
    getline(cin, telefono);

    Paciente nuevoPaciente(id, nombre, edad, direccion, telefono);
    servicioPacientes.agregarPaciente(nuevoPaciente);

    cout << "Paciente agregado exitosamente.\n";
}

void InterfazHospital::modificarPaciente() {
    int id;
    cout << "Ingrese el ID del paciente a modificar: ";
    while (!(cin >> id)) {
        cout << "ID inválido. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Paciente* paciente = servicioPacientes.buscarPacientePorId(id);
    if (paciente) {
        string nuevoNombre, nuevaDireccion, nuevoTelefono;
        int nuevaEdad;

        cin.ignore();
        cout << "Ingrese el nuevo nombre (actual: " << paciente->getNombre() << "): ";
        getline(cin, nuevoNombre);

        cout << "Ingrese la nueva edad (actual: " << paciente->getEdad() << "): ";
        while (!(cin >> nuevaEdad)) {
            cout << "Edad inválida. Intente nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore();
        cout << "Ingrese la nueva dirección (actual: " << paciente->getDireccion() << "): ";
        getline(cin, nuevaDireccion);

        cout << "Ingrese el nuevo teléfono (actual: " << paciente->getTelefono() << "): ";
        getline(cin, nuevoTelefono);

        paciente->setNombre(nuevoNombre);
        paciente->setEdad(nuevaEdad);
        paciente->setDireccion(nuevaDireccion);
        paciente->setTelefono(nuevoTelefono);

        cout << "Paciente modificado correctamente.\n";
    } else {
        cout << "No se encontró un paciente con el ID proporcionado.\n";
    }
}

void InterfazHospital::eliminarPaciente() {
    int id;
    cout << "Ingrese el ID del paciente a eliminar: ";

    while (!(cin >> id)) {
        cout << "ID inválido. Intente nuevamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    bool resultado = servicioPacientes.eliminarPaciente(id);  
    if (resultado) {
        cout << "Paciente eliminado con éxito.\n";
    } else {
        cout << "No se pudo eliminar el paciente. Verifique si el ID es válido.\n";
    }
}

void InterfazHospital::listarPacientes() {
    auto pacientes = servicioPacientes.obtenerTodosLosPacientes();
    if (pacientes.empty()) {
        cout << "No hay pacientes registrados.\n";
        return;
    }

    cout << "Listado de pacientes:\n";
    for (const auto& paciente : pacientes) {
        cout << "ID: " << paciente.getId() << "\n";
        cout << "Nombre: " << paciente.getNombre() << "\n";
        cout << "Edad: " << paciente.getEdad() << "\n";
        cout << "Dirección: " << paciente.getDireccion() << "\n";
        cout << "Teléfono: " << paciente.getTelefono() << "\n";
        cout << "-------------------------\n";
    }
}


// Gestión de Citas
void InterfazHospital::gestionarCitas() {
    int opcion;
    do {
        std::cout << "\n--- Gestión de Citas ---\n";
        std::cout << "1. Agregar Cita\n";
        std::cout << "2. Modificar Cita\n";
        std::cout << "3. Eliminar Cita\n";
        std::cout << "4. Listar Citas\n";
        std::cout << "0. Regresar\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            agregarCita();
            break;
        case 2:
            modificarCita();
            break;
        case 3:
            eliminarCita();
            break;
        case 4:
            listarCitas();
            break;
        case 0:
            break;
        default:
            std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

void InterfazHospital::agregarCita() {
    int id, idPaciente, idMedico;
    std::string fecha, hora, motivo;

    std::cout << "Ingrese ID de la cita: ";
    while (!(std::cin >> id)) {
        std::cout << "ID inválido. Ingrese un número entero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Ingrese ID del paciente: ";
    while (!(std::cin >> idPaciente)) {
        std::cout << "ID inválido. Ingrese un número entero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Ingrese ID del médico: ";
    while (!(std::cin >> idMedico)) {
        std::cout << "ID inválido. Ingrese un número entero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore();

    std::cout << "Ingrese fecha de la cita (YYYY-MM-DD): ";
    while (true) {
        std::getline(std::cin, fecha);
        if (std::regex_match(fecha, std::regex("\\d{4}-\\d{2}-\\d{2}"))) {
            break;
        }
        std::cout << "Formato inválido. Ingrese una fecha válida (YYYY-MM-DD): ";
    }

    std::cout << "Ingrese hora de la cita (HH:MM): ";
    while (true) {
        std::getline(std::cin, hora);
        if (std::regex_match(hora, std::regex("\\d{2}:\\d{2}"))) {
            break;
        }
        std::cout << "Formato inválido. Ingrese una hora válida (HH:MM): ";
    }

    std::cout << "Ingrese motivo de la cita: ";
    std::getline(std::cin, motivo);

    Cita cita(id, idPaciente, idMedico, fecha, hora, motivo);
    servicioCitas.agregarCita(cita);

    std::cout << "Cita agregada con éxito.\n";
    
}

void InterfazHospital::modificarCita() {
    int id;
    std::cout << "Ingrese ID de la cita a modificar: ";
    while (!(std::cin >> id)) {
        std::cout << "ID inválido. Ingrese un número entero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    Cita* cita = servicioCitas.buscarCitaPorId(id);  
    if (cita) {  
        std::string fecha, hora, motivo;
        std::cin.ignore();

        std::cout << "Ingrese nueva fecha de la cita (YYYY-MM-DD): ";
        while (true) {
            std::getline(std::cin, fecha);
            if (std::regex_match(fecha, std::regex("\\d{4}-\\d{2}-\\d{2}"))) {
                break;
            }
            std::cout << "Formato inválido. Ingrese una fecha válida (YYYY-MM-DD): ";
        }

        std::cout << "Ingrese nueva hora de la cita (HH:MM): ";
        while (true) {
            std::getline(std::cin, hora);
            if (std::regex_match(hora, std::regex("\\d{2}:\\d{2}"))) {
                break;
            }
            std::cout << "Formato inválido. Ingrese una hora válida (HH:MM): ";
        }

        std::cout << "Ingrese el nuevo motivo de la cita: ";
        std::getline(std::cin, motivo);

        cita->setFecha(fecha);
        cita->setHora(hora);
        cita->setMotivo(motivo);

        std::cout << "Cita modificada con éxito.\n";
    } else {
        std::cout << "Cita no encontrada.\n";
    }
}

void InterfazHospital::eliminarCita() {
    int id;
    std::cout << "Ingrese ID de la cita a eliminar: ";
    while (!(std::cin >> id)) {
        std::cout << "ID inválido. Ingrese un número entero: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    servicioCitas.eliminarCita(id);  
    std::cout << "Cita eliminada con éxito (si existía).\n";
}

void InterfazHospital::listarCitas() {
    auto citas = servicioCitas.obtenerTodasLasCitas();
    if (citas.empty()) {
        std::cout << "No hay citas registradas.\n";
        return;
    }

    std::cout << "Listado de citas:\n";
    for (const auto& cita : citas) {
        std::cout << "ID: " << cita.getId() << "\n";
        std::cout << "Paciente ID: " << cita.getIdPaciente() << "\n";
        std::cout << "Médico ID: " << cita.getIdMedico() << "\n";
        std::cout << "Fecha: " << cita.getFecha() << "\n";
        std::cout << "Hora: " << cita.getHora() << "\n";
        std::cout << "Motivo: " << cita.getMotivo() << "\n";
        std::cout << "-------------------------\n";
    }
}


