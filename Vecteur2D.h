#pragma once
#include <iostream>
#include <ostream>
#include <cmath>

class Vecteur2D
{
    friend std::ostream& operator<<(std::ostream& sortie, Vecteur2D const& vect);
    friend class ChampsPotentiels;
    friend class Potentiel;
    public:
    
    Vecteur2D (int x=0, int y=0) // constructeur par défaut au vecteur nul
    : coord_x(x), coord_y(y)
    {}
    
    Vecteur2D( Vecteur2D const& autre) // constructeur de copie pour attributs en respect de la "règle d'or" 
    :coord_x( autre.coord_x), coord_y(autre.coord_y)
    {}
    
    bool operator==(Vecteur2D const& v) const;

    Vecteur2D& operator+= ( Vecteur2D V); // operateur interne +=
    
    Vecteur2D& operator-= ( Vecteur2D v2); // operateur interne -=    
    
    const Vecteur2D operator-();  // opposé 
    
    Vecteur2D& operator*=( double x);  // operateur interne *=
    
    double produit_scal( const Vecteur2D& autre);
    
    double norme2();
    
    double norme();
    
    Vecteur2D& operator~();
    
    //Vecteur2D unitaire();
    
    protected:
    double coord_x;
    double coord_y;
    
};

//--------------------------------------------------------------EXTERNE-------------------------------------------------------------//
		
Vecteur2D& operator + ( Vecteur2D v1,  Vecteur2D& v2);  // operateur externe +
		
Vecteur2D& operator - ( Vecteur2D v1, const Vecteur2D& v2);  // operateur externe -
		
Vecteur2D& operator * ( Vecteur2D v1,  double x);  // operateur externe *

std::ostream& operator<<(std::ostream& sortie, Vecteur2D const& vect); // sert à afficher
