#include "interfaz_armas.cpp"

/////////////////////clase abstracta items magicos ///////////////////////////////////

class items_magicos: public arma
{
    protected:

        armas_totales tipo_arma;

        float nivel_magico; // 1 <= nivel_magico <= 10

        float resistencia_magia_oscura;  // 1 <= ressitencia_magia_oscura <= 10

    public:

        items_magicos(armas_totales tip_arma, float level_magico, float resistencia, double daño);

        virtual void restar_usos();
        /*
            funcion que resta los usos del arma cada vez que se ataca. dependiendo se 
        */

        void Get_infoarma_general() const override;
        /*
            imprime por consola la cantidad de usos y el daño. (metodo derivado de la clase interfaz)
        */

        void Get_info_magia();
        /*
            imprime por consola el nivel de magia del item magico y la resistencia a magia oscura
        */

        void Get_item_magico();
        /*
            imprime por consola el tipo de item magico
        */
};

//////////////// clases derivadas de items magicos //////////////////

class baston : public items_magicos
{
    private:

        float largo_baston; // 1 <= largo_baston <= 6

    public:

        baston(float level_magico, float resistencia, float largo_baston, double daño);

        void Get_largo_baston();
        /*
            imprime por consola el largo del baston
        */
};

class libro_de_hechizos : public items_magicos
{
    private:

        float prestigio_libro; // representa la antiguedad del libro. 0 <= prestigio_libro <= 1000

    public:

        libro_de_hechizos(float level_magico, float resistencia, float prestigio, double daño);
        /*
            constructor de la clase libro_de_hechizos. se inicializa con el tipo de arma, el nivel magico, la resistencia a la magia
            oscura, el prestigio del libro y el daño que puede causar
        */

        void Get_prestigio();
        /*
            imprime por consola el nivel de presitigo del libro. (representa la antiguedad del mismo)
        */
};

class pocion : public items_magicos
{
    private:

        float durabilidad_pocion; // 0 <= duracion_pocion <= 26 sg

    public:

        pocion(float level_magico, float resistencia, float durabilidad_pocion, double daño);
        /*
            constructor de la clase pocion. se inicializa con el tipo de arma, el nivel magico, la resistencia a la magia
            oscura, la durabilidad de una pocion y el daño que puede causar
        */

        void Get_durabilidad();
        /*
            imprime por consola la durabilidad de la pocion. representa segundos
        */
};

class amuleto : public items_magicos
{
    private:
        
        float suerte; // 0 <= suerte <= 10

    public:

        amuleto(float level_magico, float resistencia, float capacidad_suerte, double daño);
        /*
            constructor de la clase pocion. se inicializa con el tipo de arma, el nivel magico, la resistencia a la magia
            oscura, el nivel de suerte y el daño que puede causar
        */

        void Get_suerte();
        /*
            imprime por consola el nivel de suerte del amuleto
        */
};