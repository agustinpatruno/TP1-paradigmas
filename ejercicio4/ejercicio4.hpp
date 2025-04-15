#pragma once
#include "../ejercicio3/ejercicio3.hpp"
using namespace std;

void opciones_personajes();

void opciones_armas();

void opciones_habilidades_especiales();

float devolver_intervalo(float valor, float min, float max);
/*
    retorna el valor pasado por el usuario por la terminal, le pide el valor hasta que devuelve uno valido dentro
    del rango
*/

shared_ptr<personaje> crear_personaje_armado();
/*
    retorna un puntero a un personaje armado. crea dicho personaje con los parametros solicitados por terminal
*/

shared_ptr<personaje> generar_personaje_aleatorio();
/*
    retorna un pesonaje armado aleatorio, con todos los datos aleatorios
*/

void interfaz_pelea();
/*
    interfaz de pelea entre 2 personajes. el personaje del usuario ya esta definido y el personaje de la "maquina"
    se crea aleatoriamente. 
    consiste en un piedra, papel o tijera pero con (golpe fuerte, golpe reapdio o defensa y golpe)
    gana el ultimo con vida
*/