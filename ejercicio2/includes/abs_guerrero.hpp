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

        guerrero(tipos_guerreros nombre_guerrero, float fuerza, hab_totales hab_especial, double vida, int armas);
        /*
            constructor de la clase abstracta guerrero, inicializa los atributos tipo_guerrero, la fuerza, la hab_especial,
            el hp y la cantidad de arma en base a los parametros ingresados. en caso de que alguno este fuera del rango, arroja
            un throw y lo captura con un catch para advertir que hubo un error en los parametros ingresados
        */

        void mostrar_info_personaje() const override;
        /*
            muestra por consola el tipo de personaje guerrreo, la habilidad especial, el daño de la habilidad especial, la cantidad de usos 
            y la capacidad de fuerza.
        */

        void mostrar_hp() const override;
        /*
            muestra por consola el hp del personaje guerrero
        */

        double retornar_hp() const override;
        /*
            retorna el hp del personaje guerrero
        */

        void modificar_hp(double daño);
        /*
            modifica el hp del personaje guerrero, restandole el daño. caso de quedar sin vida, arroja un throw y lo captura con un catch 
            para avisar que se quedo sin vida
        */

        double daño(bool normal) override;
        /*
            retorna el daño del arma del guerrero, retorna el daño normal si normal = true, caso contrario retorna el daño mas el
            daño con la habilidad especial. esto ocurre siempre y cuando tenga golpes disponibles, caso contrario retorna 0
        */

        void info_arma() const override;
        /*
            imprime por consola la informacion de cada arma si es que tiene las 2
        */

        int contar_armas() const override;
        /*
            cretorna la cantidad de armas existentes. 
        */

        void agregar_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3);
        /*
            agrega un arma al guerrero en caso de que haya lugar disponible, pasando los parametros del tipo de arma, y datos extra com
            dato1, dato2 y dato3
        */

        virtual void mostrar_caracteristica_guerrero() const = 0;
        /*
            imprime por consola el atributo especifico de cada guerrero
        */

       virtual ~guerrero() = 0; // destrcutor de la clase guerrero
};

// clases derivadas de la clase guerrero //

class barbaro : public guerrero
{
    private:
        
        float espiritu_salvaje; // 0 <= espiritu_salvaje <= 10

    public:

        barbaro(hab_totales habilidad, float fuerza, int max_armas, float salvaje);
        /*
            constructor de la clase barbaro, inicializa el atributo espiritu salvaje y los atributos de la clase personaje con la fuerza
            la cantidd maxima de arma, la habilidad y el tipo de guerrero(a_barbaro). caso de que alguno de estos parametros esten fuera 
            del rango, arroja un throw y lo captura con catch para mostrar que hubo un problema con los parametros
        */

        void mostrar_caracteristica_guerrero() const override;
        /*
            imprime por consola el nivel de espiritu salvaje del guerrero
        */
};

class paladin : public guerrero
{
    private:
        
        float aura_protectora; // 0 <= aura protectora <= 10

    public:

        paladin(hab_totales habilidad, float fuerza, int max_armas, float aura);
        /*
            constructor de la clase paladin, inicializa el atributo eaura protectora y los atributos de la clase personaje con la fuerza
            la cantidd maxima de arma, la habilidad y el tipo de guerrero(a_paladin). caso de que alguno de estos parametros esten fuera 
            del rango, arroja un throw y lo captura con catch para mostrar que hubo un problema con los parametros
        */

        void mostrar_caracteristica_guerrero() const override;
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
        /*
            constructor de la clase caballero, inicializa el atributo habilidad marcial y los atributos de la clase personaje con la fuerza
            la cantidd maxima de arma, la habilidad y el tipo de guerrero(a_caballero). caso de que alguno de estos parametros esten fuera 
            del rango, arroja un throw y lo captura con catch para mostrar que hubo un problema con los parametros
        */

        void mostrar_caracteristica_guerrero() const override;
        /*
            imprime por consola el nivel de habilidad marcial del caballero
        */
    
};

class mercenario : public guerrero
{
    private:
        
        float nivel_astucia;

    public:

        mercenario(hab_totales habilidad, float fuerza, int max_armas, float astucia);
        /*
            constructor de la clase mercenario, inicializa el atributo nivel de astucia y los atributos de la clase personaje con la fuerza
            la cantidd maxima de arma, la habilidad y el tipo de guerrero(a_mercenario). caso de que alguno de estos parametros esten fuera 
            del rango, arroja un throw y lo captura con catch para mostrar que hubo un problema con los parametros
        */

        void mostrar_caracteristica_guerrero() const override;
        /*
            imprime por consola el nivel de astucia del mercenario
        */
};

class gladiador : public guerrero
{
    private:
    
        float adaptabilidad;

    public:

        gladiador(hab_totales habilidad, float fuerza, int max_armas, float adaptacion);
        /*
            constructor de la clase gladiador, inicializa el atributo adaptabilidad y los atributos de la clase personaje con la fuerza
            la cantidd maxima de arma, la habilidad y el tipo de guerrero(a_gladiador). caso de que alguno de estos parametros esten fuera 
            del rango, arroja un throw y lo captura con catch para mostrar que hubo un problema con los parametros
        */

        void mostrar_caracteristica_guerrero() const override;
        /*
            imprime por consola el nivel de adaptabilidad
        */
};