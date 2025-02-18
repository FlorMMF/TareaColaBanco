#include <iostream>
#include "Cola.hpp"
#include <windows.h>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    try{
//        Cola <double> ColaDouble;
//        ColaDouble.Encolar(12);
//        ColaDouble.Encolar(3.2);
//        ColaDouble.Encolar(7);
//        ColaDouble.imprimir();
//        cout << endl;
//        ColaDouble.Desencolar();
//        ColaDouble.imprimir();
//        ColaDouble.Desencolar();
//        ColaDouble.imprimir();
//        cout << endl << ColaDouble.CantidadElementos() << endl;
//        ColaDouble.Encolar(12);
//
//        ColaDouble.imprimir();
//        cout << endl;
//        ColaDouble.Vaciar();
//        ColaDouble.imprimir();
//        cout << endl;
//
//        ColaDouble.Encolar(12);
//        ColaDouble.Encolar(3);
//        ColaDouble.Encolar(-2.3);
//        ColaDouble.imprimir();
//        cout << endl;
//
//        Cola<double> ColaCopia(ColaDouble);
//        ColaDouble.Desencolar();
//        cout << endl;
//        ColaDouble.imprimir();
//        cout << endl;
//        ColaCopia.imprimir();
//
//        cout << endl;
        srand (time(NULL));

        Cola<string> ColaTiempo;
        int tiempo = (rand() % 15 +1);
        int tiempoQuitar = (rand() % 15 +1);
        for (int i = 0; i < 120; ++i){
            if(tiempo == i){
                ColaTiempo.Encolar("Pedrito");
                ColaTiempo.imprimir();
                cout << endl;
                tiempo = (rand() % 7 +1) +i;
            }
            if((ColaTiempo.EstaVacia()) && (tiempoQuitar == i)){
                tiempoQuitar = (rand() % 15 +1) +i;
            }else if ((!ColaTiempo.EstaVacia()) && (tiempoQuitar == i)){
                ColaTiempo.Desencolar();
                cout << "desencolado    " << endl;
                ColaTiempo.imprimir();
                cout << endl;
                tiempoQuitar = (rand() % 15 +1) +i;

            }
            Sleep(1000);
        }

    }catch(const char *mensaje){
        cerr << mensaje;
    }
    return 0;
}
