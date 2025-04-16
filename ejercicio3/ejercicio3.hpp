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

int generarAleatorio(int minimo, int maximo);
/*
    retorna un numero aleatorio dentro de un intervalo [minimo, maximo]. caso de que maximo < minimo. retorna cero
*/

// enum de los personajes totales (tienen el numero 3 para diferenciarlos del otro enum definido en el hpp de personajes)//

enum personajes_totales {hechicero3=1, conjurador3, brujo3, nigromante3, barbaro3, paladin3, caballero3, mercenario3, gladiador3};

class  PersonajeFactory
{
    public:

        PersonajeFactory() = delete; 
        /*
            constructor de la clase Personaje factory, imprime por consola que se creo correctamente el objeto.
        */

        static unique_ptr<arma> crear_arma_factory(armas_totales tipo_arma, float dato1, float dato2, float dato3);
        /*
            crea un arma y retorna un puntero share_ptr, en base a los datos ingresados, como tipo_arma, dato1, dato2 y dato3. 
            caso de que alguno este afuera del rango, arroja un throw y lo captura con cath para advertir de que hubo un error
        */

        static unique_ptr<personaje> crear_personaje_factory(personajes_totales personaje, hab_totales habilidad, int dato1, float dato_personal);
        /*
            crea un personaje y retorna un puntero share_ptr, en base a los datos ingresados, como personaje, habilidad, dato1
            y dato personal. 
            caso de que alguno este afuera del rango, arroja un throw y lo captura con cath para advertir de que hubo un error
        */

        static unique_ptr<personaje> crear_personaje_armado_factory(personajes_totales perso,hab_totales hab_especial, int dato1, float dato_personal, armas_totales tip_arma, float dato2, float dato3, float dato4);
        /*
            crae un personaje con arma y retorna un shared_ptr , en base a los parametros ingresados, llama a la funcion de crear personaje de
            la msima clase, y luego le agrega el arma con el metodo que tiene la clase personaje. en caso de que el nuevo persoanje sea
            un nullptr, arroja un throw y lo captura con catch para advertir que no se pudo crear el personaje.
        */
};
