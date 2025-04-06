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

        virtual void mostrar_cant_golpes_totales() = 0;

        virtual void mostrar_datos() = 0;

        virtual void modificar_hp(double daño) = 0;

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

        mago(string mago, double Hp, string arma, double daño_arma, int cant_usos, string habilidad_especial, double daño_especial, int cant_usos_especial, int magia, float dur_encantamiento);

        virtual void atacar(personaje& otro, bool normal);

        virtual void mostrar_tipo_personaje();

        virtual void mostrar_hp();

        virtual void mostrar_cant_golpes_totales();

        virtual void mostrar_datos();

        virtual void modificar_hp(double daño);
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

        guerrero(string guerrero, double hp, string golpe, double daño_golpe,int cant_golpes, string golpe_especial, double daño_golpe_especial, int cant_golpes_especial, float alt, float weight);

        virtual void atacar(personaje& otro, bool nomral);

        virtual void mostrar_tipo_personaje();

        virtual void mostrar_hp();

        void mostrar_cant_golpes_totales();

        virtual void mostrar_datos();

        virtual void modificar_hp(double daño);
};
