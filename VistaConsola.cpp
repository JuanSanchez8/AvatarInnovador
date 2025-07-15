
/*
Archivo: VistaConsola.cpp
Clase: VistaConsola
Responsabilidad:
- Implementa la visualización del estado del juego en la consola y gestiona la interacción con el usuario.

Colaboradores:
- Tablero, Avatar, AvatarInnovador: Proveen la información para mostrar el tablero y el estado del personaje.
- IVistaJuego: Interfaz base para la vista.

Librerías utilizadas:
- <iostream>: Para mostrar información y leer datos desde la consola.
- <string>: Para manipulación de mensajes y entrada de usuario.

Punteros y referencias:
- Utiliza referencias a Tablero y Avatar/AvatarInnovador para acceder y mostrar el estado actual.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#include "VistaConsola.h"
#include "Camino.h"
#include "Abismo.h"
#include "Salida.h"
#include <iostream>
#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

// Constructor que inicializa la vista con el tablero y el personaje
VistaConsola::VistaConsola(ITablero* tablero, IPersonaje* personaje):tablero(tablero), avatar(personaje){}

// Muestra el tablero con los tipos de ficha en cada celda
void VistaConsola::mostrarTablero() {
    limpiarPantalla();
    std::cout << "Fila/Col\t";
    for(int col=0; col<tablero->getSize(); col++) std::cout << col << "\t";
    std::cout << "\n";

    for(int fila=0; fila<tablero->getSize(); fila++){
        std::cout << fila << "\t\t";
        int numColumnas = 0;
        for(int k = 0; k < 20; k++) {
            if(tablero->getFicha(fila, k) != nullptr) {
                numColumnas = k + 1;
            } else {
                break;
            }
        }
        for(int col=0; col<numColumnas; col++){ 
            Ficha* fichaActual = tablero->getFicha(fila, col);
            if(fichaActual != nullptr) {
                std::cout << fichaActual->getTipo() << "\t";
            } else {
                std::cout << "-\t";
            }
        }
        std::cout << "\n";
    }
}
// Limpia la pantalla de la consola según el sistema operativo
void VistaConsola::limpiarPantalla(){
#ifdef _WIN32
    (void)system("cls"); // Windows
#else
    (void)system("clear"); // Linux/macOS
#endif
}

// Muestra el tablero con la posición del personaje y los tipos de ficha, sin caracteres especiales
void VistaConsola::mostrarJuego(){
    limpiarPantalla();
    for(int fila=0; fila<tablero->getSize(); fila++){
        int numColumnas = 0;
        for(int k = 0; k < 20; k++) {
            if(tablero->getFicha(fila, k) != nullptr) {
                numColumnas = k + 1;
            } else {
                break;
            }
        }
        for(int col=0; col<numColumnas; col++){ 
            if(avatar->getPosicionFila()==fila && avatar->getPosicionColumna()==col) {
                std::cout << "[A]" << "\t"; // Marca la posición del avatar
            }
            else {
                Ficha* fichaActual = tablero->getFicha(fila, col);
                if(fichaActual != nullptr) {
                    if(fichaActual->getTipo()=='1') {
                        std::cout << "C" << "\t"; // Camino
                    }
                    else if(fichaActual->getTipo()=='0') {
                        std::cout << "X" << "\t"; // Abismo
                    }
                    else {
                        std::cout << "S" << "\t"; // Salida
                    }
                } else {
                    std::cout << "-\t"; // Celda vacía
                }
            }
        }
        std::cout << "\n";
    }
}


// Muestra un mensaje en la consola
void VistaConsola::mostrarMensaje(const std::string& mensaje) {
    std::cout << "[Mensaje]: " << mensaje << std::endl;
}

// Solicita al usuario un movimiento y lo retorna
char VistaConsola::getEntradaConsola() {
    char opcionMovimiento;
    std::cout << "Seleccione dirección (a: izquierda, w: arriba, s: abajo, d: derecha): ";
    std::cin >> opcionMovimiento;
    return opcionMovimiento;
}