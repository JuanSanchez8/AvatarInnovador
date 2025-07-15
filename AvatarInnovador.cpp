
/*
Archivo: AvatarInnovador.cpp
Clase: AvatarInnovador
Responsabilidad:
- Implementa la lógica de movimiento inteligente y toma de decisiones del avatar IA.

Colaboradores:
- ITablero: Para consultar el estado del tablero.
- Avatar: Clase base.

Librerías utilizadas:
- <iostream>, <algorithm>, <cstdlib>, <ctime>, <climits>, <queue>, <map>: Para lógica de IA y utilidades.

Punteros y referencias:
- Utiliza punteros a ITablero para acceder al tablero y planificar movimientos.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/

#include "AvatarInnovador.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <queue>
#include <map>

AvatarInnovador::AvatarInnovador(ITablero* tablero) 
    : Avatar(), tablero(tablero), movimientosConsecutivosSinProgreso(0), 
      posicionSalida({-1, -1}), salidaEncontrada(false) {
    std::srand(std::time(nullptr));
    // Buscar la salida al inicio
    encontrarSalida();
}

void AvatarInnovador::mover(char direccion) {
    // Guardar posición anterior
    std::pair<int, int> posicionAnterior = {getPosicionFila(), getPosicionColumna()};

    // Realizar el movimiento básico usando la lógica de movimiento
    int nuevaFila = getPosicionFila();
    int nuevaColumna = getPosicionColumna();

    // Ajustar posición según la dirección
    switch (direccion) {
        case 'W':
        case 'w':
            nuevaFila--;
            break;
        case 'S':
        case 's':
            nuevaFila++;
            break;
        case 'A':
        case 'a':
            nuevaColumna--;
            break;
        case 'D':
        case 'd':
            nuevaColumna++;
            break;
        default:
            return;
    }

    // Establecer la nueva posición
    setPosicionFila(nuevaFila);
    setPosicionColumna(nuevaColumna);

    // Obtener nueva posición
    std::pair<int, int> nuevaPosicion = {getPosicionFila(), getPosicionColumna()};

    // Verificar si hemos hecho progreso real
    if (yaVisitado(nuevaPosicion.first, nuevaPosicion.second)) {
        movimientosConsecutivosSinProgreso++;
    } else {
        movimientosConsecutivosSinProgreso = 0;
        posicionesVisitadas.insert(nuevaPosicion);
    }

    // Registrar posición anterior también para evitar ping-pong
    posicionesVisitadas.insert(posicionAnterior);
}

char AvatarInnovador::decidirMovimiento() {
    // Estrategia anti-bucle más agresiva
    if (movimientosConsecutivosSinProgreso > 5) {
        // Limpiar memoria de posiciones visitadas pero mantener conocimiento de la salida
        posicionesVisitadas.clear();
        movimientosConsecutivosSinProgreso = 0;
        return movimientoAleatorioInteligente();
    }

    // Estrategia 1: Si conocemos la salida y estamos cerca, usar pathfinding inteligente
    if (salidaEncontrada) {
        int distancia = distanciaHastaSalida(getPosicionFila(), getPosicionColumna());
        if (distancia <= 8) { // Aumentamos el rango de detección
            char movimiento = mejorMovimientoHaciaSalida();
            if (movimiento != '\0') {
                return movimiento;
            }
        }
    }

    // Estrategia 2: Priorizar exploración si hay demasiados movimientos repetitivos
    if (movimientosConsecutivosSinProgreso > 3) {
        return movimientoExploratorioMejorado();
    }

    // Estrategia 3: Movimiento hacia la salida si la conocemos
    if (salidaEncontrada) {
        char movimiento = movimientoHaciaSalida();
        if (movimiento != '\0') {
            return movimiento;
        }
    }

    // Estrategia 4: Movimiento por defecto evitando abismos
    return movimientoEvitandoAbismos();
}

bool AvatarInnovador::esPosicionValida(int fila, int columna) const {
    if (fila < 0 || fila >= tablero->getSize()) return false;
    if (columna < 0) return false;
    
    // Verificar directamente si la ficha existe
    Ficha* ficha = tablero->getFicha(fila, columna);
    return ficha != nullptr;
}

int AvatarInnovador::getNumeroColumnasEnFila(int fila) const {
    if (fila < 0 || fila >= tablero->getSize()) return 0;
    
    // Contar columnas válidas en esta fila
    int columnas = 0;
    for (int col = 0; col < 15; col++) { // Límite más conservador
        Ficha* ficha = tablero->getFicha(fila, col);
        if (ficha != nullptr) {
            columnas = col + 1;
        } else {
            break;
        }
    }
    return columnas;
}

bool AvatarInnovador::esAbismo(int fila, int columna) const {
    if (!esPosicionValida(fila, columna)) return true;
    Ficha* ficha = tablero->getFicha(fila, columna);
    return ficha != nullptr && ficha->getTipo() == '0';
}

bool AvatarInnovador::esSalida(int fila, int columna) const {
    if (!esPosicionValida(fila, columna)) return false;
    Ficha* ficha = tablero->getFicha(fila, columna);
    return ficha != nullptr && ficha->getTipo() == 'S';
}

bool AvatarInnovador::yaVisitado(int fila, int columna) const {
    return posicionesVisitadas.find({fila, columna}) != posicionesVisitadas.end();
}

int AvatarInnovador::distanciaHastaSalida(int fila, int columna) const {
    if (!salidaEncontrada) return INT_MAX;
    return abs(fila - posicionSalida.first) + abs(columna - posicionSalida.second);
}

std::pair<int, int> AvatarInnovador::encontrarSalida() {
    if (salidaEncontrada) return posicionSalida;
    
    for (int i = 0; i < tablero->getSize(); i++) {
        int numColumnas = getNumeroColumnasEnFila(i);
        for (int j = 0; j < numColumnas; j++) {
            if (esSalida(i, j)) {
                posicionSalida = {i, j};
                salidaEncontrada = true;
                return posicionSalida;
            }
        }
    }
    return {-1, -1};
}

char AvatarInnovador::mejorMovimientoHaciaSalida() {
    if (!salidaEncontrada) return '\0';
    
    int filaActual = getPosicionFila();
    int columnaActual = getPosicionColumna();
    
    // Direcciones: arriba, abajo, izquierda, derecha
    char direcciones[] = {'w', 's', 'a', 'd'};
    int deltaFilas[] = {-1, 1, 0, 0};
    int deltaColumnas[] = {0, 0, -1, 1};
    
    char mejorDireccion = '\0';
    int menorDistancia = INT_MAX;
    
    for (int i = 0; i < 4; i++) {
        int nuevaFila = filaActual + deltaFilas[i];
        int nuevaColumna = columnaActual + deltaColumnas[i];
        
        if (esPosicionValida(nuevaFila, nuevaColumna) && !esAbismo(nuevaFila, nuevaColumna)) {
            int distancia = distanciaHastaSalida(nuevaFila, nuevaColumna);
            
            // Bonificar posiciones no visitadas
            if (!yaVisitado(nuevaFila, nuevaColumna)) {
                distancia -= 2;
            }
            
            if (distancia < menorDistancia) {
                menorDistancia = distancia;
                mejorDireccion = direcciones[i];
            }
        }
    }
    
    return mejorDireccion;
}

char AvatarInnovador::movimientoHaciaSalida() const {
    return const_cast<AvatarInnovador*>(this)->mejorMovimientoHaciaSalida();
}

char AvatarInnovador::movimientoEvitandoAbismos() const {
    int filaActual = getPosicionFila();
    int columnaActual = getPosicionColumna();
    
    char direcciones[] = {'w', 's', 'a', 'd'};
    int deltaFilas[] = {-1, 1, 0, 0};
    int deltaColumnas[] = {0, 0, -1, 1};
    
    std::vector<char> movimientosValidos;
    std::vector<char> movimientosNoVisitados;
    
    for (int i = 0; i < 4; i++) {
        int nuevaFila = filaActual + deltaFilas[i];
        int nuevaColumna = columnaActual + deltaColumnas[i];
        
        if (esPosicionValida(nuevaFila, nuevaColumna) && !esAbismo(nuevaFila, nuevaColumna)) {
            movimientosValidos.push_back(direcciones[i]);
            
            if (!yaVisitado(nuevaFila, nuevaColumna)) {
                movimientosNoVisitados.push_back(direcciones[i]);
            }
        }
    }
    
    if (movimientosNoVisitados.empty()) {
        if (movimientosValidos.empty()) {
            return 'w'; // Movimiento por defecto
        }
        return movimientosValidos[rand() % movimientosValidos.size()];
    }
    
    return movimientosNoVisitados[rand() % movimientosNoVisitados.size()];
}

char AvatarInnovador::movimientoAleatorioInteligente() {
    // Reiniciar contador
    movimientosConsecutivosSinProgreso = 0;
    
    int filaActual = getPosicionFila();
    int columnaActual = getPosicionColumna();
    
    char direcciones[] = {'w', 's', 'a', 'd'};
    int deltaFilas[] = {-1, 1, 0, 0};
    int deltaColumnas[] = {0, 0, -1, 1};
    
    std::vector<std::pair<char, int>> opcionesConPrioridad;
    
    for (int i = 0; i < 4; i++) {
        int nuevaFila = filaActual + deltaFilas[i];
        int nuevaColumna = columnaActual + deltaColumnas[i];
        
        if (esPosicionValida(nuevaFila, nuevaColumna) && !esAbismo(nuevaFila, nuevaColumna)) {
            int prioridad = 0;
            
            // Mayor prioridad para posiciones no visitadas
            if (!yaVisitado(nuevaFila, nuevaColumna)) {
                prioridad += 10;
            }
            
            // Prioridad por cercanía a la salida si la conocemos
            if (salidaEncontrada) {
                int distanciaActual = distanciaHastaSalida(filaActual, columnaActual);
                int nuevaDistancia = distanciaHastaSalida(nuevaFila, nuevaColumna);
                if (nuevaDistancia < distanciaActual) {
                    prioridad += 5;
                }
            }
            
            opcionesConPrioridad.push_back({direcciones[i], prioridad});
        }
    }
    
    if (opcionesConPrioridad.empty()) {
        return movimientoEvitandoAbismos();
    }
    
    // Ordenar por prioridad descendente
    std::sort(opcionesConPrioridad.begin(), opcionesConPrioridad.end(),
              [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
                  return a.second > b.second;
              });
    
    // Elegir entre las 2 mejores opciones para mantener algo de aleatoriedad
    int opciones = std::min(2, (int)opcionesConPrioridad.size());
    return opcionesConPrioridad[rand() % opciones].first;
}

char AvatarInnovador::movimientoExploratorio() {
    return movimientoAleatorioInteligente();
}

char AvatarInnovador::movimientoExploratorioMejorado() {
    int filaActual = getPosicionFila();
    int columnaActual = getPosicionColumna();
    
    char direcciones[] = {'w', 's', 'a', 'd'};
    int deltaFilas[] = {-1, 1, 0, 0};
    int deltaColumnas[] = {0, 0, -1, 1};
    
    std::vector<std::pair<char, int>> opcionesConPuntuacion;
    
    for (int i = 0; i < 4; i++) {
        int nuevaFila = filaActual + deltaFilas[i];
        int nuevaColumna = columnaActual + deltaColumnas[i];
        
        if (esPosicionValida(nuevaFila, nuevaColumna) && !esAbismo(nuevaFila, nuevaColumna)) {
            int puntuacion = 0;
            
            // Máxima prioridad para posiciones nunca visitadas
            if (!yaVisitado(nuevaFila, nuevaColumna)) {
                puntuacion += 20;
            }
            
            // Prioridad por distancia hacia la salida (si la conocemos)
            if (salidaEncontrada) {
                int distanciaActual = distanciaHastaSalida(filaActual, columnaActual);
                int nuevaDistancia = distanciaHastaSalida(nuevaFila, nuevaColumna);
                if (nuevaDistancia < distanciaActual) {
                    puntuacion += 10;
                } else if (nuevaDistancia == distanciaActual) {
                    puntuacion += 5; // Mantener distancia es mejor que alejarse
                }
            }
            
            // Bonificar movimientos hacia los bordes del tablero (exploración)
            if (nuevaFila == 0 || nuevaFila == tablero->getSize()-1 || 
                nuevaColumna == 0 || nuevaColumna == getNumeroColumnasEnFila(nuevaFila)-1) {
                puntuacion += 3;
            }
            
            // Penalizar ligeramente las posiciones visitadas recientemente
            if (yaVisitado(nuevaFila, nuevaColumna)) {
                puntuacion -= 5;
            }
            
            opcionesConPuntuacion.push_back({direcciones[i], puntuacion});
        }
    }
    
    if (opcionesConPuntuacion.empty()) {
        return movimientoEvitandoAbismos();
    }
    
    // Ordenar por puntuación descendente
    std::sort(opcionesConPuntuacion.begin(), opcionesConPuntuacion.end(),
              [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
                  return a.second > b.second;
              });
    
    // Elegir la mejor opción o una de las 2 mejores para algo de variabilidad
    if (opcionesConPuntuacion[0].second > 15) {
        return opcionesConPuntuacion[0].first; // Opción claramente mejor
    } else {
        // Elegir entre las mejores opciones
        int mejoresOpciones = std::min(2, (int)opcionesConPuntuacion.size());
        return opcionesConPuntuacion[rand() % mejoresOpciones].first;
    }
}

void AvatarInnovador::reiniciarMemoria() {
    posicionesVisitadas.clear();
    movimientosConsecutivosSinProgreso = 0;
    salidaEncontrada = false;
    posicionSalida = {-1, -1};
    rutaHaciaSalida.clear();
    // Volver a buscar la salida
    encontrarSalida();
}
