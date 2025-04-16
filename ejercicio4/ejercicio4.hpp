#pragma once
#include "../ejercicio3/ejercicio3.hpp"
using namespace std;

void opciones_personajes();
/*
    imprime por consola los diferentes personajes de tipo guerrero y tipo mago
*/

void opciones_armas();
/*
    imprime por consola las diferentes armas de tipo items_magicos y tipo arma_combate
*/

void opciones_habilidades_especiales();
/*
    imprime por consola las diferentes habilidades magicas de y de combate
*/

float devolver_intervalo(float valor, float min, float max);
/*
    retorna el valor pasado por el usuario por la terminal, le pide el valor hasta que devuelve uno valido dentro
    del rango
*/

unique_ptr<personaje> crear_personaje_armado();
/*
    retorna un puntero a un personaje armado. crea dicho personaje con los parametros solicitados por terminal
*/

unique_ptr<personaje> generar_personaje_aleatorio();
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