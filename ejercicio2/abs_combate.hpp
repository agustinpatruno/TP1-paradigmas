#pragma once
#include "interfaz_armas.hpp"

class armas_combate : public arma
{
    private:

        armas_totales tipo_arma;

        float durabilidad_polvo;

        float precision_disparo;

    public:

        armas_combate(armas_totales tip_arma, float durabilidad, float precision, double daño);
       
        void restar_usos();

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
        
        float Filo; // 0 <= hacha simple <= 10

    public:
        hacha_simple(float durabilidad, float precision, float filo, double daño);

        void Get_filo();
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

        void Get_longitud_alcanze();
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

        void Get_nivel_corte();
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

        void Get_distancia_alcanze();
        /*
            imprime por consola la distancia que se puede alcanzar con la lanza
        */
};

class garrote : public armas_combate
{
    private:
        
        float peso__garrote; // 0 <= peso_garrote <= 50

    public:
        garrote(float durabilidad, float precision, float peso, double daño);

        void Get_peso();
        /* 
            imprime por consola el peso del garrote
        */
};