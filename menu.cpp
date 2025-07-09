#include <iostream>
#include "menu.h"
#include "jugar.h"
#include "estadisticas.h"
#include "creditos.h"

using namespace std;

void menu()
{
    // El vector para las estadisticas
    const int cantidad = 6;
    string nombresJugadores[cantidad];
    int puntajesJugadores[cantidad];

    //inicializamos el vector en cero
    ponerVectorCero(puntajesJugadores, cantidad);

    int opcion;
    bool salir = false;

    do
    {
        opciones();
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        system("cls");

        switch(opcion)
        {

        case 0:
            cout << "SALIR" << endl;
            salir = true;
            return;

        case 1:
        {
            cout << "1. MODO UN JUGADOR" <<endl;
            cout << "2. MODO DOS JUGADORES" <<endl;
            cin >> opcion;
            switch(opcion) {
            case 1:
        {
            system("cls");
            gamePlay(nombresJugadores, puntajesJugadores, cantidad);
            system("pause");
            break;



        }
            break;
        case 2:

        {
            system("cls");
            gamePlay2(nombresJugadores, puntajesJugadores, cantidad);
            system("pause");
            break;
        }
        break;
        default :
            cout << "Opcion invalida" << endl;
            system("pause");
                }

        }

        break;




        case 2:
        {
            cout << "ESTADISTICAS" << endl;
            mostrarEstadisticas(nombresJugadores,puntajesJugadores);
            system("pause");
        }
        break;
        case 3:
        {
            mostrarCreditos();
            system("pause");
        }
        break;
        default :
        {
            cout << "Opcion invalida" << endl;
        }
        }
    }
    while(true);

}
void opciones()
{
    system("cls");
    cout << "++++++++++++++++++++" << endl;
    cout << "    Y A H T I C O   " << endl;
    cout << "++++++++++++++++++++" << endl;
    cout << endl;
    cout << " -------------------" << endl;
    cout << " | 1- JUGAR        |" << endl;
    cout << " | 2- ESTADISTICAS |" << endl;
    cout << " | 3- CREDITOS     |" << endl;
    cout << " -------------------" << endl;
    cout << " | 0- SALIR        |" << endl;
    cout << endl;
}
