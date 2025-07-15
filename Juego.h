// Guard corregido
#ifndef JUEGO_H
/*
Archivo: Juego.h
Clase: Juego
Responsabilidad:
- Controla la lógica principal del juego, gestiona el estado, puntaje y reglas.
- Coordina la interacción entre el tablero, el avatar y la lógica de movimiento.

Colaboradores:
- ITablero: Para acceder al tablero.
- IPersonaje: Para manipular el avatar.
- LogicaDeMovimiento: Para validar y ejecutar movimientos.

Librerías utilizadas:
- Ninguna adicional (solo incluye headers propios).

Punteros y referencias:
- Utiliza punteros a ITablero, IPersonaje y LogicaDeMovimiento para compartir el estado entre objetos.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#define JUEGO_H

#include "IJuegoLogica.h"
#include "ITablero.h"
#include "IPersonaje.h"
#include "LogicaDeMovimiento.h"

class Juego : public IJuegoLogica {
protected:
    ITablero* tablero;          // Puntero al tablero
    IPersonaje* avatar;         // Puntero al personaje
    LogicaDeMovimiento* logicaDeMovimiento; // Conocimiento de la lógica de movimiento
    bool estado;
    int puntaje;

public:
    Juego(ITablero* tablero, IPersonaje* avatar, LogicaDeMovimiento* logicaDeMovimiento, bool estado);
    ~Juego();

    void moverAvatar(char direccion) override;
    void iniciar() override;
    bool getEstado();
    bool getWin();
    void puntuar() override;
    int getPuntaje() override;
    void play(char moviemiento) override;
};

#endif // JUEGO_H