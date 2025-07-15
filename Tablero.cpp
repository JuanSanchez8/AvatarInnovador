#include "Tablero.h"
#include "Tablero.h"
/*
Archivo: Tablero.cpp
Clase: Tablero
Responsabilidad:
- Implementa los métodos para gestionar el tablero, cargarlo desde archivo y limpiar memoria.

Colaboradores:
- Camino, Abismo, Salida: Tipos de fichas que se instancian al cargar el tablero.
- Ficha: Clase base de las celdas.

Librerías utilizadas:
- <fstream>: Para manejo de archivos.
- <sstream>: Para procesar líneas del archivo.
- <stdexcept>: Para manejo de errores.

Punteros y referencias:
- Utiliza punteros a Ficha para crear y limpiar dinámicamente las celdas.
- Recibe referencias constantes para nombres de archivo.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#include "Camino.h"
#include "Abismo.h"
#include "Salida.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

Tablero::~Tablero() {
    limpiarTablero();
}

void Tablero::cargarDesdeArchivo(const std::string& archivo) {
    limpiarTablero();
    std::ifstream file(archivo);
    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo: " + archivo);
    }

    std::string linea;
    int fila = 0;
    while (std::getline(file, linea)) {
        std::vector<Ficha*> filaActual;
        std::istringstream stream(linea);
        char tipoFicha;
        int columna = 0;

        while (stream >> tipoFicha) {
            if (tipoFicha == '1') {
                filaActual.push_back(new Camino(fila, columna,'1'));
            } else if (tipoFicha == '0') {
                filaActual.push_back(new Abismo(fila, columna,'0'));
            } else if (tipoFicha == 'S') {
                filaActual.push_back(new Salida(fila, columna,'S'));
            } else {
                filaActual.push_back(nullptr); // Casilla vacía o no reconocida
            }
            columna++;
        }
        tablero.push_back(filaActual);
        fila++;
    }
}

Ficha* Tablero::getFicha(int fila, int columna) const {
    if (fila < 0 || fila >= static_cast<int>(tablero.size()) ||
        columna < 0 || columna >= static_cast<int>(tablero[fila].size())) {
        return nullptr; // Fuera de los límites
    }
    return tablero[fila][columna];
}


void Tablero::limpiarTablero() {
    // Iterate through the tablero to delete dynamically allocated Ficha objects
    for (auto& fila : tablero) {
        for (auto& ficha : fila) {
            delete ficha;
        }
        fila.clear(); // Clear each row
    }
    tablero.clear(); // Clear the tablero vector
}
int Tablero::getSize() const {
    return tablero.size();
}