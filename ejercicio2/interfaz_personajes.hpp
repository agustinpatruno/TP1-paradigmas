#include <iostream>
#include <string>
#include <memory>
#include "interfaz_armas.hpp"
using namespace std;

class personaje
{
    public:

        virtual void atacar(personaje& otro) = 0;

        virtual void mostrar_tipo_personaje() = 0;
        
        virtual void usar_habilidad_especial() = 0;

        virtual void mostrar_habilidad_especial() = 0;

        virtual void mostrar_hp() = 0;
};

class mago : public personaje
{
    private:

        string tipo_mago;

        string habilidad_especial;

        double daño_habilidad_especial;

        int cant_usos_hechizo_especial;

        double hp;

        shared_ptr<arma> tipo_arma;

    public:

        mago(string mago, double hp, string tipo_arma, double daño_arma, int cant_usos, string habilidad_especial, double daño_especial, int cant_usos_especial, string rareza, int golpes_extra);

        virtual void atacar(personaje& otro);

        virtual void mostrar_tipo_personaje();
        
        virtual void usar_habilidad_especial();

        virtual void mostrar_habilidad_especial();

        virtual void mostrar_hp();

        void mostrar_daño_hechizo_especial();

        void mostrar_cant_golpes_especial();
};

class guerrero
{
    private:

        string tipo_guerrero;

        string golpe_especial;

        double daño_golpe_especial;

        int cant_usos_golpe_especial;

        double hp;

        shared_ptr<arma> tipo_arma;

    public:

        guerrero(string guerrero, string golpe_especial, double daño_golpe_especial, int cant_golpes_especial, double hp, double daño_golpe);

        virtual void atacar(personaje& otro);

        virtual void mostrar_tipo_personaje();
        
        virtual void usar_habilidad_especial();

        virtual void mostrar_habilidad_especial();

        virtual void mostrar_hp();

        void mostrar_daño_golpe_especial();

        void mostrar_cant_golpes_especial();
};