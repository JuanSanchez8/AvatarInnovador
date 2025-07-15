// Avatar.h
// Avatar.h
/*
Archivo: Avatar.h
Clase: Avatar
Responsabilidad:
- Representa al jugador controlado manualmente.
- Hereda de Personaje y maneja su posición y movimientos.

Colaboradores:
- Personaje: Clase base.
- Tablero, Juego, LogicaDeMovimiento, VistaConsola: Interactúa con estos componentes.

Librerías utilizadas:
- Ninguna adicional (solo incluye Personaje.h).

Punteros y referencias:
- Utiliza herencia para compartir interfaz y comportamiento con otros personajes.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#ifndef AVATAR_H
#define AVATAR_H

#include "Personaje.h"

class Avatar : public Personaje {
public:
    Avatar();
    using Personaje::setPosicionFila;
    using Personaje::setPosicionColumna;
};

#endif // AVATAR_H
