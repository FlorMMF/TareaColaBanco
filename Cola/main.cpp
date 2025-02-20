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

        Cola<string> Caja1;
        Cola<string> Caja2;
        Cola<string> Caja3;
        Cola<string> Fila;
        int tiempo = (rand() % 10 +1);
        int tiempoQuitar1 = (rand() % 15 +1);
        int tiempoQuitar2 = (rand() % 15 +1);
        int tiempoQuitar3 = (rand() % 15 +1);
        int tiempoBanco = (rand() % 120 +120);

        for (int i = 0; i < tiempoBanco; ++i){
            cout << "Reloj: " << i << endl;

            if(Caja1.EstaVacia()){
                cout << "La caja 1 esta desocupada" << endl;
                Caja1.Encolar("Persona");
                tiempoQuitar1 = (rand() % 15 +1) + i;
            }else if(tiempoQuitar1 == i){
                cout << "La caja 1 esta ocupada por " << Caja1.ObtenerPrimero() << endl;
                Caja1.Desencolar();
            }else{
                cout << "La caja 1 esta ocupada por " << Caja1.ObtenerPrimero() << endl;
            }

            if(Caja2.EstaVacia()){
                cout << "La caja 2 esta desocupada" << endl;
                Caja2.Encolar("Persona");
                tiempoQuitar2 = (rand() % 15 +1) + i;
            }else if(tiempoQuitar2 == i){
                cout << "La caja 2 esta ocupada por " << Caja2.ObtenerPrimero() << endl;
                Caja2.Desencolar();
            }else{
                cout << "La caja 2 esta ocupada por " << Caja2.ObtenerPrimero() << endl;
            }

            if(Caja3.EstaVacia()){
                cout << "La caja 3 esta desocupada" << endl;
                Caja3.Encolar("Persona");
                tiempoQuitar3 = (rand() % 15 +1) + i;
            }else if(tiempoQuitar3 == i){
                cout << "La caja 3 esta ocupada por " << Caja3.ObtenerPrimero() << endl;
                Caja3.Desencolar();
            }else{
                cout << "La caja 3 esta ocupada por " << Caja3.ObtenerPrimero() << endl;
            }

            Sleep(1000);
            system("cls");
        }

    }catch(const char *mensaje){
        cerr << mensaje;
    }
    return 0;
}
