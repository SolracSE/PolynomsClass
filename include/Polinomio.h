#ifndef POLINOMIO
#define POLINOMIO

///////////////////////////////////////////////////////////////////////////////
//  El grado máximo será el que ocupe la posición 0 del vector
//
//
//  Clase Polinomio. Hecha por: Carlos Salas Eiroa
///////////////////////////////////////////////////////////////////////////////




class Polinomio{
private:

    double * coef = 0;
    int max_grado = 0;

    static const int MAX_GRADO_DEF = 10;

public:


//CONSTRUCTORES Y DESTRUCTORES
    Polinomio(void);                        //Constructor vacio
    Polinomio(int num_casillas);            //Constructo con tamaño
    Polinomio(const Polinomio & otro);      //Constructor copia

    ~Polinomio(void);                       //Destructo de memoría dinámica

//AJUSTAR

    void reservaMem(int num_casillas);      //Reserva memoria con tamaño para
                                            //almacenar num_casillas
    void reservaMem(void);                  //Reserva el MAX_GRADO_DEF=10

    void eliminaMem(void);                  //Borra los datos y maxGrado=0

    void setMaxGrado(int num_casillas);     //Da valor a MaxGrado

    void setElemento(double valor, int grado);  //Da valor al grado que indique

    void setPolinomio(void);                //Da valor a todos los grados

    void clonar(const Polinomio & otro);    //clona un polinomio en el implí.


//OBTENER VALORES
    int getMaxGrado(void) const;            //Devuelve el valor MaxGrado

    double & getValor(int grado);           //Devuelve referencia al valor 
    double & getValor(int grado) const;     //del grado que se indique

    void muestraPolinomio(void);            //Muestra los valores del polinomio

//COMPARADORES
    bool esIgual(const Polinomio & otro);
    bool esMayor(const Polinomio & otro);

//SOBRECARGA OPERADORES

    double & operator [] (const int grado);     //Llama getValor()

    Polinomio & operator = (const Polinomio & otro);    //Llama clonar()

    Polinomio operator + (void);               //Devuelve el polinomio*1
    Polinomio operator + (const Polinomio & otro);    //Suma valores de 2 pols.
    Polinomio operator + (const double num);          //Suma un num a un pol.

    Polinomio operator - (void);               //Devuelve el polinomio*(-1)
    Polinomio operator - (const Polinomio & otro);   //Resta valores de 2 pols.
    Polinomio operator - (const double num);         //Resta un num a un pol.


    bool operator == (const Polinomio & otro);
    bool operator != (const Polinomio & otro);
    bool operator > (const Polinomio & otro);
    bool operator >= (const Polinomio & otro);
    bool operator < (const Polinomio & otro);
    bool operator <= (const Polinomio & otro);


};

#endif
