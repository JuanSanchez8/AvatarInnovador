// Guard corregido
#ifndef IJUEGOLOGICA_H
/*
Archivo: IJuegoLogica.h
Clase: IJuegoLogica (Interfaz)
Responsabilidad:
- Define la interfaz para la lógica del juego.

Colaboradores:
- Juego: Implementa esta interfaz.

Librerías utilizadas:
- Ninguna adicional (solo incluye headers propios).

Punteros y referencias:
- Se utiliza para definir la interfaz de la lógica del juego.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#define IJUEGOLOGICA_H

class IJuegoLogica {
public:
    virtual ~IJuegoLogica() = default;
    virtual void moverAvatar(char direccion) = 0;
    virtual void iniciar() = 0;
    virtual void puntuar()=0;
    virtual int getPuntaje()=0;
    virtual void play(char movimiento) =0;
};

#endif // IJUEGOLOGICA_H
