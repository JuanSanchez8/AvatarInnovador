#include "Juego.h"
/*
Archivo: Juego.cpp
Clase: Juego
Responsabilidad:
- Implementa la lógica principal del juego, gestiona el estado, puntaje y reglas.
- Coordina la interacción entre el tablero, el avatar y la lógica de movimiento.

Colaboradores:
- ITablero: Para acceder al tablero.
- IPersonaje: Para manipular el avatar.
- LogicaDeMovimiento: Para validar y ejecutar movimientos.
- Ficha: Para determinar el tipo de celda donde está el avatar.

Librerías utilizadas:
- <iostream>: Para mostrar mensajes en consola.

Punteros y referencias:
- Utiliza punteros a ITablero, IPersonaje y LogicaDeMovimiento para compartir el estado entre objetos.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#include "Juego.h"
#include <iostream>

Juego::Juego(ITablero* tablero, IPersonaje* avatar, LogicaDeMovimiento* logicaDeMovimiento, bool estado=true)
    : tablero(tablero), avatar(avatar), logicaDeMovimiento(logicaDeMovimiento), estado(estado) {}

Juego::~Juego() {
}

void Juego::moverAvatar(char direccion) {
    logicaDeMovimiento->mover(*avatar, direccion);
    Ficha* ficha = tablero->getFicha(avatar->getPosicionFila(),avatar->getPosicionColumna());
    
    if (ficha == nullptr) {
        estado = false; // Fuera de límites
        return;
    }
    
    if(ficha->getTipo()=='1') estado=true;
    else if (ficha->getTipo()=='0') estado=false;
    else std::cout<<"win"<<std::endl;
}

void Juego::iniciar() {
    std::cout << "El juego ha comenzado." << std::endl;
    puntaje=100;
}

bool Juego::getEstado(){
    return estado;
}
bool Juego::getWin(){
     Ficha* ficha = tablero->getFicha(avatar->getPosicionFila(),avatar->getPosicionColumna());
     if (ficha == nullptr) return false;
     if(ficha->getTipo()=='S') return true;
     else return false;
}
void Juego::puntuar(){
     puntaje=puntaje-2;
}
int Juego::getPuntaje(){
    return puntaje;
}
void Juego::play(char movimiento){


            this->moverAvatar(movimiento);
            puntuar();

}