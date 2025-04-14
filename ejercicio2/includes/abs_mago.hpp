#pragma once
#include "interfaz_personajes.hpp"

///////////////////////////////////////// clase abstracta mago //////////////////////////////////////////////////////

class mago : public personaje
{
    private:

        unique_ptr<arma> arma1; // arma 1

        unique_ptr<arma> arma2; // arma 2

        tipos_magos tipo_mago; // tipo de mago

        int poder_magia; // 1 <= poder_magia <= 10

        double hp; // vida

        hab_totales habilidad_especial; // habilidad especial

        double daño_hab; // daño de la habilidad especial

        int usos_hab; // usos de la habilidad especial

        int cant_armas; // la cantidad de armas permitidas. 1 <= cant_armas <= 2

    public:

        mago(tipos_magos tip_mago, hab_totales hab_especial, int magia, double vida, int max_armas);
 
        void mostrar_info_personaje() const override;

        void mostrar_hp() const override;

        double retornar_hp() const override;

        double daño(bool normal) override;
        /*
            retorna el daño del arma, en caso de que normal = true, en caso de que se false, retorna el daño
            mas el daño de la habilidad
        */

        void modificar_hp(double daño);

        void agregar_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3);

        void info_arma() const override;

        int contar_armas() const override;

        virtual void mostrar_caracteristica_mago() const = 0;

        virtual ~mago() = 0;
};

// clases derivadas de la clase mago //

class  hechicero : public mago
{
    private:
        
        float habilidad_fuente; // 0 <= habilidad fuente <= 10

    public:

        hechicero(hab_totales hab_especial, int magia, int max_armas, float hab_fuente);
    
        void mostrar_caracteristica_mago() const override;
        /*
            imprime por consola la habilidad con la fuente que tiene el hechicero
        */
};

class  conjurador : public mago
{
    private:
        
        float conocimiento_ancestral; // 0 <= conocimiento_ancestral <= 10

    public:

        conjurador(hab_totales hab_especial, int magia, int max_armas, float conocimiento);

        void  mostrar_caracteristica_mago() const override;
        /*
            imprime por consola el nivel de conocimiento ancestral del conjurador
        */
};

class brujo : public mago
{
    private:
        
        float manipulacion_naturaleza;

    public:
    
        brujo(hab_totales hab_especial, int magia, int max_armas, float manipulacion);
    
        void mostrar_caracteristica_mago() const override;
        /*
            imprime por consola el nivel de manipulacion de naturaleza que tiene el brujo
        */
};

class nigromante : public mago
{
    private:
        
        float manipulacion_almas;

    public:

        nigromante(hab_totales hab_especial, int magia, int max_armas, float mani_almas);

        void mostrar_caracteristica_mago() const override;
        /*
            imprime por conosola el nivel de manipulacion de almas del nigronte
        */
};