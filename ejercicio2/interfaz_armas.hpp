#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

string obtenerNombreArma(armas_totales tipo);
/*
    retorna el string del tipo de arma que se le pasa por parametro. caso de no ser ninguno, retorna tipo de arma
    desconocido
*/

bool pertenece_armas_magicas(armas_totales tipo_arma);
/*
    retorna true si el tipo de arma pertenece a las armas magicas, retorna false en caso contrario.
*/

bool pertenece_armas_combate(armas_totales tipo_arma);
/*
    retorna true si el tipo de arma pertenece a las armas de combate, retorna false en caso contrario.
*/

// valores del daño de las armas magicas y de combate. ([1:5] = daño magico, [6:10] daño de combate)//
vector<double> daño_magicos_combate = {12.5, 13, 14, 10, 9, 16, 13.2, 15, 7.9};

// cant de usos de cada arma magica y de combate. ([1:5] = uso de armas magicas, [6,10] usos de armas de combate )//
vector<int> usos_armas_magicas_combate = {12,11,15,10,13,16,12,9};

// enum de las armas totales. ([1:5] = armas magicas, [6:10] = armas de combate)//
enum armas_totales {arma_baston = 1, arma_libro_de_hechizos, arma_pocion, arma_amuleto, arma_hacha_simple, arma_hacha_doble, arma_espada, arma_lanza, arma_garrote};

bool corroborar_intervalo(int min, float valor, int max);
/*
    retorna true si el valor esta dentro del intervalo, retorna false en caso contrario y en caso de que max < min. 
*/

///////////////////////////////////clase interfaz arma ////////////////////////////////////////////

class arma
{
    protected:

        double Daño;

        int cant_usos;

    public:

        virtual void Get_infoarma_general() const = 0; // muestro el tipo de arma, la cantidad de usos disponibles y el daño
        virtual ~arma() = default;
};

/////////////////////clase items magicos ///////////////////////////////////

class items_magicos: public arma
{
    protected:

        armas_totales tipo_arma;

        float nivel_magico; // 1 <= nivel_magico <= 10

        float resistencia_magia_oscura;  // 1 <= ressitencia_magia_oscura <= 10

        virtual void restar_usos(bool normal);

    public:

        items_magicos(armas_totales tip_arma, float level_magico, float resistencia, double daño);

        void Get_infoarma_general() const override;
        /*
            imprime por consola la cantidad de usos y el daño. (metodo derivado de la clase interfaz)
        */

        void Get_info_magia();
        /*
            imprime por consola el nivel de magia del item magico y la resistencia a magia oscura
        */

        void Get_item_magico();
        /*
            imprime por consola el tipo de item magico
        */
};

//////////////// clases derivadas de items magicos //////////////////

class baston : public items_magicos
{
    private:

        float largo_baston;

    public:

        baston(armas_totales tip_arma, float level_magico, float resistencia, float largo_baston, double daño);

        void Get_largo_baston();
        /*
            imprime por consola el largo del baston
        */
};

class libro_de_hechizos : public items_magicos
{
    private:

        float prestigio_libro; // representa la antiguedad del libro

    public:

        libro_de_hechizos(armas_totales tip_arma, float level_magico, float resistencia, float prestigio, double daño);

        void Get_prestigio();
};

class pocion : public items_magicos
{
    private:

        float durabilidad_pocion;

    public:

        pocion(armas_totales tip_arma, float level_magico, float resistencia, float durabilidad_pocion, double daño);

        void Get_durabilidad();
};

class amuleto : public items_magicos
{
    private:
        
        float suerte;

    public:

        amuleto(armas_totales tip_arma, float level_magico, float resistencia, float capacidad_suerte, double daño);

        void Get_suerte();
};

///////////////////////////////////////////////clase armas de combate /////////////////////////////////////////////////////////

class armas_combate : public arma
{
    private:

        armas_totales tipo_arma;

        float durabilidad_polvo;

        float precision_disparo;

        virtual void restar_usos(bool normal);

    public:

        armas_combate(armas_totales tip_arma, float durabilidad, float precision, double daño);
       

        void Get_infoarma_general() const override;
        /*
            imprime por consola la cantidad de usos y el daño. (metodo derivado de la clase interfaz)
        */

        void Get_info_combate();
        /*
            imprime por consola la durabilidad al polvo del arma y la precision del disparo
        */

        void Get_arma_combate();
        /*
            imprime por consola el tipo de arma de combate
        */
};

/////////////////clases derivadas de armas de combate /////////////

class hacha_simple : public armas_combate
{
    private:
        
        float Filo;

    public:
        hacha_simple(armas_totales tip_arma, float durabilidad, float precision, float filo, double daño);

        void Get_filo();
        /*
            imprime por consola el filo del hacha simple
        */
};

class hacha_doble : public armas_combate
{
    private:
    
        float Filo;

        float longitud_alcanze;

    public:

        hacha_doble(armas_totales tip_arma, float durabilidad, float precision, float filo, float longitud, double daño);

        void Get_filo();
        /*
            imprime por consola el filo del hacha doble
        */

        void Get_longitud_alcanze();
};

class espada :public armas_combate
{
    private:
        
        float nivel_corte;

    public:
        espada(armas_totales tip_arma, float durabilidad, float precision, float corte, double daño);

        void Get_nivel_corte();
};

class lanza : public armas_combate
{
    private:
       
        float distancia_alcanze;

    public:
        lanza(armas_totales tip_arma, float durabilidad, float precision, float alcanze, double daño);

        void Get_distancia_alcanza();
        /*
            imprime por consola la distancia que se puede alcanzar con la lanza
        */
};

class garrote : public armas_combate
{
    private:
        
        float peso__garrote;

    public:
        garrote(armas_totales tip_arma, float durabilidad, float precision, float peso, double daño);

        void Get_peso();
        /* 
            imprime por consola el peso del garrote
        */
};
