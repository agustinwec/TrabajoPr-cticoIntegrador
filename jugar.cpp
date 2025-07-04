#include <iostream>
#include "jugar.h"
#include "estadisticas.h"
#include <string>

using namespace std;

string obtenerNombreCombinacion(int v[], int tamanio)
{
    string combinacion;
    int conteo[7] = {};  //indice 1 a 6
    for (int i = 0; i < tamanio; i++)
    {
        conteo[v[i]]++;
    }

    bool hayTres = false, hayDos = false;

    for (int i = 1; i <= 6; i++)
    {
        if (conteo[i] == 5) {
            combinacion = "Yahtico";
            return combinacion;
        }
        if (conteo[i] == 4)  {
            combinacion = "Poker";
            return combinacion;
        }
        if (conteo[i] == 3){
                hayTres = true;
        }
        if (conteo[i] == 2){
                hayDos = true;
        }
    }

    if (hayTres == true && hayDos == true) {
        combinacion = "Full";
        return combinacion;
    }
    if (hayTres == true && hayDos == false) {
        combinacion = "Trio";
        return combinacion;
    }



    // Copiar y ordenar para escalera
    int copia[5];

    for (int i = 0; i < 5; i++)
    {
        copia[i] = v[i];
    }

    /*OrdenarDados(copia, 5);*/

    // Eliminar duplicados (1-2-3-3-4)
    int unicos[5], cantUnicos = 0;

    unicos[cantUnicos++] = copia[0];

    for (int i = 1; i < 5; i++){
        if (copia[i] != copia[i - 1]){
            unicos[cantUnicos++] = copia[i]; //1-2-3-4
        }
    }

    // Escalera grande
    if (cantUnicos == 5 &&
       ((unicos[0] == 1 && unicos[1] == 2 && unicos[2] == 3 && unicos[3] == 4 && unicos[4] == 5) || //1-2-3-4-5
        (unicos[0] == 2 && unicos[1] == 3 && unicos[2] == 4 && unicos[3] == 5 && unicos[4] == 6)))//2-3-4-5-6
        {combinacion = "Escalera grande";
        return combinacion;}

    // Escalera pequeña
    for (int i = 0; i <= cantUnicos - 4; i++)
    {
        if (unicos[i+1] == unicos[i]+1 &&
            unicos[i+2] == unicos[i]+2 &&
            unicos[i+3] == unicos[i]+3){
            combinacion = "Escalera pequenia";
            return combinacion;
            }
    }
    combinacion = "Change";
    return combinacion;
}


//
void gamePlay(string nombres[], int puntajes[], int t)
{
    string jugador1;
    cout << "Introduce tu nombre: ";
    cin >> jugador1;
    system("cls");

    cout << "-ARRANCA EL JUEGO-" << endl;
    int puntosTotalesJugador1 = 0;


    const int TAM = 5;
    int tirada[TAM];
    int totalRondas = 3;
    int opcion;



    for(int i = 1; i <= totalRondas; i++)
    {
        cout <<endl<< "RONDA #" << i << endl;

// TURNO JUGADOR 1
        int tiradas = 1;
        cout << endl << "JUGADOR #1 - Lanzamiento 1" << endl;
        generarTirada(tirada, TAM);
        mostrarTirada(tirada, TAM);

        int decision;
        bool terminarTurno = false;

        while (tiradas < 3 && !terminarTurno)
        {
            cout << "Deseas relanzar dados o finalizar turno? (1 = Si / 0 = no): ";
            cin >> decision;

            if (decision == 0)
            {
                terminarTurno = true;
                break;
            }

            cout << "Relanzar uno o todos? (1 = todos / 2 = uno): ";
            cin >> decision;

            if (decision == 1 )
            {
                generarTirada(tirada, TAM);
            }
            else if (decision == 2)
            {
                int pos;

                cout << "Que dado deseas relanzar? (1 a 5): ";
                cin >> pos;

                if (pos >= 1 && pos <= 5)
                {
                    tirada[pos - 1] = obtenerRandom(6);
                }

            }

            tiradas++;
            cout << endl << "JUGADOR #1 - Lanzamiento " << tiradas << endl;
            mostrarTirada(tirada, TAM);
        }

        // Mostramos combinación y puntos
        OrdenarDados(tirada, TAM);

        string combinacion1 = obtenerNombreCombinacion(tirada, TAM);
        int puntos = obtenerPuntos(tirada, TAM);
        puntosTotalesJugador1 += puntos;



        cout << "Combinacion obtenida: " << combinacion1 << endl;
        cout << "Puntos obtenidos: " << puntos << endl;





        cout << "-----------------------------------------------------------------------------------------"<<endl;
    }
    //para que aperesca en las estadiscas
    actualizarPuntajes(nombres, puntajes, t, jugador1, puntosTotalesJugador1);

    cout << "Jugador "<< jugador1<< " obtuviste "<< puntosTotalesJugador1 << " puntos" << endl;



}

