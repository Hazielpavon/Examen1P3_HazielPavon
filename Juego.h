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
	void MoverNave(int dirección, char** Espac);
	char VerificarColision(char** Espac, int gaso, int personas, int direccion);
	bool Aterrizar(int dirección, char** Espac);
	bool JuegoTerminado(bool aterrizo, bool choco, int gaso); 
};

