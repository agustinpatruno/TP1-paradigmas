#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

// valores del daño de las armas.(primera mitad = daños items magicos, segunda mitad = daños armas de combate) //
vector<double> daño_magicos_combates = {12.5, 13, 14, 10, 9, 16, 13.2, 15, 7.9};

// cant de usos de cada arma (primera mitad = cant usos items magicos, segunda mitad = cant usos armas de combate)//
vector<int> usos_armas_magicas_combates = {12,11,15,10, 13,16,12,9};

/* 
valores de los daños extra de las habilidades especiales 
(primera mitad = daños habilidades especiales magicos, segunda mitad = daños habilidades especiales combate)
*/
vector<double> daño_hab_magicos_combates = {5.4, 3.7, 8.2, 6.6, 5, 3.7, 5.3, 7, 4.2, 9};

/*
cant de usos de las habilidades especiales 
(primera mitad = cant usos habilidades especiales magicos, segunda mitad = cant usos habilidades especiales combate)
*/
vector<int> usos_hab_magicas_combates = {3,2,4,1,5,3,2,4};

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

string enum_a_string_armas(armas_magicas_y_combate arma);
/*
    retorna un string acorde al valor del enum armas_mamgicas_y_combate. caso de que no exista, retorna "valor desconocido"
*/

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
    private:

        int nivel_magico;

        int resistencia_magia_oscura;

        virtual void restar_usos(bool normal);

    public:

        items_magicos(armas_magicas_y_combate tip_arma, habilidades_especiales_magicas_y_combate habilidad_espe);
        /*
        construcor de la clase items_magicos y la habilidad especial del arma.
        el daño extra de la habilidad especial va a depender del tipo de arma
        explciacion:
            - si la habilidad especial es del grupo de habilidades de los items magicos -> se usa el 100& de su poder de daño
            - si la habilidad especial es del grupo de habilidades de las armas de combate -> se usa el 60& de su poder de daño
        
        en caso de que algun parametro no este dentro del rango, se arroja un throw y se lo captura con un catch. 
        */

        void Get_infoarma_general() const override;
        /*
            imprime por consola el tipo de arma de item magico, la cantidad de usos y el daño. (metodo derivado de la clase interfaz)
        */

        void Get_info_magia();
        /*
            imprime por consola el nivel de magia del item magico y la resistencia a magia oscura
        */

        virtual void Get_item_magico() const = 0;
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

        void Get_item_magico() const override;

        void Get_largo_baston();
        /*
            imprime por consola el largo del baston
        */
};

class libro_de_hechizos : public items_magicos
{
    private:

        int prestigio_libro; // representa la antiguedad del libro;

    public:

        void Get_item_magico() const override;

        void Get_prestigio();
};

class pocion : public items_magicos
{
    private:

        float durabilidad_pocion;

    public:
        
        void Get_item_magico() const override;

        void Get_durabilidad();

};

class amuleto : public items_magicos
{
    private:
        
        int suerte;

    public:
       
        void Get_item_magico() const override;

        void Get_suerte();
};

///////////////////////////////////////////////clase armas de combate /////////////////////////////////////////////////////////

class armas_combate : public arma
{
    private:

        int durabilidad_polvo;

        float precision_disparo;

        virtual void restar_usos(bool normal);

    public:

        armas_combate(armas_magicas_y_combate tip_arma, habilidades_especiales_magicas_y_combate habilidad_espe);
        /*
        construcor de la clase armas de combate donde inicializa el tipo de arma y la habilidad especial del
        arma.el daño extra de la habilidad especial va a depender del tipo de arma.
        explciacion:
            - si la habilidad especial es del grupo de habilidades de las armas de combate -> se usa el 100& de su poder de daño
            - si la habilidad especial es del grupo de habilidades de los items magicos -> se usa el 60& de su poder de daño
        en caso de que algun parametro no este dentro del rango, se arroja un throw y se lo captura con un catch. 
        */

        void Get_infoarma_general() const override;
        /*
            imprime por consola el tipo de arma de arma_combate, la cantidad de usos y el daño. (metodo derivado de la clase interfaz)
        */

        void Get_info_cambate();
        /*
            imprime por consola la durabilidad al polvo del arma y la precision del disparo
        */

        virtual void Get_arma_combate() const = 0;
        /*
            imprime por consola el tipo de arma de combate
        */
};

/////////////////clases derivadas de armas de combate /////////////

class hacha_simple : public armas_combate
{
    private:
        
        float filo;

    public:
        hacha_simple(/* args */);

        void Get_arma_combate() const override;

        void Get_filo();
        /*
            imprime por consola el filo del hacha simple
        */
};

class hacha_doble : public armas_combate
{
    private:
    
        float filo;

    public:
        hacha_doble(/* args */);

        void Get_arma_combate() const override;

        void Get_filo();
        /*
            imprime por consola el filo del hacha doble
        */
};

class espada :public armas_combate
{
    private:
        
        float nivel_corte;

    public:
        espada(/* args */);

        void Get_arma_combate() const override;

        void Get_nivel_corte();
};

class lanza : public armas_combate
{
    private:
       
        float distancia_alcanza;

    public:
        lanza(/* args */);

        void Get_arma_combate() const override;

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
        garrote(/* args */);

        void Get_arma_combate() const override;

        void Get_peso();
        /* 
            imprime por consola el peso del garrote
        */
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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