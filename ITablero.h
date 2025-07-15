// Guard corregido
#ifndef ITABLERO_H
/*
Archivo: ITablero.h
Clase: ITablero (Interfaz)
Responsabilidad:
- Define la interfaz para el tablero.

Colaboradores:
- Tablero: Implementa esta interfaz.

Librerías utilizadas:
- Ninguna adicional (solo incluye headers propios).

Punteros y referencias:
- Se utiliza para definir la interfaz del tablero.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#define ITABLERO_H

#include <string>
#include "Ficha.h"

class ITablero {
public:
    virtual ~ITablero() = default;

    // Cargar el tablero desde un archivo
    virtual void cargarDesdeArchivo(const std::string& archivo) = 0;

    // Obtener una ficha en una posición específica
    virtual Ficha* getFicha(int fila, int columna) const = 0;
    virtual int getSize() const =0;

};

#endif // ITABLERO_H
