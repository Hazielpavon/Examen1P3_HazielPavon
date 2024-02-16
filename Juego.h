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
	void MoverNave(int direcci�n, char** Espac);
	char VerificarColision(char** Espac, int gaso, int personas, int direccion);
	bool Aterrizar(int direcci�n, char** Espac);
	bool JuegoTerminado(bool aterrizo, bool choco, int gaso); 
};

