#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

// enum de las armas totales. ([0:4] = armas magicas, [5:9] = armas de combate)//

enum armas_totales {arma_baston = 0, arma_libro_de_hechizos, arma_pocion, arma_amuleto, arma_hacha_simple, arma_hacha_doble, arma_espada, arma_lanza, arma_garrote};

extern vector<double> daño_magicos_combate;

extern vector<int> usos_armas_magicas_combate;

string obtenerNombreArma(armas_totales tipo);
/*
    retorna el string del tipo de arma que se le pasa por parametro. caso de no ser ninguno, retorna tipo de arma
    desconocido
*/

bool pertenece_armas_magicas(armas_totales tipo_arma);
/*
    retorna true si el tipo de arma pertenece a las armas magicas, retorna false en caso contrario.
*/

bool pertenece_armas_combate(armas_totales tipo_arma);
/*
    retorna true si el tipo de arma pertenece a las armas de combate, retorna false en caso contrario.
*/

bool corroborar_intervalo(float min, float valor, float max);
/*
    retorna true si el valor esta dentro del intervalo, retorna false en caso contrario y en caso de que max < min. 
*/

///////////////////////////////////clase interfaz arma ////////////////////////////////////////////

class arma
{
    protected:

        double Daño;

        int cant_usos;

    public:

        virtual void Get_infoarma_general() const = 0; // muestro el tipo de arma, la cantidad de usos disponibles y el daño
        
        virtual double retornar_daño() const = 0;

        virtual bool restar_usos() = 0;

        virtual ~arma() = default;
};
