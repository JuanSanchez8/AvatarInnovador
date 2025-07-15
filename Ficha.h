// Guard corregido
#ifndef FICHA_H
/*
Archivo: Ficha.h
Clase: Ficha
Responsabilidad:
- Clase base para las fichas del tablero (camino, abismo, salida, etc.).
- Define la interfaz común para las celdas del tablero.

Colaboradores:
- Camino, Abismo, Salida: Clases derivadas.
- Tablero: Utiliza instancias de Ficha y sus derivadas.

Librerías utilizadas:
- Ninguna adicional (solo incluye headers propios).

Punteros y referencias:
- Utiliza herencia para compartir interfaz y comportamiento con las fichas derivadas.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#define FICHA_H

class Ficha {
protected:
    int fila;
    int columna;
    char tipo;

public:
    Ficha(int fila, int columna, char tipo);
    virtual ~Ficha() = default;

    // Getters
    int getFila() const;
    int getColumna() const;
    char getTipo() const;
};

#endif // FICHA_H