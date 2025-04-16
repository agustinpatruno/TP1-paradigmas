#include "ejercicio3.hpp"

int generarAleatorio(int minimo, int maximo) 
{
    if (minimo > maximo)
    {
        return 0;
    }
    
    return minimo + (rand() % (maximo - minimo + 1));
}

unique_ptr<arma> PersonajeFactory::crear_arma_factory(armas_totales tipo_arma, float dato1, float dato2, float dato3)
{
    try
    {
        unique_ptr<arma> nueva_arma;

        if (tipo_arma < 0 || tipo_arma >= daño_magicos_combate.size()) 
        {
            throw logic_error("error, El tipo de arma está fuera del rango permitido.");
            return nullptr;
        }
    
        double daño = daño_magicos_combate[static_cast<size_t>(tipo_arma)];
        
        switch (tipo_arma)
        {
            case arma_baston:
                nueva_arma = make_unique<baston>(dato1, dato2, dato3, daño);
                break;
            case arma_libro_de_hechizos:
                nueva_arma = make_unique<libro_de_hechizos>(dato1, dato2, dato3, daño);
                break;
            case arma_pocion:
                nueva_arma = make_unique<pocion>(dato1, dato2, dato3, daño);
                break;
            case arma_amuleto:
                nueva_arma = make_unique<amuleto>(dato1, dato2, dato3, daño);
                break;
            case arma_hacha_simple:
                nueva_arma = make_unique<hacha_simple>(dato1, dato2, dato3, daño);
                break;
            case arma_hacha_doble:
                nueva_arma = make_unique<hacha_doble>(dato1, dato2, dato3, daño);
                break;
            case arma_espada:
                nueva_arma = make_unique<espada>(dato1, dato2, dato3, daño);
                break;
            case arma_garrote:
                nueva_arma = make_unique<garrote>(dato1, dato2, dato3, daño);
                break;
            case arma_lanza:
                nueva_arma = make_unique<lanza>(dato1, dato2, dato3, daño);
                break;
            default:
                nueva_arma = nullptr;
                break;
        }
    
       if (!nueva_arma)
        {
            throw logic_error("error, hubo un error en la cracion de la nueva arma, verifique los parametros ingresados");
            return nullptr;
        }
    
       return nueva_arma;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return nullptr;
}

unique_ptr<personaje> PersonajeFactory::crear_personaje_factory(personajes_totales perso,hab_totales hab_especial, int dato1, float dato_personal)
{
    try
    {
        unique_ptr<personaje> nuevo_personaje;

        if (hechicero3 <= perso && perso <= nigromante3)
        {
            int numero_mago = static_cast<int>(perso);
     
            tipos_magos tipo_mago =static_cast<tipos_magos>(numero_mago);
     
            switch (tipo_mago)
            {
                case a_hechicero:
                    nuevo_personaje = make_unique<hechicero>(hab_especial, dato1, 2, dato_personal);
                    break;
                case a_conjurador:
                    nuevo_personaje = make_unique<conjurador>(hab_especial, dato1, 2, dato_personal);
                    break;
                case a_brujo:
                    nuevo_personaje = make_unique<brujo>(hab_especial, dato1, 2, dato_personal);
                    break;
                case a_nigromante:
                    nuevo_personaje = make_unique<nigromante>(hab_especial, dato1, 2, dato_personal);
                    break;
            }
        }
        else if (barbaro3 <= perso && perso <= gladiador3)
        {
            int numero_guerrero = static_cast<int>(perso);
     
            tipos_guerreros tipo_guerrero =static_cast<tipos_guerreros>(numero_guerrero-5);
     
            switch (tipo_guerrero)
            {
                case a_barbaro:
                    nuevo_personaje = make_unique<barbaro>(hab_especial, dato1, 2, dato_personal);
                    break;
                case a_paladin:
                    nuevo_personaje = make_unique<paladin>(hab_especial, dato1, 2, dato_personal);
                    break;
                case a_caballero:
                    nuevo_personaje = make_unique<caballero>(hab_especial, dato1, 2, dato_personal);
                    break;
                case a_mercenario:
                    nuevo_personaje = make_unique<mercenario>(hab_especial, dato1, 2, dato_personal);
                    break;
                case a_gladiador:
                    nuevo_personaje = make_unique<gladiador>(hab_especial, dato1, 2, dato_personal);
                    break;
            }
        }
        else
        {
            throw logic_error("error, ese tipo de personaje no existe");
            return nullptr;
        }
        return nuevo_personaje;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return nullptr;
}

unique_ptr<personaje> PersonajeFactory::crear_personaje_armado_factory(personajes_totales perso,hab_totales hab_especial, int dato1, float dato_personal, armas_totales tip_arma, float dato2, float dato3, float dato4)
{
    try
    {
        unique_ptr<personaje> nuevo_personaje = crear_personaje_factory(perso, hab_especial, dato1, dato_personal);

        if (nuevo_personaje)
        {
            nuevo_personaje -> agregar_arma(tip_arma, dato2, dato3, dato4);
        }
        else
        {
           throw logic_error("error en la cracion del personaje, verifique los parametros ingresados");
            return nullptr;
        }
        return nuevo_personaje;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return nullptr;
}