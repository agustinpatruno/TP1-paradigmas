#include "ejercicio4.hpp"

void opciones_personajes()
{
    cout << "magos:" << endl;
    cout << "1) hechicero" << endl;
    cout << "2) conjurador" << endl;
    cout << "3) brujo" << endl;
    cout << "4) nigromante" << endl;
    cout << "guerreros:" << endl;
    cout << "5) bárbaro" << endl;
    cout << "6) paladín" << endl;
    cout << "7) caballero" << endl;
    cout << "8) mercenario" << endl;
    cout << "9) gladiador" << endl;
}

void opciones_armas()
{
    cout << "items magicos:" << endl;
    cout << "0) baston" << endl;
    cout << "1) libro_de_hechizos" << endl;
    cout << "2) pocion" << endl;
    cout << "3) amuleto" << endl;
    cout << "armas de combate:" << endl;
    cout << "4) hacha_simple" << endl;
    cout << "5) hacha_doble" << endl;
    cout << "6) espada" << endl;
    cout << "7) lanza" << endl;
    cout << "8) garrote" << endl;
}

void opciones_habilidades_especiales()
{
    cout << "habilidades especiales magicas" << endl;
    cout << "0) Explosion_arcana" << endl;
    cout << "1)  Golpe_elemental" << endl;
    cout << "2) Corte_espectral" << endl;
    cout << "3) Encantamiento_explosivo" << endl;
    cout << "4)  Rafaga_magica" << endl;
    cout << "habilidades especiales de combate" << endl;
    cout << "5) Impacto_devastador" << endl;
    cout << "6) Corte_giratorio" << endl;
    cout << "7)  Golpe_perforante" << endl;
    cout << "8)  Ataque_ensordecedor" << endl;
    cout << "9) Ruptura_elemental" << endl;
}

float devolver_intervalo(float valor, float min, float max)
{
    if ( max < min)
    {
        cout << "Error: Rango inválido." << endl;
        return 0;
    }

    float n = valor;

    while ( n < min ||  max < n)
    {
        cout << "error, ingrese  un valor dentro de las opciones..." << endl;
        cin >> n;
    }
    return n;
}

shared_ptr<personaje> crear_personaje_armado()
{
    shared_ptr<PersonajeFactory> perso_fact = make_shared<PersonajeFactory>();

    int numero_personaje;

    int habilidad_especial;

    int tip_arma;

    ////////////// ingreso del tipo de personaje ////////////////////

    cout << "ingrese el tipo de personaje: " << endl;
    opciones_personajes();
    cin >> numero_personaje;
    numero_personaje = devolver_intervalo(numero_personaje, 1, 9);
    
    ///////////////// ingreso del tipo de arma a utilizar ////////////////////////

    cout << "ingrese el tipo de arma que se desea utilizar:" << endl;
    opciones_armas();
    cin >> tip_arma;
    tip_arma = devolver_intervalo(tip_arma, 1, 9);
    
    //////////////////// ingreso del tipo de habilidad especial ////////////////////////

    cout << "ingrese el tipo de habilidad especial del personaje: " << endl;
    opciones_habilidades_especiales();
    cin >> habilidad_especial;
    habilidad_especial = devolver_intervalo(habilidad_especial, 0, 9);

    /////////////////// ingreso de datos adicionales //////////////////////
    
    shared_ptr<personaje> nuevo_personaje;

    personajes_totales tipo_perso = personajes_totales(numero_personaje);

    hab_totales hab_perso = hab_totales(habilidad_especial);

    armas_totales tipo_arma = armas_totales(tip_arma);

    float dato_perso;

    if (numero_personaje <= 4)
    {
        int magia;

        // ingreso del poder de magia del mago //

        cout << "ingrese el poder de magia del mago:" << endl;
        cin >> magia;

        magia = devolver_intervalo(magia, 0, 10);

       switch (numero_personaje)
        {
            case 1:
                cout << "ingrese el nivel de habilidad de en la fuente" << endl;
                cin >> dato_perso;
                break;
            case 2:
                cout << "ingrese el nivel de habilidad de de conocimiento ancestral" << endl;
                cin >> dato_perso;
                break;
            case 3:
                cout << "ingrese el nivel de habilidad de en la manipulacion de la naturaleza" << endl;
                cin >> dato_perso;
                break;
            case 4:
                cout << "ingrese el nivel de habilidad de en la manipulacion de almas" << endl;
                cin >> dato_perso;
                break;
        }
       cin >> dato_perso;

       dato_perso = devolver_intervalo(dato_perso, 0, 10);

        shared_ptr<personaje> nuevo_personaje = perso_fact ->crear_personaje_armado_factory(tipo_perso, hab_perso, 5, 5, tipo_arma, 5, 5, 5);
        
    }
    else
    {
        float fuerza;

        // ingreso de la fuerza del guerrero //

        cout << " ingrese la fuerza del guerrero: " << endl;
        cin >> fuerza;

        fuerza = devolver_intervalo(fuerza, 0, 1000);

       switch (numero_personaje)
        {
            case 5:
                cout << "ingrese el nivel de espiritu salvaje" << endl;
                break;
            case 6:
                cout << "ingrese el nivel de aura protectora" << endl;
                break;
            case 7:
                cout << "ingrese el nivel de habilidad marcial" << endl;
                break;
            case 8:
                cout << "ingrese el nivel de astucia" << endl;
                break;
        }
       cin >> dato_perso;

       dato_perso = devolver_intervalo(dato_perso, 0, 10);
       

        shared_ptr<personaje> nuevo_personaje = perso_fact ->crear_personaje_armado_factory(tipo_perso, hab_perso, 5, 5, tipo_arma, 5, 5, 5);
    }

    return nuevo_personaje;
}


