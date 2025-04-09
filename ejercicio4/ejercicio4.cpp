#include "ejercicio4.hpp"

// vector con los valores del daño de las armas.(primera mitad = daños items magicos, segunda mitad = daños armas de combate) //
vector<double> daño_items_magicos_combates = {12.5, 13, 14, 10, 9, 16, 13.2, 15};

// vector con la cantidad de usos de cada arma (primera mitad = cant usos items magicos, segunda mitad = cant usos armas de combate)//
vector<int> cant_usos_armas_magicas_caombates = {12,11,15,10, 13,16,12,9};

/* 
vector con los valores de los daños extra de las habilidades especiales 
(primera mitad = daños habilidades especiales magicos, segunda mitad = daños habilidades especiales combate)
*/
vector<double> daño_habilidad_especial_magicos_combates = {5.4, 3.7, 8.2, 6.6, 5, 3.7, 5.3, 7, 4.2, 9};

/*
vecton con la cantidad de usos de las habilidades especiales 
(primera mitad = cant usos habilidades especiales magicos, segunda mitad = cant usos habilidades especiales combate)
*/
vector<int> cant_usos_especiales_magicas_combates = {3,2,4,1,5,3,2,4};

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

    while (n > max || n < min)
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
    
    shared_ptr<personaje_armado> nuevo_personaje_armado;

    if (personaje <= 4)
    {
        int magia;

        float duracion_encantamiento;

        // ingreso del poder de magia del mago //

        cout << "ingrese el poder de magia del mago:" << endl;
        cin >> magia;

        while (magia < 0 || magia > 10 )
        {
            cout << "error, ingrese un poder de magia que sea positivo, menor o igual a 10." << endl;
            cin >> magia;
        }

        // ingreso de la duracion del encantamiento del mago //

        cout << "ingrese la duracion del encantamiento del mago: " << endl;
        cin >> duracion_encantamiento;

        while ( duracion_encantamiento < 0 || duracion_encantamiento > 25)
        {
            cout << "ingrese una duracion que sea positiva, menor a 25 segundos: " << endl;
            cin >> duracion_encantamiento;
        } 

        shared_ptr<personaje_armado> nuevo_personaje_armado = make_shared<personaje_armado>(personaje, 100, magia, duracion_encantamiento, 1);
    }
    else
    {
        float peso;

        float altura;

        // ingreso del peso del guerrero //

        cout << " ingrese el peso del guerrero: " << endl;
        cin >> peso;

        while (peso < 0 || peso > 400)
        {
            cout << "error, ingrese un peso positivo menor o igual a 400 kilos" << endl;
            cin >> peso;
        }
        
        // ingrese la altura del guerrero //

        cout << "ingrese la altura del guerrero: " << endl;
        cin >> altura;

        while ( altura < 0 || altura > 4)
        {
            cout << "error, ingrese una altura positiva, menor o igual a 4 metros" << endl;
            cin >> altura;
        }

        shared_ptr<personaje_armado> nuevo_personaje_armado = make_shared<personaje_armado>(personaje, 100, altura, peso, 1);
    }

    nuevo_personaje_armado ->crear_arma( );

} 