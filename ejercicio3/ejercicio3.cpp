#include "ejercicio3.hpp"


PersonajeFactory::PersonajeFactory()
{
    cout << " se creo el objeto factory" << endl;
}

shared_ptr<arma> PersonajeFactory::crear_arma_factory(armas_totales tipo_arma, float dato1, float dato2, float dato3)
{
    unique_ptr<arma> nueva_arma;

    double daño = daño_magicos_combate[static_cast<int>(tipo_arma)];
    
   nueva_arma = crear_arma(tipo_arma, dato1, dato2, dato3, daño);
    
   shared_ptr<arma> arma_shared = move(nueva_arma);

   return nueva_arma;
}

shared_ptr<personaje> PersonajeFactory::crear_personaje_factory(personajes_totales perso,hab_totales hab_especial, int dato1, float dato_personal)
{
    try
    {
        shared_ptr<personaje> nuevo_personaje;

        if (hechicero3 <= perso <= nigromante3)
        {
            int numero_mago = static_cast<int>(perso);
     
            tipos_magos tipo_mago =static_cast<tipos_magos>(numero_mago);
     
            switch (tipo_mago)
            {
                case a_hechicero:
    
                    nuevo_personaje = make_shared<hechicero>(hab_especial, dato1, 0, dato_personal);
                    break;
                case a_conjurador:
                    nuevo_personaje = make_shared<conjurador>(hab_especial, dato1, 0, dato_personal);
                    break;
                case a_brujo:
                    nuevo_personaje = make_shared<brujo>(hab_especial, dato1, 0, dato_personal);
                    break;
                case a_nigromante:
                    nuevo_personaje = make_shared<nigromante>(hab_especial, dato1, 0, dato_personal);
                    break;
            }
        }
        else if (barbaro3 <= perso <= gladiador3)
        {
            int numero_guerrero = static_cast<int>(perso);
     
            tipos_guerreros tipo_guerrero =static_cast<tipos_guerreros>(numero_guerrero-5);
     
            switch (tipo_guerrero)
            {
                case a_barbaro:
                    nuevo_personaje = make_shared<barbaro>(hab_especial, dato1, 0, dato_personal);
                    break;
                case a_paladin:
                    nuevo_personaje = make_shared<paladin>(hab_especial, dato1, 0, dato_personal);
                    break;
                case a_caballero:
                    nuevo_personaje = make_shared<caballero>(hab_especial, dato1, 0, dato_personal);
                    break;
                case a_mercenario:
                    nuevo_personaje = make_shared<mercenario>(hab_especial, dato1, 0, dato_personal);
                    break;
                case a_gladiador:
                    nuevo_personaje = make_shared<gladiador>(hab_especial, dato1, 0, dato_personal);
                    break;
            }
        }
        else
        {
            throw logic_error("error, ese tipo de personaje no existe");
        }
        return nuevo_personaje;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}