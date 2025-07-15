// Guard corregido
#ifndef TABLERO_H
/*
Archivo: Tablero.h
Clase: Tablero
Responsabilidad:
- Representa el tablero del juego, gestiona las celdas y su estado.
- Permite cargar el tablero desde un archivo y acceder a las fichas.

Colaboradores:
- Ficha, Camino, Abismo, Salida: Elementos que conforman el tablero.
- ITablero: Interfaz base.

Librerías utilizadas:
- <vector>: Para almacenar la matriz de fichas.
- <string>: Para manejo de nombres de archivos y cadenas.

Punteros y referencias:
- Utiliza punteros a Ficha para representar cada celda del tablero.
- Métodos reciben referencias constantes para eficiencia.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#define TABLERO_H

#include <vector>
#include <string>
#include "ITablero.h"

class Tablero : public ITablero {
private:
    std::vector<std::vector<Ficha*>> tablero;

    // Add limpiarTablero declaration
    void limpiarTablero();
public:
    void cargarDesdeArchivo(const std::string& archivo) override;
    Ficha* getFicha(int fila, int columna) const override;
    int getSize()const override;
    ~Tablero();
};

#endif