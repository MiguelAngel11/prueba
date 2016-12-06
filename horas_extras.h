class empresa
{
public:
        int hora_inicio;
        int hora_salida;
        int hora_salida2;
        //constructores
        empresa();
        //operaciones
        virtual void extra_diurna()=0;
        virtual void extra_nocturna()=0;
        virtual void recargo_dominical()=0;
        virtual void extra_diurna2()=0;
        virtual void extra_nocturna2()=0;
        virtual void recargo_dominical2()=0;
        virtual void tipo_trabajor()=0;
};

class empleado : public empresa
{
public:
        char nombre[20];
        double pago_hora;
        double tiempo_trabajo;
        double min_extra;
        double total;
        //constructor
        empleado();
        //operaciones
        virtual void extra_diurna();
        virtual void extra_nocturna();
        virtual void recargo_dominical();
        virtual void extra_diurna2();
        virtual void extra_nocturna2();
        virtual void recargo_dominical2();
        virtual void tipo_trabajor();
        void dia();
        void dia2();
        void capturar(void);
};
