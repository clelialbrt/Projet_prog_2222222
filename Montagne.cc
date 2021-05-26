#include <cmath>
#include <iostream>
#include "Montagne.h"
#include "Dessinable.h"
#include "SupportADessin.h"
using namespace std;

double Montagne:: altitude(double a, double b) const //méthode virtuelle qui calcule l'altitude d'une montagne pure
{
	double altitude(H*exp(-((a-x0)*(a-x0))/(2*ex*ex)-((b-y0)*(b-y0))/(2*ey*ey)));
	if (altitude < 0.5) { return 0; }
	else { return altitude; }
}

void Montagne:: set_montagne(double x, double y, double h, double ox, double oy) //méthode permettant de modifier les attributs d'une montagne avec les valeurs passées en arguments
{
	x0 = x;
	y0 = y;
	H = h;
	ex = ox;
	ey = oy;
}

void Montagne :: affiche_para() //méthode permettant d'afficher les attributs d'une montagne

{
	cout << " une montagne : " << endl;
	cout << type << " de paramètre : " << endl;
	cout << " centre de la montagne (" << x0 << "," << y0 << ");" << endl;
	cout << " hauteur maximale : " << H << endl;
	cout << " étalement en x : " << ex << endl;
	cout << " étalement en y : " << ey << endl;

	
	
}
void Montagne ::  dessine_sur(SupportADessin a_dessiner) override //méthode dessine_sur redéfinie
{
	a_dessiner.dessine->this*;
	
}

void ChaineDeMontagnes:: set_montagne(double x, double y, double h, double ox, double oy, const unsigned int &indice) //méthode permettant de modifier la indice-ieme montagne simple du tableau de montagnes en attributs d'une chaine de montagnes 
{
	montagnes_simples[indice].set_montagne(x, y, h, ox, oy);
}

void ChaineDeMontagnes:: set_montagne(ChaineDeMontagnes chaine, const unsigned int &indice) //la meme chpse mais y met une chaine passée en argument 
{
	montagnes_simples[indice] = chaine;
}
	
double ChaineDeMontagnes:: altitude(double a, double b) //quand on fait l'altitude sur une CHAINE on regarde si le nomre de montagnes simples et de chaines simples est mul, ici c'est pas le cas...
{//c'est un mal de tête cette méthode mais trkl
	double retour;
	if ((nombre_montagnes == 0) && (nombre_chaines == 0)) //si il y a pas de montagnes y a pas d'altitude
	{
		retour = 0;
	}
	else
	{
		if (montagnes_simples.size() == 0) //eviter un segmentation fault si y a aucune montagne simple 
		{
			retour = chaines_simples[0].altitude(a, b); //on initialise le retour avec la premiere valeur
			for (size_t j(0); j < chaines_simples.size(); ++j)
			{
				if (chaines_simples[j].altitude(a, b) > retour)
				{
					retour = chaines_simples[j].altitude(a, b); //si on trouve une valeur plus grande on la met dans le nouveau retour 
				}
			}
		}
		else if (chaines_simples.size() == 0) //idem pour les chaines 
		{
			retour = montagnes_simples[0].altitude(a, b); //on initialise pareil
			for (size_t i(0); i < montagnes_simples.size(); ++i)
			{
				if (montagnes_simples[i].altitude(a, b) > retour)
				{
					retour = montagnes_simples[i].altitude(a, b);
				}
			}
		}
		else //si il a des elemts dans les deux tableaux on peut utiliser les deux tableaux
		{
			
			if (montagnes_simples[0].altitude(a, b) > chaines_simples[0].altitude(a, b)) //on initialise avec la valeur la plus grande des deux 
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

int ChaineDeMontagnes:: get_nbre_montagnes() //getter du nombre de montagnes pures qui composent la chaine
{
	return nombre_montagnes;
}

int ChaineDeMontagnes:: get_nbre_chaines() //gette du nombre de chaines qui composent la chaine 
{
	return nombre_chaines;
}
