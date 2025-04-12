#include "interfaz_personajes.hpp"

/////// funciones auxiliares /////////

// funcion para el enum de tipo_magos

string getTipoMago(tipos_magos tipo) {
    switch (tipo) {
        case a_hechicero: return "hechicero";
        case a_conjurador: return "conjurador";
        case a_brujo: return "brujo";
        case a_nigromante: return "nigromante";
        default: return "tipo desconocido";
    }
}

// Función para el enum de tipos_guerreros

string getTipoGuerrero(tipos_guerreros tipo) {
    switch (tipo) {
        case a_barbaro: return "barbaro";
        case a_paladin: return "paladin";
        case a_caballero: return "caballero";
        case a_mercenario: return "mercenario";
        case a_gladiador: return "gladiador";
        default: return "tipo desconocido";
    }
}

// Función para el enum de hab_totales, retorna el string del valor del enum pasado por parametro. caso contrario retorna 
// "habilidad desconocida"

string getHabilidad(hab_totales habilidad) {
    switch (habilidad) {
        case Explosion_arcana: return "Explosion_arcana";
        case Golpe_elemental: return "Golpe_elemental";
        case Corte_espectral: return "Corte_espectral";
        case Encantamiento_explosivo: return "Encantamiento_explosivo";
        case Rafaga_magica: return "Rafaga_magica";
        case Impacto_devastador: return "Impacto_devastador";
        case Corte_giratorio: return "Corte_giratorio";
        case Golpe_perforante: return "Golpe_perforante";
        case Ataque_ensordecedor: return "Ataque_ensordecedor";
        case Ruptura_elemental: return "Ruptura_elemental";
        default: return "habilidad desconocida";
    }
}

bool pertenece_hab_magicas(hab_totales habilidad)
{
    return habilidad >= Explosion_arcana && habilidad <= Rafaga_magica;
}

unique_ptr<arma> crear_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3, double daño)
{
    switch (tipo_arma)
    {
        case arma_baston:

            return make_unique<baston>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        case arma_libro_de_hechizos:
            return make_unique<libro_de_hechizos>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        case arma_pocion:
            return make_unique<pocion>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        case arma_amuleto:
            return make_unique<amuleto>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        case arma_hacha_simple:
            return make_unique<hacha_simple>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        case arma_hacha_doble:
            return make_unique<hacha_doble>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        case arma_espada:
            return make_unique<espada>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        case arma_garrote:
            return make_unique<garrote>(tipo_arma, dato1, dato2, dato3, daño);
            break;
        break;
    
    default:
        return nullptr;
        break;
    }
}

////////////////////////////////////////////implementacion metodos de la clase abstracta mago/////////////////////////////////