shared_ptr<personaje> generar_personaje_aleatorio()
{
    // genero el numero aleatorio del personaje //

    int ale_perso = generarAleatorio(1,9);

    personajes_totales tip_personaje = personajes_totales(ale_perso);

    // numeros para completar //

    auto dato1 = generarAleatorio(0,10); // valores cualquiera
    auto dato2 = generarAleatorio(0,10); // valores cualquiera

    // genero la habilidad aleatoria (guardo la habilidad especial, su cantidad de usos y el daño extra)//

    int ale_habilidad = generarAleatorio(0,9);

    hab_totales hab_especial = hab_totales(ale_habilidad);

    // genero el arma aleatoria (guardo el arma, su cantidad de usos y el daño)//

    int ale_arma = generarAleatorio(0,8);

    armas_totales tip_arma = armas_totales(ale_arma);

    shared_ptr<PersonajeFactory> factory = make_shared<PersonajeFactory>();

    shared_ptr<personaje> personaje_aleatorio = factory ->crear_personaje_armado_factory(tip_personaje, hab_especial, dato1, static_cast<float>(dato2),tip_arma, static_cast<float>(3), static_cast<float>(3), static_cast<float>(3));

    // retorno el personaje //

    return personaje_aleatorio;
}


void opciones_golpes()
{
    cout << "elije el tipo de golpe: " << endl;
    cout << "1) golpe fuerte" << endl;
    cout << "2) golpe rapido" << endl;
    cout << "3) defensa y golpe" << endl;
}

