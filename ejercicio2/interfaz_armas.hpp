#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;


// enuma de las armas (primeros 4 elementos = items magicos, los ultimos 5 = armas de combate//

enum armas_magicas_y_combate {baston = 1, libro_de_hechizos, pocion, amuleto, hacha_simple, hacha_doble, espada, lanza, garrote};

// enum de las habilidades especiales //

enum habilidades_especiales_magicas_y_combate {Explosion_arcana = 1, Golpe_elemental, Corte_espectral, Encantamiento_explosivo, Rafaga_magica, Impacto_devastador, Corte_giratorio, Golpe_perforante, Ataque_ensordecedor, Ruptura_elemental };


bool pertenece_en_magicos(armas_magicas_y_combate arma);
/*
    retorna true en caso de que el tipo de arma perteznca al conjunto de items magicos. caso contrario retorna flase. 
*/

bool pertenece_en_combate(armas_magicas_y_combate arma);
/*
    retorna true en caso de que el tipo de arma pertenezca al conjunto de armas de combate. caso contrario 
    retorna flase. 
*/

bool pertenece_habilidad_espe_magico(habilidades_especiales_magicas_y_combate habilidad);
/*
    retorna true en caso de que la habilidad especial pertenezca al conjunto de habilidades especiales de los magos. 
    caso contrario retorna flase. 
*/

bool pertenece_habilidad_espe_combate(habilidades_especiales_magicas_y_combate habilidad);
/*
    retorna true en caso de que la habilidad especial pertenezca al conjunto de habilidades especiales de los guerreros. 
    caso contrario retorna flase. 
*/

///////////////////////////////////clase interfaz arma ////////////////////////////////////////////

class arma
{
    public:

        virtual void mostrar_tipo_arma() = 0;

        virtual void mostrar_daño() = 0;

        virtual void mostrar_daño_especial() = 0;

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
        
        armas_magicas_y_combate tipo_arma;

        double Daño;

        int cant_golpes_disponibles;

        habilidades_especiales_magicas_y_combate habilidad_especial;

        double daño_extra_especial;
        
        int cant_golpes_especial;

        virtual void restar_usos(bool normal);

    public:

        items_magicos(armas_magicas_y_combate tip_arma, double daño, int cant_golpes_dispo, habilidades_especiales_magicas_y_combate habilidad_espe, double daño_extra_espe, int cant_golpes_espe);
        /*
        construcor de la clase items_magicos donde inicializa el tipo de arma, el daño, la cantidad de golpes, la habilidad especial del
        arma, el daño extra que genera la habilidad especial y la cantidad de golpes de la habilidad especial. 
        el daño extra de la habilidad especial va a depender del que habilidad sea
        explciacion:
            - si la habilidad especial es del grupo de habilidades de los items magicos -> se usa el 100& de su poder de daño
            - si la habilidad especial es del grupo de habilidades de las armas de combate -> se usa el 60& de su poder de daño
        
        en caso de que algun parametro no este dentro del rango, se arroja un throw y se lo captura con un catch. 
        */

        virtual void mostrar_tipo_arma();
        /*
            imprime por consola el tipo de arma de item magico
        */

        virtual void mostrar_daño();
        /*
            imprime por consola el poder de daño que puede hacer el arma
        */

        virtual void mostrar_daño_especial();
        /*
            imprime por consola el poder de daño adicional del item magico con la habilidad especial
        */

        virtual void mostrar_golpes_disponibles();
        /*
            imprime por consola la cantidad de golpes disponibles del arma
        */

        virtual void mostrar_habilidad_especial();
        /*
            imprime por conola la habilidad especial del arma
        */

        virtual void mostrar_golpes_dispo_especial();
        /*
            imprime por consola la cantidad de golpes especiales disponibles del arma
        */

        virtual double devolver_daño(bool normal);
        /*
            retorna el daño del arma depedniendo del tipo de ataque que se quiera
            si normal = true, se devuelve el daño del arma normal
            si normal = false, se devuelve el daño del arma con la habilidad especial incluida
        */
};

////////////////////////////clase armas de combate //////////////////////////////

class armas_combate : public arma
{
    private:

        armas_magicas_y_combate tipo_arma;

        double Daño;

        int cant_golpes_disponibles;

        habilidades_especiales_magicas_y_combate habilidad_especial;

        double daño_extra_especial;
        
        int cant_golpes_especial;

        virtual void restar_usos(bool normal);

    public:

        armas_combate(armas_magicas_y_combate tip_arma, double daño, int cant_golpes_dispo, habilidades_especiales_magicas_y_combate habilidad_espe, double daño_extra_espe, int cant_golpes_espe);
        /*
        construcor de la clase armas de combate donde inicializa el tipo de arma, el daño, la cantidad de golpes, la habilidad especial del
        arma, el daño extra que genera la habilidad especial y la cantidad de golpes de la habilidad especial. 
        el daño extra de la habilidad especial va a depender del que habilidad sea
        explciacion:
            - si la habilidad especial es del grupo de habilidades de las armas de combate -> se usa el 100& de su poder de daño
            - si la habilidad especial es del grupo de habilidades de los items magicos -> se usa el 60& de su poder de daño
           
        
        en caso de que algun parametro no este dentro del rango, se arroja un throw y se lo captura con un catch. 
        */


        virtual void mostrar_tipo_arma() = 0;
        /*
            imprime por consola el tipo de arma de combate
        */

        virtual void mostrar_daño() = 0;
        /*
            imprime por consola el poder de daño que puede hacer el arma de item magico
        */

        virtual void mostrar_daño_especial();
        /*
            imprime por consola el poder de daño adicional del arma de combate con la habilidad especial
        */

        virtual void mostrar_golpes_disponibles() = 0;
        /*
            imprime por consola la cantidad de golpes disponibles del arma
        */

        virtual void mostrar_habilidad() = 0;
        /*
            imprime por conola la habilidad especial del arma
        */

        virtual void mostrar_golpes_dispo_especial() = 0;
        /*
            imprime por consola la cantidad de golpes especiales disponibles del arma
        */

        virtual double devolver_daño(bool normal);
        /*
            retorna el daño del arma depedniendo del tipo de ataque que se quiera
            si normal = true, se devuelve el daño del arma normal
            si normal = false, se devuelve el daño del arma con la habilidad especial incluida
        */
};

bool pertenece_en_magicos(armas_magicas_y_combate tipo_arma);
/*
    retorna true si el tipo de arma es de los item magicos. retorna false en caso contrario
*/

bool pertenece_en_combate(armas_magicas_y_combate tipo_arma);
/*
    retorna true si el tipo de arma es de las armas de combate. retorna false en caso contrario
*/

bool pertenece_habilidad_espe_magico(habilidades_especiales_magicas_y_combate habilidad_especial);
/*
    retorna true si la habilidad especial es de las de los itemas magicos. retorna false en caso contrario
*/

bool pertenece_habilidad_espe_combate(habilidades_especiales_magicas_y_combate habilidad_combate);
/*
    retorna true si la habilidad especial es de las armas de combate. retorna false en caso contrario
*/