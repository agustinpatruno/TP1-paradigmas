#include "interfaz_armas.hpp"

////// funciones auxiliares ///////

string obtenerNombreArma(armas_totales tipo)
{
    switch (tipo)
    {
        case arma_baston:
            return "Bastón";
        case arma_libro_de_hechizos:
            return "Libro de Hechizos";
        case arma_pocion:
            return "Poción";
        case arma_amuleto:
            return "Amuleto";
        case arma_hacha_simple:
            return "Hacha Simple";
        case arma_hacha_doble:
            return "Hacha Doble";
        case arma_espada:
            return "Espada";
        case arma_lanza:
            return "Lanza";
        case arma_garrote:
            return "Garrote";
        default:
            return "Tipo de arma de combate desconocido";
    }
}

bool pertenece_armas_magicas(armas_totales tipo_arma)
{
    return arma_baston <= tipo_arma <= arma_amuleto;
}

bool pertenece_armas_combate(armas_totales tipo_arma)
{
    return arma_hacha_simple <= tipo_arma <= arma_garrote;
}

bool corroborar_intervalo(int min, float valor, int max)
{
    if (max < min)
    {
        return false;
    }
    
    return min <= valor <= max;
}

/////////////////////////////////////////////implementacion de metodos de la clase items magicos//////////////////////////////////////

