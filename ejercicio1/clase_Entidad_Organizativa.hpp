#include <string>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Entidad_Organizativa
{
    private:

        string nombre;

        vector<unique_ptr<Entidad_Organizativa>> entidades;

    public:

        Entidad_Organizativa(string nombre_entidad)
        {
            nombre = nombre_entidad;
        }

        string getNombre()
        {
            return nombre;
        }

        void agregarSubentidad(Entidad_Organizativa* nueva_entidad);

        ~Entidad_Organizativa();
};

Entidad_Organizativa::Entidad_Organizativa(/* args */)
{
}

Entidad_Organizativa::~Entidad_Organizativa()
{
}
