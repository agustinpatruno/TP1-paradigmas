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

bool pertence_magicos_especiales(string habilidad_magico)
{
    vector<string> especiales_magicos = {"Llama Eterna","Escudo Arcano","Toque Fantasmal","Tormenta de Fulgor","Prisión de Sombras"};

    for (int i = 0; i < especiales_magicos.size(); i++)
    {
        if (habilidad_magico == especiales_magicos[i])
        {
            return true;
        }
    }
    return false;
}

bool pertenece_combate_especiales(string habilidad_combate)
{
    vector<string> especiales_combates = {"Golpe elemental","Ataque giratorio","Corte crítico","Escudo mágico","Ruptura de defensas"};

    for (int i = 0; i < especiales_combates.size(); i++)
    {
        if (habilidad_combate == especiales_combates[i])
        {
            return true;
        }
    }
    return false;
}

//////////////////////////////////////////////////implementacion metodos de la clase mago////////////////////////////////////////////////

mago::mago(string mago, double Hp, string arma, double daño_arma, int cant_usos, string habilidad_especial, double daño_especial, int cant_usos_especial, string rareza, int golpes_extra)
{
    try
    {
        if (pertenece_a_magos(mago) && (pertenece_en_magicos(arma) || pertenece_en_combate(arma)) && Hp > 0 && daño_arma > 0 && cant_usos > 0 && daño_especial > 0 && cant_usos_especial > 0 && (pertenece_combate_especiales(habilidad_especial) || pertence_magicos_especiales(habilidad_especial)) && pertence_en_rareza(rareza) && golpes_extra)
        {
            tipo_mago = mago;

            hp = Hp;

            if (pertenece_en_magicos(arma))
            {
                tipo_arma = make_shared<items_magicos>(arma, rareza, daño_arma, cant_usos, golpes_extra);
            }
            else
            {
                tipo_arma = make_shared<armas_combate>(arma, rareza, daño_arma, cant_usos,golpes_extra);
            }
            
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void mago::atacar(personaje& otro)
{


}

void mago::mostrar_tipo_personaje()
{


}

void mago::usar_habilidad_especial()
{


}

void mago::mostrar_habilidad_especial()
{


}

void mago::mostrar_hp()
{


}

void mago::mostrar_daño_hechizo_especial()
{


}

void mago::mostrar_cant_golpes_especial()
{


}