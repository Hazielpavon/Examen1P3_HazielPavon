#include <iostream>
#include "Juego.h"
using namespace std; 
int main()
{
    cout << "Ingrese la cantidad de personas: " << endl;
    int personas;
    cin >> personas;
    cout << "ingrese la cantidad de gasolina: " << endl;
    int gasolina;
    cin >> gasolina;

    int eje = 1; 
    while (eje != 0) {
        Juego g;
        char** mat = g.InicializarEspacio();
        g.MostrarTablero(mat);
        cout << "Ingrese la posicion en la que quiere moverse 1) arriba, 2) abajo, 3)Derecha, 4) Izquierda: o 0 para salir " << endl;
        eje = 0;
        cin >> eje;
        delete[] mat; 
       
    }
}