void gamePlay2(string nombres[], int puntajes[], int t)
{
    string nombre1;
    string nombre2;
    int opcion;
    cout << "Intoduce el nombre del jugador 1: " ;
    cin >> nombre1;
    cout <<endl;
    cout << "Intoduce el nombre del jugador 2: ";
    cin >> nombre2;
    cout <<endl;
    system("cls");

    cout << "Comenzaremos tirando un dado para decidir quien empieza... "<<endl<<endl;
    cout << "Elijan quien de los dos tira primero el dado. "<< endl;
    cout << "precione 1. para: " << nombre1 <<endl <<"precione 2. para: " << nombre2 <<endl;
    cin >> opcion;

    string jugador1;
    string jugador2;
    system("cls");

    //Se decide quien empieza
    switch(opcion) {

    case 1:
        {
        int turno = decidirJugadorinicial(nombre1, nombre2);

        if(turno ==1 ){
            jugador1 = nombre1;
            jugador2 = nombre2;
        }
        else {
            jugador1 = nombre2;
            jugador2 = nombre1;
        }
    }
    break;
    case 2: {
        int turno = decidirJugadorinicial(nombre2, nombre1);

        if(turno == 1) {
            jugador1 = nombre2;
            jugador2 = nombre1;
        }
        else {
            jugador1 = nombre1;
            jugador2 = nombre2;
        }
    }
    break;
    }
    system("pause");
    system("cls");


    cout << "-ARRANCA EL JUEGO-" << endl;
    int puntosTotalesJugador1 = 0;
    int puntosTotalesJugador2 = 0;

    const int TAM = 5;
    int tirada[TAM];
    int totalRondas = 3;


    for(int i = 1; i <= totalRondas; i++)
    {
        cout <<endl<< "RONDA #" << i << endl;

    // j=2 por que son 2 jugadores
    for(int j = 1; j <=2; j++) {

        string jugador;
        if(j==1){
            jugador = jugador1;
        }
        else {
            jugador = jugador2;
        }

        int tiradas = 1;
        cout << endl << "JUGADOR #"<<j<<": "<< jugador << " - Lanzamiento 1" << endl;
        generarTirada(tirada, TAM);
        mostrarTirada(tirada, TAM);

        int decision;
        bool terminarTurno = false;

        while (tiradas < 3 && !terminarTurno)
        {
            cout << "Deseas relanzar dados o finalizar turno? (1 = Si / 0 = no): ";
            cin >> decision;

            if (decision == 0)
            {
                terminarTurno = true;
                break;
            }

            cout << "Relanzar uno o todos? (1 = todos / 2 = uno): ";
            cin >> decision;

            if (decision == 1 )
            {
                generarTirada(tirada, TAM);
            }
            else if (decision == 2)
            {
                int pos;

                cout << "Que dado deseas relanzar? (1 a 5): ";
                cin >> pos;

                if (pos >= 1 && pos <= 5)
                {
                    tirada[pos - 1] = obtenerRandom(6);
                }

            }

            tiradas++;
            cout << endl << "JUGADOR #"<<j<<": "<<jugador<<" - Lanzamiento " << tiradas << endl;
            mostrarTirada(tirada, TAM);
        }
        OrdenarDados(tirada, TAM);

        string combinacion1 = obtenerNombreCombinacion(tirada, TAM);
        int puntos = obtenerPuntos(tirada, TAM);
        if(j==1) {
            puntosTotalesJugador1 += puntos;
        }
        else {
            puntosTotalesJugador2 += puntos;
        }
        cout << "Combinacion obtenida: " << combinacion1 << endl;
        cout << "Puntos obtenidos: " << puntos << endl;


    cout << "-----------------------------------------------------------------------------------------"<<endl;
    }

    }
    if(puntosTotalesJugador1> puntosTotalesJugador2) {
        cout << "GANADOR... "<< jugador1<<endl<<endl;
    }
    else if(puntosTotalesJugador1<puntosTotalesJugador2) {
        cout << "GANADOR... "<< jugador2<<endl<<endl;
    }
    else {
        cout << "Hubo un empate.."<< endl<<endl;
    }

    cout << "Jugador 1: "<<jugador1 << " obtuvo "<< puntosTotalesJugador1 << " puntos" << endl;

    cout << "Jugador 2: "<<jugador2 << " obtuvo "<< puntosTotalesJugador2 << " puntos" << endl;



    // Actualizando las estadisticas
    actualizarPuntajes(nombres, puntajes, t, jugador1, puntosTotalesJugador1);

    actualizarPuntajes(nombres, puntajes, t, jugador2, puntosTotalesJugador2);

    int respuesta;
    cout << "Quieres jugar otra vez? (1 = Si / 0 = No): ";
    cin >> respuesta;

    if(respuesta == 1) {
        gamePlay2(nombres, puntajes, t);
    } else {
        system("cls");
        cout << "Gracias por jugar!" << endl;
    }

}


