
/*
Archivo: Ficha.cpp
Clase: Ficha
Responsabilidad:
- Implementa los métodos de la clase base para las fichas del tablero.

Colaboradores:
- Camino, Abismo, Salida: Clases derivadas.

Librerías utilizadas:
- Ninguna adicional (solo incluye Ficha.h).

Punteros y referencias:
- Utiliza herencia para compartir interfaz y comportamiento con las fichas derivadas.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#include "Ficha.h"

Ficha::Ficha(int fila, int columna, char tipo) : fila(fila), columna(columna), tipo(tipo){}

int Ficha::getFila() const {
    return fila;
}

int Ficha::getColumna() const {
    return columna;
}

char Ficha::getTipo() const {
    return tipo;
}