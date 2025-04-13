#pragma once
#include "interfaz_personajes.hpp"

//////////////////////////////////////////// clase abstracta guerrero //////////////////////////////////////////////////

class guerrero : public personaje
{
    private:

       unique_ptr<arma> arma1; // arma 1

       unique_ptr<arma> arma2; // arma 2

        tipos_guerreros tipo_guerrero; // tipo de guerrero

        float capacidad_fuerza; // fuerza del guerrero

        double hp; // puntos de vida

        hab_totales habilidad_especial; // habilidad especial

        double daño_hab; // daño de la habilidad especial

        int usos_hab; // cantidad de usos de la habilidad especial

        int cant_armas; // cantidad maxima de armas

    public:

        guerrero(tipos_guerreros guerrero, float fuerza, hab_totales hab_especial, double vida, int armas);

        void mostrar_info_personaje() const override;
        /*
            muestra por consola el tipo de personaje, la habilidad especial, el daño de la habilidad especial, la cantidad de usos 
            y la capacidad de fuerza.
        */

        void mostrar_hp() const override;
        /*
            muestra por consola el hp del personaje
        */

        double retornar_hp() const override;
        /*
            retorna el hp del personaje
        */

        void modificar_hp(double daño);
        /*
            modifica el hp del personaje, restandole el daño
        */

        void agregar_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3);
        /*
            crear un arma y la agrega a alguno de los 
        */

        void info_arma() const override;

        int contar_armas() const override;
        /*
            cretorna la cantidad de armas existentes. 
        */
};

// clases derivadas de la clase guerrero //

class barbaro : public guerrero
{
    private:
        
        float espiritu_salvaje; // 0 <= espiritu_salvaje <= 10

    public:

        barbaro(hab_totales habilidad, float fuerza, int max_armas, float salvaje);

        void Get_espiritu_salvaje();
        /*
            imprime por consola el nivel de espiritu salvaje del guerrero
        */
};

class paladin : public guerrero
{
    private:
        
        float aura_protectora;

    public:

        paladin(hab_totales habilidad, float fuerza, int max_armas, float aura);

        void Get_aura_protectora();
        /*
            imprime por consola el nivel de aura protectora del paladin
        */
};

class  caballero : public guerrero
{
    private:
        
        float habilidad_marcial; // nivel del manejo de armas

    public:

        caballero(hab_totales habilidad, float fuerza, int max_armas, float hab_marcial);

        void Get_habilidad_marcial();
        /*
            imprime por consola el nivel de habilidad marcial del caballero
        */
    
};

class mercenario : public guerrero
{
    private:
        
        float nivel_astucia;

    public:

        mercenario(hab_totales habilidad, float fuerza, float aura, int max_armas, float astucia);

        void Get_astucia();
        /*
            imprime por consola el nivel de astucia del mercenario
        */
};

class gladiador : public guerrero
{
    private:
    
        float adaptabilidad;

    public:

        gladiador(hab_totales habilidad, float fuerza, float aura, int max_armas, float adaptacion);

        void Get_adaptacion();
        /*
            imprime por consola el nivel de adaptabilidad
        */
};