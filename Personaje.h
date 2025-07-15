// Guard corregido
#ifndef PERSONAJE_H
/*
Archivo: Personaje.h
Clase: Personaje
Responsabilidad:
- Clase base para los personajes del juego.
- Define la interfaz común para los personajes (Avatar, AvatarInnovador).

Colaboradores:
- Avatar, AvatarInnovador: Clases derivadas.
- Juego: Utiliza instancias de Personaje y sus derivadas.

Librerías utilizadas:
- Ninguna adicional (solo incluye headers propios).

Punteros y referencias:
- Utiliza herencia para compartir interfaz y comportamiento con los personajes derivados.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#define PERSONAJE_H

#include "IPersonaje.h"

class Personaje : public IPersonaje {
protected:
    int posicionFila;
    int posicionColumna;

public:
    Personaje();
    virtual ~Personaje() = default;

    // Métodos de la interfaz IPersonaje
    virtual int getPosicionFila() const override;
    virtual int getPosicionColumna() const override;
    virtual void mover(char direccion) override;
    virtual void setPosicionFila(int fila) override;
    virtual void setPosicionColumna(int columna) override;
};

#endif // PERSONAJE_H