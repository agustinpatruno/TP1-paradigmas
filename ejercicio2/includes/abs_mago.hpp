#pragma once
#include "interfaz_personajes.hpp"

///////////////////////////////////////// clase abstracta mago //////////////////////////////////////////////////////

class mago : public personaje
{
    protected:

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
        /*
            muestra por consola el tipo de personaje mago, la habilidad especial, el daño de la habilidad especial, la cantidad de usos 
            y el poder de magia.
        */

        void info_arma() const override;
        /*
            imprime por consola la informacion de cada arma si es que tiene las 2
        */

        int contar_armas() const override;
        /*
            cretorna la cantidad de armas existentes. 
        */

        void mostrar_hp() const override;
        /*
            muestra por consola el hp del personaje mago
        */

        double retornar_hp() const override;
        /*
            retorna el hp del personaje mago
        */

        void modificar_hp(double daño);
        /*
            modifica el hp del personaje guerrero, restandole el daño. caso de quedar sin vida, arroja un throw y lo captura con un catch 
            para avisar que se quedo sin vida
        */

        double daño(bool normal) override;
        /*
            retorna el daño del arma, en caso de que normal = true, en caso de que se false, retorna el daño
            mas el daño de la habilidad
        */

        void agregar_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3);
        /*
            agrega un arma al mago en caso de que haya lugar disponible, pasando los parametros del tipo de arma, y datos extra com
            dato1, dato2 y dato3
        */

        unique_ptr<arma> crear_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3, double daño) override;
        /*
            retorna un puntero unique_ptr a un arma  en base a los parametros del tipo de arma, dato1, dato2, dato3 y el daño
        */

        virtual void mostrar_caracteristica_mago() const = 0;
        /*
            imprime por consola el atributo especifico de cada mago
        */

        virtual ~mago() = 0; // destrcutor de la clase mago
};

// clases derivadas de la clase mago //

class  hechicero : public mago
{
    private:
        
        float habilidad_fuente; // 0 <= habilidad fuente <= 10

    public:

        hechicero(hab_totales hab_especial, int magia, int max_armas, float hab_fuente);
        /*
            constructor de la clase hechicero, inicializa el atributo habilidad fuente y los atributos de la clase personaje con el nivel de
            magia, la cantidd maxima de arma, la habilidad y el tipo de mago(a_hechicero). caso de que alguno de estos parametros esten fuera 
            del rango, arroja un throw y lo captura con catch para mostrar que hubo un problema con los parametros
        */
    
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
        /*
            constructor de la clase conjurador, inicializa el atributo conocimieneto ancestral y los atributos de la clase personaje con 
            el nivel de magia, la cantidd maxima de arma, la habilidad y el tipo de mago(a_conjurador). caso de que alguno de estos 
            parametros esten fuera del rango, arroja un throw y lo captura con catch para mostrar que hubo un problema con los parametros
        */

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
        /*
            constructor de la clase brujo, inicializa el atributo manipulacion de la naturaleza y los atributos de la clase personaje con 
            el nivel de magia, la cantidd maxima de arma, la habilidad y el tipo de mago(a_brujo). caso de que alguno de estos 
            parametros esten fuera del rango, arroja un throw y lo captura con catch para mostrar que hubo un problema con los parametros
        */
    
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
        /*
            constructor de la clase nigromante, inicializa el atributo manipulacion de almas y los atributos de la clase personaje con 
            el nivel de magia, la cantidd maxima de arma, la habilidad y el tipo de mago(a_nigromante). caso de que alguno de estos 
            parametros esten fuera del rango, arroja un throw y lo captura con catch para mostrar que hubo un problema con los parametros
        */

        void mostrar_caracteristica_mago() const override;
        /*
            imprime por conosola el nivel de manipulacion de almas del nigronte
        */
};