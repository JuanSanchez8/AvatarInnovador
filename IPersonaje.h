// IPersonaje.h
// Guard corregido
#ifndef IPERSONAJE_H
/*
Archivo: IPersonaje.h
Clase: IPersonaje (Interfaz)
Responsabilidad:
- Define la interfaz para personajes (Avatar, AvatarInnovador).

Colaboradores:
- Avatar, AvatarInnovador: Implementan esta interfaz.
- Juego: Utiliza instancias de IPersonaje.

Librerías utilizadas:
- Ninguna adicional (solo incluye headers propios).

Punteros y referencias:
- Se utiliza para definir la interfaz de los personajes.

Autores:
- Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
- Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
*/
#define IPERSONAJE_H

class IPersonaje {
public:
    virtual int getPosicionFila() const = 0;
    virtual int getPosicionColumna() const = 0;
    virtual void mover(char direccion) = 0;

    // Cambiar retorno de void a int para setPosicionFila y setPosicionColumna
    virtual void setPosicionFila(int fila) = 0;
    virtual void setPosicionColumna(int columna) = 0;

    virtual ~IPersonaje() = default;
};

#endif // IPERSONAJE_H
