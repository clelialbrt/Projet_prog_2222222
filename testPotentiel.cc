#include <iostream> 
#include "Vecteur2D.h"
#include "Montagne.h"
#include "ChampsPotentiels.h"
#include "Potentiel.h"

using namespace std;
using namespace Physique;

int main()
{
	Montagne montagne(15.0, 15.0, 15.0, 5.0, 5.0);
	ChampsPotentiels champ(30, 30, 30, 20.0/29.0);
	int vinfini(15);
	champ.initialise(vinfini, montagne);
	vector<vector<vector<Potentiel>>> a_afficher(champ.get_tableaudepotentiels());
	for (int x(0); x < champ.getNx(); ++x)
	{
		for (int y(0); y < champ.getNy(); ++y) 
		{
			for (int z(0); z < champ.getNz(); ++z)
			{
				cout << x << " " << y << " " << z << " ";
				a_afficher[x][y][z].affiche();
			}
		}
	} 
	return 0;
}
