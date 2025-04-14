#include "../includes/abs_guerrero.hpp"

////////////////////////////////////////////implementacion metodos de la clase abstracta guerrero/////////////////////////////////

guerrero::guerrero(tipos_guerreros nombre_guerrero, float fuerza, hab_totales hab_especial, double vida, int armas)
{
    try
    {
        if (corroborar_intervalo(0,fuerza,1000) && corroborar_intervalo(0,static_cast<float>(armas), 2))
        {
            this -> tipo_guerrero = nombre_guerrero;

            habilidad_especial = hab_especial;
        
            capacidad_fuerza = fuerza;
        
            hp = vida;

            cant_armas = armas;
        
            if (!pertenece_hab_magicas(hab_especial)) // en caso de que la habilidad sea de las de combate, se usa el 100% del daño
            {
               daño_hab = daño_hab_magicos_combate[static_cast<size_t>(hab_especial)];
            }
            else // en caso de que la habilidad sea de las magicas, se usa el 60% del daño
            {
                daño_hab = daño_hab_magicos_combate[static_cast<size_t>(hab_especial)]*(0.6);
            }
            usos_hab = usos_hab_magicas_combate[static_cast<size_t>(hab_especial)];
        }
        else
        {
            throw logic_error("error en la creacion de un objeto guerrero, verifique que todos los parametros ingresados sean correctos");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void guerrero::mostrar_info_personaje() const
{
    cout << "tipo de guerrero: " << getTipoGuerrero(tipo_guerrero) << endl;
    cout << "habilidad especial: " << getHabilidad(habilidad_especial) << endl;
    cout << "cantidad de daño de la habilidad especial: " << daño_hab << endl;
    cout << "cantidad de usos de la habilidad especial: " << usos_hab << endl;
    cout << "capacidad de fuerza: " << capacidad_fuerza << " Kg" << endl;
}

void guerrero::mostrar_hp() const
{
    cout << "Hp del guerrero: " << hp << endl;
}

double guerrero::retornar_hp() const
{
    return hp;
}

double guerrero::daño(bool normal)
{
    if (normal)
    {
        if (arma1->restar_usos())
        {
            return arma1 ->retornar_daño();
        }
        else
        {
            return 0;
        }
    }
    else
    {
      if (usos_hab > 0)
        {
            usos_hab -= 1;
            return arma1 ->retornar_daño() + daño_hab;
        }
      else
        {
            cout << "te has quedado sin golpes especailes" << endl;
            return 0;
        }
    }
}

void guerrero::modificar_hp(double daño)
{
    try
    {
        if (daño > 0)
        {
            if (hp > daño)
            {
                hp -= daño;
            }
            else
            {
                hp = 0;
                throw logic_error("el guerrero se quedo sin vida");
            }
        }
        else
        {
            throw logic_error("error, daño negativo, ingrese un daño positivo");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void guerrero::agregar_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3)
{
    try
    {
        if (contar_armas() < cant_armas)
        {
            double daño = daño_magicos_combate[static_cast<size_t>(tipo_arma)];

            if (pertenece_armas_combate(tipo_arma)) // en caso de que pertenezca a un item magico, se usa el 100% del daño 
            {
                if (arma1)
                {
                    arma1 = crear_arma(tipo_arma, dato1, dato2, dato3, daño);
                }
                else
                {
                    arma2 = crear_arma(tipo_arma, dato1, dato2, dato3, daño);
                }
            }
            else if (pertenece_armas_magicas(tipo_arma)) // en caso de que pertenezca a un arma de combate, se usa el 80% del daño 
            {
                if (arma1)
                {
                    arma1 = crear_arma(tipo_arma, dato1, dato2, dato3, daño*(0.8));
                }
                else
                {
                    arma2 = crear_arma(tipo_arma, dato1, dato2, dato3, daño*(0.8));
                }
            }
            else
            {
                throw logic_error("error, tipo de arma no valida");
            }
        }
        else
        {
            throw logic_error("error, no puede ingresar mas armas");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void guerrero::info_arma() const
{
    if (arma1)
    {
        arma1 -> Get_infoarma_general();
    }
    if (arma2)
    {
        arma2 -> Get_infoarma_general();
    }
}

int guerrero::contar_armas() const
{
    int c = 0;

    if (arma1)
    {
        c+=1;
    }
    if (arma2)
    {
        c+=1;
    }
    return c;
}

guerrero::~guerrero(){}

// implementacion de la clase derivada barbaro //

barbaro::barbaro(hab_totales habilidad, float fuerza, int max_armas, float salvaje) : guerrero( a_barbaro, fuerza, habilidad, 100, max_armas), espiritu_salvaje(salvaje)
{
    try
    {
        if (!corroborar_intervalo(0, salvaje, 10))
        {
            throw logic_error("error en la creacion de un personaje barbaro, ingrese un nivel de espiritu salvaje[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void barbaro::mostrar_caracteristica_guerrero() const
{
    cout << "nivel de espiritu salvaje: " << espiritu_salvaje << endl;
}

// implementacion de la clase derivada paladin //

paladin::paladin(hab_totales habilidad, float fuerza, int max_armas, float aura) : guerrero(a_paladin,fuerza, habilidad, 100, max_armas), aura_protectora(aura)
{
    try
    {
        if (!corroborar_intervalo(0, aura, 10))
        {
            throw("error en la creacion de un personaje paladin, ingrese un nivel de aura protectora[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void paladin::mostrar_caracteristica_guerrero() const
{
    cout << "nivel de aura protectora: " << aura_protectora << endl;
}

// implementacion de la clase derivada caballero //

caballero::caballero(hab_totales habilidad, float fuerza, int max_armas, float hab_marcial) : guerrero(a_caballero,fuerza, habilidad, 100, max_armas), habilidad_marcial(hab_marcial)
{
    try
    {
        if (!corroborar_intervalo(0, hab_marcial, 10))
        {
            throw("error en la creacion de un personaje caballero, ingrese un nivel de habilidad marcial[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void caballero::mostrar_caracteristica_guerrero() const
{
    cout << "nivel de habilidad marcial: " << habilidad_marcial << endl;
}

// implementacion de la clase derivada mercenario //

mercenario::mercenario(hab_totales habilidad, float fuerza, int max_armas, float astucia) : guerrero(a_mercenario,fuerza, habilidad, 100, max_armas), nivel_astucia(astucia)
{
    try
    {
        if (!corroborar_intervalo(0, astucia, 10))
        {
            throw("error en la creacion de un personaje mercenario, ingrese un nivel de astucia[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void mercenario::mostrar_caracteristica_guerrero() const
{
    cout << "nivel de astucia: " << nivel_astucia << endl;
}

// implementacion de la clase derivada gladiador //

gladiador::gladiador(hab_totales habilidad, float fuerza, int max_armas, float adaptacion) : guerrero(a_gladiador,fuerza, habilidad, 100, max_armas), adaptabilidad(adaptacion)
{
    try
    {
        if (!corroborar_intervalo(0, adaptabilidad, 10))
        {
            throw("error, ingrese un nivel de adaptabilidad[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void gladiador::mostrar_caracteristica_guerrero() const
{
    cout << "nivel de adaptabilidad: " << adaptabilidad << endl;
}