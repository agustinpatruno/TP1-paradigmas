CXX = g++
CXXFLAGS = -std=c++17 -Wall -I../ejercicio2/include

# Fuentes comunes
COMMON_SRC = ../ejercicio2/source/abs_combate.cpp \
			 ../ejercicio2/source/abs_guerrero.cpp \
			 ../ejercicio2/source/abs_items.cpp \
			 ../ejercicio2/source/abs_mago.cpp \
			 ../ejercicio2/source/interfaz_personajes.cpp \
			 ../ejercicio2/source/interfaz_armas.cpp

# Archivos individuales
PT1_SRC = $(COMMON_SRC) ejercicio3,1.cpp
PT2_SRC = $(COMMON_SRC) ejercicio3.cpp

# Ejecutables
PT1_EXE = programa_pt1
PT2_EXE = programa_pt2

# Regla principal: no hace nada en esta configuración
all: help

# Compilación de pt1
pt1: $(PT1_SRC)
	$(CXX) $(CXXFLAGS) -o $(PT1_EXE) $(PT1_SRC)

# Compilación de pt2
pt2: $(PT2_SRC)
	$(CXX) $(CXXFLAGS) -o $(PT2_EXE) $(PT2_SRC)

# Limpiar los ejecutables
clean:
	rm -f $(PT1_EXE) $(PT2_EXE)

# Ayuda para uso del Makefile
help:
	@echo "Opciones disponibles:"
	@echo "  make pt1  -> Compila el ejercicio3,1.cpp con los archivos comunes"
	@echo "  make pt2  -> Compila el ejercicio3,2.cpp con los archivos comunes"
	@echo "  make clean -> Limpia los ejecutables generados"
