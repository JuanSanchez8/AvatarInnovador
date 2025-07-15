
/*
Archivo: LogicaDeMovimiento.cpp
Clase: LogicaDeMovimiento
Responsabilidad:
- Implementa la lógica para validar y ejecutar movimientos de los avatares.

Colaboradores:
- IPersonaje: Para manipular el personaje a mover.

Librerías utilizadas:
- <iostream>: Para mostrar mensajes en consola.

Punteros y referencias:
- Utiliza referencias a IPersonaje para modificar su posición.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/

#include "LogicaDeMovimiento.h"
#include <iostream>

void LogicaDeMovimiento::mover(IPersonaje &personaje, char direccion) {
    int nuevaFila = personaje.getPosicionFila();
    int nuevaColumna = personaje.getPosicionColumna();

    // Ajustar posición según la dirección
    switch (direccion) {
        case 'W': // Mover hacia arriba
        case 'w':
            nuevaFila--;
            break;
        case 'S': // Mover hacia abajo
        case 's':
            nuevaFila++;
            break;
        case 'A': // Mover hacia la izquierda
        case 'a':
            nuevaColumna--;
            break;
        case 'D': // Mover hacia la derecha
        case 'd':
            nuevaColumna++;
            break;
        default:
            // Dirección no válida
            return;
    }

    // Establecer la nueva posición del personaje
    personaje.setPosicionFila(nuevaFila);
    personaje.setPosicionColumna(nuevaColumna);
}
