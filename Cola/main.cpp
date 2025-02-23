#include <iostream>
#include "Cola.hpp"
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;
/**

 * \file main.cpp

 * Este archivo simula 3 cajas de banco y una fila de espera, los nombres de los clientes son tomados desde un archivo .txt llamado "Nombres.txt"

 * En cuanto alguna de las cajas se desocupa, el primer cliente en la fila de espera toma su lugar y la usa por un periodo de tiempo aleatorio

 * Al finalizar el tiempo de la simulación se imprimen los nombres de cada una de las personas que atendió cada una de las cajas en orden de llegada y también a los que no se atenderion

 * \author Flor Machado y Elias Peregrina

 * \date 21/02/2025

 */

const int MAX_CLI = 100;

void leerNombres(const string& nombreArchivo, string nombrecli[], int& totalcli);
int main()
{
    try{

        srand (time(NULL));

        Cola<string> Caja1, Caja2, Caja3, Fila, Atendidos1, Atendidos2, Atendidos3;

        int tiempo = (rand() % 5 +1);
        int tiempoQuitar1 = (rand() % 15 +1);
        int tiempoQuitar2 = (rand() % 15 +1);
        int tiempoQuitar3 = (rand() % 15 +1);
        int tiempoBanco = (rand() % 120 +120);
        string nombreArchivo = "Nombres.txt";
        string nombrecli[MAX_CLI];
        int totalcli = 0;
        int indice = 0;
        int aux1, aux2, aux3; //miden el tiempo de atencion por cada cliente
        leerNombres(nombreArchivo, nombrecli, totalcli);

        cout << "Las cajas atender\240n a tantos clientes puedan en " << tiempoBanco << " minutos" << endl;
        cout << "\nEl tiempo que tarda cada uno de las personas es totalmente aleatorio" << endl;

        system("pause");


        for (int i = 0; i < tiempoBanco; ++i){
            cout << "Las cajas atender\240n a tantos clientes puedan en " << tiempoBanco << " minutos" << endl;
            cout << "\nReloj: " << i << endl;

            if ( (indice < totalcli) && ( tiempo == i) ){
                Fila.Encolar(nombrecli[indice++]);
                tiempo = (rand() % 5 +1) +i;
            }

            if(Caja1.EstaVacia() && !Fila.EstaVacia()){
                string cliente = Fila.ObtenerPrimero();
                Fila.Desencolar();
                Caja1.Encolar(cliente);
                Atendidos1.Encolar(cliente);
                tiempoQuitar1 = (rand() % 10 + 5) + i;
            }else if(tiempoQuitar1 == i && !Caja1.EstaVacia()){
                Caja1.Desencolar();
            }

            cout << "Caja 1: ";
            if (!Caja1.EstaVacia()){
                cout << Caja1.ObtenerPrimero();
                cout << "\t Tiempo de atenci\242n: " << aux1;
                ++aux1;
            } else {
                cout << "Desocupada";
                aux1 = 0;
            }
            cout << endl;

            if(Caja2.EstaVacia() && !Fila.EstaVacia()){
                string cliente = Fila.ObtenerPrimero();
                Fila.Desencolar();
                Caja2.Encolar(cliente);
                Atendidos2.Encolar(cliente);
                tiempoQuitar2 = (rand() % 10 + 5) + i;
            }else if(tiempoQuitar2 == i && !Caja2.EstaVacia()){
                Caja2.Desencolar();
            }

            cout << "Caja 2: ";
            if (!Caja2.EstaVacia()){
                cout << Caja2.ObtenerPrimero();
                cout << "\t Tiempo de atenci\242n: " << aux2;
                ++aux2;
            } else {
                cout << "Desocupada";
                aux2 = 0;
            }
            cout << endl;

            if(Caja3.EstaVacia() && !Fila.EstaVacia()){
                string cliente = Fila.ObtenerPrimero();
                Fila.Desencolar();
                Caja3.Encolar(cliente);
                Atendidos3.Encolar(cliente);
                tiempoQuitar3 = (rand() % 10 + 5) + i;
            }else if(tiempoQuitar3 == i && !Caja3.EstaVacia()){
                Caja3.Desencolar();
            }

            cout << "Caja 3: ";
            if (!Caja3.EstaVacia()){
                cout << Caja3.ObtenerPrimero();
                cout << "\t Tiempo de atenci\242n: " << aux3;
                ++aux3;
            } else {
                cout << "Desocupada";
                aux3 = 0;
            }

            cout << endl;

            cout << "Clientes en espera:\n";
            Fila.imprimir();

            Sleep(1000);
            system("cls");
        }

        cout << "Clientes atendidos por la Caja 1: " << endl;
        Atendidos1.imprimir();
        cout << endl << "Clientes atendidos por la Caja 2: " <<endl;
        Atendidos2.imprimir();
        cout << endl << "Clientes atendidos por la Caja 3: " << endl;
        Atendidos3.imprimir();
        cout << endl << "Clientes que no fueron atendidos:" << endl;
        Fila.imprimir();

    }catch(const char *mensaje){
        cerr << mensaje;
    }
    return 0;
}

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
