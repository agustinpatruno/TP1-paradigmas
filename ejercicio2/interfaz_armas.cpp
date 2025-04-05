#include "interfaz_armas.hpp"

bool pertenece_en_magicos(string tipo_arma)
{
    vector<string> tipos_armas = {"bastón", "libro de hechizos", "poción" , "amuleto"};

    for (int i = 0; i < tipos_armas.size(); i++)
    {
        if (tipo_arma == tipos_armas[i])
        {
            return true;
        }
    }
    return false;
}

bool pertence_en_rareza(string rareza)
{
    vector<string> rarezas = {"normal","epico","legendario"};

    for (int i = 0; i < rarezas.size(); i++)
    {
        if (rareza == rarezas[i])
        {
            return true;
        }
    }
    return false;
}

items_magicos::items_magicos(string tip_arma, string rareza, double daño_arma, int cant_golpes, int cant_golpes_extra)
{
    try
    {
        if (daño_arma > 0 && cant_golpes > 0 && cant_golpes_extra >= 0 && pertenece_en_magicos(tip_arma)&& pertence_en_rareza(rareza))
        {
            daño = daño_arma;
            cantidad_golpes_disponibles = cant_golpes;
            golpes_extra = cant_golpes_extra;

            tipo_arma = tip_arma;
            nivel_rareza = rareza;
        }
        else
        {
            throw logic_error("error, verifique que los parametros ingresados sean correctos y acorde a los items magicos");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void items_magicos::mostrar_tipo_arma()
{
    cout << "tipo de arma magica: " << tipo_arma << endl;
}

void items_magicos::mostrar_daño()
{
    cout << "poder de daño: " << daño << endl;
}

void items_magicos::restar_usos()
{
    cantidad_golpes_disponibles-=1;
}

void items_magicos::mostrar_golpes_disponibles()
{
    cout << "cantidad de golpes disponibles: " << cantidad_golpes_disponibles << endl;
}

void items_magicos::mostrar_rareza()
{
    cout << "tipo de rareza: " << nivel_rareza << endl;
}

void items_magicos::mostrar_golpes_extra()
{
    cout << "cantidad de golpes extra: " << golpes_extra << endl;
}

//////////////////////implementacion metodos de la clase armas_combate//////////////////////////////

bool pertenece_en_combate(string tipo_arma)
{
    vector<string> tipos_armas = { "hacha simple","hacha doble","espada","lanza","garrote"};

    for (int i = 0; i < tipos_armas.size(); i++)
    {
        if (tipos_armas[i] == tipo_arma)
        {
            return true;
        }
    }
    return false;
}

armas_combate::armas_combate(string tip_arma, string rareza, double daño_arma, int cant_golpes, int cant_golpes_extra)
{
    try
    {
        if (daño_arma > 0 && cant_golpes > 0 && cant_golpes_extra >= 0 && pertenece_en_combate(tip_arma)&& pertence_en_rareza(rareza))
        {
            daño = daño_arma;
            cantidad_golpes_disponibles = cant_golpes;
            golpes_extra = cant_golpes_extra;

            tipo_arma = tip_arma;
            nivel_rareza = rareza;
        }
        else
        {
            throw logic_error("error, verifique que los parametros ingresados sean correctos y acordes a las armas de combate");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void armas_combate::mostrar_tipo_arma()
{
    cout << " tipo de arma de combate: " << tipo_arma << endl;
}

void armas_combate::mostrar_daño()
{
    cout << " poder de daño: " << daño << endl;
}

void armas_combate::restar_usos()
{
    cantidad_golpes_disponibles-= 1;
}

void armas_combate::mostrar_golpes_disponibles()
{
    cout << "cantidad de golpes disponibles: " << cantidad_golpes_disponibles << endl;
}

void armas_combate::mostrar_rareza()
{
    cout << "tipo de rareza " << nivel_rareza << endl;
}

void armas_combate::mostrar_golpes_extra()
{
    cout << " cantidad de golpes extra: " << golpes_extra << endl;
}