void interfaz_pelea()
{
    shared_ptr<PersonajeFactory> perso_factory = make_shared<PersonajeFactory>();

    shared_ptr<personaje> personaje_propio= perso_factory ->crear_personaje_armado_factory(hechicero3, Explosion_arcana,7, static_cast<float>(8), arma_baston,static_cast<float>(5), static_cast<float>(4), static_cast<float>(3));

    shared_ptr<personaje> personaje_aleatorio = generar_personaje_aleatorio();


    while (personaje_propio ->retornar_hp() > 0 && personaje_propio ->retornar_hp() > 0)
    {
        cout << "---------------------------------------------" << endl;

        cout << "----------personaje 1: " << endl;
        cout << "informacion personal" << endl;
        personaje_propio ->mostrar_info_personaje();
        cout << "informacion del arma" << endl;
        personaje_propio ->info_arma();
        cout << "hp" << endl;
        personaje_propio ->mostrar_hp();
        
        cout << "---------personaje 2:" << endl;
        cout << "informacion personal" << endl;
        personaje_aleatorio ->mostrar_info_personaje();
        cout << "informacion del arma" << endl;
        personaje_aleatorio ->info_arma();
        cout << "hp" << endl;
        personaje_aleatorio ->mostrar_hp();

        int eleccion;
        opciones_golpes();
        cin >> eleccion;
        eleccion = devolver_intervalo(eleccion, 1, 3);

        int eleccion_maquina = generarAleatorio(1, 3);

        int sub_eleccion;
        double daño_causado;

        if ((eleccion == 1 && eleccion_maquina == 2) || (eleccion == 2 && eleccion_maquina == 3) || (eleccion == 3 && eleccion_maquina == 1))
        {
            cout << "----------------------------" << endl;
            cout << "ataca personaje 1, que decide, golpe normal(1) o golpe con habilidad especial(2): " << endl;
            cin >> sub_eleccion;
            sub_eleccion = devolver_intervalo(sub_eleccion,1,2);

            if (sub_eleccion == 1)
            {
                daño_causado = personaje_propio ->daño(true);
                if (daño_causado != 0.0)
                {
                    cout << "personaje 1 realiza un ataque normal, haciendo: " << daño_causado << " de daño" << endl;
                    personaje_aleatorio ->modificar_hp(daño_causado);
                }
                else
                {
                    cout << " personaje 1, no tienes golpes disponibles, pierdes el golpe(verificar que haya golpes disponibles de la habilidad)" << endl;
                }
            }
            else
            {
                daño_causado = personaje_propio ->daño(false);
                if (daño_causado != 0.0)
                {
                    cout << " personaje 1 realiza un ataque especial, haciendo " << daño_causado << " de daño" << endl;
                    personaje_aleatorio ->modificar_hp(daño_causado);
                }
                else
                {
                    cout << "personaje 1, no tienes golpes de habilidad especial, te defenderas con los puños, sacando 5 de vida" << endl;
                    personaje_aleatorio ->modificar_hp(5);
                }
            }
        }
        else if (eleccion == eleccion_maquina)
        {
            cout << "----------------------------" << endl;
            cout << "empate, vuelvan a tirar: " << endl;
        }
        else
        {
            cout << "----------------------------" << endl;
            sub_eleccion = generarAleatorio(1,2);

            if (sub_eleccion == 1)
            {
                daño_causado = personaje_propio ->daño(true);
                if (daño_causado != 0.0)
                {
                    cout << "personaje 2 realiza un ataque normal, haciendo: " << daño_causado << " de daño" << endl;
                    personaje_propio ->modificar_hp(daño_causado);
                }
                else
                {
                    cout << "personaje 2, no tienes golpes disponibles, pierdes el golpe(verificar que haya golpes disponibles de la habilidad)" << endl;
                }
            }
            else
            {
                daño_causado = personaje_propio ->daño(false);
                if (daño_causado != 0.0)
                {
                    cout << "personaje 2 realiza un ataque especial, haciendo " << daño_causado << " de daño" << endl;
                    personaje_propio ->modificar_hp(daño_causado);
                }
                else
                {
                    cout << "personaje 2, no tienes golpes de habilidad especial, te defenderas con los puños, sacando 5 de vida" << endl;
                    personaje_propio ->modificar_hp(5);
                }
            }
        }
        
        if (personaje_propio ->retornar_hp() <= 0)
        {
            cout << "ganador personaje aleatorio 2, perdedor personaje 1" << endl;
            return;
        }
        if (personaje_aleatorio ->retornar_hp() <= 0)
        {
            cout << "ganador personaje 1, perdedor personaje aleatorio 2" << endl;
            return;
        }
    }
}

