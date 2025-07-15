// Guard corregido
#ifndef LOGICA_DE_MOVIMIENTO_H
/*
Archivo: LogicaDeMovimiento.h
Clase: LogicaDeMovimiento
Responsabilidad:
- Implementa la lógica para validar y ejecutar movimientos de los avatares.

Colaboradores:
- IPersonaje: Para manipular el personaje a mover.

Librerías utilizadas:
- Ninguna adicional (solo incluye headers propios).

Punteros y referencias:
- Utiliza referencias a IPersonaje para modificar su posición.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#define LOGICA_DE_MOVIMIENTO_H

#include "IPersonaje.h"

class LogicaDeMovimiento {
public:
    // Método que mueve al personaje basado en la dirección dada
    void mover(IPersonaje &personaje, char direccion);
};

#endif // LOGICA_DE_MOVIMIENTO_H