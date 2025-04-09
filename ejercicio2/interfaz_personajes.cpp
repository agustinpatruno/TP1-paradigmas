#include "interfaz_personajes.hpp"

bool pertenece_a_magos(tipos_personajes mago)
{
    return hechicero <= mago && hechicero <= nigromante;
}

bool pertenence_a_guerreros(tipos_personajes guerrero)
{
    return barbaro <= guerrero && guerrero <= gladiador;
}

//////////////////////////////////////////////////implementacion metodos de la clase mago////////////////////////////////////////////////

mago::mago(tipos_personajes mago, double Hp, int magia, float dur_encantamiento, habilidades_especiales_magicas_y_combate hab_especial)
{
  try
   {
        if (pertenece_a_magos(mago) && Hp > 0 && 0 < magia <= 10 && dur_encantamiento > 0 && (pertenece_habilidad_espe_combate(hab_especial) || pertenece_habilidad_espe_magico(hab_especial)))
        {
            tipo_mago = mago;

            hp = hp;

            poder_magia = magia;

            duracion_encantamientos = dur_encantamiento;

            habilidad_especial = hab_especial;
        }
        else
        {
            throw logic_error("error, verigique que todos los parametros ingresados sean correctos");
        }
    }
  catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } 
}

void mago::mostrar_tipo_personaje()
{
    cout << "tipo de mago: " << tipo_mago << endl;
}

void mago::mostrar_hp()
{
    cout << " hp del mago: " << hp << endl;
}

double mago::retornar_hp()
{
    return hp;
}

void mago::modificar_hp(double daño)
{
    hp -= daño;
}

void mago::mostrar_dato1()
{
    cout << "poder de magia del mago: " << poder_magia << endl; 
}

void mago::mostrar_dato2()
{
    cout << "duracion de los encantamientos: " << duracion_encantamientos << endl;
}

void mago::mostrar_habilidad()
{
    cout << "habilidad especial del mago: " << habilidad_especial << endl;
}

///////////////////////////////////implementacion de metodos de la clase guerrero//////////////////////////////////////

guerrero::guerrero(tipos_personajes guerrero, double hp, float alt, float weight, habilidades_especiales_magicas_y_combate hab_especial)
{
    try
    {
        if (pertenence_a_guerreros(guerrero) && hp > 0 && 0 < alt <= 4 && weight > 0 && (pertenece_habilidad_espe_combate(hab_especial) || pertenece_habilidad_espe_magico(hab_especial)))
        {
            tipo_guerrero = guerrero;

            hp = hp;

           altura = alt;

           peso = weight;

           habilidad_especial = hab_especial;
        }
        else
        {
            throw logic_error("error, verigique que todos los parametros ingresados sean correctos");
        }
    }
  catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void guerrero::mostrar_tipo_personaje()
{
    cout << "tipo de guerrero: " << tipo_guerrero;
}

void guerrero::mostrar_hp()
{
    cout << " hp del guerrero: " << hp << endl;
}

double guerrero::retornar_hp()
{
    return hp;
}

void guerrero::modificar_hp(double daño)
{
    hp -= daño;
}

void guerrero::mostrar_dato1()
{
    cout << "altura del guerrero: " << altura << endl;
}

void guerrero::mostrar_dato2()
{
    cout << "peso del guerrero: " << peso << endl;
}

void guerrero::mostrar_habilidad()
{
    cout << "habilidad especial del guerrero: " << habilidad_especial << endl;
}