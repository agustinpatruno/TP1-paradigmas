#include "../includes/abs_combate.hpp"

///////////////////// implementacion de los metodos de la clase abstracta armas_combate //////////////////////////

armas_combate::armas_combate(armas_totales tip_arma, float durabilidad, float precision, double daño)
{
    try
    {
        if (!corroborar_intervalo(1, durabilidad_polvo, 25) && corroborar_intervalo(1, precision, 10) && pertenece_armas_combate(tip_arma) && daño >0)
        {
            tipo_arma = tip_arma;

            durabilidad_polvo = durabilidad;

            precision_disparo = precision;

            Daño = daño;

            cant_usos = usos_armas_magicas_combate[static_cast<size_t>(tip_arma)];
        }
        else
        {
            throw logic_error("error en la creacion de un arma de combate, verifique que los parametros ingresados sean correctos");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void armas_combate::Get_infoarma_general() const
{
    Get_arma_combate();
    cout << " daño del arma de combate: " << Daño << endl;
    cout << " cantidad de usos del arma de combate: " << cant_usos << endl;
}

void armas_combate::Get_info_combate() const
{
    cout << "durabilidad al polvo del arma: "<< durabilidad_polvo << endl;
}

void armas_combate::Get_arma_combate() const
{
    cout << "tipo de arma de combate: " << obtenerNombreArma(tipo_arma) << endl;
}

double armas_combate::retornar_daño() const
{
    return Daño;
}

bool armas_combate::restar_usos()
{
    if (cant_usos > 0)
    {
        cant_usos-=1;
        return false;
    }
    else
    {
        cout << "te has quedado sin golpes disponibles, verifique si quedan golpes especiales" << endl;
        return false;
    }
}

armas_combate::~armas_combate(){}

// implementacion de metodos de la clase derivada hacha simple //

hacha_simple::hacha_simple(float durabilidad, float precision, float filo, double daño)
: armas_combate(arma_hacha_simple, durabilidad, precision, daño), Filo(filo)
{
    try
    {
        if (!corroborar_intervalo(0, filo, 10))
        {
            throw logic_error("error en la creacion de una hacha_simple, ingrese un filo[0,25] mayor a cero");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void hacha_simple::Get_caracteristica_arma() const
{
    cout << "filo del hacha simple: " << Filo << endl;
}

// implementacion de metodos de la clase derivada hacha doble //

hacha_doble::hacha_doble(float durabilidad, float precision, float longitud, double daño)
: armas_combate(arma_hacha_doble, durabilidad, precision, daño), longitud_alcanze(longitud)
{
    try
    {
        if (!corroborar_intervalo(0, longitud, 25))
        {
            throw logic_error("error en la creacion de un hacha doble, ingrese una longitud[0,25] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void hacha_doble::Get_caracteristica_arma() const
{
    cout << "longitud de alcanza del hacha doble:" << longitud_alcanze << endl;
}

// implementacion de metodos de la clase derivada espada //

espada::espada(float durabilidad, float precision, float corte, double daño)
: armas_combate(arma_espada, durabilidad, precision, daño), nivel_corte(corte)
{
    try
    {
        if (!corroborar_intervalo(0, corte, 10) )
        {
            throw logic_error("error en la cracion de una espada, ingrese un nivel de corte[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void espada::Get_caracteristica_arma() const
{
    cout << "nivel de corte de la espada: " << nivel_corte << endl;
}

// implementacion de metodos de la clase lanza //

lanza::lanza(float durabilidad, float precision, float alcanze, double daño)
: armas_combate(arma_lanza, durabilidad, precision, daño), distancia_alcanze(alcanze)
{
    try
    {
        if (!corroborar_intervalo(static_cast<float>(0), alcanze,static_cast<float>(20)))
        {
            throw logic_error("error en la creacion de una lanza, ingrese una distancia de alcanze[0,20] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void lanza::Get_caracteristica_arma() const
{
    cout << "distancia de alcanze de la espada: " << distancia_alcanze << endl;
}

// implementacion de metodos de la clase garrote //

garrote::garrote(float durabilidad, float precision, float peso, double daño)
: armas_combate(arma_garrote, durabilidad, precision, daño), peso_garrote(peso)
{
    try
    {
        if (!corroborar_intervalo(static_cast<float>(0), peso,static_cast<float>(50)))
        {
            throw logic_error("error en la creacion de un garrote, ingrese un peso del garrote[0,50] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void garrote::Get_caracteristica_arma() const
{
    cout << "peso del garrote: " << peso_garrote << endl;
}
