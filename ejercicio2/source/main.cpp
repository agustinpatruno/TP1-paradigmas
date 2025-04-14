#include "../includes/abs_mago.hpp"
#include "../includes/abs_guerrero.hpp"


// comando para compilar
// g++ abs_combate.cpp abs_guerrero.cpp abs_items.cpp abs_mago.cpp interfaz_personajes.cpp interfaz_armas.cpp main.cpp  -o programa //

/*
int main()
{
    // menu para corroborar el funcionamiento de los personajes // 
    
    unique_ptr<hechicero> nuevo_hechicero = make_unique<hechicero>(Corte_giratorio, 7, 2, 8);

    nuevo_hechicero ->mostrar_info_personaje();
    nuevo_hechicero ->mostrar_hp();
    nuevo_hechicero ->mostrar_caracteristica_mago();
    nuevo_hechicero ->modificar_hp(16);
    cout << "vida: " << nuevo_hechicero ->retornar_hp()<< endl; 

    nuevo_hechicero ->agregar_arma(arma_baston, 6, 3, 5.4);
    nuevo_hechicero ->info_arma();

    cout << "------------------" << endl;

    unique_ptr<conjurador> nuevo_conjurador = make_unique<conjurador>(Corte_espectral, 8, 2, 9);

    nuevo_conjurador -> mostrar_info_personaje();
    nuevo_conjurador -> mostrar_hp();
    nuevo_conjurador -> mostrar_caracteristica_mago();
    nuevo_conjurador -> modificar_hp(16);
    cout << "vida: " << nuevo_conjurador ->retornar_hp()<< endl; 

    nuevo_conjurador ->agregar_arma(arma_pocion, 6, 3, 5.4);
    nuevo_conjurador ->info_arma();

    cout << "------------------" << endl;

    unique_ptr<barbaro> nuevo_barbaro = make_unique<barbaro>(Golpe_perforante, 700, 2, 8);

    nuevo_barbaro -> mostrar_info_personaje();
    nuevo_barbaro -> mostrar_hp();
    nuevo_barbaro -> mostrar_caracteristica_guerrero();
    nuevo_barbaro -> modificar_hp(18);
    cout << "vida: " << nuevo_barbaro ->retornar_hp()<< endl; 

    nuevo_barbaro ->agregar_arma(arma_pocion, 6, 3, 5.4);
    nuevo_barbaro ->info_arma();
    
   return 0;
}
*/