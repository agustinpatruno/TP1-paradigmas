#include "ejercicio3.hpp"

void crear_personajes_aleatorios()
{
    int cant_magos = generarAleatorio(3,7);
    cout << "numero aleatorio de la cantidad de magos: " << cant_magos << endl;

    int cant_guerreros = generarAleatorio(3,7);
    cout << "numero aleatorio de la cantidad de guerreros: " << cant_guerreros << endl;

    vector<shared_ptr<mago>> magos;

    vector<shared_ptr<guerrero>> guerreros;

    for (int i = 0; i < cant_magos; i++)
    {
        int numero_mago = generarAleatorio(1,4); // valor aleatoria que representa el numero de mago en el enum de tipos_magos

        int numero_habilidad = generarAleatorio(0,9); // valor aleatorio que representa la habilidad del mago

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
            // datos adicionales del arma1
            int da1 = generarAleatorio(1,10);
            int da2 = generarAleatorio(1,10);
            int da3 = generarAleatorio(1,10);

            nuevo_mago ->agregar_arma(static_cast<armas_totales>(random_arma),static_cast<float>(da1),static_cast<float>(da2),static_cast<float>(da3));   
            
            if ( cant_armas == 2)
            {
                int random_arma2 = generarAleatorio(1,9);
                // datos adicionales del arma2
                int d1 = generarAleatorio(1,10);
                int d2 = generarAleatorio(1,10);
                int d3 = generarAleatorio(1,10);

                nuevo_mago ->agregar_arma(static_cast<armas_totales>(random_arma2), static_cast<float>(d1),static_cast<float>(d2),static_cast<float>(d3));   
            }
        }  
        magos.push_back(nuevo_mago);
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

            nuevo_guerrero ->agregar_arma(static_cast<armas_totales>(random_arma), static_cast<float>(da1),static_cast<float>(da2),static_cast<float>(da3));   
            
            if ( cant_armas == 2)
            {
                int random_arma2 = generarAleatorio(1,9);
                // datos adicionales del arma
                int d1 = generarAleatorio(1,10);
                int d2 = generarAleatorio(1,10);
                int d3 = generarAleatorio(1,10);

                nuevo_guerrero ->agregar_arma(static_cast<armas_totales>(random_arma2), static_cast<float>(d1),static_cast<float>(d2),static_cast<float>(d3));   
            }
        }  
        guerreros.push_back(nuevo_guerrero);
    }
    
    cout << "---------------personajes guerreros creados aleatoriamente-----------" << endl;

    for (size_t i = 0; i < guerreros.size(); i++)
    {
        cout << "guerrero n°" << "---------" << i << endl;
        guerreros[i] -> mostrar_info_personaje();
        guerreros[i] ->info_arma();
        guerreros[i] ->mostrar_caracteristica_guerrero();
    }
    
    cout << "---------------personajes magos creados aleatoriamente-------------" << endl;

    for (size_t i = 0; i < magos.size(); i++)
    {
        cout << "mago n°" << i << "------------" << endl;
        magos[i] -> mostrar_info_personaje();
        magos[i] -> info_arma();
        magos[i] ->mostrar_caracteristica_mago();
    }
}

void crear_elementos()
{
    shared_ptr<PersonajeFactory> perso_factory = make_shared<PersonajeFactory>();

    cout << "---------informacion del arma: " << endl;

    shared_ptr<arma> arma = perso_factory ->crear_arma_factory(arma_baston, 5, 4, 3);

    arma ->Get_infoarma_general();

    cout << "---------informacion del personaje-------------- " << endl;

    shared_ptr<personaje> crear_personaje = perso_factory ->crear_personaje_factory(hechicero3, Explosion_arcana,7, 8);
    
    crear_personaje ->mostrar_info_personaje();
    crear_personaje ->mostrar_hp();
    crear_personaje ->modificar_hp(15);
    cout << "hp: " << crear_personaje ->retornar_hp() << endl;

    cout << "---------informacion del personaje armado-------------" << endl;

    shared_ptr<personaje> crear_personaje_armado= perso_factory ->crear_personaje_armado_factory(hechicero3, Explosion_arcana,7, 8, arma_baston, 5, 4, 3);

    crear_personaje_armado -> mostrar_info_personaje();
    crear_personaje_armado -> info_arma();
    crear_personaje_armado ->mostrar_hp();
    crear_personaje_armado ->modificar_hp(16);
    cout << "hp: " << crear_personaje_armado ->retornar_hp() << endl;

    return;
}

/*
    comando para compilar manualmente: 

        g++ -std=c++17 -Wall -I../ejercicio2/include -o programa  ../ejercicio2/source/abs_combate.cpp ../ejercicio2/source/abs_guerrero.cpp ../ejercicio2/source/abs_items.cpp ../ejercicio2/source/abs_mago.cpp ../ejercicio2/source/interfaz_personajes.cpp ../ejercicio2/source/interfaz_armas.cpp ejercicio3.cpp main3.cpp

    comando para compilar con makefile:

        make

    comando para ejecutar manualmente y con makefile:

        ./programa

    primera parte: 

        crea varios personajes aleatorios de guerreros y magos, con datos aleatorios y luego imprime 
        sus valores por consola
     
    segunda paerte:

        crea un arma, un personaje y un personaje armado
        muestra los datos por pantalla
*/

int main()
{
    cout << "--------------creacion de personajes guerreros y magos aleatoriamente" << endl;

    srand(static_cast<unsigned int>(time(0)));
    
    crear_personajes_aleatorios();
    
    cout << "--------------creacion de un objeto arma, un objeto personaje y un objeto personaje armado" << endl;

    crear_elementos();

    return 0;
}