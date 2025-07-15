
/*
Archivo: Abismo.cpp
Clase: Abismo
Responsabilidad:
- Implementa los métodos de la celda de tipo abismo.

Colaboradores:
- Ficha: Clase base.

Librerías utilizadas:
- Ninguna adicional (solo incluye Abismo.h).

Punteros y referencias:
- Utiliza herencia para compartir interfaz y comportamiento con otras fichas.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#include "Abismo.h"

Abismo::Abismo(int fila, int columna, char tipo) : Ficha(fila, columna, tipo) {}