int obtenerRandom(int tamanio)
{
    return rand()%tamanio + 1;
}
// Son los dados que tiras
void generarTirada(int v[], int tamanio)
{
    for(int i = 0; i < tamanio; i++)
    {
        v[i] = obtenerRandom(6);
    }
}
// Muestra los dados
void mostrarTirada(int v[], int tamanio)
{
    for(int i = 0; i < tamanio; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
//



// Sumar los puntos segun el nombre de la combinacion
int obtenerPuntos(int v[], int tamanio)
{
    string combinacion;
    combinacion = obtenerNombreCombinacion(v, tamanio);

    int puntos = 0;


    if(combinacion == "Yahtico") {
        puntos = 50;
    }
    else if(combinacion == "Escalera grande") {
        puntos = 35;
    }
    else if(combinacion == "Escalera pequeña") {
        puntos = 30;
    }
    else if(combinacion == "Full") {

        puntos = 25;
    }
    else if(combinacion == "Poker") {

        for(int i = 0; i < tamanio; i++)
        {
        puntos += v[i];
        }
    }
    else if(combinacion == "Trio" ) {

        puntos = sumaDeIguales(v, tamanio);
    }
    else {
        int mayor = v[0];
        for(int i = 1; i < tamanio; i++)
    {
        if(v[i]> mayor) {
            mayor = v[i];
        }
    }
     puntos = mayor;

    }
    return puntos;
}


//
void OrdenarDados(int v[], int tamanio) {
    for(int i = 0; i < tamanio - 1; i++)
    {
        for(int j = 0; j < tamanio - 1 - i; j++)
        {
            if(v[j] > v[j + 1])
        {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
        }
        }
    }
   }
//

// Para ver quien empieza
int decidirJugadorinicial(string nombre1, string nombre2){

    int dado1, dado2;
    do {
        cout << nombre1 << " lanza el dado..." << endl;
        dado1 = obtenerRandom(6);
        cout << "Resultado: " << dado1 << endl<<endl;

        cout << nombre2 << " lanza el dado..." << endl;
        dado2 = obtenerRandom(6);
        cout << "Resultado: " << dado2 << endl<<endl;

        if (dado1 > dado2) {
            cout << nombre1 << " comienza la partida." << endl;
            return 1;
        } else if (dado2 > dado1) {
            cout << nombre2 << " comienza la partida." << endl;
            return 2;
        } else {
            cout << "Empate. Se repite la tirada." << endl;
            system("pause");
        }
    } while (true);
}


// los dados que se repiten se suman. Sirve para lcuando sale la combinacion "Trio"
int sumaDeIguales(int v[],int tamanio) {

    int suma = 0;

    for (int i = 0; i < tamanio; i++) {
        bool yaEstaContado = false;

        // Verificar si ya se sumo antes
        for (int k = 0; k < i; k++) {
            if (v[i] == v[k]) {
                yaEstaContado = true;
                break;
            }
        }

        if (!yaEstaContado) {
            int repeticiones = 0;
            for (int j = 0; j < tamanio; j++) {
                if (v[i] == v[j]) {
                    repeticiones++;
                }
            }

            if (repeticiones > 1) {
                suma += v[i] * repeticiones;
            }
        }
    }

    return suma;
}


