#pragma once
#include "abs_combate.hpp"
#include "abs_items.hpp"
using namespace std;

// enum de los magos //

enum tipos_magos {a_hechicero = 1, a_conjurador, a_brujo, a_nigromante};

// enum de los guerreros // 

enum tipos_guerreros {a_barbaro = 1, a_paladin, a_caballero, a_mercenario, a_gladiador};

// enum de las habilidades totales([1:5] = habilidades magicas, [6:10] = habilidades de combate) //

enum hab_totales {Explosion_arcana = 1, Golpe_elemental, Corte_espectral, Encantamiento_explosivo, Rafaga_magica, Impacto_devastador, Corte_giratorio, Golpe_perforante, Ataque_ensordecedor, Ruptura_elemental};

/* valores de los daños extra de las habilidades especiales magicas y las de combate([1:5] = daño magicas, [6:10] = daño de combate) */

extern vector<double> daño_hab_magicos_combate;

/* cant de usos de las habilidades especiales magicas y de combate ([1:5] = usos magicas, [6:10] = usos de combate)*/

extern vector<int> usos_hab_magicas_combate;

/*funcion que retorna un string del valor en base al enum tipos_magos que se le pase por parametro*/

string getTipoMago(tipos_magos tipo);

/*funcion que retorna un string del valor en base al enum tipos_guerreros que se le pase por parametro*/

string getTipoGuerrero(tipos_guerreros tipo);

/*funcion que retorna un string del valor en base al enum hab_especiales_magicas que se le pase por parametro*/

string getHabilidad(hab_totales habilidad);

bool pertenece_hab_magicas(hab_totales habilidad);

unique_ptr<arma> crear_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3, double daño);

///////////// interfaz de pesonaje ////////////////

class personaje
{
    public:

        virtual void mostrar_info_personaje() const = 0;
        /*
            muestra por consola el tipo de personaje, y todos sus atributos adicionales de informacion
        */

        virtual void mostrar_hp() const= 0;
        /*
            muestra por consola el hp del personaje
        */

        virtual double retornar_hp() const = 0;
        /*
            retorna el hp del personaje
        */

        virtual void modificar_hp(double daño) = 0;
        /*
            modifica el hp del personaje, restandole el daño
        */

        virtual void agregar_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3) = 0;

        virtual int contar_armas() = 0;

        virtual ~personaje() = default;
};
