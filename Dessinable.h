#pragma once
#include <iostream>
#include "SupportADessin.h"


class Dessinable //  permet de classer les objets qui sont dessinabletout les objets necessaure pour dessiner 
{
	public :
	
	virtual void dessine_sur(SupportADessin& a_dessiner) = 0;
	
	
};