/*
    comando para compilar:
      
        g++ -std=c++17 -I../ejercicio2/include ../ejercicio2/source/abs_combate.cpp ../ejercicio2/source/abs_guerrero.cpp ../ejercicio2/source/abs_items.cpp ../ejercicio2/source/abs_mago.cpp ../ejercicio2/source/interfaz_personajes.cpp ../ejercicio2/source/interfaz_armas.cpp ../ejercicio3/ejercicio3.cpp ejercicio4.cpp -o programa

    comando para ejecutar:
        ./programa

    warnings:
        ejercicio4.cpp:82:43: warning: conversion from ‘int’ to ‘float’ may change value [-Wconversion]
   82 |     numero_personaje = devolver_intervalo(numero_personaje, 1, 9);
      |                                           ^~~~~~~~~~~~~~~~
ejercicio4.cpp:82:42: warning: conversion from ‘float’ to ‘int’ may change value [-Wfloat-conversion]
   82 |     numero_personaje = devolver_intervalo(numero_personaje, 1, 9);
      |                        ~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~
ejercicio4.cpp:89:35: warning: conversion from ‘int’ to ‘float’ may change value [-Wconversion]
   89 |     tip_arma = devolver_intervalo(tip_arma, 1, 9);
      |                                   ^~~~~~~~
ejercicio4.cpp:89:34: warning: conversion from ‘float’ to ‘int’ may change value [-Wfloat-conversion]
   89 |     tip_arma = devolver_intervalo(tip_arma, 1, 9);
      |                ~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~
ejercicio4.cpp:96:45: warning: conversion from ‘int’ to ‘float’ may change value [-Wconversion]
   96 |     habilidad_especial = devolver_intervalo(habilidad_especial, 0, 9);
      |                                             ^~~~~~~~~~~~~~~~~~
ejercicio4.cpp:96:44: warning: conversion from ‘float’ to ‘int’ may change value [-Wfloat-conversion]
   96 |     habilidad_especial = devolver_intervalo(habilidad_especial, 0, 9);
      |                          ~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~
ejercicio4.cpp:119:36: warning: conversion from ‘int’ to ‘float’ may change value [-Wconversion]
  119 |         magia = devolver_intervalo(magia, 0, 10);
      |                                    ^~~~~
ejercicio4.cpp:119:35: warning: conversion from ‘float’ to ‘int’ may change value [-Wfloat-conversion]
  119 |         magia = devolver_intervalo(magia, 0, 10);
      |                 ~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~
ejercicio4.cpp:144:31: warning: declaration of ‘nuevo_personaje’ shadows a previous local [-Wshadow]
  144 |         shared_ptr<personaje> nuevo_personaje = perso_fact ->crear_personaje_armado_factory(tipo_perso, hab_perso, 5, 5, tipo_arma, 5, 5, 5);
      |                               ^~~~~~~~~~~~~~~
ejercicio4.cpp:100:27: note: shadowed declaration is here
  100 |     shared_ptr<personaje> nuevo_personaje;
      |                           ^~~~~~~~~~~~~~~
ejercicio4.cpp:178:31: warning: declaration of ‘nuevo_personaje’ shadows a previous local [-Wshadow]
  178 |         shared_ptr<personaje> nuevo_personaje = perso_fact ->crear_personaje_armado_factory(tipo_perso, hab_perso, 5, 5, tipo_arma, 5, 5, 5);
      |                               ^~~~~~~~~~~~~~~
ejercicio4.cpp:100:27: note: shadowed declaration is here
  100 |     shared_ptr<personaje> nuevo_personaje;
      |                           ^~~~~~~~~~~~~~~
ejercicio4.cpp: In function ‘void interfaz_pelea()’:
ejercicio4.cpp:260:39: warning: conversion from ‘int’ to ‘float’ may change value [-Wconversion]
  260 |         eleccion = devolver_intervalo(eleccion, 1, 3);
      |                                       ^~~~~~~~
ejercicio4.cpp:260:38: warning: conversion from ‘float’ to ‘int’ may change value [-Wfloat-conversion]
  260 |         eleccion = devolver_intervalo(eleccion, 1, 3);
      |                    ~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~
ejercicio4.cpp:272:47: warning: conversion from ‘int’ to ‘float’ may change value [-Wconversion]
  272 |             sub_eleccion = devolver_intervalo(sub_eleccion,1,2);
      |                                               ^~~~~~~~~~~~
ejercicio4.cpp:272:46: warning: conversion from ‘float’ to ‘int’ may change value [-Wfloat-conversion]
  272 |             sub_eleccion = devolver_intervalo(sub_eleccion,1,2);
      |                            ~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~
ejercicio4.cpp:277:34: warning: comparing floating-point with ‘==’ or ‘!=’ is unsafe [-Wfloat-equal]
  277 |                 if (daño_causado != 0.0)
      |                     ~~~~~~~~~~~~~^~~~~~
ejercicio4.cpp:290:34: warning: comparing floating-point with ‘==’ or ‘!=’ is unsafe [-Wfloat-equal]
  290 |                 if (daño_causado != 0.0)
      |                     ~~~~~~~~~~~~~^~~~~~
ejercicio4.cpp:315:34: warning: comparing floating-point with ‘==’ or ‘!=’ is unsafe [-Wfloat-equal]
  315 |                 if (daño_causado != 0.0)
      |                     ~~~~~~~~~~~~~^~~~~~
ejercicio4.cpp:328:34: warning: comparing floating-point with ‘==’ or ‘!=’ is unsafe [-Wfloat-equal]
  328 |                 if (daño_causado != 0.0)
      |                     ~~~~~~~~~~~~~^~~~~~


*/

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    interfaz_pelea();

    return 0;
}
