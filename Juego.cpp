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

void Juego::MoverNave(int direccion)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (direccion == 1) {

            }
            else if (direccion == 2) {

            }
            else if (direccion == 3) {

            }
            else if (direccion == 4) {

          }
        }
    }

}

bool Juego::VerificarColision(int dirección, char** Espac)
{
    return true;
}

bool Juego::Aterrizar(int dirección, char** Espac)
{
    return true;
}

bool Juego::JuegoTerminado(bool att, bool col, int gaso) {

    

    return false;
}

Juego::~Juego() {
    delete[] espacio;
    for (int i = 0; i < 6; i++)
    {
        delete[] espacio[i];
    }
}
