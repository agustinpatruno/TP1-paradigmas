CXX = g++
CXXFLAGS = -std=c++17 -Wall -I../ejercicio2/include

# Fuentes comunes
COMMON_SRC = ../ejercicio2/source/abs_combate.cpp \
			 ../ejercicio2/source/abs_guerrero.cpp \
			 ../ejercicio2/source/abs_items.cpp \
			 ../ejercicio2/source/abs_mago.cpp \
			 ../ejercicio2/source/interfaz_personajes.cpp \
			 ../ejercicio2/source/interfaz_armas.cpp


# Fuentes individuales
MAIN_SRC = main3.cpp
EJ3_SRC = ../ejercicio3/ejercicio3.cpp

# Todos los archivos fuente para compilar
ALL_SRC = $(COMMON_SRC) $(EJ3_SRC) $(MAIN_SRC)

# Nombre del ejecutable
EXECUTABLE = programa

# Regla principal
all: $(EXECUTABLE)

# Regla para compilar el programa
$(EXECUTABLE): $(ALL_SRC)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(ALL_SRC)

# Limpiar los ejecutables generados
clean:
	rm -f $(EXECUTABLE)

# Ayuda para uso del Makefile
help:
	@echo "Opciones disponibles:"
	@echo "  make        -> Compila todo el proyecto"
	@echo "  make clean  -> Limpia los ejecutables generados"