#include "interfaz_personajes.hpp"

bool pertenece_a_magos(string mago)
{
    vector<string> magos = {"hechicero","conjurador","brujo","nigromante"};

    for (int i = 0; i < magos.size(); i++)
    {
        if (magos[i] == mago)
        {
            return true;
        }
    }
    return false;
}


//////////////////////////////////////////////////implementacion metodos de la clase mago////////////////////////////////////////////////


mago::mago(string mago, double Hp, string arma, double daño_arma, int cant_usos, string habilidad_especial, double daño_especial, int cant_usos_especial, string rareza, int golpes_extra)
{
  
}

void mago::atacar(personaje& otro, bool normal)
{


}

void mago::mostrar_tipo_personaje()
{


}

void mago::mostrar_hp()
{


}

void mago::mostrar_cant_golpes_especial()
{


}


void mago::mostrar_datos()
{

    
}