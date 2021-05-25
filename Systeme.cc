#include <iostream>
#include "Systeme.h"


void Systeme :: affiche ()
{
	ptr_hill->affiche_para;
	ptr_champs->affiche();
	
}
virtual void Systeme :: dessine_sur() override
{ A->dessine(*this); }

virtual void Systeme ::  evolue ()
{
	dessine_sur ();
	
	
}


virtual void Systeme :: demarre ()
{
	ptr_champs ->resolution();
	&ptr_ciel (&ptr_champs)
	dessine_sur();
	evolue();
}

std::ostream& operator<<(std::ostream& sortie, Systeme const& Sys)
{
	Sys.affiche();
}

