#pragma once
#include "../ejercicio3/ejercicio3.hpp"
using namespace std;

void opciones_personajes();

void opciones_armas();

void opciones_habilidades_especiales();

int devolver_intervalo(int valor, int min, int max);

shared_ptr<personaje> crear_personaje_armado();
/*
    retorna un puntero a un personaje armado. crea dicho personaje con los parametros solicitados por terminal
*/

shared_ptr<personaje> generar_personaje_aleatorio();
/*
    retorna un pesonaje armado aleatorio
*/

void interfaz_pelea();