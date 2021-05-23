#pragma once
#include <iostream> 
#include <cmath>
#include <string>
#include "Dessinable.h"

class Montagne : public Dessinable 
{
	
	public: 
	Montagne(double x, double y, double h, double ox, double oy) : x0(x), y0(y), H(h), ex(ox), ey(oy) {}
	double altitude(double a, double b) const;
	
	void affiche_para();
	virtual dessine_sur(SupportADessin a_dessiner) override ;
	
	// méthode pour afficher différents types de montagnes grâce à du polymorphisme
	
	private:
	double x0;
	double y0;
	double H;
	double ex;
	double ey;
	string type;
};
