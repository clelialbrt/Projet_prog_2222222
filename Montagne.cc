#include <cmath>
#include "Montagne.h"
using namespace std;

double Montagne:: altitude(double a, double b) const
{
	double altitude(H*exp(-((a-x0)*(a-x0))/(2*ex*ex)-((b-y0)*(b-y0))/(2*ey*ey)));
	if (altitude < 0.5) { return 0; }
	else { return altitude; }
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
int main()
{
	return 0;
}
