#include <iostream>
#include "Vecteur2D.h"
using namespace std;

int main()
{
	Vecteur2D vect1(1.0, 2.0);
	Vecteur2D vect2(1.0, 2.0);
	Vecteur2D vect3(vect1);
	
	cout << "Vecteur 1 : ";
	cout << vect1;
	cout << endl;
	
	cout << "Vecteur 2 : ";
	cout << vect2;
	cout << endl;
	
	cout << "Le vecteur 1 est ";
	if (vect1 == vect2) {
		    cout << "égal au";
	} else {
		    cout << "différent du";
	}
	
	cout << " vecteur 2," << endl << "et est ";
	if (vect1 == vect3) {
		    cout << "égal au";
	} else {
		    cout << "différent du";
	}
	cout << " vecteur 3." << endl;
	
	 Vecteur2D vect4;
	Vecteur2D vect5(3.0, 9.0);
	
	cout << "Test vecteur nul" << endl;
	cout << "vect4 : " << vect4 << endl;
	
	cout << endl;
	
	cout << "Test opérateurs" << endl;
	
	cout << endl;
	
	cout << " vect5 - vect1 = " << vect5 - vect1 << endl;
	cout << " vect1 - vect5 = " << vect1 - vect5 << endl;
	cout << " vect5 + vect1 = " << vect5 + vect1 << endl;
	cout << " vect1 + vect5 = " << vect1 + vect5 << endl;
	
	cout << endl;
	

	cout << " 3 * vect2 = " << 3 * vect2 << endl;
	
	cout << endl;
	
	cout << " - vect2 = " << -vect2 << endl;
	
	cout << endl;
	
	cout << " vecteur unitaire de vect3 : " <<  ~vect3 << endl;
	
	return 0;
}
