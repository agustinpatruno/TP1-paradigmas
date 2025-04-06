#include "interfaz_armas.hpp"

bool pertenece_en_magicos(string tipo_arma)
{
    vector<string> tipos_armas = {"bastón", "libro de hechizos", "poción" , "amuleto"};

    for (int i = 0; i < tipos_armas.size(); i++)
    {
        if (tipo_arma == tipos_armas[i])
        {
            return true;
        }
    }
    return false;
}

bool pertenece_en_combate(string tipo_arma)
{
    vector<string> tipos_armas = { "hacha simple","hacha doble","espada","lanza","garrote"};

    for (int i = 0; i < tipos_armas.size(); i++)
    {
        if (tipos_armas[i] == tipo_arma)
        {
            return true;
        }
    }
    return false;
}

bool pertenece_habilidad_espe_magico(string habilidad_especial)
{
    vector<string> habilidades = {"Explosión arcana","Golpe elemental","Corte espectral","Encantamiento explosivo","Ráfaga mágica"};

    for (int i = 0; i < habilidades.size(); i++)
    {
        if (habilidad_especial == habilidades[i])
        {
            return true;
        }
    }
    return false;
}

bool pertenece_habilidad_espe_combate(string habilidad_combate)
{
    vector<string> habilidades = {"Impacto devastador","Corte giratorio","Golpe perforante","Ataque ensordecedor","Ruptura elemental"};

    for (int i = 0; i < habilidades.size(); i++)
    {
        if (habilidad_combate == habilidades[i])
        {
            return true;
        }
    }
    return false;
}

/////////////////////////////////////////////implementacion de metodos de la clase items magicos//////////////////////////////////////

void items_magicos::restar_usos(bool normal)
{
    try
    {
        if (normal)
        {
            if (cant_golpes_disponibles > 0)
            {
                cant_golpes_disponibles-=1;
            }
            else
            {
                throw logic_error("error, te has quedado sin golpes disponibles, verifique si quedan golpes especiales");
            }
        }
        if (cant_golpes_especial > 0)
        {
            cant_golpes_especial-=1;
        }
        else
        {
            throw logic_error("error, te has quedado sin golpes espceciales");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

items_magicos::items_magicos(string tip_arma, double daño, int cant_golpes_dispo, string habilidad_espe, double daño_extra_espe, int cant_golpes_espe)
{
    try
    {
        if (pertenece_en_magicos(tip_arma) && daño > 0 && cant_golpes_dispo > 0 && (pertenece_habilidad_espe_magico(habilidad_espe) || pertenece_habilidad_espe_combate(habilidad_espe)) && daño_extra_espe > 0 && cant_golpes_espe > 0)
        {
           tipo_arma = tip_arma;

           cant_golpes_disponibles = cant_golpes_dispo;

           habilidad_especial = habilidad_espe;

           cant_golpes_especial = cant_golpes_espe;

            daño = daño;

            if (pertenece_habilidad_espe_magico(habilidad_espe))
            {
                daño_extra_especial = daño_extra_espe;
            }
            else
            {
                daño_extra_especial = daño_extra_espe*(0.6);
            }
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

void items_magicos::mostrar_tipo_arma()
{
    cout << "tipo de item magico " << tipo_arma << endl;
}

void items_magicos::mostrar_daño()
{
    cout << " poder de daño del item magico: " << Daño << endl;
}

void items_magicos::mostrar_golpes_disponibles()
{
    cout << "cantidadd de golpes_disponibles: " << cant_golpes_disponibles << endl;
}

void items_magicos::mostrar_habilidad_especial()
{
    cout << "habilidad especial: " << habilidad_especial << endl;
}

void items_magicos::mostrar_golpes_dispo_especial()
{
    cout << "golpes disponibles de la habilidad especial: " << cant_golpes_especial << endl;
}

double items_magicos::devolver_daño(bool normal)
{
    restar_usos(normal);
    if (normal)
    {
        return Daño;
    }
    return Daño + daño_extra_especial;
}

//////////////////////////////////////////implementacion metodos de la clase de combate //////////////////////////////////////////

void armas_combate::restar_usos(bool normal)
{
    try
    {
        if (normal)
        {
            if (cant_golpes_disponibles > 0)
            {
                cant_golpes_disponibles-=1;
            }
            else
            {
                throw logic_error("error, te has quedado sin golpes disponibles, verifique si quedan golpes especiales");
            }
        }
        if (cant_golpes_especial > 0)
        {
            cant_golpes_especial-=1;
        }
        else
        {
            throw logic_error("error, te has quedado sin golpes espceciales");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

armas_combate::armas_combate(string tip_arma, double daño, int cant_golpes_dispo, string habilidad_espe, double daño_extra_espe, int cant_golpes_espe)
{
    try
    {
        if (pertenece_en_combate(tip_arma) && daño > 0 && cant_golpes_dispo > 0 && (pertenece_habilidad_espe_magico(habilidad_espe) || pertenece_habilidad_espe_combate(habilidad_espe)) && daño_extra_espe > 0 && cant_golpes_espe > 0)
        {
           tipo_arma = tip_arma;

           cant_golpes_disponibles = cant_golpes_dispo;

           habilidad_especial = habilidad_espe;

           cant_golpes_especial = cant_golpes_espe;

            daño = daño;

            if (pertenece_habilidad_espe_combate(habilidad_espe))
            {
                daño_extra_especial = daño_extra_espe;
            }
            else
            {
                daño_extra_especial = daño_extra_espe*(0.6);
            }
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

void armas_combate::mostrar_tipo_arma()
{
    cout << "tipo de arma de combate: " << tipo_arma << endl;
}

void armas_combate::mostrar_daño()
{
    cout << " poder de daño del arma de combate: " << Daño << endl;
}

void armas_combate::mostrar_golpes_disponibles()
{
    cout << " cantidad de golpes disponibles: " << endl;
}

void armas_combate::mostrar_habilidad()
{
    cout << " habilidad especial: " << habilidad_especial << endl;
}

void armas_combate::mostrar_golpes_dispo_especial()
{
    cout << "cantidad de golpes disponibles de la habilidad especial: " << cant_golpes_especial << endl;
}

double armas_combate::devolver_daño(bool normal)
{
    restar_usos(normal);
    if (normal)
    {
        return Daño;
    }
    return Daño + daño_extra_especial;
}