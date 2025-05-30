#include "../includes/abs_items.hpp"

/////////////////////////////////////////////implementacion de metodos de la clase items magicos//////////////////////////////////////

items_magicos::items_magicos(armas_totales tip_arma, float level_magico, float resistencia, double daño)
{
    try
    {
        if (corroborar_intervalo(1,level_magico,10) && corroborar_intervalo(1, resistencia, 100) && pertenece_armas_magicas(tip_arma) && daño > 0)
        {
            tipo_arma = tip_arma;

            Daño = daño;

            cant_usos = usos_armas_magicas_combate[static_cast<size_t>(tip_arma)];

            this->nivel_magico = level_magico;

            this->resistencia_magia_oscura = resistencia;
        }
        else
        {
            throw logic_error("error, verifique que los parametros ingresados sean correctos");
        }
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
    }
}

void items_magicos::Get_infoarma_general() const
{
    Get_item_magico();
    cout << "daño del arma magica: " << Daño << endl;
    cout << "cantidad de usos del arma magica: " << cant_usos << endl;
}

void items_magicos::Get_info_magia() const
{
    cout << "nivel de magia: " << nivel_magico << endl;
    cout << "resistencia a la magia oscura: " << resistencia_magia_oscura << endl;
}

void items_magicos::Get_item_magico() const
{
    cout << "tipo de item magico: " << obtenerNombreArma(tipo_arma) << endl;
}

double items_magicos::retornar_daño() const 
{
    return Daño;
}

bool items_magicos::restar_usos()
{
    if (cant_usos > 0)
    {
        cant_usos-=1;
        return true;
    }
    else
    {
       cout << "te has quedado sin golpes disponibles, verifique si quedan golpes especiales" << endl;
       return false;
    }
}

items_magicos::~items_magicos(){}

///////////////// implementacion de metodos de la clase derivada baston //////////////////////

baston::baston(float level_magico, float resistencia, float long_baston, double daño)
: items_magicos(arma_baston, level_magico, resistencia, daño), largo_baston(long_baston)
{
    try
    {
        if (!corroborar_intervalo(1, long_baston, 6))
        {
            throw logic_error("error en la creacion de un baston, verifique que los parametros ingresados esten dentro del rango. long_baston[0,6]");
        }   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void baston::Get_caracteristica_arma_magica() const
{
    cout << "largo del baston: " << largo_baston << endl;
}

// implementacion de metodos de la clase derivada libro_de_hechizos //

libro_de_hechizos::libro_de_hechizos(float level_magico, float resistencia, float prestigio, double daño)
: items_magicos(arma_libro_de_hechizos, level_magico, resistencia, daño), prestigio_libro(prestigio)
{
    try
    {
        if (!corroborar_intervalo(0, prestigio_libro, 1000))
        {
            throw logic_error(" error en la creacion de un libro de hechizos, ingrese un valor de prestigio[0,1000] dentro del intervalo");
        }   
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
}

void libro_de_hechizos::Get_caracteristica_arma_magica() const
{
    cout << "prestigio del libro de hechizos: " << prestigio_libro << endl;
}

// implementacion de metodos de la clase derivada pocion //

pocion::pocion(float level_magico, float resistencia, float duracion_pocion, double daño)
: items_magicos(arma_pocion, level_magico, resistencia, daño), durabilidad_pocion(duracion_pocion)
{
    try
    {
        if (!corroborar_intervalo(0, duracion_pocion, 25))
        {
            throw logic_error(" error en la creacion de una pocion, ingrese una duracion de la pocion[0,25] dentro del intervalo");
        }   
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
}

void pocion::Get_caracteristica_arma_magica() const
{
    cout << "durabilidad de la pocion: " << durabilidad_pocion << endl;
}

// implementacion de metodos de la clase derivada amuleto //

amuleto::amuleto(float level_magico, float resistencia, float capacidad_suerte, double daño)
: items_magicos(arma_amuleto, level_magico, resistencia, daño), suerte(capacidad_suerte)
{
    try
    {
        if (!corroborar_intervalo(0, suerte, 10))
        {
            throw logic_error("error en la creacion de un amuleto, ingrese una poder de suerte[0,10] dentro del intervalo");
        }   
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
}

void amuleto::Get_caracteristica_arma_magica() const
{
    cout << "suerte del amuleto: " << suerte << endl;
}
