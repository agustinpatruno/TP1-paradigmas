#include "interfaz_armas.hpp"
using namespace std;

// enum de los magos //

enum tipos_magos {hechicero=1, conjurador, brujo, nigromante};

// enum de los guerreros // 

enum tipos_guerreros {barbaro, paladin, caballero, mercenario, gladiador};

// enum de las habilidades especiales magicas //

enum hab_especiales_magicas {Explosion_arcana = 1, Golpe_elemental, Corte_espectral, Encantamiento_explosivo, Rafaga_magica, Impacto_devastador, Corte_giratorio, Golpe_perforante, Ataque_ensordecedor, Ruptura_elemental };

// enum de las habilidades especiales de combate //

enum hab_especiales_combate {Impacto_devastador = 1, Corte_giratorio, Golpe_perforante, Ataque_ensordecedor, Ruptura_elemental };

/* valores de los daños extra de las habilidades especiales magicas */
vector<double> daño_hab_magicos = {5.4, 3.7, 8.2, 6.6, 5};

/*  valores de los daños extra de las habilidades especiales magicas */
vector<double> daño_hab_combate = { 3.7, 5.3, 7, 4.2, 9};

/* cant de usos de las habilidades especiales magicas */
vector<int> usos_hab_magicas = {3,2,4,1};

/* cant de usos de las habilidades especiales de combate */
vector<int> usos_hab_combate = {5,3,2,4};

///////////// interfaz de pesonaje ////////////////

class personaje
{
    public:

        virtual void mostrar_info_personaje() const = 0;
        /*
            muestra por consola el tipo de personaje
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

        virtual void agregar_arma( arma tipo_arma, float dato1, float dato2, float dato3) = 0;
};

///////////////////////////////////////// clase abstracta mago //////////////////////////////////////////////////////

class mago : public personaje
{
    private:

        vector<unique_ptr<arma>> armas;

        tipos_magos tipo_mago;

        hab_especiales_magicas habilidad_especial;

        int poder_magia; // 1 <= poder_magia <= 10

        double hp;

    public:

        mago(tipos_magos tip_mago, hab_especiales_magicas hab_especial, int magia, double vida);
 
        void mostrar_info_personaje() const override;

        void mostrar_hp() const override;

        double retornar_hp() const override;

        void modificar_hp();

        void agregar_arma(arma tipo_arma, float dato1, float dato2, float dato3);
};

///////////////////// clases derivadas de la clase mago /////////////////////////

class  hechicero : public mago
{
    private:
        
        float habilidad_fuente;

    public:

        hechicero(tipos_magos tip_mago, hab_especiales_magicas hab_especial, int magia, float hab_fuente);
    
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

        conjurador(tipos_magos tip_mago, hab_especiales_magicas hab_especial, int magia, arma tipo_arma, float dato1, float dato2, float dato3, float conocimiento);

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
        brujo(tipos_magos tip_mago, hab_especiales_magicas hab_especial, int magia, arma tipo_arma, float dato1, float dato2, float dato3, float manipulacion);
    
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

        nigromante(tipos_magos tip_mago, hab_especiales_magicas hab_especial, int magia, arma tipo_arma, float dato1, float dato2, float dato3, float mani_armas);

        void Get_manipulacion_almas();
        /*
            imprime por conosola el nivel de manipulacion de almas del nigronte
        */
};

//////////////////////////////////////////// clase abstracta guerrero //////////////////////////////////////////////////

class guerrero : public personaje
{
    private:

        vector<unique_ptr<arma>> armas;

        tipos_guerreros tipo_guerrero; // tipo de guerrero

        hab_especiales_combate habilidad_especial; // habilidad especial

        float capacidad_fuerza; // fuerza del guerrero

        double hp; // puntos de vida

    public:

        guerrero(tipos_guerreros guerrero, float fuerza, hab_especiales_combate hab_especial);

        void mostrar_info_personaje() const override;
        /*
            muestra por consola el tipo de personaje
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

        void agregar_arma(arma tipo_arma, float dato1, float dato2, float dato3);
        /*
            crear un arma y la agrega al vector de armas
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