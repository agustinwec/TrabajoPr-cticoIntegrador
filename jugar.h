#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED
#include <string>
#include "estadisticas.h"
using namespace std;


void gamePlay(string nombres[], int puntajes[], int t);
void gamePlay2(string nombres[], int puntajes[], int t);

int obtenerRandom(int tamanio);
void generarTirada(int v[], int tamanio);
void mostrarTirada(int v[], int tamanio);
int obtenerPuntos(int v[], int tamanio);
void OrdenarDados(int v[], int tamanio);

int sumaDeIguales(int v[], int tamanio);
int decidirJugadorinicial(string nombre1, string nombre2);

#endif // JUGAR_H_INCLUDED
