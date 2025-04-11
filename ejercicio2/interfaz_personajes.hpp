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
};

///////////// clase mago ////////////////

class mago : public personaje
{
    private:

        vector<unique_ptr<arma>> armas;

        tipos_magos tipo_mago;

        hab_especiales_magicas habilidad_especial;

        int poder_magia; // 1 <= poder_magia <= 10

        double hp;

    public:

        mago(tipos_magos tip_mago, hab_especiales_magicas hab_especial, int magia, double vida, arma tipo_arma, float dato1, float dato2, float dato3);
 
        void mostrar_info_personaje() const override;

        void mostrar_hp() const override;

        double retornar_hp() const override;

        void agregar_arma();

        void modificar_hp();
};

///////////////////// clases derivadas de la clase mago /////////////////////////

class  hechicero : public mago
{
    private:
        
        float habilidad_fuente;

    public:

        hechicero(tipos_magos tip_mago, hab_especiales_magicas hab_especial, int magia, double vida, arma tipo_arma, float dato1, float dato2, float dato3, );
    
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



