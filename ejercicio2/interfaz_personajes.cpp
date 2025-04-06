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

bool pertenence_a_guerreros(string guerrero)
{
    vector<string> guerreros = {"bárbaro", "paladín", "caballero","mercenario","gladiador"};

    for (int i = 0; i < guerreros.size(); i++)
    {
        if (guerrero == guerreros[i])
        {
            return true;
        }
    }
    return false;
}

//////////////////////////////////////////////////implementacion metodos de la clase mago////////////////////////////////////////////////

mago::mago(string mago, double Hp, string arma, double daño_arma, int cant_usos, string habilidad_especial, double daño_especial, int cant_usos_especial, int magia, float dur_encantamiento)
{
  try
   {
        if (pertenece_a_magos(mago) && Hp > 0 && (pertenece_en_combate(arma) || pertenece_en_magicos(arma)) && cant_usos > 0 && (pertenece_habilidad_espe_magico(habilidad_especial) || pertenece_habilidad_espe_combate(habilidad_especial)) && daño_especial > 0 && cant_usos_especial > 0 && 0 < magia <= 10 && dur_encantamiento >0)
        {
            tipo_mago = mago;

            hp = hp;

            poder_magia = magia;

            duracion_encantamientos = dur_encantamiento;

            if (pertenece_en_magicos(arma))
            {
                tipo_arma = make_shared<items_magicos>(arma, daño_arma, cant_usos, habilidad_especial, daño_especial, cant_usos_especial);
            }
            else
            {
                tipo_arma = make_shared<armas_combate>(arma, daño_arma, cant_usos, habilidad_especial, daño_especial, cant_usos_especial);
            }
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

void mago::atacar(personaje& otro, bool normal)
{
    double devolver_daño = tipo_arma->devolver_daño(normal);
    otro.modificar_hp(devolver_daño);
}

void mago::mostrar_tipo_personaje()
{
    cout << "tipo de mago: " << tipo_mago << endl;
}

void mago::mostrar_hp()
{
    cout << " hp del mago: " << hp << endl;
}

void mago::mostrar_cant_golpes_totales()
{
    tipo_arma ->mostrar_golpes_disponibles();
    tipo_arma -> mostrar_golpes_dispo_especial();
}

void mago::mostrar_datos()
{
    cout << "poder de magia del mago: " << poder_magia << endl;
    cout << "duracion de los encantamientos: " << duracion_encantamientos << endl;
}

void mago::modificar_hp(double daño)
{
    try
    {
        if (hp > daño)
        {
            hp-=daño;
        }
        else
        {
         throw(" jugador sin vida");   
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

///////////////////////////////////implementacion de metodos de la clase guerrero//////////////////////////////////////

guerrero::guerrero(string guerrero, double hp, string golpe, double daño_golpe, int cant_golpes, string golpe_especial, double daño_golpe_especial, int cant_golpes_especial, float alt, float weight)
{
    try
    {
        if (pertenence_a_guerreros(guerrero) && hp > 0 && (pertenece_en_combate(golpe) || pertenece_en_magicos(golpe)) && cant_golpes > 0 && (pertenece_habilidad_espe_magico(golpe_especial) || pertenece_habilidad_espe_combate(golpe_especial)) && daño_golpe_especial > 0 && cant_golpes_especial > 0 && 0 < alt <= 4 && weight > 0)
        {
            tipo_guerrero = guerrero;

            hp = hp;

           altura = alt;

           peso = weight;

            if (pertenece_en_combate(golpe))
            {
                tipo_arma = make_shared<armas_combate>(golpe, daño_golpe, cant_golpes, golpe_especial, daño_golpe_especial, cant_golpes_especial);
            }
            else
            {
                tipo_arma = make_shared<items_magicos>(golpe, daño_golpe, cant_golpes, golpe_especial, daño_golpe_especial, cant_golpes_especial);
            }
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

void guerrero::atacar(personaje& otro, bool normal)
{
    double daño = tipo_arma ->devolver_daño(normal);
    otro.modificar_hp(daño);
}

void guerrero::mostrar_tipo_personaje()
{
    cout << "tipo de guerrero: " << tipo_guerrero;
}

void guerrero::mostrar_hp()
{
    cout << " hp del guerrero: " << hp << endl;
}

void guerrero::mostrar_cant_golpes_totales()
{
    tipo_arma->mostrar_golpes_disponibles();
    tipo_arma->mostrar_golpes_dispo_especial();
}

void guerrero::mostrar_datos()
{
    cout << "altura del guerrero: " << altura << endl;
    cout << "peso del guerrero: " << peso << endl;
}

void guerrero::modificar_hp(double daño)
{
    try
    {
        if (hp > daño)
        {
            hp-=daño;
        }
        else
        {
         throw(" jugador sin vida");   
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}