#include <iostream> 
#include "Montagne.h"
#include <cmath>

using namespace std;

int main()
{
	ChaineDeMontagnes chaine(1, 1); //on cree une chaine avec une montagne et une chaine de montagne vides
	chaine.set_montagne(15, 15, 18, 5, 10, 0); //dans la première case du tableau on met une montagne simple -> la dimension de ce tableau n'est pas vide ou bien? on le met dans quel tableau?
	ChaineDeMontagnes chaine1(2, 0); //on cree la chaine secondaire qui contient deux montagnes simples... mais peut etre faut la creer avec des attributs non nuls??
	chaine1.set_montagne(2, 22, 12, 12, 3, 0); //on cree la premiere montagne dans la deuxieme chaine, bien faire attention a pas reutiliser le constructeur!!
	chaine1.set_montagne(20, 2, 15, 8, 4, 1); //on cree la deuxieme montagne dans la deuxieme chaine 
	chaine.set_montagne(chaine1, 1); //on met la chaine secondaire dans la premiere donc techniquement ses attributs remplacent ceux de la chaine vide... 

//probleme de constructeur connasse!!
//cest la méthode altutude qui fonctionne ap

	for (double i(0); i <= 29; ++i)
	{
		for (double j(0); j <= 29; ++j)
		{
			cout << i << " " << j << " " << chaine.altitude(i,j) << endl;
		}
		cout << endl;
	}

	return(0);
}


//conceptuellement qu'est ce qui marche pas? notre methode altitude... pourquoi il retourne pas le maximum comme on veut? est ce qu'il rentre dans les autres iterations?
//et si on met sa hauteur plus basse que celle des autres on a le meme probleme? aussi pq toutes nos valeurs sont 0?
