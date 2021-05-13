#pragma once
#include <iostream>
#include "Montagne.h"
#include "Ciel.h"
#include "ChampsPotentiels"


class Systeme : public Dessinable // rep ce qui forme un système physique
{
public :

Systeme ( Montagne& M), Ciel& C, ChampsPotentiels& Ch)
: ptr_champs(*Ch), ptr_ciel(*C), ptr_hill(*M) {}

~Systeme() 
{ 
	delete ptr_champs;
	delete ptr_ciel;
	delete ptr_hill;
}

virtual void affiche ();
virtual void demarre ();
virtual void dessine_sur() override;


private : 

ChampsPotentiels* ptr_champs;
Ciel* ptr_ciel;
Montagne* ptr_hill;
virtual void evolue ();

friend std::ostream& operator<<(std::ostream& sortie, Systeme const& Sys);

/*vector <Montagne*> ptr_hill;*/
	
};
