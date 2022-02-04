#include <iostream>
using namespace std;

//---VARIABLES
bool player = 1; //indica el jugador
bool fin = 1; //inidca el fin del juego
//indica las posicones del tablero
char cuadro[] = {'1','2','3','4','5','6','7','8','9'}; 
char m1 = 'X', m2 = 'O', marca; //indica las marcas usadas en el juego
int pos=0; //indica la posicion a poner una marca
int cont_marca=0; //cuenta el numero de marcas en el tablero

//---FUNCIONES
void turno() { //turno del jugador
    if (player) {
        marca = m1;
        cout <<"Turno jugador 1 [" << marca << "]"<< endl;
    }
    else {
        marca = m2;
        cout <<"Turno jugador 2 [" << marca << "]"<< endl;
    }
}
void act_tablero() { //Funcion que actualiza el tablero
    cout << endl;
    cout <<"   |   |   "<< endl;
    cout <<" "<< cuadro[0] <<" | "<< cuadro[1] <<" | "<< cuadro[2] <<" "<< endl;
    cout <<"___|___|___"<< endl;
    cout <<"   |   |   "<< endl;
    cout <<" "<< cuadro[3] <<" | "<< cuadro[4] <<" | "<< cuadro[5] <<" "<< endl;
    cout <<"___|___|___"<< endl;
    cout <<"   |   |   "<< endl;
    cout <<" "<< cuadro[6] <<" | "<< cuadro[7] <<" | "<< cuadro[8] <<" "<< endl;
    cout <<"   |   |   "<< endl;
}
bool fin_juego() { //Funcion de fin de juego
    bool val=1;
    if(cuadro[0] == cuadro[1] && cuadro[1] == cuadro[2]) val = 0;
    if(cuadro[0] == cuadro[3] && cuadro[3] == cuadro[6]) val = 0;
    if(cuadro[0] == cuadro[4] && cuadro[4] == cuadro[8]) val = 0;
    if(cuadro[1] == cuadro[4] && cuadro[4] == cuadro[7]) val = 0;
    if(cuadro[2] == cuadro[4] && cuadro[4] == cuadro[6]) val = 0;
    if(cuadro[2] == cuadro[5] && cuadro[5] == cuadro[8]) val = 0;
    if(cuadro[3] == cuadro[4] && cuadro[4] == cuadro[5]) val = 0;
    if(cuadro[6] == cuadro[7] && cuadro[7] == cuadro[8]) val = 0;

    cout << endl;

    //Gana 1 o 2 
    if (!val) {
        if (player) {
            cout <<">> Ganador: JUGADOR 1";
        }
        else {
            cout <<">> Ganador: JUGADOR 2";
        }
        cont_marca = 0;   
    }

    //No hay espacios disponibles
    if(cont_marca == 9) { 
            cout << ">> EMPATE" << endl;
            val = 0;
    }

    return val;
}

//---FUNCION PRINCIPAL
int main() {  
    act_tablero(); //Actualizar tablero

    while(fin) {
        turno(); //turno del jugador

        //Colocar marca
        do{
            cout << "Ingrese posicion: ";
            cin >> pos; //Posicion a colocar la marca
            pos--;
        } while (cuadro[pos] == m1 || cuadro[pos] == m2);
        
        cuadro[pos] = marca;
        cont_marca++;

        fin = fin_juego(); //Fin juego

        act_tablero(); //Actualizar tablero

        player=!player;//Cambio de jugador
    }
}