#include <iostream>
#include <string>
#include <memory>
#include "interfaz_armas.hpp"
using namespace std;

///////////// interfaz de pesonaje ////////////////

class personaje
{
    public:

        virtual void atacar(personaje& otro, bool normal) = 0;

        virtual void mostrar_tipo_personaje() = 0;

        virtual void mostrar_hp() = 0;

        virtual void mostrar_cant_golpes_especial() = 0;

        virtual void mostrar_cant_golpes_especial() = 0;

        virtual void mostrar_datos() = 0;
};

///////////// clase mago ////////////////

class mago : public personaje
{
    private:

        string tipo_mago;

        int poder_magia; // 1 <= poder_magia <= 10

        float duracion_encantamientos; //cantidad de segundos que dura un hechizo

        double hp;

        shared_ptr<arma> tipo_arma;

    public:

        mago(string mago, double hp, int magia, float duracion_encant, string tip_arma, double daño, int golpes, string habilidad_especial, double daño_especial, int golpes_especial);

        virtual void atacar(personaje& otro, bool normal);

        virtual void mostrar_tipo_personaje();

        virtual void mostrar_hp();

        virtual void mostrar_cant_golpes_especial();

        virtual void mostrar_datos();
};

////////////////// clase guerrero /////////////////////

class guerrero
{
    private:

        string tipo_guerrero;

        float altura; // altua del guerrero Mts

        float peso; // peso del guerrero en Kg

        double hp;

        shared_ptr<arma> tipo_arma;

    public:

        guerrero(string guerrero, string golpe_especial, double daño_golpe_especial, int cant_golpes_especial, double hp, double daño_golpe);

        virtual void atacar(personaje& otro, bool nomral);

        virtual void mostrar_tipo_personaje();

        virtual void mostrar_hp();

        void mostrar_cant_golpes_especial();

        virtual void mostrar_datos();
};
