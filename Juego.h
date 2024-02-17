#pragma once
class Juego
{
private: 
	char** espacio; 
	int navePosicionX; 
	int navePosicionY; 
	int cantidadPersonas; 
	int cantidadCombustible; 
	
public: 
	char** InicializarEspacio();
	~Juego(); 
	void MostrarTablero(char** Espac);
	char MoverNave(int dirección, char** Espac);
	char VerificarColision(char p);
	void Aterrizar(char p, int personas);
	bool JuegoTerminado(int per, int gaso); 
	// aca retornan los char o bools
};

