
/*
Archivo: Camino.cpp
Clase: Camino
Responsabilidad:
- Implementa los métodos de la celda de camino transitable.

Colaboradores:
- Ficha: Clase base.

Librerías utilizadas:
- Ninguna adicional (solo incluye Camino.h).

Punteros y referencias:
- Utiliza herencia para compartir interfaz y comportamiento con otras fichas.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#include "Camino.h"

Camino::Camino(int fila, int columna, char tipo) : Ficha(fila, columna, tipo) {}