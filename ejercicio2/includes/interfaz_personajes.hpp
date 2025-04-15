#pragma once
#include "abs_combate.hpp"
#include "abs_items.hpp"
using namespace std;

// enum de los magos //

enum tipos_magos {a_hechicero = 1, a_conjurador, a_brujo, a_nigromante};

// enum de los guerreros // 

enum tipos_guerreros {a_barbaro = 1, a_paladin, a_caballero, a_mercenario, a_gladiador};

// enum de las habilidades totales([0:4] = habilidades magicas, [5:9] = habilidades de combate) //

enum hab_totales {Explosion_arcana = 0, Golpe_elemental, Corte_espectral, Encantamiento_explosivo, Rafaga_magica, Impacto_devastador, Corte_giratorio, Golpe_perforante, Ataque_ensordecedor, Ruptura_elemental};

/* valores de los daños extra de las habilidades especiales magicas y las de combate([1:5] = daño magicas, [6:10] = daño de combate) */

extern vector<double> daño_hab_magicos_combate;

/* cant de usos de las habilidades especiales magicas y de combate ([1:5] = usos magicas, [6:10] = usos de combate)*/

extern vector<int> usos_hab_magicas_combate;

/*retorna un string del valor en base al enum tipos_magos que se le pase por parametro*/
string getTipoMago(tipos_magos tipo);

/*retorna un string del valor en base al enum tipos_guerreros que se le pase por parametro*/
string getTipoGuerrero(tipos_guerreros tipo);

/*retorna un string del valor en base al enum hab_especiales_magicas que se le pase por parametro, caso de no ser ninguna, 
retorna habildad desconocida*/
string getHabilidad(hab_totales habilidad);

/*retorna true si la habilidad pertenece a las habilidades magicas, caso contrario, retorna false*/
bool pertenece_hab_magicas(hab_totales habilidad);

/*retorna un puntero unique_ptr a un arma  en base a los parametros del tipo de arma, dato1, dato2, dato3 y el daño*/
unique_ptr<arma> crear_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3, double daño);

///////////////////////////////////// interfaz de pesonaje /////////////////////////////////////

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
        /*
            crea un arma y la agrega al personaje, en caso de que no se pueda agregar, arroja un throw y lo
            captura con un catch diciendo que no hay lugar disponible o por algun otro motivo posible
        */

        virtual void info_arma()const = 0;
        /*
            imprime por consola la informacion del arma
        */

        virtual int contar_armas() const = 0;
        /*
            cuenta la cantidad de armas que hay
        */

        virtual double daño(bool normal) = 0;
        /*
            retorna el ataque del arma, en caso de que normal = true, en caso de que se false, retorna el daño
            mas el daño de la habilidad. esto ocurre siempre y cuando tenga golpes disponibles en el arma o en la habilidad especial
        */

        virtual ~personaje() = default;
        /*
            destructor virtual por default
        */
};
