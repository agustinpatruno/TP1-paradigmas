CXX = g++
CXXFLAGS = -std=c++17 -I../ejercicio2/include
SRC = ../ejercicio2/source/abs_combate.cpp \
      ../ejercicio2/source/abs_guerrero.cpp \
      ../ejercicio2/source/abs_items.cpp \
      ../ejercicio2/source/abs_mago.cpp \
      ../ejercicio2/source/interfaz_personajes.cpp \
      ../ejercicio2/source/interfaz_armas.cpp \
	ejercicio3,1.cpp
TARGET = programa

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

