#pragma once
#include "interfaz_armas.hpp"

class armas_combate : public arma
{
    protected:

        double Daño; // daño del arma

        int cant_usos; // cantidad de usos del arma

        armas_totales tipo_arma; // tipo de arma de combate

        float durabilidad_polvo; // nivel de durabilidad al polvo

        float precision_disparo; // nivel de precision de disparo

    public:

        armas_combate(armas_totales tip_arma, float durabilidad, float precision, double daño);

        void Get_infoarma_general() const override;
        /*
            imprime por consola el tipo de arma, la cantidad de usos y el daño. (metodo derivado de la clase interfaz)
        */

        void Get_info_combate() const;
        /*
            imprime por consola la durabilidad al polvo del arma y la precision del disparo
        */

        void Get_arma_combate() const;
        /*
            imprime por consola el tipo de arma de combate
        */

        double retornar_daño() const override;
        /*
            retorna el daño del arma
        */

        bool restar_usos();
        /*
            resta en una unidad a cant_usos, retorna true si antes de la resta es mayor a cero, caso contrario retorna false.
        */

        virtual void Get_caracteristica_arma() const = 0;
        /*
            imprime por consola el dato especifico de cada arma en cuestion
        */

        virtual ~armas_combate() = 0; // destructor de la clase armas_combate
};

/////////////////clases derivadas de armas de combate /////////////

class hacha_simple : public armas_combate
{
    private:
        
        float Filo; // 0 <= hacha simple <= 10

    public:
        hacha_simple(float durabilidad, float precision, float filo, double daño);
        /*
            constructor de la clase hacha_simple, inializa el atributo largo_baston y los atributos de la clase 
            abstracta llamando al constructor con el tipo de arma(arma_hacha_simple), el level_magico, la 
            resistencia y el daño
        */

        void Get_caracteristica_arma() const override;
        /*
            imprime por consola el filo del hacha simple
        */
};

class hacha_doble : public armas_combate
{
    private:

        float longitud_alcanze; // 0 <= longitud_alcanze <= 25

    public:

        hacha_doble(float durabilidad,float precision, float longitud, double daño);
        /*
            constructor de la clase hacha_doble, inializa el atributo longitud_alcanze y los atributos de la clase 
            abstracta llamando al constructor con el tipo de arma(arma_hacha_doble), el level_magico, la 
            resistencia y el daño
        */

        void Get_caracteristica_arma() const override;
        /*
            imprime por consola la longitud de alcanze del hacha doble
        */
};

class espada :public armas_combate
{
    private:
        
        float nivel_corte; // 0 <= nivel_corte <= 10

    public:
        espada(float durabilidad, float precision, float corte, double daño);
        /*
            constructor de la clase espada, inializa el atributo nivel_corte y los atributos de la clase 
            abstracta llamando al constructor con el tipo de arma(arma_espada), el level_magico, la 
            resistencia y el daño
        */

        void Get_caracteristica_arma() const override;
        /*
            imprime por consola el nivel de corta de la espada
        */
};

class lanza : public armas_combate
{
    private:
       
        float distancia_alcanze; // 0 <= distancia_alcanze <= 20

    public:
        lanza(float durabilidad, float precision, float alcanze, double daño);
        /*
            constructor de la clase lanza, inializa el atributo distancia_alcanze y los atributos de la clase 
            abstracta llamando al constructor con el tipo de arma(arma_lanza), el level_magico, la 
            resistencia y el daño
        */

        void Get_caracteristica_arma() const override;
        /*
            imprime por consola la distancia que se puede alcanzar con la lanza
        */
};

class garrote : public armas_combate
{
    private:
        
        float peso_garrote; // 0 <= peso_garrote <= 50

    public:
        garrote(float durabilidad, float precision, float peso, double daño);
            /*
            constructor de la clase garrote, inializa el atributo peso_garrote y los atributos de la clase 
            abstracta llamando al constructor con el tipo de arma(arma_garrote), el level_magico, la 
            resistencia y el daño
        */

        void Get_caracteristica_arma() const override;
        /* 
            imprime por consola el peso del garrote
        */
};