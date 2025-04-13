#include "interfaz_armas.hpp"

////// funciones auxiliares ///////

// valores del daño de las armas magicas y de combate. ([1:5] = daño magico, [6:10] daño de combate)//

vector<double> daño_magicos_combate = {12.5, 13, 14, 10, 9, 16, 13.2, 15, 7.9};

// cant de usos de cada arma magica y de combate. ([1:5] = uso de armas magicas, [6,10] usos de armas de combate )//

vector<int> usos_armas_magicas_combate = {12,11,15,10,13,16,12,9,11};


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
            return "Tipo de arma de desconocido";
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
    
    return min <= valor && valor <= max;
}

