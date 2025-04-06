#include <iostream>
#include <string>
#include <memory>
#include "interfaz_armas.hpp"
using namespace std;

///////////// interfaz de pesonaje ////////////////

class personaje
{
    public:

        virtual void atacar(personaje& otro, bool normal) = 0;

        virtual void mostrar_tipo_personaje() = 0;

        virtual void mostrar_hp() = 0;

        virtual void mostrar_cant_golpes_totales() = 0;

        virtual void mostrar_datos() = 0;

        virtual void modificar_hp(double daño) = 0;

};

///////////// clase mago ////////////////

class mago : public personaje
{
    private:

        string tipo_mago;

        int poder_magia; // 1 <= poder_magia <= 10

        float duracion_encantamientos; //cantidad de segundos que dura un hechizo

        double hp;

        shared_ptr<arma> tipo_arma;

    public:

        mago(string mago, double Hp, string arma, double daño_arma, int cant_usos, string habilidad_especial, double daño_especial, int cant_usos_especial, int magia, float dur_encantamiento);
        /*
            constructor de la clase mago, donde se inicializa el tipo de mago, el Hp, el poder de magia y la duracion de sus encantamientos. 
            por otro lado, se crea un objeto de la interfaz arma, donde depende que tipo de arma sea y que habilidad especial, se le 
            bajara en porcentaje la capacidad de daño de la misma. 
            explicacion:
                - si se usa un tipo de arma de item magico -> se usa el 100% de su poder de daño.
                - si se usa un tipo de arma de armas de combate -> se usa el 80& de su poder de daño.
            
                - si se usa una habilidad especial dentro de los magicos -> se usa el 100% de su poder de daño
                - si se usa una habilidad especial dentro de los combates -> se usa el 60& de su poder de daño
            
            en el caso que alguno de los parametros no cumpla con el rango, se arrojara un throw y se lo capturara con un catch
        */

        virtual void atacar(personaje& otro, bool normal);
        /*
            le resta hp al otro personaje que recibe el ataque, donde dependiendo si normal es true o false, usa el ataque normal
            o el ataque especial. en caso de no tener mas usos disponibles, arroja un throw y la copatura con catch. 
        */

        virtual void mostrar_tipo_personaje();
        /*
            imprime por consola el tipo de mago
        */

        virtual void mostrar_hp();
        /*
            imprime por consola el hp del mago
        */

        virtual void mostrar_cant_golpes_totales();
        /*
            imprime por consola la cantidad de golpes totales, (normales y especiales).
        */

        virtual void mostrar_datos();
        /*
            imprime por consola los datos del poder de magia y la duracion de los encantamientos
        */

        virtual void modificar_hp(double daño);
        /*
            modifica el hp del objeto, restandole el daño que se le pasa por parametro. 
            en caso de ser mayor al hp, se arroja un throw y se lo captura con catch. Si no, se lo resta normalmente. 
        */
};

////////////////// clase guerrero /////////////////////

class guerrero
{
    private:

        string tipo_guerrero;

        float altura; // altua del guerrero Mts

        float peso; // peso del guerrero en Kg

        double hp;

        shared_ptr<arma> tipo_arma;

    public:

        guerrero(string guerrero, double hp, string golpe, double daño_golpe,int cant_golpes, string golpe_especial, double daño_golpe_especial, int cant_golpes_especial, float alt, float weight);
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

        virtual void atacar(personaje& otro, bool nomral);
        /*
            le resta hp al otro personaje que recibe el ataque, donde dependiendo si normal es true o false, usa el ataque normal
            o el ataque especial. en caso de no tener mas usos disponibles, arroja un throw y la copatura con catch. 
        */

        virtual void mostrar_tipo_personaje();
        /*
            imprime por consola el tipo de guerrero. 
        */
      
        virtual void mostrar_hp();
        /*
            imprime por consola el hp del guerrero. 
        */

        void mostrar_cant_golpes_totales();
        /*
            muestra por consola la cantidad de golpes totales que tiene, (golpes normales y especiales).
        */

        virtual void mostrar_datos();
        /*
            imprime por consola la altura y el peso del guerrero. 
        */

        virtual void modificar_hp(double daño);
        /*
            modifica el hp del objeto, restandole el daño que se le pasa por parametro. 
            en caso de ser mayor al hp, se arroja un throw y se lo captura con catch. Si no, se lo resta normalmente. 
        */
};
