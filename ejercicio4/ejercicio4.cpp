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
    cout << "1) baston" << endl;
    cout << "2) libro_de_hechizos" << endl;
    cout << "3) pocion" << endl;
    cout << "4) amuleto" << endl;
    cout << "armas de combate:" << endl;
    cout << "5) hacha_simple" << endl;
    cout << "6) hacha_doble" << endl;
    cout << "7) espada" << endl;
    cout << "8) lanza" << endl;
    cout << "9) garrote" << endl;
}

void opciones_habilidades_especiales()
{
    cout << "habilidades especiales magicas" << endl;
    cout << "1) Explosion_arcana" << endl;
    cout << "2)  Golpe_elemental" << endl;
    cout << "3) Corte_espectral" << endl;
    cout << "4) Encantamiento_explosivo" << endl;
    cout << "5)  Rafaga_magica" << endl;
    cout << "habilidades especiales de combate" << endl;
    cout << "6) Impacto_devastador" << endl;
    cout << "7) Corte_giratorio" << endl;
    cout << "8)  Golpe_perforante" << endl;
    cout << "9)  Ataque_ensordecedor" << endl;
    cout << "10) Ruptura_elemental" << endl;
}

int devolver_intervalo(int valor, int min, int max)
{
    int n = valor;

    while ( n < min ||  max < n)
    {
        cout << "error, ingrese  un valor dentro de las opciones..." << endl;
        cin >> n;
    }
    return n;
}

shared_ptr<personaje_armado> crear_personaje_armado()
{
    int personaje;

    int habilidad_especial;

    int tip_arma;

    ////////////// ingreso del tipo de personaje ////////////////////

    cout << "ingrese el tipo de personaje: " << endl;
    opciones_personajes();
    cin >> personaje;

    personaje = devolver_intervalo(personaje, 1, 9);
    
    ///////////////// ingreso del tipo de arma a utilizar ////////////////////////

    cout << "ingrese el tipo de arma que se desea utilizar:" << endl;
    opciones_armas();
    cin >> tip_arma;

    tip_arma = devolver_intervalo(tip_arma, 1 , 9);
    
    //////////////////// ingreso del tipo de habilidad especial ////////////////////////

    cout << "ingrese el tipo de habilidad especial del personaje: " << endl;
    opciones_habilidades_especiales();
    cin >> habilidad_especial;

    habilidad_especial = devolver_intervalo(habilidad_especial, 1, 10);

    /////////////////// ingreso de datos adicionales //////////////////////
    
    shared_ptr<personaje_armado> nuevo_personaje_armado;

    if (personaje <= 4)
    {
        int magia;

        float duracion_encantamiento;

        // ingreso del poder de magia del mago //

        cout << "ingrese el poder de magia del mago:" << endl;
        cin >> magia;

        magia = devolver_intervalo(magia, 0, 10);

        // ingreso de la duracion del encantamiento del mago //

        cout << "ingrese la duracion del encantamiento del mago: " << endl;
        cin >> duracion_encantamiento;

       duracion_encantamiento = devolver_intervalo(duracion_encantamiento, 0, 25);

        nuevo_personaje_armado = make_shared<personaje_armado>(personaje, 100, magia, duracion_encantamiento, 1);
    }
    else
    {
        float peso;

        float altura;

        // ingreso del peso del guerrero //

        cout << " ingrese el peso del guerrero: " << endl;
        cin >> peso;

        peso = devolver_intervalo(peso, 0, 400);
        
        // ingrese la altura del guerrero //

        cout << "ingrese la altura del guerrero: " << endl;
        cin >> altura;

        altura = devolver_intervalo(altura, 0, 4);

        nuevo_personaje_armado = make_shared<personaje_armado>(personaje, 100, altura, peso, 1);
    }
    nuevo_personaje_armado ->crear_arma(armas_magicas_y_combate(tip_arma), daño_items_magicos_combates[tip_arma],cant_usos_armas_magicas_combates[tip_arma], habilidades_especiales_magicas_y_combate(habilidad_especial), daño_habilidad_especial_magicos_combates[habilidad_especial], cant_usos_especiales_magicas_combates[habilidad_especial]);

    return nuevo_personaje_armado;
}

shared_ptr<personaje_armado> generar_personaje_aleatorio()
{
    // genero el numero aleatorio del personaje //

    int ale_perso = generarAleatorio(1,9);

    tipos_personajes tip_personaje = tipos_personajes(ale_perso);

    // numeros cualquiera para completar //

    auto dato1 = 3; // valores cualquiera
    auto dato2 = 21; // valores cualquiera

    // genero la habilidad aleatoria (guardo la habilidad especial, su cantidad de usos y el daño extra)//

    int ale_habilidad = generarAleatorio(1,10);

    habilidades_especiales_magicas_y_combate hab_especial = habilidades_especiales_magicas_y_combate(ale_habilidad);

    double daño_hab_especial = daño_habilidad_especial_magicos_combates[ale_habilidad];

    int cant_usos_especial = cant_usos_especiales_magicas_combates[ale_habilidad];

    // genero el arma aleatoria (guardo el arma, su cantidad de usos y el daño)//

    int ale_arma = generarAleatorio(1,9);

    armas_magicas_y_combate tip_arma = armas_magicas_y_combate(ale_arma);

    int cant_usos = cant_usos_armas_magicas_combates[ale_arma];

    int daño_arma = daño_items_magicos_combates[ale_arma];

    // creo el personaje armado con los datos //

    shared_ptr<PersonajeFactory> factory;

    shared_ptr<personaje_armado> personaje_aleatorio = factory ->crear_personaje_armado(tip_personaje, 100, dato1, dato2, hab_especial, tip_arma, daño_arma, cant_usos, hab_especial, daño_hab_especial, cant_usos_especial);

    // retorno el personaje //

    return personaje_aleatorio;
}

void interfaz_pelea()
{
    
    shared_ptr<personaje_armado> personaje_creado = crear_personaje_armado();

    shared_ptr<personaje_armado> personaje_aleatorio = generar_personaje_aleatorio();

    
}
