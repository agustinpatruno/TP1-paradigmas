#include "ejercicio3.hpp"

int generarNumeroAleatorio(int minimo, int maximo) 
{
    return minimo + (rand() % (maximo - minimo + 1));
}

////////////////////////////////////////implementacion de los metodos de personaje armado//////////////////////////////////////////////

personaje_armado::personaje_armado(tipos_personajes personaje, double hp, auto dato1, auto dato2, habilidades_especiales_magicas_y_combate hab_especial, int cant_armas)
{
    try
    {
        if (pertenece_a_magos(personaje))
        {
            avatar = make_shared<mago>(string personaje, double hp, auto dato1, auto dato2, string hab_especial);
        }
        else if (pertenence_a_guerreros(personaje))
        {
            avatar = make_shared<guerrero>(string personaje, double hp, auto dato1, auto dato2, string hab_especial);
        }
        else
        {
            throw logic_error("error, ingrese un peesonaje que sea de tipo amgo o de tipo guerrero");
        }
        cant_armas_maximas = cant_armas;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void personaje_armado::atacar(personaje_armado& otro, bool normal, int indice_arma)
{
    try
    {
        if ( 0 <= indice_arma <= 2 && armas[indice_arma] != nullptr)
        {
            otro.modificar_hp(armas[indice_arma]->devolver_daño(normal));
        }
        else
        {
            throw logic_error("error, verifique que el indice este dentro de las opciones y que el arma exista");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void personaje_armado::modificar_hp(double daño)
{
    try
    {
        if (daño > 0 && avatar->retornar_hp() >  daño)
        {
            avatar->modificar_hp(daño);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void personaje_armado::mostrar_tipo_personaje()
{
    avatar ->mostrar_tipo_personaje();
}

void personaje_armado::mostrar_hp()
{
    avatar ->mostrar_hp();
}

void personaje_armado::mostrar_cant_golpes_totales()
{
    for (int i = 0; i < armas.size(); i++)
    {
        cout << "arma " << i << endl;
        armas[i] -> mostrar_golpes_disponibles();
        armas[i] -> mostrar_golpes_dispo_especial();
    }
}

void personaje_armado::mostrar_daños_totales()
{
    for (int i = 0; i < armas.size(); i++)
    {
        cout << "arma " << i << endl;
        armas[i] -> mostrar_daño();
        armas[i] -> mostrar_daño_especial();
    }
}

void personaje_armado::crear_arma(string tip_arma, double daño, int cant_usos_dispo, string habilidad_espe, double daño_extra_espe, int cant_usos_espe)
{
    try
    {
        if (armas.size() < cant_armas_maximas)
        {
            shared_ptr<arma> nueva_arma;

            if (pertenece_en_magicos(tip_arma))
            {
                nueva_arma = make_shared<items_magicos>(tip_arma, daño, cant_usos_dispo, habilidad_espe, daño_extra_espe, cant_usos_espe);
            }
            else if (pertenece_en_combate(tip_arma))
            {
                nueva_arma = make_shared<armas_combate>(tip_arma, daño, cant_usos_dispo, habilidad_espe, daño_extra_espe, cant_usos_espe);
            }
            else
            {
                throw logic_error("ingrese un tipo de arma que este dentro del conjunto de item amgicos o dentro del conjunto de armas de combate");
            }
        }
        else
        {
            throw logic_error("error, no puedes ingresar mas armas al personaje. no hay mas espacio");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void personaje_armado::mostrar_datos_adicionales()
{
    avatar -> mostrar_dato1();
    avatar -> mostrar_dato2();
}

////////////////////////////////////implementacion de los metodos de la clase personajefactory ///////////////////////////////////

PersonajeFactory::PersonajeFactory()
{
    cout << " se creo un objeto de la clase factory" << endl;
}

shared_ptr<arma> PersonajeFactory::crear_arma(string tip_arma, double daño, int cant_usos_dispo, string habilidad_espe, double daño_extra_espe, int cant_usos_espe)
{
    shared_ptr<arma> nueva_arma;

    if (pertenece_en_magicos(tip_arma))
    {
        nueva_arma = make_shared<items_magicos>(tip_arma, daño, cant_usos_dispo, habilidad_espe, daño_extra_espe, cant_usos_espe);
    }
    else if (pertenece_en_combate(tip_arma))
    {
        nueva_arma = make_shared<armas_combate>(tip_arma, daño, cant_usos_dispo, habilidad_espe, daño_extra_espe, cant_usos_espe);
    }
    else
    {
        return nullptr;
    }
    return nueva_arma;
}

shared_ptr<personaje> PersonajeFactory::crear_personaje(string personaje, double hp, auto dato1, auto dato2, string hab_especial)
{
    shared_ptr<personaje> nuevo_personaje;

    if (pertenece_a_magos(personaje))
    {
        nuevo_personaje = make_shared<mago>(string personaje, double hp, auto dato1, auto dato2, string hab_especial);
    }
    else if (pertenence_a_guerreros(personaje))
    {
        nuevo_personaje = make_shared<guerrero>(string personaje, double hp, auto dato1, auto dato2, string hab_especial);
    }
    else
    {
        return nullptr;
    }
    return nuevo_personaje;

}

shared_ptr<personaje_armado> PersonajeFactory::crear_personaje_armado(string personaje, double hp, auto dato1, auto dato2, string hab_especial,string tip_arma, double daño, int cant_usos_dispo, string habilidad_espe, double daño_extra_espe, int cant_usos_espe)
{
    shared_ptr<personaje_armado> nuevo_personaje_armado;

    nuevo_personaje_armado -> avatar = crear_personaje(string personaje, double hp, auto dato1, auto dato2, string hab_especial);

    nuevo_personaje_armado ->

}


int main()
{
    srand(time(0));
}
