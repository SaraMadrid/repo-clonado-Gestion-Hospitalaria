#include "InterfazHospital.h"
#include "ServicioCitas.h"
#include "ServicioPacientes.h"
#include "ServicioMedicos.h"
#include "ServicioArchivos.h"
#include <iostream>
#include <memory>
#include <locale>

int main() {
    try {
        std::locale::global(std::locale(""));
        std::cout << "Iniciando sistema de gestión hospitalaria...\n";

        auto servicioCitas = std::make_unique<ServicioCitas>("citas.txt");
        auto servicioPacientes = std::make_unique<ServicioPacientes>("pacientes.txt");
        auto servicioMedicos = std::make_unique<ServicioMedicos>("medicos.txt");
        auto servicioArchivos = std::make_unique<ServicioArchivos>();  

        InterfazHospital interfaz(std::move(servicioCitas), std::move(servicioPacientes), std::move(servicioMedicos), std::move(servicioArchivos));

        interfaz.iniciar(); 

    } catch (const std::exception& e) {
        std::cerr << "Error crítico: " << e.what() << std::endl;
    }

    std::cout << "Presione Enter para salir...";
    std::cin.get();  // Evita que la ventana se cierre inmediatamente si hay algún error

    return 0;
}
