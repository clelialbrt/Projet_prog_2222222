#pragma once 
#include <iostream>
#include "ChampsPotentiels.h"
#include "Vecteur2D.h"

class Potentiel
{
	friend class ChampsPotentiels;
	public:
	Potentiel() : poten(), laplacien() {}
	void affiche();

	protected:
	Vecteur2D poten;
	private:
	Vecteur2D laplacien;

};
