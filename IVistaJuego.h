// Guard corregido
#ifndef IVISTA_JUEGO_H
/*
Archivo: IVistaJuego.h
Clase: IVistaJuego (Interfaz)
Responsabilidad:
- Define la interfaz para la vista del juego.

Colaboradores:
- VistaConsola: Implementa esta interfaz.

Librerías utilizadas:
- <string>: Para manejo de mensajes y entrada.

Punteros y referencias:
- Se utiliza para definir la interfaz de la vista.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#define IVISTA_JUEGO_H

#include <string>

class IVistaJuego {
public:
    virtual ~IVistaJuego() = default;

    // Muestra el estado actual del tablero
    virtual void mostrarTablero() = 0;
     // Muestra el estado actual del tablero y el avatar
    virtual void mostrarJuego() = 0;
    virtual void limpiarPantalla()= 0;

    // Muestra un mensaje al usuario
    virtual void mostrarMensaje(const std::string& mensaje) = 0;

    // Lee una entrada del usuario
    virtual char getEntradaConsola() = 0;
};

#endif // IVISTA_JUEGO_H
