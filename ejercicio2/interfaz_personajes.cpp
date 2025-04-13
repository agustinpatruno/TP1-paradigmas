#include "interfaz_personajes.hpp"

/* valores de los daños extra de las habilidades especiales magicas y las de combate([1:5] = daño magicas, [6:10] = daño de combate) */

vector<double> daño_hab_magicos_combate = {5.4, 3.7, 8.2, 6.6, 5, 3.7, 5.3, 7, 4.2, 9};

/* cant de usos de las habilidades especiales magicas y de combate ([1:5] = usos magicas, [6:10] = usos de combate)*/

vector<int> usos_hab_magicas_combate = {3,2,4,1,5,5,3,2,4,3};

// funcion para el enum de tipo_magos

string getTipoMago(tipos_magos tipo) {
    switch (tipo) 
    {
        case a_hechicero: 
            return "hechicero";
            break;
        case a_conjurador: 
            return "conjurador";
            break;
        case a_brujo: 
            return "brujo";
            break;
        case a_nigromante: 
            return "nigromante";
            break;
        default: 
            return "tipo desconocido";
            break;
    }
}

// Función para el enum de tipos_guerreros

string getTipoGuerrero(tipos_guerreros tipo) {

    switch (tipo) 
    {
        case a_barbaro: 
            return "barbaro";
            break;
        case a_paladin: 
            return "paladin";
            break;
        case a_caballero: 
            return "caballero";
            break;
        case a_mercenario: 
            return "mercenario";
            break;
        case a_gladiador: 
            return "gladiador";
            break;
        default: 
            return "tipo desconocido";
            break;
    }
}

// Función para el enum de hab_totales, retorna el string del valor del enum pasado por parametro. caso contrario retorna 
// "habilidad desconocida"

string getHabilidad(hab_totales habilidad) {
    
    switch (habilidad) 
    {
        case Explosion_arcana: 
            return "Explosion_arcana";
            break;
        case Golpe_elemental: 
            return "Golpe_elemental";
            break;
        case Corte_espectral: 
            return "Corte_espectral";
            break;
        case Encantamiento_explosivo: 
            return "Encantamiento_explosivo";
            break;
        case Rafaga_magica: 
            return "Rafaga_magica";
            break;
        case Impacto_devastador: 
            return "Impacto_devastador";
            break;
        case Corte_giratorio: 
            return "Corte_giratorio";
            break;
        case Golpe_perforante: 
            return "Golpe_perforante";
            break;
        case Ataque_ensordecedor: 
            return "Ataque_ensordecedor";
            break;
        case Ruptura_elemental: 
            return "Ruptura_elemental";
            break;
        default: 
            return "habilidad desconocida";
            break;
    }
}

bool pertenece_hab_magicas(hab_totales habilidad)
{
    return habilidad >= Explosion_arcana && habilidad <= Rafaga_magica;
}

unique_ptr<arma> crear_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3, double daño)
{
    switch (tipo_arma)
    {
        case arma_baston:
            return make_unique<baston>(dato1, dato2, dato3, daño);
            break;
        case arma_libro_de_hechizos:
            return make_unique<libro_de_hechizos>(dato1, dato2, dato3, daño);
            break;
        case arma_pocion:
            return make_unique<pocion>(dato1, dato2, dato3, daño);
            break;
        case arma_amuleto:
            return make_unique<amuleto>(dato1, dato2, dato3, daño);
            break;
        case arma_hacha_simple:
            return make_unique<hacha_simple>(dato1, dato2, dato3, daño);
            break;
        case arma_hacha_doble:
            return make_unique<hacha_doble>(dato1, dato2, dato3, daño);
            break;
        case arma_espada:
            return make_unique<espada>(dato1, dato2, dato3, daño);
            break;
        case arma_garrote:
            return make_unique<garrote>(dato1, dato2, dato3, daño);
            break;
        case arma_lanza:
            return make_unique<lanza>(dato1, dato2, dato3, daño);
            break;
        default:
            return nullptr;
            break;
    }
}
