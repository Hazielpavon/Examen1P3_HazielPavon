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
	Juego g;
	char** mat = g.InicializarEspacio();
	while (eje != 0) {
		g.MostrarTablero(mat);
		cout << "Ingrese la posicion en la que quiere moverse 1) arriba, 2) abajo, 3)Derecha, 4) Izquierda: o 0 para salir " << endl;
		eje = 0;
		cin >> eje;
		g.MoverNave(eje, mat);
		if (g.VerificarColision(mat, gasolina, personas, eje) == 'E') {
			cout << "Ha chocado con una Estrella, se le restaron 3 personas" << endl;
			personas -= 3; 
		}
		else if (g.VerificarColision(mat, gasolina, personas, eje) == 'S') {
			cout << "Ha chocado con un Sol, se le restaron 5 personas" << endl;
			personas -= 5;
		}
		else if (g.VerificarColision(mat, gasolina, personas, eje) == 'S') {
			cout << "Ha chocado con un Planeta, se le sumo 20 de gasolina!" << endl;
			gasolina += 20; 

		}
	}
}


