#include <iostream>
#include <vector>
#include "Vecteur2D.h"
#include "Montagne.h"
#include "ChampsPotentiels.h"
#include "constantes.h"
#include <cmath>

using namespace std;
using namespace Physique;

void ChampsPotentiels:: initialise(double vi, Montagne const& mont) 
{
	for (unsigned int x(0); x < Nx; ++x)
	{
		potentiels3D.push_back(vector<vector<Potentiel>> ());
		
		for (unsigned int y(0); y < Ny; ++y)
		{
			potentiels3D[x].push_back(vector<Potentiel> ());
			
			for (unsigned int z(0); z < Nz; ++z)
			{
				potentiels3D[x][y].push_back(Potentiel ()); //modifier le constructeur par défaut 
				
				if ((x != 0) or (x != Nx-1) or (y != 0) or (y != Ny-1) or (z != 0) or (z != Nz-1) or (z >= mont.altitude(x, y))) 
				{
					potentiels3D[x][y][z].poten.coord_x = - (vi/2.0) * (z * pas);
					potentiels3D[x][y][z].poten.coord_y = (vi/2.0) * (y - (Ny - 1)/2.0) * pas;	
					/*cout << x << " " << y << " " << z << " " << - (vi/2) * (z * pas) << " " << (vi/2) * (y - (Ny - 1)/2) * pas << " " << vi/2  << " " << pas << " ";
					cout << endl;*/
				}
				else
				{
					potentiels3D[x][y][z].poten.coord_x = 0;
					potentiels3D[x][y][z].poten.coord_y = 0;
				}
			}
		}
	}
}

array<double, 3> ChampsPotentiels:: vitesse(unsigned int i, unsigned int j, unsigned int k) const
{
	array < double, 3 > v {0};
	if (( i > Nx) or ( j > Ny) or ( k > Nz))
	{
		cerr << "Erreur : dimension fausse " << endl;
		return v; 
	}
	else 
	{
		if (not estauxbords(potentiels3D[i][j][k]))
		{
			v[0] = potentiels3D[i+1][j][k].poten.coord_x - potentiels3D[i-1][j][k].poten.coord_x;
			v[1] = potentiels3D[i-1][j][k].poten.coord_y - potentiels3D[i+1][j][k].poten.coord_y;
			v[2] = (potentiels3D[i][j+1][k].poten.coord_y - potentiels3D[i][j-1][k].poten.coord_y - potentiels3D[i][j][k+1].poten.coord_x + potentiels3D[i][j][k-1].poten.coord_x);
			for ( auto element : v)
			{
				element *= (1./ pas) ;
			}
			return v;
		}
		else { return v; }
	}	
}

double ChampsPotentiels:: norme_vitesse(unsigned int pointi, unsigned int pointj, unsigned int pointk)
{
	array<double, 3> coord_vitesse(vitesse(pointi, pointj, pointk));
	return sqrt(coord_vitesse[0]*coord_vitesse[0] + coord_vitesse[1]*coord_vitesse[1] + coord_vitesse[2]*coord_vitesse[2]);
}

	
void ChampsPotentiels:: resolution (double seuil, unsigned int max, bool verbeuse)
{
	unsigned int n = 0;	
	while (( erreur() >= seuil ) and (n < max))
	{
		++n;
		calcule_laplaciens();
		iteration();
		cout << n << " ";
		/*if (verbeuse)
		{
			for (unsigned int x(0); x < Nx; ++x)
			{
				for (unsigned int y(0); y < Ny; ++y)
				{
					for (unsigned int z(0); z < Nz; ++z)
					{
						potentiels3D[x][y][z].affiche();
					}
				}
			}
		}*/
	}
}

void ChampsPotentiels:: iteration(double E) 
{
	for (unsigned int x(0); x < Nx; ++x)
	{
		for (unsigned int y(0); y < Ny; ++y)
		{
			for (unsigned int z(0); z < Nz; ++z)
			{
				if (not estauxbords(potentiels3D[x][y][z]))
				{
					potentiels3D[x][y][z].poten += potentiels3D[x][y][z].laplacien * E;
				}
			}
		}
	}
	
}

void ChampsPotentiels :: calcule_laplaciens()
    {
        for (size_t i(1); i < Nz-1; ++i)
        {
            for(size_t j(1); j < Ny-1; ++j)
            {
                for (size_t k(1); k < Nx-1; ++k)
                {
                    /*if (estauxbords(potentiels3D[i][j][k]))                    
                    {
                        potentiels3D[i][j][k].laplacien = 0; //est ce qu'il considere qu'ils sont tous au bord?????????????????????????????????????                
                    }
                    else 
                    {*/
					potentiels3D[i][j][k].laplacien = potentiels3D[i-1][j][k].poten + potentiels3D[i][j-1][k].poten + potentiels3D[i][j][k-1].poten 
					+ potentiels3D[i+1][j][k].poten + potentiels3D[i][j+1][k].poten + potentiels3D[i][j][k+1].poten - potentiels3D[i][j][k].poten * 6.0;
					//cout << i << " " << j << " " << k << " " << potentiels3D[i][j][k].laplacien << endl;
					//cout << i << " " << j << " " << k << " " << potentiels3D[i][j][k].laplacien << endl;
                }
            }
        }
        cout << "27 18 1 " << potentiels3D[27][18][1].laplacien << endl;
        //remettre(m);
    }
/*void ChampsPotentiels::remettre(Montagne m){
    for (unsigned int x(0); x < Nx; ++x)
	{
		for (unsigned int y(0); y < Ny; ++y)
		{
			for (unsigned int z(0); z < Nz; ++z)
			{
                if (m.altitude(x,y)> z)
                {
                    potentiels3D[x][y][z].laplacien.coord_x = 0;
                    potentiels3D[x][y][z].laplacien.coord_y = 0;
                }
            }
        }
    }
}*/

double ChampsPotentiels:: erreur()
{
	double retour(0);
	for (unsigned int x(0); x < Nx; ++x)
	{
		for (unsigned int y(0); y < Ny; ++y)
		{
			for (unsigned int z(0); z < Nz; ++z)
			{
				retour += potentiels3D[x][y][z].laplacien.norme2(); //pour tous les points? pour quelle valeur de la vitesse? 
				cout << retour << endl;
			}
		}
	}
	cout << retour << endl;
	return retour;
}

bool ChampsPotentiels:: estauxbords(Potentiel pot) const
{
	if ((pot.poten.coord_x == 0) or (pot.poten.coord_x == Nx-1) or (pot.poten.coord_y == 0) or (pot.poten.coord_y == Ny-1))
	{
		return true;
	}
	else
	{
		return false;
	}
}
