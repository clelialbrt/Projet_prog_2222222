#include <iostream>
#include <ostream>
#include <cmath>
#include "Vecteur2D.h"

using namespace std;

bool Vecteur2D:: operator==(Vecteur2D const& v) const
{
	bool retour((coord_x == v.coord_x) && (coord_y == v.coord_y));
	return retour;
}
    
Vecteur2D& Vecteur2D:: operator+= ( Vecteur2D V) // operateur interne +=
{
    coord_x += V.coord_x;
    coord_y += V.coord_y;
                         
    return *this;
}
    
Vecteur2D& Vecteur2D:: operator-= ( Vecteur2D v2)  // operateur interne -=
{
    coord_x -= v2.coord_x;
    coord_y -= v2.coord_y;

    return *this;
}
    
    
const Vecteur2D Vecteur2D:: operator-()  // opposé 
{
        
     coord_x = -coord_x;
     coord_y = -coord_y;
        
     return *this;
        
}
    
Vecteur2D& Vecteur2D:: operator*=( double x)  // operateur interne *=
{
		
     coord_x *= x;
     coord_y *= x;
        
     return *this;
    
}
    
double Vecteur2D:: produit_scal( const Vecteur2D& autre)
{
	return (coord_x * autre.coord_y - coord_y * autre.coord_x);
}
    
double Vecteur2D:: norme2()
{
    return (coord_x * coord_x + coord_y * coord_y);
}
    
double Vecteur2D:: norme()
{
    return sqrt( norme2()); 
}
    
Vecteur2D& Vecteur2D:: operator~()
{
        
    coord_x /= norme();
    coord_y /= norme();

    return *this ;
}
    
Vecteur2D Vecteur2D:: unitaire()
{
    Vecteur2D unitaire;
    unitaire.set_coord( coord_x / norme(), coord_y/ norme());

    return unitaire;
}
	
//--------------------------------------------------------------EXTERNE-------------------------------------------------------------//


		
Vecteur2D& operator + ( Vecteur2D v1,  Vecteur2D& v2)  // operateur externe +
{
	return v1 += v2;
}
		
Vecteur2D& operator - ( Vecteur2D v1, const Vecteur2D& v2)  // operateur externe -
{
	return v1 -= v2;
}
		
Vecteur2D& operator * ( Vecteur2D v1,  double x)  // operateur externe *
{
	return v1 *= x;
}

std::ostream& operator<<(std::ostream& sortie, Vecteur2D const& vect)
{
	sortie << vect.coord_x << " " << vect.coord_y;
	return sortie;
}
