
/*
Archivo: main.cpp
Función principal: main
Responsabilidad:
- Es el punto de inicio del programa y gestiona el flujo principal del juego.
- Presenta el menú principal y permite seleccionar entre los diferentes modos de juego.
- Llama a las funciones correspondientes para cada modo: manual, IA o demostración automática.

Colaboradores:
- Juego: Gestiona la lógica y reglas del juego.
- Tablero: Estructura que representa el entorno de juego.
- Avatar: Personaje controlado por el usuario.
- AvatarInnovador: Personaje controlado por inteligencia artificial.
- LogicaDeMovimiento: Encargada de validar y ejecutar los movimientos.
- VistaConsola: Encargada de mostrar el estado del juego y recibir entradas del usuario.

Librerías utilizadas:
- <iostream>: Entrada y salida estándar.
- <cstdlib>: Utilidades generales.
- <thread>, <chrono>: Control de pausas y temporización.

Punteros y referencias:
- Se emplean punteros y referencias para compartir el estado entre los objetos principales.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#include <iostream>
#include "Tablero.h"
#include "Camino.h"
#include "Abismo.h"
#include "Salida.h"
#include "Juego.h"
#include "LogicaDeMovimiento.h"
#include "VistaConsola.h"
#include "Avatar.h"
#include "AvatarInnovador.h"
#include <cstdlib>
#include <thread>
#include <chrono>

// Muestra el menú principal del juego
void mostrarMenu() {
    std::cout << "\n=== MENÚ PRINCIPAL ===\n";
    std::cout << "1. Modo manual (control directo del avatar)\n";
    std::cout << "2. Modo inteligente (avatar IA)\n";
    std::cout << "3. Demostración automática (IA sin intervención)\n";
    std::cout << "4. Finalizar programa\n";
    std::cout << "Ingrese el número de la opción deseada: ";
}

// Ejecuta el modo manual donde el usuario controla el avatar
void juegoManual() {
    std::cout << "\n--- MODO MANUAL ACTIVADO ---\n";

    Tablero tableroPrincipal;
    tableroPrincipal.cargarDesdeArchivo("dataTablero.txt");

    Avatar personajeUsuario;
    personajeUsuario.setPosicionFila(2);
    personajeUsuario.setPosicionColumna(2);

    LogicaDeMovimiento motorMovimientos;

    Juego partida(&tableroPrincipal, &personajeUsuario, &motorMovimientos, true);
    partida.iniciar();

    VistaConsola interfaz(&tableroPrincipal, &personajeUsuario);
    do {
        interfaz.mostrarJuego();
        interfaz.mostrarMensaje("Ingrese su movimiento (a/w/s/d):");
        partida.play(interfaz.getEntradaConsola());
    } while(partida.getWin() == false && partida.getEstado() == true);

    if (partida.getWin() == true) {
        interfaz.mostrarMensaje("¡Felicidades! Has completado el reto. Puntuación: " + std::to_string(partida.getPuntaje()));
    } else {
        interfaz.limpiarPantalla();
        interfaz.mostrarMensaje("Juego finalizado. No lograste completar el objetivo. Puntuación: 0");
    }
}

// Ejecuta el modo inteligente donde el avatar es controlado por IA
void juegoInteligente() {
    std::cout << "\n--- MODO INTELIGENTE (IA) ---\n";

    Tablero tableroIA;
    tableroIA.cargarDesdeArchivo("dataTablero.txt");

    AvatarInnovador personajeIA(&tableroIA);
    personajeIA.setPosicionFila(2);
    personajeIA.setPosicionColumna(2);

    LogicaDeMovimiento motorIA;

    Juego partidaIA(&tableroIA, &personajeIA, &motorIA, true);
    partidaIA.iniciar();

    VistaConsola interfazIA(&tableroIA, &personajeIA);

    do {
        interfazIA.mostrarJuego();
        interfazIA.mostrarMensaje("La IA está calculando su próximo movimiento...");

        char movimiento = personajeIA.decidirMovimiento();

        std::cout << "La IA elige: " << movimiento << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));

        partidaIA.play(movimiento);

    } while(partidaIA.getWin() == false && partidaIA.getEstado() == true);

    if (partidaIA.getWin() == true) {
        interfazIA.mostrarMensaje("¡La IA ha superado el desafío! Puntuación: " + std::to_string(partidaIA.getPuntaje()));
    } else {
        interfazIA.limpiarPantalla();
        interfazIA.mostrarMensaje("La IA no logró completar el reto. Puntuación: 0");
    }
}

// Ejecuta la demostración automática con la IA moviéndose sola
void demostracionAutomatica() {
    std::cout << "\n--- DEMOSTRACIÓN AUTOMÁTICA ---\n";

    Tablero tableroDemo;
    tableroDemo.cargarDesdeArchivo("dataTablero.txt");

    AvatarInnovador demoIA(&tableroDemo);
    demoIA.setPosicionFila(2);
    demoIA.setPosicionColumna(2);

    LogicaDeMovimiento motorDemo;

    Juego partidaDemo(&tableroDemo, &demoIA, &motorDemo, true);
    partidaDemo.iniciar();

    VistaConsola interfazDemo(&tableroDemo, &demoIA);

    int contadorMovimientos = 0;
    const int limiteMovimientos = 100;

    do {
        interfazDemo.mostrarJuego();
        std::cout << "Turno #" << (contadorMovimientos + 1) << " | Puntuación: " << partidaDemo.getPuntaje() << std::endl;

        char movimiento = demoIA.decidirMovimiento();

        std::cout << "La IA decide: " << movimiento << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        partidaDemo.play(movimiento);
        contadorMovimientos++;

    } while(partidaDemo.getWin() == false && partidaDemo.getEstado() == true && contadorMovimientos < limiteMovimientos);

    if (partidaDemo.getWin() == true) {
        interfazDemo.mostrarMensaje("¡Demostración completada exitosamente por la IA!");
        std::cout << "Puntuación final: " << partidaDemo.getPuntaje() << std::endl;
        std::cout << "Total de movimientos: " << contadorMovimientos << std::endl;
    } else if (contadorMovimientos >= limiteMovimientos) {
        interfazDemo.mostrarMensaje("Demostración detenida: se alcanzó el límite de movimientos.");
    } else {
        interfazDemo.limpiarPantalla();
        interfazDemo.mostrarMensaje("La IA no logró completar la demostración. Puntuación: 0");
    }
}

// Función principal que ejecuta el ciclo del menú y los modos de juego
int main() {
    int seleccionMenu;

    do {
        mostrarMenu();
        std::cin >> seleccionMenu;

        // Validación de la entrada del usuario
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Entrada no válida. Por favor, ingrese un número de opción.\n";
            continue;
        }

        switch(seleccionMenu) {
            case 1:
                juegoManual();
                break;
            case 2:
                juegoInteligente();
                break;
            case 3:
                demostracionAutomatica();
                break;
            case 4:
                std::cout << "Programa finalizado. ¡Hasta la próxima!\n";
                break;
            default:
                std::cout << "Opción fuera de rango. Intente nuevamente.\n";
        }

        if (seleccionMenu != 4) {
            std::cout << "\nPulse Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
        }

    } while(seleccionMenu != 4);

    return 0;
}