#pragma once
#include <iostream>
#include "SupportADessin.h"


class Dessinable //  permet de classer les objets qui sont dessinabletout les objets necessaure pour dessiner 
{
	public :
	
	void dessine_sur() = 0;
	virtual ~Dessinable() {}
	
	protected :
	
	SupportADessin* A;
};
