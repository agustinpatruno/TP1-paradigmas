#include "../includes/interfaz_armas.hpp"

////// funciones auxiliares ///////

// valores del daño de las armas magicas y de combate. ([0:3] = daño magico, [4:8] daño de combate)//

vector<double> daño_magicos_combate = {12.5, 13.0, 14.0, 10.0, 9.0, 16.0, 13.2, 15.0, 7.9};

// cant de usos de cada arma magica y de combate. ([0:3] = uso de armas magicas, [4,8] usos de armas de combate )//

vector<int> usos_armas_magicas_combate = {12,11,15,10,13,16,12,9,11};

string obtenerNombreArma(armas_totales tipo)
{
    switch (tipo)
    {
        case arma_baston:
            return "Bastón";
            break;
        case arma_libro_de_hechizos:
            return "Libro de Hechizos";
            break;
        case arma_pocion:
            return "Poción";
            break;
        case arma_amuleto:
            return "Amuleto";
            break;
        case arma_hacha_simple:
            return "Hacha Simple";
            break;
        case arma_hacha_doble:
            return "Hacha Doble";
            break;
        case arma_espada:
            return "Espada";
            break;
        case arma_lanza:
            return "Lanza";
            break;
        case arma_garrote:
            return "Garrote";
            break;
        default:
            return "Tipo de arma de desconocido";
            break;
    }
}

bool pertenece_armas_magicas(armas_totales tipo_arma)
{
    return arma_baston <= tipo_arma && tipo_arma <= arma_amuleto;
}

bool pertenece_armas_combate(armas_totales tipo_arma)
{
    return arma_hacha_simple <= tipo_arma && tipo_arma <= arma_garrote;
}

bool corroborar_intervalo(float min, float valor, float max)
{
    if (max < min)
    {
        return false;
    }
    
    return min <= valor && valor <= max;
}

