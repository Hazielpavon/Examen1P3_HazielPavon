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
	void MoverNave(int dirección); 
	bool VerificarColision(int dirección, char** Espac);
	bool Aterrizar(int dirección, char** Espac);
	bool JuegoTerminado(); 
};

