#pragma once
#include <cstdlib>
#include <ctime>
#include "../ejercicio2/includes/abs_combate.hpp"
#include "../ejercicio2/includes/abs_guerrero.hpp"
#include "../ejercicio2/includes/abs_items.hpp"
#include "../ejercicio2/includes/abs_mago.hpp"
#include "../ejercicio2/includes/interfaz_personajes.hpp"
#include "../ejercicio2/includes/interfaz_armas.hpp"
using namespace std;

// enum de los personajes totales (tienen el numero 3 para diferenciarlos del otro enum definido en el hpp de personajes)//

enum personajes_totales {hechicero3=1, conjurador3, brujo3, nigromante3, barbaro3, paladin3, caballero3, mercenario3, gladiador3};

class  PersonajeFactory
{
    public:

        PersonajeFactory(); 

        shared_ptr<arma> crear_arma_factory(armas_totales tipo_arma, float dato1, float dato2, float dato3);
        /*
            retorna un share_ptr a un objeto arma
        */

        shared_ptr<personaje> crear_personaje_factory(personajes_totales personaje, hab_totales habilidad, int dato1, float dato_personal);
        /*
            retorna un shared_ptr a un objeto personaje (sin arma)
        */

        shared_ptr<personaje> crear_personaje_armado_factory(personajes_totales perso,hab_totales hab_especial, int dato1, float dato_personal, armas_totales tip_arma, float dato2, float dato3, float dato4);
        /*
            retorna un shared_ptr a un objeto personaje (con arma)
        */
};
