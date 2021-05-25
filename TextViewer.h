pragma once 
# include <iostream>
# include "SupportADessin.h"


class TextViewer : public SupportADessin
{
virtual void dessine(Systeme const&);
virtual void dessine(Montagne const&);
virtual void dessine(Ciel const&); 	
	
private :

std :: ostream& flot; 

	
};
