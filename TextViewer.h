pragma once 
# include <iostream>
# include "SupportADessin"


class TextViewer : public SupportADessin
{
virtual void dessine(Systeme const&);
virtual void dessine(Montagne const&);
virtual void dessine(Ciel const&); 	
	
private :

ofstream& flot; 

	
};
