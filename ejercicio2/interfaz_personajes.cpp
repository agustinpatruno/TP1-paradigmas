#include "interfaz_personajes.hpp"

// funcion para el enum de tipo_magos

string getTipoMago(tipos_magos tipo) {
    switch (tipo) {
        case a_hechicero: return "hechicero";
        case a_conjurador: return "conjurador";
        case a_brujo: return "brujo";
        case a_nigromante: return "nigromante";
        default: return "tipo desconocido";
    }
}

// Función para el enum de tipos_guerreros

string getTipoGuerrero(tipos_guerreros tipo) {
    switch (tipo) {
        case a_barbaro: return "barbaro";
        case a_paladin: return "paladin";
        case a_caballero: return "caballero";
        case a_mercenario: return "mercenario";
        case a_gladiador: return "gladiador";
        default: return "tipo desconocido";
    }
}

// Función para el enum de hab_totales, retorna el string del valor del enum pasado por parametro. caso contrario retorna 
// "habilidad desconocida"

string getHabilidad(hab_totales habilidad) {
    switch (habilidad) {
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
        default: return "habilidad desconocida";
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

            return make_unique<baston>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        case arma_libro_de_hechizos:
            return make_unique<libro_de_hechizos>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        case arma_pocion:
            return make_unique<pocion>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        case arma_amuleto:
            return make_unique<amuleto>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        case arma_hacha_simple:
            return make_unique<hacha_simple>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        case arma_hacha_doble:
            return make_unique<hacha_doble>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        case arma_espada:
            return make_unique<espada>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        case arma_garrote:
            return make_unique<garrote>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        break;
    
    default:
        return nullptr;
        break;
    }
}

int main()
{
    cout << " se ejecuto correctamente interfaz personajes" << endl;
}
