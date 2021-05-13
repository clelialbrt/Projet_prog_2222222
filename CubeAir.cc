#include <iostream>
#include "CubeAir.h"

double CubedAir:: enthalpie(unsigned int pointx, unsigned int pointy, unsigned int pointz, ChampsPotentiels champo)
{
	return (Physique::cte - Physique::g*pointz*champo.getpas() - 0.5*champo.norme_vitesse(pointx, pointy, pointz)*champo.norme_vitesse(pointx, pointy, pointz));
}
	
double CubedAir:: temperature(unsigned int px, unsigned int py, unsigned int pz, ChampsPotentiels champo1)
{
	return ((2/7)*enthalpie(px, py, pz, champo1)*(Physique::Mair_sec/Physique::R));
}
