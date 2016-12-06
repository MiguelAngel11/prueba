#include<iostream>
#include"horas_extras.h"

using namespace std;

empresa::empresa()
{
    hora_inicio=8;
    hora_salida=16;
    hora_salida2=12;
}

empleado::empleado()
{
    total=0.0;
    min_extra=0.0;
}

void empleado::capturar(void)
{
    double a,b;
    cout<<endl<<"Ingrese su nombre: ";
    cin>>nombre;
    cout<<endl<<"Ingrese el valor de su salario mensual en pesos: ";
    cin>>b;
    pago_hora=b/240;
    cout<<endl<<"En sistema horario de 24 horas ingrese a que hora finalizo el trabajo: ";
    cin>>a;
    if(a<=24){
        tiempo_trabajo=a;
    }
    else{cout<<endl<<"La hora "<<a<<" no corresponde al sistema horario de 24 horas";
        while(a>24){
            cout<<endl<<endl<<"En sistema horario de 24 horas ingrese a que hora finalizo el trabajo: ";
            cin>>a;
        }
        tiempo_trabajo=a;
    }
}

void empleado::extra_diurna()
{
    double t,h,x,y;
    t=tiempo_trabajo-hora_salida;
    if(-8<t && t<=0){
        cout<<endl<<"Usted aun no termina su jornada laboral de 8 horas";
    }
    if(1<=tiempo_trabajo && tiempo_trabajo<=8){
        if(7==tiempo_trabajo || tiempo_trabajo==8){
            h=(pago_hora*1.25)*tiempo_trabajo;
            cout<<endl<<endl<<"========> La empresa debe pagarle "<<h<<" pesos, por trabajar "<<tiempo_trabajo<<" horas extras diurnas";
            min_extra=tiempo_trabajo+min_extra;
            total=h+total;
        }
        else{
        x=(pago_hora*1.25)*6;
        cout<<endl<<endl<<"========> La empresa debe pagarle "<<x<<" pesos, por trabajar 6 horas extras diurnas";
        min_extra=6+min_extra;
        total=x+total;
        }
    }
    else{
        if(23<=tiempo_trabajo && tiempo_trabajo<=24){
        y=(pago_hora*1.25)*6;
        cout<<endl<<endl<<"========> la empresa debe pagarle "<<y<<" pesos, por trabajar 6 horas extras diurnas";
        min_extra=6+min_extra;
        total=y+total;
        }
    }
    double a,b;
    a=tiempo_trabajo-hora_salida;
    if(a<=6 && a>0){
            b=(pago_hora*1.25)*a;
            cout<<endl<<endl<<"========> la empresa debe pagarle "<<b<<" pesos, por trabajar "<<a<<" horas extras diurnas";
            min_extra=a+min_extra;
            total=b+total;
    }
}

void empleado::extra_nocturna()
{
    double a,b,c,d,x;
    if(23<=tiempo_trabajo && tiempo_trabajo<=24){
        a=tiempo_trabajo-22;
        b=(pago_hora*1.75)*a;
        cout<<endl<<endl<<"========> La empresa debe pagarle "<<b<<" pesos, por trabajar "<<a<<" horas extras nocturas";
        min_extra=a+min_extra;
        total=b+total;
    }

    if(1<=tiempo_trabajo && tiempo_trabajo<=6){
            c= tiempo_trabajo+2;
            d=(pago_hora*1.75)*c;
            cout<<endl<<endl<<"========> La empresa debe pagarle "<<d<<" pesos, por trabajar "<<c<<" horas extras nocturas";
            min_extra=c+min_extra;
            total=d+total;
        }
    if(7==tiempo_trabajo || tiempo_trabajo==8){
            x=(pago_hora*1.75)*8;
            cout<<endl<<endl<<"========> La empresa debe pagarle "<<x<<" pesos, por trabajar 8 horas extras nocturas";
            min_extra=8+min_extra;
            total=x+total;
    }

}

void empleado::recargo_dominical()
{
    double a,b,x,y;
    a= tiempo_trabajo-hora_inicio;
    if(a<=8 && a>0){
        b= (pago_hora*1.75)*a;
        cout<<endl<<endl<<"========> La empresa debe pagarle "<<b<<" pesos, por recargo de "<<a<<" horas dominicales";
        total=b+total;
    }
    if(16<tiempo_trabajo && tiempo_trabajo<=24){
        x=(pago_hora*1.75)*8;
        cout<<endl<<endl<<"========> La empresa debe pagarle "<<x<<" pesos, por recargo de 8 horas dominicales";
        total=x+total;
        extra_diurna();
        extra_nocturna();
    }
    if(1<=tiempo_trabajo && tiempo_trabajo<=8){
        y=(pago_hora*1.75)*8;
        cout<<endl<<endl<<"========> La empresa debe pagarle "<<y<<" pesos, por recargo de 8 horas dominicales";
        total=y+total;
        extra_diurna();
        extra_nocturna();
    }
}

