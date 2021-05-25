#include <iostream>
#include "Ciel.h"

void Ciel :: dessine_sur(SupportADessin a_dessiner)
{ a_dessiner.dessine(*this); }

CubedAir Ciel:: precedente(double pas_temps, double x, double y, double z)
{
	double norme_vitesse_cubedair(sqrt(cubes_dair[x][y][z].vitesse_cubedair[0]*cubes_dair[x][y][z].vitesse_cubedair[0] + cubes_dair[x][y][z].vitesse_cubedair[1]*cubes_dair[x][y][z].vitesse_cubedair[1] + cubes_dair[x][y][z].vitesse_cubedair[2]*cubes_dair[x][y][z].vitesse_cubedair[2]));
	double deplacement(-pas_temps * norme_vitesse_cubedair);
	x += deplacement;
	y += deplacement;
	z += deplacement;
	if ((x > Nx) or (y > Ny) or (z > Nz))
	{
		cubes_dair[x][y][z].etat == false;
		return cubes_dair[x][y][z];
	}
	else
	{
		return cubes_dair[x][y][z];
	}
}

