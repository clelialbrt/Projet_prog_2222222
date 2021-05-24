#include <iostream>
#include <cmath>
#include "Vecteur2D.h"

using namespace std;

//--------------------------------------------------------------OPERATEURS INTERNES-------------------------------------------------------------//


bool Vecteur2D:: operator == (Vecteur2D const& V) const
{
	return (coord_x == V.coord_x) && (coord_y == V.coord_y));
	//return not((abs(coord_x - V.coord_x) > 10e-6) or (abs(coord_y - V.coord_y) > 10e-6) or (abs(coord_z - V.coord_z) > 10e-6));
}

// - opérateur interne - Retourne l'addition au vecteur du vecteur "V"   
Vecteur2D& Vecteur2D:: operator += (Vecteur2D const& V) 
{
    coord_x += V.coord_x;
    coord_y += V.coord_y;
                         
    return *this;
}

// - opérateur interne - Retourne la soustraction au vecteur du vecteur "V" 
Vecteur2D& Vecteur2D:: operator -= (Vecteur2D const& V)  
{
    coord_x -= V.coord_x;
    coord_y -= V.coord_y;

    return *this;
}   
 
// - opérateur interne - Retourne le vecteur multiplié par x
const Vecteur2D& Vecteur2D:: operator *= (double const& x)  
{		
     coord_x *= x;
     coord_y *= x;  
     
     return *this;    
}

// Retourne l'opposé du vecteur
Vecteur2D Vecteur2D:: operator Op ()  
{       
     coord_x = 0. - coord_x;
     coord_y = 0. - coord_y;
        
     return *this;        
}

// - opérateur interne - Retourne le vecteur unitaire associé à la direction du vecteur initial
Vecteur2D& Vecteur2D:: operator ~ ()
{
        
    coord_x = 1.0 / norme(); // assure une division de double
    coord_y = 1.0 / norme();

    return *this ;
}
    
//--------------------------------------------------------------METHODES-------------------------------------------------------------//


//Retourne le produit scalaire du vecteur appelé et de "V"
double Vecteur2D:: produit_scal(Vecteur2D const& V) const
{
	return (coord_x * V.coord_y + coord_y * V.coord_x);
}

//Retourne la norme du vecteur au carré
double Vecteur2D:: norme2() const
{
    return (coord_x * coord_x + coord_y * coord_y);
}

//Retourne la norme du vecteur 
double Vecteur2D:: norme() const
{ 
    return sqrt(norme2()); 
}
    

/*Vecteur2D Vecteur2D:: unitaire() const
{
    Vecteur2D unitaire;
    unitaire.set_coord( coord_x / norme(), coord_y/ norme());
    return unitaire;
}*/


//--------------------------------------------------------------OPERATEURS EXTERNES-------------------------------------------------------------//



Vecteur2D& operator + (Vecteur2D v1, const Vecteur2D& v2) // operateur externe +
{
	return v1 += v2;
}
		
Vecteur2D& operator - (Vecteur2D v1, const Vecteur2D& v2) // operateur externe -
{
	return v1 -= v2;
}
		
Vecteur2D& operator * (double x, Vecteur2D& V) // operateur externe *
{
	return V *= x;
}

Vecteur2D& operator * (Vecteur2D& V, double const& x) // assure commutativité de la multiplication par un scalaire
{
	return V *= x;
}

std::ostream& operator<<(std::ostream& sortie, Vecteur2D const& V) // permet d'afficher un vecteur par surcharge de <<
{
	sortie << V.coord_x << " " << V.coord_y;
	return sortie;
}


