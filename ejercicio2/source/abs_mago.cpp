#include "../includes/abs_mago.hpp"

////////////////////////////////implementacion metodos de la clase abstracta mago/////////////////////////////////

mago::mago(tipos_magos tip_mago, hab_totales hab_especial, int magia, double vida, int max_armas)
{
    try
    {
        if (corroborar_intervalo(0,static_cast<float>(magia),10) && corroborar_intervalo(0, static_cast<float>(max_armas), 2))
        {
            tipo_mago = tip_mago;

            habilidad_especial = hab_especial;
        
            poder_magia = magia;
        
            hp = vida;
        
            cant_armas = max_armas;
        
            if (pertenece_hab_magicas(hab_especial)) // en caso de que la habilidad sea de las magicas, se usa el 100% del daño
            {
               daño_hab = daño_hab_magicos_combate[static_cast<size_t>(hab_especial)];
            }
            else // en caso de que la habilidad sea de las de combate, se usa el 60% del daño
            {
                daño_hab = daño_hab_magicos_combate[static_cast<size_t>(hab_especial)]*(0.6);
            }
            usos_hab = usos_hab_magicas_combate[static_cast<size_t>(hab_especial)];
        }
        else
        {
            throw logic_error("error en la creacion de un personaje mago, verifique que todos los parametros ingresados sean correctos");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void mago::mostrar_info_personaje() const
{
    cout << "tipo de personaje mago: " << getTipoMago(tipo_mago) << endl;
    cout << "habilidad especial: " << getHabilidad(habilidad_especial) << endl;
    cout << " poder de daño de la habilidad especial: " << daño_hab << endl;
    cout << "cantidad de usos de la habilidad especial: " << usos_hab << endl;
    cout << "poder de magia: " << poder_magia << endl;
}

void mago::info_arma() const
{
    if (arma1)
    {
        arma1 ->Get_infoarma_general();
    }
    if ( arma2)
    {
        arma2 ->Get_infoarma_general();
    }
}

int mago::contar_armas() const
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

void mago::mostrar_hp() const
{
    cout << "Hp del mago: " << hp << endl;
}

double mago::retornar_hp() const
{
    return hp;
}

void mago::modificar_hp(double daño)
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
                throw logic_error("el mago se quedo sin vida");
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

double mago::daño(bool normal)
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

void mago::agregar_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3)
{
    try
    {
        if (contar_armas() < cant_armas)
        {
            double daño = daño_magicos_combate[static_cast<size_t>(tipo_arma)];

            if (pertenece_armas_magicas(tipo_arma)) // en caso de que pertenezca a un item magico, se usa el 100% del daño 
            {
                if (!arma1)
                {
                    arma1 = this -> crear_arma(tipo_arma, dato1, dato2, dato3, daño);
                }
                else
                {
                    arma2 = this -> crear_arma(tipo_arma, dato1, dato2, dato3, daño);
                }
            }
            else if (pertenece_armas_combate(tipo_arma)) // en caso de que pertenezca a un arma de combate, se usa el 80% del daño 
            {
                if (!arma1)
                {
                    arma1 = this -> crear_arma(tipo_arma, dato1, dato2, dato3, daño*(0.8));
                }
                else
                {
                    arma2 = this -> crear_arma(tipo_arma, dato1, dato2, dato3, daño*(0.8));
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

unique_ptr<arma> mago::crear_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3, double daño)
{
    switch (tipo_arma)
    {
        case arma_baston:
            return make_unique<baston>(dato1, dato2, dato3, daño);
            break;
        case arma_libro_de_hechizos:
            return make_unique<libro_de_hechizos>(dato1, dato2, dato3, daño);
            break;
        case arma_pocion:
            return make_unique<pocion>(dato1, dato2, dato3, daño);
            break;
        case arma_amuleto:
            return make_unique<amuleto>(dato1, dato2, dato3, daño);
            break;
        case arma_hacha_simple:
            return make_unique<hacha_simple>(dato1, dato2, dato3, daño);
            break;
        case arma_hacha_doble:
            return make_unique<hacha_doble>(dato1, dato2, dato3, daño);
            break;
        case arma_espada:
            return make_unique<espada>(dato1, dato2, dato3, daño);
            break;
        case arma_garrote:
            return make_unique<garrote>(dato1, dato2, dato3, daño);
            break;
        case arma_lanza:
            return make_unique<lanza>(dato1, dato2, dato3, daño);
            break;
        default:
            return nullptr;
            break;
    }
}

mago::~mago(){}

// implementacion de la clase derivada hechicero //

hechicero::hechicero(hab_totales hab_especial, int magia, int max_armas, float hab_fuente) : mago(a_hechicero, hab_especial, magia, 100, max_armas), habilidad_fuente(hab_fuente)
{
    try
    {
        if (!corroborar_intervalo(0, hab_fuente, 10))
        {
            throw logic_error("error en la creacion de un personaje hechicero, ingrese una habilidad de fuente[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void hechicero::mostrar_caracteristica_mago() const
{
    cout << "habilidad en la fuente: " << habilidad_fuente << endl;
}

// implementacion de la clase derivada conjurador //

conjurador::conjurador(hab_totales hab_especial, int magia, int max_armas, float conocimiento) : mago(a_conjurador, hab_especial, magia, 100, max_armas), conocimiento_ancestral(conocimiento)
{
    try
    {
        if (!corroborar_intervalo(0, conocimiento, 10))
        {
            throw logic_error("error en la creacion de un personaje conjurador, ingrese una nivel de conocimiento ancestral[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void conjurador:: mostrar_caracteristica_mago() const
{
    cout << "conocimiento ancestral: " << conocimiento_ancestral << endl;
}

// implementacion de la clase derivada brujo //

brujo::brujo(hab_totales hab_especial, int magia, int max_armas, float manipulacion) : mago(a_brujo, hab_especial, magia, 100, max_armas), manipulacion_naturaleza(manipulacion)
{
    try
    {
        if (!corroborar_intervalo(0, manipulacion, 10))
        {
            throw logic_error("error en la creacion de un personaje brujo, ingrese una nivel de manipulacion de naturaleza[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void brujo::mostrar_caracteristica_mago() const
{
    cout << "nivel de manipulacion de naturaleza: " << manipulacion_naturaleza << endl;
}

// implementacion de la clase derivada nigromante //

nigromante::nigromante(hab_totales hab_especial, int magia, int max_armas, float mani_almas) : mago(a_nigromante, hab_especial, magia, 100, max_armas), manipulacion_almas(mani_almas)
{
    try
    {
        if (!corroborar_intervalo(0, mani_almas, 10))
        {
            throw logic_error("error en la creacion de un personaje nigromante, ingrese una nivel de manipulacion de almas[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void nigromante::mostrar_caracteristica_mago() const
{
    cout << "nivel de manipulacion de almas: " << manipulacion_almas << endl;
}