mago::mago(tipos_magos tip_mago, hab_totales hab_especial, int magia, double vida, int max_armas)
{
    try
    {
        if (corroborar_intervalo(0,magia,10) && corroborar_intervalo(0,vida, 100) && corroborar_intervalo(0, max_armas, 10))
        {
            tipo_mago = tip_mago;

            habilidad_especial = hab_especial;
        
            poder_magia = magia;
        
            hp = vida;
        
            cant_armas = max_armas;
        
            if (pertenece_hab_magicas(hab_especial)) // en caso de que la habilidad sea de las magicas, se usa el 100% del daño
            {
               daño_hab = daño_hab_magicos_combate[static_cast<int>(hab_especial)];
            }
            else // en caso de que la habilidad sea de las de combate, se usa el 60% del daño
            {
                daño_hab = daño_hab_magicos_combate[static_cast<int>(hab_especial)]*(0.6);
            }
            usos_hab = usos_hab_magicas_combate[static_cast<int>(hab_especial)];
        }
        else
        {
            throw logic_error("error, verifique que los parametros ingresados sean correctos");
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

void mago::mostrar_hp() const
{
    cout << "cantidad de vida: " << hp << endl;
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

void mago::agregar_arma(armas_totales tipo_arma, float dato1, float dato2, float dato3)
{
    try
    {
        if (contar_armas() < cant_armas)
        {
            double daño = daño_magicos_combate[static_cast<int>(tipo_arma)];

            if (pertenece_armas_magicas(tipo_arma)) // en caso de que pertenezca a un item magico, se usa el 100% del daño 
            {
                if (!arma1)
                {
                    arma1 = crear_arma(tipo_arma, dato1, dato2, dato3, daño);
                }
                else
                {
                    arma2 = crear_arma(tipo_arma, dato1, dato2, dato3, daño);
                }
            }
            else if (pertenece_armas_combate(tipo_arma)) // en caso de que pertenezca a un arma de combate, se usa el 80% del daño 
            {
                if (!arma1)
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

int mago::contar_armas()
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

// implementacion de la clase derivada hechicero //

hechicero::hechicero(hab_totales hab_especial, int magia, int max_armas, float hab_fuente) : mago(a_hechicero, hab_especial, magia, 100, max_armas), habilidad_fuente(hab_fuente)
{
    try
    {
        if (!corroborar_intervalo(0, hab_fuente, 10))
        {
            throw logic_error("error, ingrese una habilidad[0,10] de fuente dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void hechicero::Get_habilidad_fuente()
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
            throw logic_error("error, ingrese una nivel de conocimiento ancestral[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void conjurador::Get_conocimiento()
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
            throw logic_error("error, ingrese una nivel de manipulacion de naturaleza[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void brujo::Get_manipulacion_naturaleza()
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
            throw logic_error("error, ingrese una nivel de manipulacion de almas[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void nigromante::Get_manipulacion_almas()
{
    cout << "nivel de manipulacion de almas: " << manipulacion_almas << endl;
}

////////////////////////////////////////////implementacion metodos de la clase abstracta guerrero/////////////////////////////////

guerrero::guerrero(tipos_guerreros guerrero, float fuerza, hab_totales hab_especial, double vida, int armas)
{
    try
    {
        if (corroborar_intervalo(0,fuerza,1000) && corroborar_intervalo(0, vida, 100) && corroborar_intervalo(0, armas, 2))
        {
            tipo_guerrero = guerrero;

            habilidad_especial = hab_especial;
        
            capacidad_fuerza = fuerza;
        
            hp = vida;

            cant_armas = armas;
        
            if (!pertenece_hab_magicas(hab_especial)) // en caso de que la habilidad sea de las de combate, se usa el 100% del daño
            {
               daño_hab = daño_hab_magicos_combate[static_cast<int>(hab_especial)];
            }
            else // en caso de que la habilidad sea de las magicas, se usa el 60% del daño
            {
                daño_hab = daño_hab_magicos_combate[static_cast<int>(hab_especial)]*(0.6);
            }
            usos_hab = usos_hab_magicas_combate[static_cast<int>(hab_especial)];
        }
        else
        {
            throw logic_error("error, verifique que todos los parametros ingresados sean correctos y esten dentro del rango");
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
    cout << "cantidad de daño de la habilidad especial: " << daño_hab;
    cout << "cantidad de usos de la habilidad especial: " << usos_hab;
    cout << "capacidad de fuerza: " << capacidad_fuerza << endl;
}

void guerrero::mostrar_hp() const
{
    cout << "vida del guerrero: " << hp << endl;
}

double guerrero::retornar_hp() const
{
    return hp;
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
            double daño = daño_magicos_combate[static_cast<int>(tipo_arma)];

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

int guerrero::contar_armas()
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

// implementacion de la clase derivada barbaro //

barbaro::barbaro(hab_totales habilidad, float fuerza, int max_armas, float salvaje) : guerrero( a_barbaro, fuerza, habilidad, 100, max_armas), espiritu_salvaje(salvaje)
{
    try
    {
        if (!corroborar_intervalo(0, salvaje, 10))
        {
            throw logic_error("error, ingrese un nivel de espiritu salvaje[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void barbaro::Get_espiritu_salvaje()
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
            throw("error, ingrese un nivel de aura protectora[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void paladin::Get_aura_protectora()
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
            throw("error, ingrese un nivel de habilidad marcial[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void caballero::Get_habilidad_marcial()
{
    cout << "nivel de habilidad marcial: " << habilidad_marcial << endl;
}

// implementacion de la clase derivada mercenario //

mercenario::mercenario(hab_totales habilidad, float fuerza, float aura, int max_armas, float astucia) : guerrero(a_mercenario,fuerza, habilidad, 100, max_armas), nivel_astucia(astucia)
{
    try
    {
        if (!corroborar_intervalo(0, astucia, 10))
        {
            throw("error, ingrese un nivel de astucia[0,10] dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void mercenario::Get_astucia()
{
    cout << "nivel de astucia: " << nivel_astucia << endl;
}

// implementacion de la clase derivada gladiador //

gladiador::gladiador(hab_totales habilidad, float fuerza, float aura, int max_armas, float adaptacion) : guerrero(a_gladiador,fuerza, habilidad, 100, max_armas), adaptabilidad(adaptacion)
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

void gladiador::Get_adaptacion()
{
    cout << "nivel de adaptabilidad: " << adaptabilidad << endl;
}
