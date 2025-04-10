#include "interfaz_armas.hpp"
using namespace std;

// enum de los personajes //

enum tipos_personajes {hechicero=1, conjurador, brujo, nigromante, barbaro, paladin, caballero, mercenario, gladiador};

bool pertenece_a_magos(tipos_personajes mago);
/*
    retorna true en caso de que el tipo de mago pertenezca al conjunto de magos. caso contrario retorna false
*/

bool pertenence_a_guerreros(tipos_personajes guerrero);
/*
    retorna true en caso de que el tipo de guerrero pertenezca al conjunto de guerreros. caso contrario retorna false
*/

///////////// interfaz de pesonaje ////////////////

class personaje
{
    public:

        virtual void mostrar_tipo_personaje() = 0;
        /*
            muestra por consola el tipo de personaje
        */

        virtual tipos_personajes retornar_tipo_personaje() = 0;
        /*
        
        */

        virtual void mostrar_hp() = 0;
        /*
            muestra por consola el hp del personaje
        */

        virtual double retornar_hp() = 0;
        /*
            retorna el hp del personaje
        */

      

        virtual void modificar_hp(double daño) = 0;
        /*
            modifica el hp del personaje, restandole el daño
        */

        virtual void mostrar_dato1() = 0;
        /*
            muestra un dato del personaje
        */

       virtual void mostrar_dato2() = 0;
        /*
            muestra otro dato del personaje
        */
       
       virtual void mostrar_habilidad() = 0;
       /*
            muestra la habilidad especial del personaje
       */
};

///////////// clase mago ////////////////

class mago : public personaje
{
    private:

        tipos_personajes tipo_mago;

        habilidades_especiales_magicas_y_combate habilidad_especial;

        int poder_magia; // 1 <= poder_magia <= 10

        float duracion_encantamientos; //cantidad de segundos que dura un hechizo

        double hp;

    public:

        mago(tipos_personajes mago, double Hp, int magia, float dur_encantamiento, habilidades_especiales_magicas_y_combate hab_especial);
        /*
            constructor de la clase mago, donde se inicializa el tipo de mago, el Hp, el poder de magia y la duracion de sus encantamientos. 
          
            en el caso que alguno de los parametros no cumpla con el rango, se arrojara un throw y se lo capturara con un catch
        */

        virtual void mostrar_tipo_personaje();
        /*
            imprime por consola el tipo de mago
        */

        virtual void mostrar_hp();
        /*
            imprime por consola el hp del mago
        */

        virtual double retornar_hp();
        /*
            retorna el hp del mago
        */

        virtual tipos_personajes retornar_tipo_personaje();
        /*
            retorna el tipo de personaje
        */

        virtual void modificar_hp(double daño);
        /*
            modifica el hp del mago, restandole el daño
        */

        virtual void mostrar_dato1();
        /*
            imprime por consola el poder de magia del mago
        */

       virtual void mostrar_dato2();
       /*
          imprime por consola la duracion de los encantamientos del mago
       */

       virtual void mostrar_habilidad();
       /*
            imprime por consola la habilidad especial del mago
       */
};

///////////////////// clases derivadas de la clase mago /////////////////////////

class  hechicero : public mago
{
    private:
        /* data */
    public:
        hechicero(/* args */);
    
};

class  conjugador : public mago
{
    private:
        /* data */
    public:
        conjugador(/* args */);
};

class brujo : public mago
{
    private:
        /* data */
    public:
        brujo(/* args */);
    
};

class nigronte : public mago
{
    private:
        /* data */
    public:
        nigronte(/* args */);
};

////////////////// clase guerrero /////////////////////

class guerrero
{
    private:

        tipos_personajes tipo_guerrero; // tipo de guerrero

        habilidades_especiales_magicas_y_combate habilidad_especial; // habilidad especial

        float altura; // altua del guerrero Mts

        float peso; // peso del guerrero en Kg

        double hp; // puntos de vida

    public:

        guerrero(tipos_personajes guerrero, double hp, float alt, float weight, habilidades_especiales_magicas_y_combate hab_especial);
        /*
            constructor de la clase guerrero donde se inicializa el tipo de guerrero, el Hp, el peso y altura del guerrero. 
            por otro lado, se crea un objeto de la interfaz arma, donde depende que tipo de arma sea y que habilidad especial, se le 
            bajara en porcentaje la capacidad de daño de la misma.
            explicacion: 
                - si se usa un tipo de arma de combate -> se usa el 100% de su poder de daño.
                - si se usa un tipo de arma de item guerrero -> se usa el 80& de su poder de daño.
            
                - si se usa una habilidad especial dentro de los combates -> se usa el 100% de su poder de daño
                - si se usa una habilidad especial dentro de los magicos -> se usa el 60& de su poder de daño
            
               
            en el caso que alguno de los parametros no cumpla con el rango de posibilidades, se arrojara un throw y se lo capturara 
            con un catch.
        */

        virtual void mostrar_tipo_personaje();
        /*
            imprime por consola el tipo de guerrero. 
        */
      
        virtual void mostrar_hp();
        /*
            imprime por consola el hp del guerrero. 
        */

        virtual double retornar_hp();
        /*
            retorna el hp del guerrero
        */

        virtual tipos_personajes retornar_tipo_personaje();
        /*
            retorna el tipo de personaje
        */

        virtual void modificar_hp(double daño);
        /*
            modifica el hp del guerrero, restandole el daño
        */

        virtual void mostrar_dato1();
        /*
            imprime por consola la altura del guerrero. 
        */
        
        virtual void mostrar_dato2();
        /*
            imprime por consola el peso del guerrero.
        */

        virtual void mostrar_habilidad();
        /*
            imprime por consola la habilidad del guerrero.
        */
};

////////////clases derivadas de la clase guerrero ////////////////////

class barbaro : public guerrero
{
    private:
        /* data */
    public:
        barbaro(/* args */);
};

class paladin : public guerrero
{
    private:
        /* data */
    public:
        paladin(/* args */);
};

class  caballero : public guerrero
{
    private:
        /* data */
    public:
        caballero(/* args */);
    
};

class mercenario : public guerrero
{
    private:
        /* data */
    public:
        mercenario(/* args */);
};

class gladiador : public guerrero
{
    private:
        /* data */
    public:
        gladiador(/* args */);
    
};



