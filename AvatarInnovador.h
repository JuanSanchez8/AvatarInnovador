// Guard corregido
#ifndef AVATAR_INNOVADOR_H
/*
Archivo: AvatarInnovador.h
Clase: AvatarInnovador
Responsabilidad:
- Representa un avatar controlado por IA, decide movimientos inteligentes automáticamente.
- Hereda de Avatar y añade lógica de decisión inteligente.

Colaboradores:
- Avatar: Clase base.
- ITablero: Para consultar el estado del tablero.
- Tablero, Juego, LogicaDeMovimiento, VistaConsola: Interactúa con estos componentes.

Librerías utilizadas:
- <vector>, <set>, <utility>: Para almacenar rutas, posiciones y lógica de IA.

Punteros y referencias:
- Utiliza punteros a ITablero para acceder al tablero y planificar movimientos.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#define AVATAR_INNOVADOR_H

#include "Avatar.h"
#include "ITablero.h"
#include <vector>
#include <set>
#include <utility>

class AvatarInnovador : public Avatar {
private:
    ITablero* tablero;  // Referencia al tablero para tomar decisiones inteligentes
    std::set<std::pair<int, int>> posicionesVisitadas; // Memoria de posiciones visitadas
    int movimientosConsecutivosSinProgreso; // Contador para detectar bucles
    std::pair<int, int> posicionSalida; // Cache de la posición de salida
    bool salidaEncontrada; // Flag para saber si ya encontramos la salida
    std::vector<std::pair<int, int>> rutaHaciaSalida; // Ruta planificada hacia la salida

    // Métodos auxiliares para el movimiento inteligente
    bool esPosicionValida(int fila, int columna) const;
    bool esAbismo(int fila, int columna) const;
    bool esSalida(int fila, int columna) const;
    bool yaVisitado(int fila, int columna) const;
    int getNumeroColumnasEnFila(int fila) const;

    // Calcula la distancia Manhattan hasta la salida
    int distanciaHastaSalida(int fila, int columna) const;

    // Encuentra la posición de la salida en el tablero
    std::pair<int, int> encontrarSalida();
    
    // Planificación de ruta usando A*
    std::vector<std::pair<int, int>> planificarRuta(int filaInicio, int columnaInicio, int filaDestino, int columnaDestino);
    
    // Mejores heurísticas
    char mejorMovimientoHaciaSalida();
    char movimientoAleatorioInteligente();
    char movimientoExploratorioMejorado();

    // Estrategias de movimiento
    char movimientoHaciaSalida() const;
    char movimientoEvitandoAbismos() const;
    char movimientoExploratorio();

public:
    AvatarInnovador(ITablero* tablero);

    // Sobrescribe el método mover con lógica inteligente
    void mover(char direccion) override;

    // Método especial para movimiento autónomo inteligente
    char decidirMovimiento();

    // Reinicia la memoria del avatar
    void reiniciarMemoria();
};

#endif // AVATAR_INNOVADOR_H