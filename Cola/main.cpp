#include <iostream>
#include "Cola.hpp"
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

const int MAX_CLI = 100;

void leerNombres(const string& nombreArchivo, string nombrecli[], int& totalcli){
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()){
        string linea;
        while (getline(archivo, linea) && totalcli < MAX_CLI){
            if (!linea.empty()){
                nombrecli[totalcli++] = linea;
            }
        } archivo.close();
    }
}

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
        string nombreArchivo = "Nombres.txt";
        string nombrecli[MAX_CLI];
        int totalcli = 0;
        int indice = 0;
        leerNombres(nombreArchivo, nombrecli, totalcli);

        cout << "Las cajas atenderan a tantos clientes puedan en " << tiempoBanco << " minutos" << endl;
        cout << "\nEl tiempo que tarda cada uno de las personas es totalmente aleatorio" << endl;

        system("pause");


        for (int i = 0; i < tiempoBanco; ++i){
            cout << "Las cajas atenderan a tantos clientes puedan en " << tiempoBanco << " minutos" << endl;
            cout << "\nReloj: " << i << endl;

            if (indice < totalcli && rand() % 5 == 0){
                Fila.Encolar(nombrecli[indice++]);
            }

            if(Caja1.EstaVacia() && !Fila.EstaVacia()){
                string cliente = Fila.ObtenerPrimero();
                Fila.Desencolar();
                Caja1.Encolar(cliente);
                tiempoQuitar1 = (rand() % 15 +1) + i;
            }else if(tiempoQuitar1 == i && !Caja1.EstaVacia()){
                Caja1.Desencolar();
            }

            cout << "Caja 1: ";
            if (!Caja1.EstaVacia()){
                cout << Caja1.ObtenerPrimero();
            } else {
                cout << "Desocupada";
            }
            cout << endl;

            if(Caja2.EstaVacia() && !Fila.EstaVacia()){
                string cliente = Fila.ObtenerPrimero();
                Fila.Desencolar();
                Caja2.Encolar(cliente);
                tiempoQuitar2 = (rand() % 15 +1) + i;
            }else if(tiempoQuitar2 == i && !Caja1.EstaVacia()){
                Caja2.Desencolar();
            }
            
            cout << "Caja 2: ";
            if (!Caja2.EstaVacia()){
                cout << Caja2.ObtenerPrimero();
            } else {
                cout << "Desocupada";
            }
            cout << endl;

            if(Caja3.EstaVacia() && !Fila.EstaVacia()){
                string cliente = Fila.ObtenerPrimero();
                Fila.Desencolar();
                Caja3.Encolar(cliente);
                tiempoQuitar3 = (rand() % 15 +1) + i;
            }else if(tiempoQuitar3 == i && !Caja1.EstaVacia()){
                Caja3.Desencolar();
            }

            cout << "Caja 3: ";
            if (!Caja3.EstaVacia()){
                cout << Caja3.ObtenerPrimero();
            } else {
                cout << "Desocupada";
            }

            cout << endl;

            cout << "Clientes en espera:\n";
            Fila.imprimir();

            Sleep(1000);
            system("cls");
        }

        cout << "Clientes atendidos por la Caja 1: ";
        Caja1.imprimir();
        cout << "Clientes atendidos por la Caja 2: ";
        Caja2.imprimir(); 
        cout << "Clientes atendidos por la Caja 3: ";
        Caja3.imprimir();
        cout << "Clientes que no fueron atendidos:";
        Fila.imprimir();

    }catch(const char *mensaje){
        cerr << mensaje;
    }
    return 0;
}