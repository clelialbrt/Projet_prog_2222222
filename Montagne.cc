#include <cmath>
#include <iostream>
#include "Montagne.h"
#include "Dessinable.h"
#include "SupportADessin.h"
using namespace std;

double Montagne:: altitude(double a, double b) const
{
	double altitude(H*exp(-((a-x0)*(a-x0))/(2*ex*ex)-((b-y0)*(b-y0))/(2*ey*ey)));
	if (altitude < 0.5) { return 0; }
	else { return altitude; }
}

void Montagne:: set_montagne(double x, double y, double h, double ox, double oy)
{
	x0 = x;
	y0 = y;
	H = h;
	ex = ox;
	ey = oy;
}

void Montagne :: affiche_para()

{
	cout << " une montagne : " << endl;
	cout << type << " de paramètre : " << endl;
	cout << " centre de la montagne (" << x0 << "," << yo << ");" << endl;
	cout << " hauteur maximale : " << H << endl;
	cout << " étalement en x : " << ex << endl;
	cout << " étalement en y : " << ey << endl;

	
	
}
void Montagne ::  dessine_sur(SupportADessin a_dessiner) override 
{
	a_dessiner.dessine->this*;
	
}

void ChaineDeMontagnes:: set_montagne(double x, double y, double h, double ox, double oy, const unsigned int &indice)
{
	montagnes_simples[indice].set_montagne(x, y, h, ox, oy);
}

void ChaineDeMontagnes:: set_montagne(ChaineDeMontagnes chaine, const unsigned int &indice)
{
	montagnes_simples[indice] = chaine;
}
	
double ChaineDeMontagnes:: altitude(double a, double b) //quand on fait l'altitude sur une CHAINE on regarde si le nomre de montagnes simples et de chaines simples est mul, ici c'est pas le cas...
{
	double retour;
	if ((nombre_montagnes == 0) && (nombre_chaines == 0)) //pour une certaine raison ces deux nombres sont nuls c'était pas prévu
	{
		retour = 0;
	}
	else
	{
		if (montagnes_simples.size() == 0)
		{
			retour = chaines_simples[0].altitude(a, b);
			for (size_t j(0); j < chaines_simples.size(); ++j)
			{
				if (chaines_simples[j].altitude(a, b) > retour)
				{
					retour = chaines_simples[j].altitude(a, b);
				}
			}
		}
		else if (chaines_simples.size() == 0)
		{
			retour = montagnes_simples[0].altitude(a, b);
			retour = montagnes_simples[0].altitude(a, b);
			for (size_t i(0); i < montagnes_simples.size(); ++i)
			{
				if (montagnes_simples[i].altitude(a, b) > retour)
				{
					retour = montagnes_simples[i].altitude(a, b);
				}
			}
		}
		else
		{
			
			if (montagnes_simples[0].altitude(a, b) > chaines_simples[0].altitude(a, b))
			{
				retour = montagnes_simples[0].altitude(a, b);
			}
			else
			{
				retour = chaines_simples[0].altitude(a, b);
			}

			for (size_t i(0); i < montagnes_simples.size(); ++i)
			{
				if (montagnes_simples[i].altitude(a, b) > retour)
				{
					retour = montagnes_simples[i].altitude(a, b);
				}
			}

			for (size_t j(0); j < chaines_simples.size(); ++j)
			{
				if (chaines_simples[j].altitude(a, b) > retour)
				{
					retour = chaines_simples[j].altitude(a, b);
				}
			}
		}
		
	}
	return retour;
}

int ChaineDeMontagnes:: get_nbre_montagnes()
{
	return nombre_montagnes;
}

int ChaineDeMontagnes:: get_nbre_chaines()
{
	return nombre_chaines;
}
