#include "Juego.h"
#include <iostream>
using namespace std;

char** Juego::InicializarEspacio()
{
	bool vali = true;
	char x[] = { 'S', 'P', 'E', 'M' };
	srand((unsigned)time(NULL));
	int conte = 0, conts = 0, contp = 0, contm = 0;
	espacio = new char* [6];
	for (int i = 0; i < 6; i++)
	{
		espacio[i] = new char[6];
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i == 0 && j == 0) {
				espacio[i][j] = 'H';
			}
			else {
				if (conts < 5 || conte < 4 || contp < 4 || contm < 2) {
					int r = (rand() % 4);
					int r2 = (rand() % 4);
					if (r == r2) {
						if (r == 0 && conts < 4) {
							conts++;
							espacio[i][j] = x[r];
						}
						else if (r == 1 && contp < 3) {
							contp++;
							espacio[i][j] = x[r];
						}
						else if (r == 2 && conte < 3) {
							conte++;
							espacio[i][j] = x[r];
						}
						else if (r == 3 && contm < 1) {
							contm++;
							espacio[i][j] = x[r];
						}
						else {
							espacio[i][j] = ' ';
						}
					}
					else {
						espacio[i][j] = ' ';

					}
				}
			}
		}
	}
	return espacio;
}

void Juego::MostrarTablero(char** Espac)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << "[" << Espac[i][j] << "]";
		}
		cout << endl;
	}
}
char Juego::VerificarColision(char** Espac, int com, int per, int direccion)
{
	/* Si la nave llega a la posición donde se encontraba una estrella, la nave pierde
		 3 pasajeros.
		 o Si la nave llega a la posición donde se encontraba un sol, la nave pierde 5
		 pasajeros.
		 o Si la nave llega a la posición donde se encontraba un planeta, la nave gana 20
		 de combustible.*/


	cantidadCombustible = com;
	cantidadPersonas = per;

	navePosicionX = -1;
	navePosicionY = -1;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (Espac[i][j] == 'H') {
				navePosicionX = i;
				navePosicionY = j;
				break;
			}
		}
		if (navePosicionX != -1) {
			break;
		}
	}
	int nuevaFilaNave = navePosicionX;
	int nuevaColumnaNave = navePosicionY;
	if (direccion == 1) {  // Arriba
		nuevaFilaNave--;
	}
	else if (direccion == 2) {  // Abajo
		nuevaFilaNave++;
	}
	else if (direccion == 3) {  // Derecha
		nuevaColumnaNave++;
	}
	else if (direccion == 4) {  // Izquierda
		nuevaColumnaNave--;
	}
	if (nuevaFilaNave >= 0 && nuevaFilaNave < 6 && nuevaColumnaNave >= 0 && nuevaColumnaNave < 6) {

		if (Espac[nuevaFilaNave][nuevaColumnaNave] == 'E') {
			return 'E'; 
		}
		else if (Espac[nuevaFilaNave][nuevaColumnaNave] == 'S') {
			return 'S';
		}
		else if (Espac[nuevaFilaNave][nuevaColumnaNave] == 'P') {
			return 'P'; 
		}

	}

}

bool Juego::Aterrizar(int dirección, char** Espac)
{
	return true;
}

bool Juego::JuegoTerminado(bool att, bool col, int gasolina) {



	return false;
}

Juego::~Juego() {
	delete[] espacio;
	for (int i = 0; i < 6; i++)
	{
		delete[] espacio[i];
	}
}
void Juego::MoverNave(int direccion, char** Espac)
{
	navePosicionX = -1;
	navePosicionY = -1;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (Espac[i][j] == 'H') {
				navePosicionX = i;
				navePosicionY = j;
				break;
			}
		}
		if (navePosicionX != -1) {
			break;
		}
	}

	Espac[navePosicionX][navePosicionY] = ' ';

	int nuevaFilaNave = navePosicionX;
	int nuevaColumnaNave = navePosicionY;
	if (direccion == 1) {  // Arriba
		nuevaFilaNave--;
	}
	else if (direccion == 2) {  // Abajo
		nuevaFilaNave++;
	}
	else if (direccion == 3) {  // Derecha
		nuevaColumnaNave++;
	}
	else if (direccion == 4) {  // Izquierda
		nuevaColumnaNave--;
	}
	if (nuevaFilaNave >= 0 && nuevaFilaNave < 6 && nuevaColumnaNave >= 0 && nuevaColumnaNave < 6) {

		Espac[nuevaFilaNave][nuevaColumnaNave] = 'H';
	}
	else {
		Espac[navePosicionX][navePosicionY] = 'H';
		cout << "No puede Salirse del mapa de juego" << endl; 
	}

}
