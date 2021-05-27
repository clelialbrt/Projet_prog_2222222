pragma once 
#include <iostream>
#include "SupportADessin.h"
#include "Montagne.h"
#include "Systeme.h"
#include "Ciel.h"


class TextViewer : public SupportADessin
{
	virtual void dessine(Systeme const&);
	virtual void dessine(Montagne const&);
	virtual void dessine(Ciel const&); 	
	
	private :

	std :: ostream& flot; 

	
};