void items_magicos::restar_usos(bool normal)
{
    try
    {
        if (normal)
        {
            if (cant_usos > 0)
            {
                cant_usos-=1;
            }
            else
            {
                throw logic_error("error, te has quedado sin golpes disponibles, verifique si quedan golpes especiales");
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

items_magicos::items_magicos(armas_totales tip_arma, float level_magico, float resistencia, double daño)
{
    try
    {
        if (corroborar_intervalo(1,nivel_magico,10) &&  corroborar_intervalo(1, resistencia, 10) && pertenece_armas_magicas(tip_arma) && daño > 0)
        {
            tipo_arma = tip_arma;

            Daño = daño;

            cant_usos = usos_armas_magicas_combate[static_cast<int>(tip_arma)];

            this->nivel_magico = level_magico;

            this->resistencia_magia_oscura = resistencia;
        }
        else
        {
            throw logic_error("error, verifique que los parametros ingresados esten dentro de los rangos");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void items_magicos::Get_infoarma_general() const
{
    cout << "daño del arma magica: " << Daño;
    cout << "cantidad de usos del arma magica: " << cant_usos;
}

void items_magicos::Get_info_magia()
{
    cout << "nivel de magia: " << nivel_magico;
    cout << "resistencia a la magia oscura: " << resistencia_magia_oscura << endl;
}

void items_magicos::Get_item_magico()
{
    cout << "tipo de item magico: " << obtenerNombreArma(tipo_arma) << endl;
}


// implementacion de metodos de la clase derivada baston //


baston::baston(armas_totales tip_arma, float level_magico, float resistencia, float long_baston, double daño)
: items_magicos(tip_arma, level_magico, resistencia, daño), largo_baston(long_baston)
{
    try
    {
        if (!corroborar_intervalo(0, long_baston, 6))
        {
            throw std::invalid_argument("error, ingrese un largo de baston[0,10] dentro del intervalo");
        }   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void baston::Get_largo_baston()
{
    cout << "largo del baston: " << largo_baston << endl;
}

// implementacion de metodos de la clase derivada libro_de_hechizos //

libro_de_hechizos::libro_de_hechizos(armas_totales tip_arma, float level_magico, float resistencia, float prestigio, double daño)
: items_magicos(tip_arma, level_magico, resistencia, daño), prestigio_libro(prestigio)
{
    try
    {
        if (!corroborar_intervalo(0, prestigio_libro, 10))
        {
            throw std::invalid_argument(" error, ingrese un valor de prestigio[0,10] dentro del intervalo");
        }   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void libro_de_hechizos::Get_prestigio()
{
    cout << "prestigio del libro de hechizos: " << prestigio_libro << endl;
}

// implementacion de metodos de la clase derivada pocion //

pocion::pocion(armas_totales tip_arma, float level_magico, float resistencia, float duracion_pocion, double daño)
: items_magicos(tip_arma, level_magico, resistencia, daño), durabilidad_pocion(duracion_pocion)
{
    try
    {
        if (!corroborar_intervalo(0, duracion_pocion, 25))
        {
            throw std::invalid_argument(" error, ingrese una duracion de la pocion[0,25] dentro del intervalo");
        }   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void pocion::Get_durabilidad()
{
    cout << "durabilidad de la pocion: " << durabilidad_pocion << endl;
}

// implementacion de metodos de la clase derivada amuleto //

amuleto::amuleto(armas_totales tip_arma, float level_magico, float resistencia, float capacidad_suerte, double daño)
: items_magicos(tip_arma, level_magico, resistencia, daño), suerte(capacidad_suerte)
{
    try
    {
        if (!corroborar_intervalo(0, suerte, 10))
        {
            throw std::invalid_argument(" error, ingrese una poder de suerte[0,10] dentro del intervalo");
        }   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void amuleto::Get_suerte()
{
    cout << "suerte del amuleto: " << suerte;
}

////////////////////////////// implementacion de los metodos de la clase abstracta armas_combate ////////////////////////////////////////

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

            cant_usos = usos_armas_magicas_combate[static_cast<int>(tip_arma)];
        }
        else
        {
            throw logic_error("error, verifique que los parametros ingresados sean correctos");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void armas_combate::Get_infoarma_general() const
{
    cout << " daño del arma de combate " << Daño << endl;
    cout << " cantidad de usos del arma magica: " << cant_usos << endl;
}

void armas_combate::Get_info_combate()
{
    cout << "durabilidad al polvo del arma "<< durabilidad_polvo << endl;
}

void armas_combate::Get_arma_combate()
{
    cout << "tipo de arma de combate: " << obtenerNombreArma(tipo_arma) << endl;
}

// implementacion de metodos de la clase derivada hacha simple //

hacha_simple::hacha_simple(armas_totales tip_arma, float durabilidad, float precision, float filo, double daño)
: armas_combate(tip_arma, durabilidad, precision, daño), Filo(filo)
{
    try
    {
        if (!corroborar_intervalo(0, filo, 10))
        {
            throw logic_error("error, ingrese un filo[0,25] mayor a cero");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void hacha_simple::Get_filo()
{
    cout << "filo del hacha simple: " << Filo << endl;
}

// implementacion de metodos de la clase derivada hacha doble //

hacha_doble::hacha_doble(armas_totales tip_arma, float durabilidad, float precision, float filo, float longitud, double daño)
: armas_combate(tip_arma, durabilidad, precision, daño), Filo(filo), longitud_alcanze(longitud)
{
    try
    {
        if (!corroborar_intervalo(0, filo, 10) || !corroborar_intervalo(0, longitud, 25))
        {
            throw logic_error("error, ingrese un filo[0,10] y una longitud[0,25] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void hacha_doble::Get_filo()
{
    cout << "filo del hacha doble:" << Filo << endl;
}

void hacha_doble::Get_longitud_alcanze()
{
    cout << "longitud de alcanza del hacha doble:" << longitud_alcanze << endl;
}

// implementacion de metodos de la clase derivada espada //

espada::espada(armas_totales tip_arma, float durabilidad, float precision, float corte, double daño)
: armas_combate(tip_arma, durabilidad, precision, daño), nivel_corte(corte)
{
    try
    {
        if (!corroborar_intervalo(0, corte, 10) )
        {
            throw logic_error("error, ingrese un nivel de corte[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void espada::Get_nivel_corte()
{
    cout << "nivel de corte de la espada: " << nivel_corte << endl;
}

// implementacion de metodos de la clase lanza //

lanza::lanza(armas_totales tip_arma, float durabilidad, float precision, float alcanze, double daño)
: armas_combate(tip_arma, durabilidad, precision, daño), distancia_alcanze(alcanze)
{
    try
    {
        if (!corroborar_intervalo(0, alcanze, 20) )
        {
            throw logic_error("error, ingrese una distancia de alcanze[0,20] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void lanza::Get_distancia_alcanza()
{
    cout << "distancia de alcanze de la espada: " << distancia_alcanze << endl;
}

// implementacion de metodos de la clase garrote //

garrote::garrote(armas_totales tip_arma, float durabilidad, float precision, float peso, double daño)
: armas_combate(tip_arma, durabilidad, precision, daño), peso__garrote(peso)
{
    try
    {
        if (!corroborar_intervalo(0, peso, 50) )
        {
            throw logic_error("error, ingrese un peso del garrote[0,50] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void garrote::Get_peso()
{
    cout << "peso del garrote: " << peso__garrote << endl;
}