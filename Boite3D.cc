#include <iostream>
#inlude "Boite3D.h"

using namespace std;

double Boite3D:: getpas() const //getters pour les différents attributs 
{
	return pas;
}

int Boite3D:: getNx() const
{
	return Nx;
}

int Boite3D:: getNy() const
{ 
	return Ny;
} 

int Boite3D:: getNz() const
{
	return Nz;
}

void Boite3D:: affiche(double x, double y, double z)
{
	cout << x << " " << y << " " << z << " " << Nx << " " << Ny << " " << Nz << " " << pas << endl;
}

