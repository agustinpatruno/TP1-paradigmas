#pragma once
#include "interfaz_armas.hpp"

//////////////////////////////////////////////clase abstracta items magicos /////////////////////////////////////////////////////////

class items_magicos: public arma
{
    protected:

        double Daño; // daño del arma

        int cant_usos; // cantidad de usos del arma

        armas_totales tipo_arma; // tipo de arma magica

        float nivel_magico; // 1 <= nivel_magico <= 10

        float resistencia_magia_oscura;  // 1 <= ressitencia_magia_oscura <= 10

    public:

        items_magicos(armas_totales tip_arma, float level_magico, float resistencia, double daño);
        /*
            constructor de la clase abstracta item magicos. inicializa el atributo tipo_arma, nivel_magico, y el daño del arma.
            caso de que alguno de estos parametros no esten dentro del rango, arroja un throw y se captura con un cathc, advirtiendo
            que algun parametro esta mal ingresado.
        */

        void Get_infoarma_general() const override;
        /*
            imprime por consola la cantidad de usos y el daño. (metodo derivado de la clase interfaz arma)
        */

        void Get_info_magia() const;
        /*
            imprime por consola el nivel de magia del item magico y la resistencia a magia oscura
        */

        void Get_item_magico() const;
        /*
            imprime por consola el tipo de item magico
        */

        virtual void Get_caracteristica_arma_magica() const = 0;
        /*
            imprime por consola el dato especifico del arma en cuestion
        */

        double retornar_daño() const override;
        /*
            retorna el daño del arma. (metodo derivado de la clase interfaz arma)
        */

        bool restar_usos();
        /*
           resta en una unidad a cant_usos, retorna true si antes de la resta es mayor a cero, caso contrario retorna false.
        */

        virtual ~items_magicos() = 0; // destructor de la clase items_magicos
};

//////////////// clases derivadas de items magicos //////////////////

class baston : public items_magicos
{
    private:

        float largo_baston; // 1 <= largo_baston <= 6

    public:

        baston(float level_magico, float resistencia, float largo_baston, double daño);
        /*
            constructor de la clase baston, inializa el atributo largo_baston y los atributos de la clase abstracta llamando al constructor
            con el tipo de arma(arma_baston), el level_magico, la resistencia y el daño
        */

        void Get_caracteristica_arma_magica() const override;
        /*
            imprime por consola el largo del baston
        */
};

class libro_de_hechizos : public items_magicos
{
    private:

        float prestigio_libro; // representa la antiguedad del libro. 0 <= prestigio_libro <= 1000

    public:

        libro_de_hechizos(float level_magico, float resistencia, float prestigio, double daño);
        /*
            constructor de la clase libro_de_hechizos, inializa el atributo prestigio_libro y los atributos de la clase abstracta 
            llamando al constructor con el tipo de arma(arma_libro_de_hechizos), el level_magico, la resistencia 
            y el daño
        */

        void Get_caracteristica_arma_magica() const override;
        /*
            imprime por consola el nivel de presitigo del libro. (representa la antiguedad del mismo)
        */
};

class pocion : public items_magicos
{
    private:

        float durabilidad_pocion; // 0 <= duracion_pocion <= 26 sg

    public:

        pocion(float level_magico, float resistencia, float durabilidad_pocion, double daño);
        /*
            constructor de la clase pocion, inializa el atributo durabilidad_pocion y los atributos de la clase abstracta llamando al 
            constructor con el tipo de arma(arma_pocion), el level_magico, la resistencia y el daño
        */

        void Get_caracteristica_arma_magica() const override;
        /*
            imprime por consola la durabilidad de la pocion. representa segundos
        */
};

class amuleto : public items_magicos
{
    private:
        
        float suerte; // 0 <= suerte <= 10

    public:

        amuleto(float level_magico, float resistencia, float capacidad_suerte, double daño);
        /*
            constructor de la clase amuleto, inializa el atributo suerte y los atributos de la clase abstracta llamando al constructor
            con el tipo de arma(arma_amuleto), el level_magico, la resistencia y el daño
        */

        void Get_caracteristica_arma_magica() const override;
        /*
            imprime por consola el nivel de suerte del amuleto
        */
};