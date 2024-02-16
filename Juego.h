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
	void InicializarEspacio(char** Espac);
	void borrar(); 
	void MostrarTablero(char** Espac);
	void MoverNave(int direcci�n); 
	bool VerificarColision(int direcci�n, char** Espac);
	bool Aterrizar(int direcci�n, char** Espac);
	bool JuegoTerminado(); 
};

