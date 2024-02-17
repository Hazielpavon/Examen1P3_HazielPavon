#include <iostream>
#include "Juego.h"
using namespace std;
int main()
{
	bool gano = false;
	bool vali = false;
	int personas;
	int gasolina;
	int eje;
	// valido las entradas 
	while (!vali) {
		cout << "Ingrese la cantidad de personas: " << endl;
		personas = 0;
		cin >> personas;
		cout << "ingrese la cantidad de gasolina: " << endl;
		gasolina = 0;
		cin >> gasolina;
		if (gasolina > 501 || gasolina < 99 && personas < 14 && personas > 29) {
			cout << "La gasolina debe ser mayor a 100 y menor a 500 y Deben haber mas de 15 pasajeros y no mas de 28" << endl;
		}
		else {
			vali = true;
		}
	}
	Juego g;
	char** mat = g.InicializarEspacio();
	while (!gano) {
		g.MostrarTablero(mat);
		cout << "Ingrese la posicion en la que quiere moverse 1) arriba, 2) abajo, 3)Derecha, 4) Izquierda: o 0 para salir " << endl;
		eje = 0;
		cin >> eje;
		char x = g.MoverNave(eje, mat);
		char l = g.VerificarColision(x);
		g.Aterrizar(x, personas);
		// hago que los metodos en la clase retornen un caracter para validar directamente si encuentran algun objeto y ahi mismo le resto o sumo a las variables
		if (l == 'E') {
			personas -= 3;
		}
		else if (l == 'S') {
			personas -= 5;
		}
		else if (l == 'S') {
			gasolina += 20;

		}
		else if (x == 'M') {
			gano = true;
		}
		if (g.JuegoTerminado(personas, gasolina)) {
			gano = true;
		}
	}
}