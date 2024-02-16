#pragma once
class Juego
{
private: 
	char** espacio; 
	int naveponavePosicionX; 
	int navePosicionY; 
	int cantidadPersonas; 
	int cantidadCombustible; 
	
public: 
	char** InicializarEspacio();
	~Juego(); 
	void MostrarTablero(char** Espac);
	void MoverNave(int direcci�n); 
	bool VerificarColision(int direcci�n, char** Espac);
	bool Aterrizar(int direcci�n, char** Espac);
	bool JuegoTerminado(bool aterrizo, bool choco, int gaso); 
};

