#include "abs_mago.hpp"
#include "abs_guerrero.hpp"

int main()
{

    unique_ptr<hechicero> nu_hechi = make_unique<hechicero>(Rafaga_magica, 7, 2, 8);

    nu_hechi ->Get_habilidad_fuente();
    nu_hechi ->mostrar_hp();
    nu_hechi ->mostrar_info_personaje();
    nu_hechi ->modificar_hp(16);
    cout << "vida: " << nu_hechi ->retornar_hp()<< endl; 

}