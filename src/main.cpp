#include <iostream>
#include "InterfazHospital.h"

int main() {
    InterfazHospital interfaz;

    int opcion = 0;
    while (opcion != 6) {
        std::cout << "Simulador de Gestión Hospitalaria\n";
        std::cout << "1. Gestionar Pacientes\n";
        std::cout << "2. Gestionar Médicos\n";
        std::cout << "3. Gestionar Citas\n";
        std::cout << "4. Generar Reportes\n";
        std::cout << "5. Gestionar Archivos\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: interfaz.gestionarPacientes(); break;
            case 2: interfaz.gestionarMedicos(); break;
            case 3: interfaz.gestionarCitas(); break;
            case 4: interfaz.generarReportes(); break;
            case 5: interfaz.gestionarArchivos(); break;
            case 6: std::cout << "Saliendo del programa...\n"; break;
            default: std::cout << "Opción no válida, intente de nuevo.\n";
        }
    }

    return 0;
}
