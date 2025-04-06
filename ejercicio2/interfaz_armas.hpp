#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

////////////////clase interfaz arma /////////////////////////////////

class arma
{
    public:

        virtual void mostrar_tipo_arma() = 0;

        virtual void mostrar_daño() = 0;

        virtual void mostrar_golpes_disponibles() = 0;

        virtual void mostrar_habilidad() = 0;

        virtual void mostrar_golpes_dispo_especial() = 0;

        virtual double devolver_daño(bool normal) = 0;

        virtual void restar_usos(bool normal) = 0;
};

/////////////////////clase items magicos ///////////////////////////////////

class items_magicos: public arma
{
    private:
        
        string tipo_arma;

        double Daño;

        int cant_golpes_disponibles;

        string habilidad_especial;

        double daño_extra_especial;
        
        int cant_golpes_especial;

        virtual void restar_usos(bool normal);

    public:

        items_magicos(string tip_arma, double daño, int cant_golpes_dispo, string habilidad_espe, double daño_extra_espe, int cant_golpes_espe);

        virtual void mostrar_tipo_arma();

        virtual void mostrar_daño();

        virtual void mostrar_golpes_disponibles();

        virtual void mostrar_habilidad_especial();

        virtual void mostrar_golpes_dispo_especial();

        virtual double devolver_daño(bool normal);
};

////////////////////////////clase armas de combate //////////////////////////////

class armas_combate : public arma
{
    private:

        string tipo_arma;

        double Daño;

        int cant_golpes_disponibles;

        string habilidad_especial;

        double daño_extra_especial;
        
        int cant_golpes_especial;

        virtual void restar_usos(bool normal);

    public:

        armas_combate(string tip_arma, double daño, int cant_golpes_dispo, string habilidad_espe, double daño_extra_espe, int cant_golpes_espe);

        virtual void mostrar_tipo_arma() = 0;

        virtual void mostrar_daño() = 0;

        virtual void mostrar_golpes_disponibles() = 0;

        virtual void mostrar_habilidad() = 0;

        virtual void mostrar_golpes_dispo_especial() = 0;

        virtual double devolver_daño(bool normal);
};

bool pertenece_en_magicos(string tipo_arma);

bool pertenece_en_combate(string tipo_arma);

bool pertenece_habilidad_espe_magico(string habilidad_especial);

bool pertenece_habilidad_espe_combate(string habilidad_combate);