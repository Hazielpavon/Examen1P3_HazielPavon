#include "Juego.h"
#include <iostream>
using namespace std;

char** Juego::InicializarEspacio()
{
	// inicio la memoria para la matriz 
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
	// y aca mismo lleno la matriz y la retorno para mostrarla en el main 
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
	// muestro la matriz 
}
char Juego::VerificarColision(char p)
{
	if (p == 'E') {
		cout << "Ha chocado con una Estrella, se le restaron 3 personas" << endl;
		return 'E';
	}
	else if (p == 'S') {
		cout << "Ha chocado con un Sol, se le restaron 5 personas" << endl;
		return 'S';
	}
	else if (p == 'P') {
		cout << "Ha chocado con un Planeta, se le sumo 20 de gasolina!" << endl;
		return 'P';
	}
	return ' ';
	// validando de los caracteres capturados para tener un codigo mas eficiente 
}
void Juego::Aterrizar(char x, int personas)
{
	if (x == 'M') {
		cout << "Felicidades,ha logrado llegar a Marte con: " << personas << ", pasajeros!" << endl;
	}
	// validacion simple 
}

bool Juego::JuegoTerminado(int per, int gasolina) {
	if (per == 0) {
		cout << "Todos suspasajeros han muerto antes de llegar a marte" << endl;
		return true;
	}
	else if (gasolina == 0) {
		cout << "Se ha quedado sin combustible y se ha perdido en el espacio con: " << per << ", pasajeros" << endl;
		return true;
	}
	return false;
}

Juego::~Juego() {
	for (int i = 0; i < 6; i++)
	{
		delete[] espacio[i];
	}
	delete[] espacio;
}
char Juego::MoverNave(int direccion, char** Espac)
{
	// inicio las variables 
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
				// capturo la posicion 
			}
		}
	}

	Espac[navePosicionX][navePosicionY] = ' ';
	// el espacio anterior ahora es un espacio vacio 

	int nuevaFilaNave = navePosicionX;
	int nuevaColumnaNave = navePosicionY;
	// estos valores nuevos los modificare en base el movimiento del usuario 
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
		char x = Espac[nuevaFilaNave][nuevaColumnaNave];
		// esta linea es la mas importante de mi codigo, capturo el caracter par utilizarlo en todo el codigo 
		Espac[nuevaFilaNave][nuevaColumnaNave] = 'H';
		return x;
		// y esa misma variable la retorno 
	}
	else {
		Espac[navePosicionX][navePosicionY] = 'H';
		cout << "No puede Salirse del mapa de juego" << endl;
	}
	// validacion para que no se salga de la matriz 
	return ' ';
	// si no hay nignun caracter no retorna nada 
}
