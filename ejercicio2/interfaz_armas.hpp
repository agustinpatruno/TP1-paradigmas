#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

string obtenerNombreArmaMagica(armas_magicas tipo);

string obtenerNombreArmaCombate(armas_de_combate tipo);

// valores del daño de las armas magicas //
vector<double> daño_magicos = {12.5, 13, 14, 10};

// valores del daño de las armas de combate //
vector<double> daño_combate = { 9, 16, 13.2, 15, 7.9};

// cant de usos de cada arma magica //
vector<int> usos_armas_magicas = {12,11,15,10};

// cant de usos de cada arma de combate //
vector<int> usos_armas_combate = {13,16,12,9};


// enuma de las armas magicas//

enum armas_magicas {baston = 1, libro_de_hechizos, pocion, amuleto};

// enum de las armas de combates //

enum armas_de_combate {hacha_simple = 1, hacha_doble, espada, lanza, garrote};


bool corroborar_intervalo(int min, float valor, int max);

///////////////////////////////////clase interfaz arma ////////////////////////////////////////////

class arma
{
    protected:

        double Daño;

        int cant_usos;

    public:

        virtual void Get_infoarma_general() const = 0; // muestro el tipo de arma, la cantidad de usos disponibles y el daño
        virtual ~arma();
};

/////////////////////clase items magicos ///////////////////////////////////

class items_magicos: public arma
{
    protected:

        armas_magicas tipo_arma;

        float nivel_magico; // 1 <= nivel_magico <= 10

        float resistencia_magia_oscura;  // 1 <= ressitencia_magia_oscura <= 10

        virtual void restar_usos(bool normal);

    public:

        items_magicos(armas_magicas tip_arma, float level_magico, float resistencia);

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

        baston(armas_magicas tip_arma, float level_magico, float resistencia, float largo_baston);

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

        libro_de_hechizos(armas_magicas tip_arma, float level_magico, float resistencia, float prestigio);

        void Get_prestigio();
};

class pocion : public items_magicos
{
    private:

        float durabilidad_pocion;

    public:

        pocion(armas_magicas tip_arma, float level_magico, float resistencia, float durabilidad_pocion);

        void Get_durabilidad();
};

class amuleto : public items_magicos
{
    private:
        
        float suerte;

    public:

        amuleto(armas_magicas tip_arma, float level_magico, float resistencia, float capacidad_suerte);

        void Get_suerte();
};

///////////////////////////////////////////////clase armas de combate /////////////////////////////////////////////////////////

class armas_combate : public arma
{
    private:

        armas_de_combate tipo_arma;

        float durabilidad_polvo;

        float precision_disparo;

        virtual void restar_usos(bool normal);

    public:

        armas_combate(armas_de_combate tip_arma, float durabilidad, float precision);
       

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
        hacha_simple(armas_de_combate tip_arma, float durabilidad, float precision, float filo);

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

        hacha_doble(armas_de_combate tip_arma, float durabilidad, float precision, float filo, float longitud);

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
        espada(armas_de_combate tip_arma, float durabilidad, float precision, float corte);

        void Get_nivel_corte();
};

class lanza : public armas_combate
{
    private:
       
        float distancia_alcanze;

    public:
        lanza(armas_de_combate tip_arma, float durabilidad, float precision, float alcanze);

        void Get_distancia_alcanza();
        /*
            imprime por consola la distancia que se puede alcanzar con la lanza
        */
        
};

class garrote : armas_combate
{
    private:
        
        float peso__garrote;

    public:
        garrote(armas_de_combate tip_arma, float durabilidad, float precision, float peso);

        void Get_peso();
        /* 
            imprime por consola el peso del garrote
        */
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
