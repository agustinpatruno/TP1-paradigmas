#include <iostream>
#include <string>
#include <memory>
using namespace std;

class arma
{
    public:
        virtual ~arma(/* args */) = default;

        virtual void mostrar_tipo_arma();

        virtual void mostrar_daño();

        virtual int mostrar_cantidad_de_usos();

        virtual void restar_usos();

        virtual void restar_daño();

};
arma::arma(/* args */)
{
}