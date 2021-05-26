#include <iostream> 
#include "Montagne.h"
#include <cmath>

using namespace std;

int main()
{
	Montagne montagne(15, 15, 18, 5, 10);
	for (double i(0); i <= 29; ++i)
	{
		for (double j(0); j <= 29; ++j)
		{
			cout << i << " " << j << " " << montagne.altitude(i, j) << endl;
		}
		cout << endl;
	}
	return(0);
};
