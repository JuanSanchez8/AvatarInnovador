// Guard corregido
#ifndef CAMINO_H
/*
Archivo: Camino.h
Clase: Camino
Responsabilidad:
- Representa una celda de camino transitable en el tablero.
- Hereda de Ficha.

Colaboradores:
- Ficha: Clase base.
- Tablero: Utiliza instancias de Camino.

Librerías utilizadas:
- Ninguna adicional (solo incluye headers propios).

Punteros y referencias:
- Utiliza herencia para compartir interfaz y comportamiento con otras fichas.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#define CAMINO_H

#include "Ficha.h"

class Camino : public Ficha {
public:
    Camino(int fila, int columna, char tipo);
};

#endif // CAMINO_H