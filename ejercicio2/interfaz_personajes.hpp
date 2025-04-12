#include "interfaz_armas.hpp"
using namespace std;

// enum de los magos //

enum tipos_magos {a_hechicero=1, a_conjurador, a_brujo, a_nigromante};

// enum de los guerreros // 

enum tipos_guerreros {a_barbaro, a_paladin, a_caballero, a_mercenario, a_gladiador};

// enum de las habilidades totales //

enum hab_totales {Explosion_arcana = 1, Golpe_elemental, Corte_espectral, Encantamiento_explosivo, Rafaga_magica, Impacto_devastador, Corte_giratorio, Golpe_perforante, Ataque_ensordecedor, Ruptura_elemental};

/* valores de los daños extra de las habilidades especiales magicas y las de combate */

vector<double> daño_hab_magicos_combate = {5.4, 3.7, 8.2, 6.6, 5, 3.7, 5.3, 7, 4.2, 9};

/* cant de usos de las habilidades especiales magicas y de combate */

vector<int> usos_hab_magicas_combate = {3,2,4,1,5,5,3,2,4,3};

/*funcion que retorna un string del valor en base al enum tipos_magos que se le pase por parametro*/

string getTipoMago(tipos_magos tipo);

/*funcion que retorna un string del valor en base al enum tipos_guerreros que se le pase por parametro*/

string getTipoGuerrero(tipos_guerreros tipo);

/*funcion que retorna un string del valor en base al enum hab_especiales_magicas que se le pase por parametro*/

string getHabilidad(hab_totales habilidad);


///////////// interfaz de pesonaje ////////////////

class personaje
{
    public:

        virtual void mostrar_info_personaje() const = 0;
        /*
            muestra por consola el tipo de personaje, y todos sus atributos adicionales de informacion
        */

        virtual void mostrar_hp() const= 0;
        /*
            muestra por consola el hp del personaje
        */

        virtual double retornar_hp() const = 0;
        /*
            retorna el hp del personaje
        */

        virtual void modificar_hp(double daño) = 0;
        /*
            modifica el hp del personaje, restandole el daño
        */

        virtual void agregar_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3) = 0;

        virtual int contar_armas() = 0;
};

///////////////////////////////////////// clase abstracta mago //////////////////////////////////////////////////////

class mago : public personaje
{
    private:

        unique_ptr<arma> arma1; // arma 1

        unique_ptr<arma> arma2; // arma 2

        tipos_magos tipo_mago; // tipo de mago

        int poder_magia; // 1 <= poder_magia <= 10

        double hp = 100; // por default es 100

        hab_totales habilidad_especial; // habilidad especial

        double daño_hab; // daño de la habilidad especial

        int usos_hab; // usos de la habilidad especial

        int cant_armas; // la cantidad de armas permitidas

    public:

        mago(tipos_magos tip_mago, hab_totales hab_especial, int magia, double vida, int max_armas);
 
        void mostrar_info_personaje() const override;

        void mostrar_hp() const override;

        double retornar_hp() const override;

        void modificar_hp(double daño);

        void agregar_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3);

        int contar_armas();
};

// clases derivadas de la clase mago //

class  hechicero : public mago
{
    private:
        
        float habilidad_fuente;

    public:

        hechicero(hab_totales hab_especial, int magia, int max_armas, float hab_fuente);
    
        void Get_habilidad_fuente();
        /*
            imprime por consola la habilidad con la fuente que tiene el hechicero
        */
};

class  conjurador : public mago
{
    private:
        
    float conocimiento_ancestral;

    public:

        conjurador(tipos_magos tip_mago, hab_totales hab_especial, int magia, int max_armas, float conocimiento);

        void Get_conocimiento();
        /*
            imprime por consola el nivel de conocimiento ancestral del conjurador
        */
};

class brujo : public mago
{
    private:
        
        float manipulacion_naturaleza;

    public:
        brujo(tipos_magos tip_mago, hab_totales hab_especial, int magia, int max_armas, float manipulacion);
    
        void Get_manipulacion_naturaleza();
        /*
            imprime por consola el nivel de manipulacion de naturaleza que tiene el brujo
        */
};

class nigromante : public mago
{
    private:
        
        float manipulacion_almas;

    public:

        nigromante(tipos_magos tip_mago, hab_totales hab_especial, int magia, int max_armas, float mani_almas);

        void Get_manipulacion_almas();
        /*
            imprime por conosola el nivel de manipulacion de almas del nigronte
        */
};

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
            crear un arma y la agrega al vector de armas
        */

        int contar_armas() override;
        /*
            cretorna la cantidad de armas existentes. 
        */
};

// clases derivadas de la clase guerrero //

class barbaro : public guerrero
{
    private:
        
        float espiritu_salvaje;

    public:

        barbaro(tipos_guerreros tip_guerrero, hab_totales habilidad, float fuerza, int max_armas, float salvaje);

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

        paladin(tipos_guerreros tip_guerrero, hab_totales habilidad, float fuerza, float aura);

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

        caballero(tipos_guerreros tip_guerrero, hab_totales habilidad, float fuerza, float hab_marcial);

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

        mercenario(tipos_guerreros tip_guerrero, hab_totales habilidad, float fuerza, float aura, float astucia);

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

        gladiador(tipos_guerreros tip_guerrero, hab_totales habilidad, float fuerza, float aura, float adaptacion);

        void Get_adaptacion();
        /*
            imprime por consola el nivel de adaptabilidad
        */
};