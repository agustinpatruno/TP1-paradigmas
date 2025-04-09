#include "/home/apatruno/2°do año ing en IA/TP1 paradigmas/TP1-paradigmas/ejercicio3/ejercicio3.cpp"


void opciones_personajes();

void opciones_armas();

void opciones_habilidades_especiales();

int devolver_intervalo(int valor, int min, int max);

shared_ptr<personaje_armado> crear_personaje_armado();
/*
    retorna un puntero a un personaje armado. crea dicho personaje con los parametros solicitados por terminal
*/

shared_ptr<personaje_armado> generar_personaje_aleatorio();

void interfaz_pelea();