void empleado::extra_diurna2()
{
    double t,h,x,y,q;
    t=tiempo_trabajo-hora_salida2;
    if(-4<t && t<=0){
        cout<<endl<<"usted aun no termina su jornada laboral de 8 horas";
    }
    if(1<=tiempo_trabajo && tiempo_trabajo<=8){
        if(7==tiempo_trabajo || tiempo_trabajo==8){
            q=tiempo_trabajo+4;
            h=(pago_hora*1.25)*q;
            cout<<endl<<endl<<"========> La empresa debe pagarle "<<h<<" pesos, por trabajar "<<q<<" horas extras diurnas";
            min_extra=q+min_extra;
            total=h+total;
        }
        else{
        x=(pago_hora*1.25)*10;
        cout<<endl<<endl<<"========> La empresa debe pagarle "<<x<<" pesos, por trabajar 10 horas extras diurnas";
        min_extra=10+min_extra;
        total=x+total;
        }
    }
    else{
        if(23<=tiempo_trabajo && tiempo_trabajo<=24){
        y=(pago_hora*1.25)*10;
        cout<<endl<<endl<<"========> La empresa debe pagarle "<<y<<" pesos, por trabajar 10 horas extras diurnas";
        min_extra=10+min_extra;
        total=y+total;
        }
    }
    double a,b;
    a=tiempo_trabajo-hora_salida2;
    if(a<=10 && a>0){
            b=(pago_hora*1.25)*a;
            cout<<endl<<endl<<"========> La empresa debe pagarle "<<b<<" pesos, por trabajar "<<a<<" horas extras diurnas";
            min_extra=a+min_extra;
            total=b+total;
    }

}

void empleado::extra_nocturna2()
{
    double a,b,c,d,x;
    if(23<=tiempo_trabajo && tiempo_trabajo<=24){
        a=tiempo_trabajo-22;
        b=(pago_hora*1.75)*a;
        cout<<endl<<endl<<"========> La empresa debe pagarle "<<b<<" pesos, por trabajar "<<a<<" horas extras nocturas";
        min_extra=a+min_extra;
        total=b+total;
    }

    if(1<=tiempo_trabajo && tiempo_trabajo<=6){
            c= tiempo_trabajo+2;
            d=(pago_hora*1.75)*c;
            cout<<endl<<endl<<"========> La empresa debe pagarle "<<d<<" pesos, por trabajar "<<c<<" horas extras nocturas";
            min_extra=c+min_extra;
            total=d+total;
        }
    if(7==tiempo_trabajo || tiempo_trabajo==8){
            x=(pago_hora*1.75)*8;
            cout<<endl<<endl<<"========> La empresa debe pagarle "<<x<<" pesos, por trabajar 8 horas extras nocturas";
            min_extra=8+min_extra;
            total=x+total;
    }
}

void empleado::recargo_dominical2()
{
    double a,b,x,y;
    a= tiempo_trabajo-hora_inicio;
    if(a<=4 && a>0){
        b= (pago_hora*1.75)*a;
        cout<<endl<<endl<<"========> La empresa debe pagarle "<<b<<" pesos, por recargo de "<<a<<" horas dominicales";
        total=b+total;
    }
    if(12<tiempo_trabajo && tiempo_trabajo<=24){
        x=(pago_hora*1.75)*4;
        cout<<endl<<endl<<"========> La empresa debe pagarle "<<x<<" pesos, por recargo de 4 horas dominicales";
        total=x+total;
        extra_diurna2();
        extra_nocturna2();
    }
    if(1<=tiempo_trabajo && tiempo_trabajo<=8){
        y=(pago_hora*1.75)*4;
        cout<<endl<<endl<<"========> La empresa debe pagarle "<<y<<" pesos, por recargo de 4 horas dominicales";
        total=y+total;
        extra_diurna2();
        extra_nocturna2();
    }
}

void empleado::dia()
{
     int x;
     double a,b;
    cout<<endl<<"Seleccione una opcion respecto al dia actual"<<endl<<"1 ) Lunes a sabado"<<endl<<"2 ) domingo o festivo"<<endl<<endl<<"=) ";
    cin>>x;
    switch(x)
    {
    case 1:
            extra_diurna();
            extra_nocturna();
            a=min_extra*60;
            cout<<endl<<endl<<endl<<endl<<endl<<"                       =========== SE\xA5OR "<<nombre<<" LA EMPRESA LE CANCELARA UN TOTAL DE "<<total<<" PESOS POR TRABAJAR "<<a<< " MINUTOS EXTRA ==========="<<endl<<endl;
            break;
    case 2:
            recargo_dominical();
            b=min_extra*60;
            cout<<endl<<endl<<endl<<endl<<endl<<"                       =========== SE\xA5OR "<<nombre<<" LA EMPRESA LE CANCELARA UN TOTAL DE "<<total<<" PESOS POR TRABAJAR "<<b<<" MINUTOS EXTRA ==========="<<endl<<endl;
    }
}

void empleado::dia2()
{
    int y;
    double x,z;
    cout<<endl<<"Seleccione una opcion respecto al dia actual"<<endl<<"1 ) Lunes a sabado"<<endl<<"2 ) domingo o festivo"<<endl<<endl<<"=) ";
    cin>>y;
    switch(y)
    {
    case 1:
            extra_diurna2();
            extra_nocturna2();
            x=min_extra*60;
            cout<<endl<<endl<<endl<<endl<<endl<<"                       =========== SE\xA5OR "<<nombre<<" LA EMPRESA LE CANCELARA UN TOTAL DE "<<total<<" PESOS POR TRABAJAR "<<x<< " MINUTOS EXTRA ==========="<<endl<<endl;
            break;
    case 2:
            recargo_dominical2();
            z=min_extra*60;
            cout<<endl<<endl<<endl<<endl<<endl<<"                       =========== SE\xA5OR "<<nombre<<" LA EMPRESA LE CANCELARA UN TOTAL DE "<<total<<" PESOS POR TRABAJAR "<<z<< " MINUTOS EXTRA ==========="<<endl<<endl;
    }
}

void empleado::tipo_trabajor()
{
    int y;
    cout<<endl<<"Seleccione una opcion respecto a que tipo de trabajor eres "<<endl<<"1 ) trabajador de tiempo completo"<<endl<<"2 ) trabajador de medio tiempo"<<endl<<endl<<"=) ";
    cin>>y;
    switch(y)
    {
    case 1:
            dia();
            break;
    case 2:
            dia2();
    }
}
