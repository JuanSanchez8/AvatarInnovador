// Guard corregido
#ifndef SALIDA_H
/*
Archivo: Salida.h
Clase: Salida
Responsabilidad:
- Representa la celda de salida en el tablero, objetivo del juego.
- Hereda de Ficha.

Colaboradores:
- Ficha: Clase base.
- Tablero: Utiliza instancias de Salida.

Librerías utilizadas:
- Ninguna adicional (solo incluye headers propios).

Punteros y referencias:
- Utiliza herencia para compartir interfaz y comportamiento con otras fichas.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#define SALIDA_H

#include "Ficha.h"

class Salida : public Ficha {
public:
    Salida(int fila, int columna, char tipo);
};

#endif // SALIDA_H
