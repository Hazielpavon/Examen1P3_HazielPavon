#include "Juego.h"
#include <iostream>
using namespace std;
void Juego::InicializarEspacio(char** mat)
{
	char x[] = { 'S', 'P', 'E', 'M' };
	srand((unsigned)time(NULL));
	int conte = 0, conts = 0, contp = 0, contm = 0;
	mat = new char* [6]; // filas
	for (int i = 0; i < 6; i++)
	{
		mat[i] = new char[6]; // columnas 
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i == 0 && j == 0) {
				mat[i][j] = 'H';
			}
			else {
				if (conts != 4 || conte != 3 || contp != 3 || contm != 1 && mat[i][j] != ' ') {
					int r = 0 + (rand() % 4);
					int r2 = 0 + (rand() % 4);
					if (r == r2) {
						mat[i][j] = x[r];
						if (r == 0) {
							conts++;
						}
						else if (r == 1) {
							contp++;
						}
						else if (r == 2) {
							conte++;
						}
						else if (r == 3) {
							contm++;
						}
					}
					else {
						mat[i][j] = ' ';
					}
				}
				else {
					mat[i][j] = ' ';
				}
			}
			cout << "[" << mat[i][j] << "]";
		}
		cout << endl;
	}
	for (int i = 0; i < 6; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
void Juego::MostrarTablero(char** Espac)
{
}

void Juego::MoverNave(int dirección)
{
}

bool Juego::VerificarColision(int dirección, char** Espac)
{
	return true;
}

bool Juego::Aterrizar(int dirección, char** Espac)
{
	return true;
}

bool Juego::JuegoTerminado()
{
	return false;
}
