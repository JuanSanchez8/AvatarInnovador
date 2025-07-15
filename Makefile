#############################################################
# Archivo: Makefile
# Responsabilidad:
# - Define las reglas de compilación y enlazado del proyecto.
#
# Colaboradores:
# - Archivos fuente (.cpp) y cabeceras (.h) del proyecto.
#
# Herramientas utilizadas:
# - gcc/g++: Compilador de C++.
#
# Autores:
# - Alejandro Cardona Arellano (alejandro.arellano@correounivalle.edu.co)
# - Juan Marmolejo (juan.fernando.marmolejo@correounivalle.edu.co)
#############################################################

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Archivos fuente
SOURCES = main.cpp \
          Ficha.cpp \
          Camino.cpp \
          Abismo.cpp \
          Salida.cpp \
          Personaje.cpp \
          Avatar.cpp \
          AvatarInnovador.cpp \
          Tablero.cpp \
          LogicaDeMovimiento.cpp \
          VistaConsola.cpp \
          Juego.cpp

# Archivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Ejecutable
TARGET = main

# Regla principal
all: $(TARGET)

$(TARGET): $(OBJECTS)
    $(CXX) $(OBJECTS) -o $(TARGET)

# Regla para compilar archivos .cpp a .o
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
    rm -f $(OBJECTS) $(TARGET)

# Regla para ejecutar el programa
run: $(TARGET)
    ./$(TARGET)

.PHONY: all clean run
