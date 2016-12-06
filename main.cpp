#include <iostream>
#include"horas_extras.h"

using namespace std;

int main()
{
    cout<<"                                       -----------------------------------------------------------------------------------"<<endl<<"                                       ============================= BIENVENIDO A LA EMPRESA ============================="<<endl<<"                                       -----------------------------------------------------------------------------------"<<endl<<endl<<endl<<endl;
    cout<<"A continuacion podra calcular el pago de sus horas extra "<<endl<<"Recuerde que la jornada laborar en la empresa inicia a las 8am y solo podra calcular sus horas extra durante 24 horas"<<endl<<endl;
    empleado p1,p2,p3;
    p1.capturar();
    p1.tipo_trabajor();

    p2.capturar();
    p2.tipo_trabajor();

    p3.capturar();
    p3.tipo_trabajor();

    cout<<endl<<endl;

    return 0;
}
