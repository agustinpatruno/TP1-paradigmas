#include <cstdlib>
#include <ctime>
#include "interfaz_armas.hpp"
#include "interfaz_personajes.hpp"
using namespace std;

int generarNumeroAleatorio(int minimo, int maximo);

class personaje_armado
{
    private:

        shared_ptr<personaje> avatar;

        vector<shared_ptr<arma>> armas;

        int cant_armas_maximas;

    public:

        personaje_armado(tipos_personajes personaje, double hp, auto dato1, auto dato2, habilidades_especiales_magicas_y_combate hab_especial, int cant_armas);
        /*
            constructor del objeto personaje armado. crea un objeto de la clase personaje y un objeto de la clase arma en base a los 
            parametros ingresados. en caso de tener algun parametro fuera de las opciones, arroja un thron y lo captura con catch
            para indicar un error.  
        */

        void atacar(personaje_armado& otro, bool normal, int indice_arma);
        /*
            ataca a otro personaje, restando el daño causado dependiendo del ataque elejido
        */

        void modificar_hp(double daño);
        /*
            modifica el hp del personaje, restandole el pasado por parametro
        */

        void mostrar_tipo_personaje();
        /*
            muestra por consola el tipo de personaje
        */

        void mostrar_hp();
        /*
            muestra por consola el hp del personaje
        */

        void mostrar_cant_golpes_totales();
        /*
            muestra por consola la cantidad de golpes totales del personaje
        */

        void mostrar_daños_totales();
        /*
            muestra por consola el daño del arma y el daño adicional con la habilidad especial
        */

        void crear_arma(string tip_arma, double daño, int cant_usos_dispo, string habilidad_espe, double daño_extra_espe, int cant_usos_espe);
        /*
            crea un arma con los parametros ingresados. caso de que no haya mas lugar para armas, se arrojara un throw y se captura con
            catch
        */

        void mostrar_datos_adicionales();
        /*
            muestra los datos adicionales del personaje
        */

};

class  PersonajeFactory
{
    public:

        PersonajeFactory(); 

        shared_ptr<arma> crear_arma(string tip_arma, double daño, int cant_usos_dispo, string habilidad_espe, double daño_extra_espe, int cant_usos_espe);

        shared_ptr<personaje> crear_personaje(string personaje, double hp, auto dato1, auto dato2, string hab_especial);

        shared_ptr<personaje_armado> crear_personaje_armado(string personaje, double hp, auto dato1, auto dato2, string hab_especial,string tip_arma, double daño, int cant_usos_dispo, string habilidad_espe, double daño_extra_espe, int cant_usos_espe);
};
