
/*
Archivo: Personaje.cpp
Clase: Personaje
Responsabilidad:
- Implementa los métodos de la clase base para los personajes del juego.

Colaboradores:
- Avatar, AvatarInnovador: Clases derivadas.

Librerías utilizadas:
- Ninguna adicional (solo incluye Personaje.h).

Punteros y referencias:
- Utiliza herencia para compartir interfaz y comportamiento con los personajes derivados.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#include "Personaje.h"

Personaje::Personaje() : posicionFila(0), posicionColumna(0) {}

int Personaje::getPosicionFila() const {
    return posicionFila;
}

int Personaje::getPosicionColumna() const {
    return posicionColumna;
}

void Personaje::mover(char direccion) {
    // Implementación del movimiento (puedes agregar lógica)
}

void Personaje::setPosicionFila(int fila) {
    posicionFila = fila;

}

void Personaje::setPosicionColumna(int columna) {
    posicionColumna = columna;
}