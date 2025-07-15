// Guard corregido
#ifndef ABISMO_H
/*
Archivo: Abismo.h
Clase: Abismo
Responsabilidad:
- Representa una celda de tipo abismo en el tablero.
- Hereda de Ficha.

Colaboradores:
- Ficha: Clase base.
- Tablero: Utiliza instancias de Abismo.

Librerías utilizadas:
- Ninguna adicional (solo incluye headers propios).

Punteros y referencias:
- Utiliza herencia para compartir interfaz y comportamiento con otras fichas.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#define ABISMO_H

#include "Ficha.h"

class Abismo : public Ficha {
public:
    Abismo(int fila, int columna, char tipo);
};

#endif // ABISMO_H