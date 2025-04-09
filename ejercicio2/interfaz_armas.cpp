#include "interfaz_armas.hpp"

bool pertenece_en_magicos(armas_magicas_y_combate arma)
{
    return arma >= baston && arma <= amuleto;
}

bool pertenece_en_combate(armas_magicas_y_combate arma)
{
    return arma >= hacha_simple && garrote <= arma;
}

bool pertenece_habilidad_espe_magico(habilidades_especiales_magicas_y_combate habilidad)
{
    return  Explosion_arcana <= habilidad &&  habilidad <= Rafaga_magica;
}

bool pertenece_habilidad_espe_combate(habilidades_especiales_magicas_y_combate habilidad)
{
    return  Impacto_devastador <= habilidad &&  habilidad <= Ruptura_elemental;
}

string enum_a_string_armas(armas_magicas_y_combate arma) {
    switch (arma) 
    {
        case baston: return "baston";

        case libro_de_hechizos: return "libro_de_hechizos";

        case pocion: return "pocion";

        case amuleto: return "amuleto";

        case hacha_simple: return "hacha_simple";

        case hacha_doble: return "hacha_doble";

        case espada: return "espada";

        case lanza: return "lanza";

        case garrote: return "garrote";

        default: return "Valor desconocido";
    }
}

string enum_a_string_habilidades(habilidades_especiales_magicas_y_combate habilidad) {
    switch (habilidad) 
    {
        case Explosion_arcana: return "Explosion_arcana";

        case Golpe_elemental: return "Golpe_elemental";

        case Corte_espectral: return "Corte_espectral";

        case Encantamiento_explosivo: return "Encantamiento_explosivo";

        case Rafaga_magica: return "Rafaga_magica";

        case Impacto_devastador: return "Impacto_devastador";

        case Corte_giratorio: return "Corte_giratorio";

        case Golpe_perforante: return "Golpe_perforante";

        case Ataque_ensordecedor: return "Ataque_ensordecedor";

        case Ruptura_elemental: return "Ruptura_elemental";

        default: return "Valor desconocido";
    }
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

items_magicos::items_magicos(armas_magicas_y_combate tip_arma, double daño, int cant_golpes_dispo, habilidades_especiales_magicas_y_combate habilidad_espe, double daño_extra_espe, int cant_golpes_espe)
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
    cout << "tipo de item magico " << enum_a_string_armas(tipo_arma) << endl;
}

void items_magicos::mostrar_daño()
{
    cout << " poder de daño del item magico: " << Daño << endl;
}

void items_magicos::mostrar_daño_especial()
{
    cout << " poder de daño del item magico: " << Daño + daño_extra_especial << endl;
}

void items_magicos::mostrar_golpes_disponibles()
{
    cout << "cantidadd de golpes_disponibles: " << cant_golpes_disponibles << endl;
}

void items_magicos::mostrar_habilidad_especial()
{
    cout << "habilidad especial: " << enum_a_string_habilidades(habilidad_especial) << endl;
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

armas_combate::armas_combate(armas_magicas_y_combate tip_arma, double daño, int cant_golpes_dispo, habilidades_especiales_magicas_y_combate habilidad_espe, double daño_extra_espe, int cant_golpes_espe)
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
    cout << "tipo de arma de combate: " << enum_a_string_armas(tipo_arma) << endl;
}

void armas_combate::mostrar_daño()
{
    cout << " poder de daño del arma de combate: " << Daño << endl;
}

void armas_combate::mostrar_daño_especial()
{
    cout << " poder de daño del arma de combate: " << Daño + daño_extra_especial << endl;
}

void armas_combate::mostrar_golpes_disponibles()
{
    cout << " cantidad de golpes disponibles: " << endl;
}

void armas_combate::mostrar_habilidad()
{
    cout << " habilidad especial: " << enum_a_string_habilidades(habilidad_especial) << endl;
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