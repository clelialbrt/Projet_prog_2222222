#pragma once
#include <iostream>
#include <vector>
#include <array>
#include "Vecteur2D.h"
#include "constantes.h"
#include "Boite3D.h"
#include "Potentiel.h"
#include "Montagne.h"



class ChampsPotentiels : public Boite3D
{
	friend class Ciel;
	public:
	ChampsPotentiels(unsigned int nox = 30, unsigned int noy = 30, unsigned int noz = 30, double p = 1) : Boite3D(nox, noy, noz, p) {}

	void initialise(double vi, const Montagne& mont);
	
	bool estauxbords(Potentiel pot) const;
	
	void calcule_laplaciens();
	double erreur();
	void iteration( double E = 0.1);
	void resolution ( double seuil = 2.2621843e-5, unsigned int max = 5000, bool verbeuse = false);
	std::array<double, 3> vitesse(unsigned int i, unsigned int j, unsigned int k) const;
	double norme_vitesse(unsigned int pointi, unsigned int pointj, unsigned int pointk);


	std::vector<std::vector<std::vector<Potentiel>>> get_tableaudepotentiels();
	
	//void remettre(Montagne m);
		
	private:
	std::vector<std::vector<std::vector<Potentiel>>> potentiels3D;
	 
};

