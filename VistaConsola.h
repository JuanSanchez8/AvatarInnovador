// Guard corregido
#ifndef VISTA_CONSOLA_H
/*
Archivo: VistaConsola.h
Clase: VistaConsola
Responsabilidad:
- Muestra el estado del juego en consola y gestiona la entrada/salida del usuario.
- Implementa la interfaz IVistaJuego.

Colaboradores:
- Tablero, Avatar, AvatarInnovador: Para mostrar el estado del juego.
- IVistaJuego: Interfaz base.

Librerías utilizadas:
- <iostream>: Para mostrar mensajes en consola.
- <string>: Para manejo de mensajes y entrada.

Punteros y referencias:
- Utiliza referencias a Tablero y Avatar/AvatarInnovador para mostrar el estado.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#define VISTA_CONSOLA_H

#include "IVistaJuego.h"
#include "Tablero.h"
#include "Avatar.h"
#include <vector>
#include <string>

// Implementación concreta de IVistaJuego
class VistaConsola : public IVistaJuego {
private:
    ITablero* tablero;          // Puntero al tablero
    IPersonaje* avatar;         // Puntero al personaje
public:
    // Constructor y destructor
    VistaConsola(ITablero* tablero, IPersonaje* avatar);
    ~VistaConsola() override = default;

    // Métodos que implementan IVistaJuego
    void mostrarTablero() override;
    void mostrarJuego() override;
    void limpiarPantalla() override;
    void mostrarMensaje(const std::string& mensaje) override;
    char getEntradaConsola() override;
};

#endif // VISTA_CONSOLA_H
