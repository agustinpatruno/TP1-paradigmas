#include "ejercicio3.hpp"

int generarAleatorio(int minimo, int maximo) 
{
    if (minimo > maximo)
    {
        return 0;
    }
    
    return minimo + (rand() % (maximo - minimo + 1));
}

////////////////////////////////////////implementacion de los metodos de personaje armado//////////////////////////////////////////////

void crear_personajes()
{
    int cant_magos = generarAleatorio(3,7);
    cout << "numero aleatorio de la cantidad de magos" << endl;

    int cant_guerreros = generarAleatorio(3,7);
    cout << "numero aleatorio de la cantidad de guerreros" << endl;

    vector<shared_ptr<mago>> magos;

    vector<shared_ptr<guerrero>> guerreros;

    for (int i = 0; i < cant_magos; i++)
    {
        int numero_mago = generarAleatorio(1,4); // valor aleatoria que representa el numero de mago en el enum de tipos_magos

        int numero_habilidad = generarAleatorio(1,10); // valor aleatorio que representa la habilidad del mago

        int cant_armas = generarAleatorio(0,2); // valor aleatorio que representa la cantidad de armas

        int dato1 = generarAleatorio(1,10); // valor aleatorio que representa la magia

        int dato_personal = generarAleatorio(1,10); // valor aleatorio que representa el dato particular de cada clase derivada
    
        tipos_magos tipo_mago = static_cast<tipos_magos>(numero_mago); // casteo del tipo de mago

        hab_totales habilidad = static_cast<hab_totales>(numero_habilidad); // casteo de la habilidad especial 

        shared_ptr<mago> nuevo_mago;

        switch (tipo_mago)
        {
            case a_hechicero:
                nuevo_mago = make_shared<hechicero>(habilidad, dato1, cant_armas, dato_personal);
                break;
            case a_conjurador:
                nuevo_mago = make_shared<conjurador>(habilidad, dato1, cant_armas, dato_personal);
                break;
            case a_brujo:
                nuevo_mago = make_shared<brujo>(habilidad, dato1, cant_armas, dato_personal);
                break;
            case a_nigromante:
                nuevo_mago = make_shared<nigromante>(habilidad, dato1, cant_armas, dato_personal);
                break;
        }

        if (cant_armas != 0)
        {
            int random_arma = generarAleatorio(1,9);
            // datos adicionales del arma
            int da1 = generarAleatorio(1,10);
            int da2 = generarAleatorio(1,10);
            int da3 = generarAleatorio(1,10);

            nuevo_mago ->agregar_arma(static_cast<armas_totales>(random_arma), da1, da2, da3);   
            
            if ( cant_armas == 2)
            {
                int random_arma2 = generarAleatorio(1,9);
                // datos adicionales del arma
                int d1 = generarAleatorio(1,10);
                int d2 = generarAleatorio(1,10);
                int d3 = generarAleatorio(1,10);

                nuevo_mago ->agregar_arma(static_cast<armas_totales>(random_arma2), d1, d2, d3);   
            }
        }  
    }

    for (int i = 0; i < cant_guerreros; i++)
    {
        int numero_guerrero = generarAleatorio(1,5); // valor aleatoria que representa el numero de guerrero en el enum de tipos_magos

        int numero_habilidad = generarAleatorio(1,10); // valor aleatorio que representa la habilidad del guerrero

        int cant_armas = generarAleatorio(0,2); // valor aleatorio que representa la cantidad de armas

        int dato1 = generarAleatorio(1,10); // valor aleatorio que representa la magia

        int dato_personal = generarAleatorio(1,10); // valor aleatorio que representa el dato particular de cada clase derivada
    
        tipos_guerreros tipo_guerrero = static_cast<tipos_guerreros>(numero_guerrero); // casteo del tipo de guerrero

        hab_totales habilidad = static_cast<hab_totales>(numero_habilidad); // casteo de la habilidad especial 

        shared_ptr<guerrero> nuevo_guerrero;

        switch (tipo_guerrero)
        {
            case a_barbaro:
                nuevo_guerrero = make_shared<barbaro>(habilidad, dato1, cant_armas, dato_personal);
                break;
            case a_paladin:
                nuevo_guerrero = make_shared<paladin>(habilidad, dato1, cant_armas, dato_personal);
                break;
            case a_caballero:
                nuevo_guerrero = make_shared<caballero>(habilidad, dato1, cant_armas, dato_personal);
                break;
            case a_mercenario:
                nuevo_guerrero = make_shared<mercenario>(habilidad, dato1, cant_armas, dato_personal);
                break;
            case a_gladiador:
                nuevo_guerrero = make_shared<gladiador>(habilidad, dato1, cant_armas, dato_personal);
                break;
        }

        if (cant_armas != 0)
        {
            int random_arma = generarAleatorio(1,9);
            // datos adicionales del arma
            int da1 = generarAleatorio(1,10);
            int da2 = generarAleatorio(1,10);
            int da3 = generarAleatorio(1,10);

            nuevo_guerrero ->agregar_arma(static_cast<armas_totales>(random_arma), da1, da2, da3);   
            
            if ( cant_armas == 2)
            {
                int random_arma2 = generarAleatorio(1,9);
                // datos adicionales del arma
                int d1 = generarAleatorio(1,10);
                int d2 = generarAleatorio(1,10);
                int d3 = generarAleatorio(1,10);

                nuevo_guerrero ->agregar_arma(static_cast<armas_totales>(random_arma2), d1, d2, d3);   
            }
        }  
    }
    
    for (int i = 0; i < guerreros.size(); i++)
    {
        guerreros[i] -> mostrar_info_personaje();
    }
    
    for (int i = 0; i < magos.size(); i++)
    {
        magos[i] -> mostrar_info_personaje();
    }
}

int main()
{
    srand(time(0));
    
    crear_personajes();
}
