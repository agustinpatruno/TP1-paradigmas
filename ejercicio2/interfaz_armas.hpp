#include <iostream>
#include <string>
#include <memory>
using namespace std;

class arma
{
    public:

        virtual void mostrar_tipo_arma() = 0;

        virtual void mostrar_daño() = 0;

        virtual int mostrar_cantidad_de_usos() = 0;

        virtual void restar_usos() = 0;

        virtual void mostrar_golpes_disponibles() = 0;

        virtual void mostrar_rareza() = 0;

        virtual void mostrar_golpes_extra() = 0;
};

class items_magicos: public arma
{
    private:
        
        string tipo_arma;

        string nivel_rareza;

        double daño;

        int cantidad_golpes_disponibles;

        int golpes_extra;

    public:

        items_magicos(string tip_arma, string rareza, double daño_arma, int cant_golpes, int cant_golpes_extra);

        virtual void mostrar_tipo_arma();

        virtual void mostrar_daño();

        virtual int mostrar_cantidad_de_usos();

        virtual void restar_usos();

        void mostrar_golpes_disponibles();

        void mostrar_rareza();

        void mostrar_golpes_extra();
};

class armas_combate
{
    private:

        string tipo_arma;

        string nivel_rareza;

        double daño;

        int cantidad_golpes_disponibles;

        int golpes_extra;

    public:

        armas_combate(string tip_arma, string rareza, double daño_arma, int cant_golpes, int cant_golpes_extra);

        virtual void mostrar_tipo_arma();

        virtual void mostrar_daño();

        virtual int mostrar_cantidad_de_usos();

        virtual void restar_usos();

        void mostrar_golpes_disponibles();

        void mostrar_rareza();

        void mostrar_golpes_extra();
};