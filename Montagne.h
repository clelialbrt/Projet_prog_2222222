#pragma once
#include <iostream> 
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include "Dessinable.h"
#include "SupportADessin.h"
#include "ChampsPotentiels.h"

class Montagne : public Dessinable
{
	
	public: 
	Montagne(double x, double y, double h, double ox, double oy) : x0(x), y0(y), H(h), ex(ox), ey(oy) {}
	Montagne() : x0(0), y0(0), H(0), ex(0), ey(0) {}
	virtual double altitude(double a, double b) const;
	virtual void set_montagne(double x, double y, double h, double ox, double oy);
	void affiche_para();
	virtual void dessine_sur(SupportADessin &a_dessiner) override ;
	
	private:
	double x0;
	double y0;
	double H;
	double ex;
	double ey;
	std::string type;
	
};

class ChaineDeMontagnes : public Montagne
{
	
	public: 
	//elle possede quand meme une methode permettant de calculer son altitude, il faudrait des manipulateurs permettant de déterminer la valeur des attributs "uniques" en fonction du tableau
	//ou alors rendre la classe Montagne virtuelle et respécifier uniquement les attributs qui nous intéressent ici?
	//ou alors ne pas la faire en tant que sous classe... ca n'a pas beaucoup de sens...
	//faire une méthode qui créée le tableau?
	ChaineDeMontagnes(double x, double y, double h, double ox, double oy, const unsigned int &nombre) : Montagne(x, y, h, ox, oy), nombre_montagnes(nombre) 
	{
		Montagne mon(x, y, h, ox, oy);
		for (size_t i(0); i < nombre_montagnes; ++i)
		{
			montagnes_simples.push_back(mon);
		}
	}
	* 
	ChaineDeMontagnes(ChaineDeMontagnes	chaine_a_mettre, const unsigned int &nombre2) : Montagne(0, 0, 0, 0, 0), nombre_chaines(nombre2)
	{
		for (size_t j(0); j < nombre_chaines; ++j)
		{
			chaines_simples.push_back(chaine_a_mettre);
		}
	}
	
	ChaineDeMontagnes() : Montagne(), nombre_montagnes(0), nombre_chaines(0) //y a suremenet un probleme avec le fait qu'ils soient tous vides 
	{
		std::vector<Montagne> monts;
		std::vector<ChaineDeMontagnes> chais;
		montagnes_simples = monts;
		chaines_simples = chais;
	}
	
	ChaineDeMontagnes(const unsigned int &nombre, const unsigned int &nombre2) : Montagne(0, 0, 0, 0, 0), nombre_montagnes(nombre), nombre_chaines(nombre2)
	{
		Montagne mon;
		for (size_t i(0); i < nombre_montagnes; ++i)
		{
			montagnes_simples.push_back(mon);
		}
		ChaineDeMontagnes chai;
		for (size_t j(0); j < nombre_chaines; ++j)
		{
			chaines_simples.push_back(chai); //du coup on met autant de chaines vides qu'on veut 
			//puis quand on 
		}
	}
	
	int get_nbre_montagnes();
	int get_nbre_chaines();
	
	void set_montagne(double x, double y, double h, double ox, double oy, const unsigned int &indice);
	void set_montagne(ChaineDeMontagnes chaine, const unsigned int &indice);
	
	//une méthode qui boucle pour ajouter des montagnes?? comment on fait?
	//le probleme c'est qu'on a deux tableaux differents... comment 
	
	double altitude(double a, double b);
	
	
	//private:
	unsigned int nombre_montagnes;
	unsigned int nombre_chaines;
	std::vector<Montagne> montagnes_simples; 
	std::vector<ChaineDeMontagnes> chaines_simples;
	
	//conception: tableau de pointeurs vers des Montagnes simples et en meme temps herite de Montagne -> comment definir son etalement, etc? ca ne peut pas etre une montagne simple ig... alors une montagne simple herite d'une chaine de montagnes? mais alors comment on definit ses attributs?
	//pour l'instant on la laisse en sous-classe mais va falloir trouver un moyen de calculer ses autres attributs eh
	//ses autres attributs seront initialisés aux valeurs nulles alors? par defaut?
};
