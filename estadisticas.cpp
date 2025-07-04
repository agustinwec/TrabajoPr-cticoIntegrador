#include <iostream>
using namespace std;

#include <string>
#include "estadisticas.h"


void mostrarEstadisticas(string nombres[], int puntajes[]) {
    system("cls");
    cout << "---------------- ESTADISTICAS ----------------" << endl;
    mostrarMejoresJugadores(nombres, puntajes);
    if(puntajes[0] == 0) {
        sinEstadisticas();
    }
    cout << "\n----------------------------------------------" << endl;
}

void sinEstadisticas() {
    cout << "\nNo se hayan registros de jugadores todavia.." << endl;
}

void mostrarMejoresJugadores(string nombres[], int puntajes[]) {
    cout << "TOP 5: " << endl;
    cout << "Posicion    Puntos              Jugador" << endl;
    cout << "\n";
    for (int i = 0; i < 5; i++) {
        cout << "#" << i+1 << "          " << puntajes[i] << "                  " << nombres[i] << endl;
    }
}

void ponerVectorCero (int v[], int t) {
    for(int i = 0; i < t; i++) {
        v[i] = 0;
    }
}

void actualizarPuntajes(string nombres[], int puntajes[], int t, string nombre, int puntaje) {
    bool actualizado = false;

    for(int i = 0; i < t; i++) {
        if(actualizado == false) {
            if(puntajes[i] == 0) { ///ES EL PRIMER NRO
                nombres[i] = nombre;
                puntajes[i] = puntaje;
                actualizado = true;
            }else if(puntaje > puntajes[i]) {

                for(int j = 5; j>i; j--) {
                    nombres[j] = nombres[j-1];
                    puntajes[j] = puntajes[j-1];
                }
                nombres[i] = nombre;
                puntajes[i] = puntaje;
                actualizado = true;
                }
                }
            }

        }



