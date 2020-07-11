///////////////////////////////////////////////////////////////////////////////
//  El grado máximo será el que ocupe la posición 0 del vector
//
//
//  Clase POolinomio. Hecha por: Carlos Salas Eiroa
///////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <iomanip>
#include <Polinomio.h>

using namespace std;


//CONSTRUCTORES Y DESTRUCTORES

Polinomio :: Polinomio(void){
    reservaMem();
}
Polinomio :: Polinomio(int num_casillas){
    reservaMem(num_casillas);
}
Polinomio :: Polinomio(const Polinomio & otro){
    clonar(otro);
}

Polinomio :: ~Polinomio(void){
    eliminaMem();
}

//AJUSTAR

void Polinomio :: reservaMem(int num_casillas){
    setMaxGrado(num_casillas);
    coef = new double[num_casillas+1];
}
void Polinomio :: reservaMem(void){
    setMaxGrado(MAX_GRADO_DEF);
    coef = new double[getMaxGrado()+1];
}
void Polinomio :: eliminaMem(void){
    if(coef != 0){
        delete [] coef;
    }

    coef = 0;
    setMaxGrado(0);

    
}


void Polinomio :: setMaxGrado(int num_casillas){
    max_grado = num_casillas;
}


void Polinomio :: setElemento(double valor, int grado){
    int posicion = getMaxGrado() - grado;

    if(posicion < 0){
        cout << "Grado no válido" << endl;
    }
    else{
        coef[posicion] = valor;
    }
}

void Polinomio :: setPolinomio(void){

    double valor;

    for(int i = 0; i <= getMaxGrado(); i++){
        cout << "Introduzca el valor del coeficiente de grado " << getMaxGrado()-i << ":" << endl;
        cin >> valor;
        setElemento(valor, getMaxGrado()-i);
    }
}

void Polinomio :: clonar(const Polinomio & otro){
    eliminaMem();
    reservaMem(otro.getMaxGrado());

    for(int i = 0; i <= getMaxGrado(); i++){
        setElemento(otro.getValor(i),i);
    }
}


//OBTENER VALORES

int Polinomio ::  getMaxGrado(void) const{
    return max_grado;
}

double & Polinomio :: getValor(int grado){      //Si dan un grado mayor al máx
    if(!(grado > getMaxGrado())){               //devolverá el valor del grado
        return coef[getMaxGrado()-grado];       //mayor
    }
    else{
        return coef[0];
    }
} 

double & Polinomio :: getValor(int grado) const{      //Si dan un grado mayor al máx
   if(!(grado > getMaxGrado())){                      //devolverá el valor del grado
        return coef[getMaxGrado()-grado];             //mayor
    }
    else{
        return coef[0];
    }
}


void Polinomio :: muestraPolinomio(void){
    for(int i = 0; i <= getMaxGrado(); i++){
        if(coef[i] != 0){
            if(getMaxGrado()-i != 0){
                cout << setw(8) <<  coef[i] << "x^"<<getMaxGrado()-i;
            }
            else{
                cout << setw(8) <<  coef[i];
            }
        }
    }

    cout << endl;
}

//COMPARADORES
bool Polinomio :: esIgual(const Polinomio & otro){
    bool iguales = (getMaxGrado() == otro.getMaxGrado() ? true:false);

    if(iguales){
        for(int i =0; i <= getMaxGrado() && iguales; i++){
            if(getValor(i) != otro.getValor(i)){
                iguales = false;
            }
        }
    }

    return iguales;

}

bool Polinomio :: esMayor(const Polinomio & otro){
    bool mayor = (getMaxGrado() - otro.getMaxGrado() > 0);

    if(getMaxGrado() == otro.getMaxGrado()){
        for(int i = getMaxGrado(); i >= 0 && !mayor; i--){
            if(getValor(i) > otro.getValor(i)){
                mayor = true;
            }
        }
    }

    return mayor;
}


//SOBRECARGA OPERADORES

double & Polinomio :: operator [] (const int grado){
    return getValor(grado);
}

Polinomio & Polinomio :: operator = (const Polinomio & otro){
    clonar(otro);
    return (*this);
}

Polinomio Polinomio :: operator + (void){
    return (*this);
}
Polinomio Polinomio :: operator + (const Polinomio & otro){
    int GradoMax = (getMaxGrado() > otro.getMaxGrado() ? getMaxGrado():otro.getMaxGrado());
    bool thisMayor = getMaxGrado() > otro.getMaxGrado();
    int DifGrado;

    if(thisMayor){
        DifGrado = getMaxGrado() - otro.getMaxGrado();
    }
    else{
        DifGrado = otro.getMaxGrado() - getMaxGrado();
    }

    Polinomio tmp(GradoMax);

    if(thisMayor){
        for(int i = 0; i <= GradoMax-DifGrado; i++){
            tmp.setElemento(getValor(i)+otro.getValor(i),i);
        }

        for(int i = GradoMax-DifGrado+1; i <= GradoMax; i++){
            tmp.setElemento(getValor(i), i);
        }
    }
    else{

        for(int i = 0; i <= GradoMax-DifGrado; i++){
            tmp.setElemento(getValor(i)+otro.getValor(i),i);
        }

        for(int i = GradoMax-DifGrado+1; i <= GradoMax; i++){
            tmp.setElemento(otro.getValor(i), i);
        }
    }

    return tmp;
}
Polinomio Polinomio :: operator + (const double num){
    Polinomio tmp(0);
    tmp[0] = num;

    tmp = *this + tmp;

    return tmp;
}


Polinomio Polinomio :: operator - (void){
    Polinomio tmp(*this);

    for(int i = 0; i <= tmp.getMaxGrado(); i++){
        tmp.setElemento(tmp.getValor(i)*(-1), i);
    }

    return tmp;
}
Polinomio Polinomio :: operator - (const Polinomio & otro){
    Polinomio tmp;
    tmp = otro;
    return (*this+(-tmp));
}
Polinomio Polinomio :: operator - (const double num){
    Polinomio tmp(0);
    tmp[0] = num*(-1);

    tmp = *this + tmp;

    return tmp;
}


bool Polinomio :: operator == (const Polinomio & otro){
    return esIgual(otro);

}
bool Polinomio :: operator != (const Polinomio & otro){
    return !(esIgual(otro));
}


bool Polinomio :: operator > (const Polinomio & otro){
    return esMayor(otro);
}
bool Polinomio :: operator >= (const Polinomio & otro){
    return ( esMayor(otro) || esIgual(otro));
}


bool Polinomio :: operator < (const Polinomio & otro){
    return !(esMayor(otro) && esIgual(otro));
}
bool Polinomio :: operator <= (const Polinomio & otro){
    return !(esMayor(otro));
}