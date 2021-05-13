#pragma once
#include <iostream> 
#include <cmath>

class Montagne
{
	
	public: 
	Montagne(double x, double y, double h, double ox, double oy) : x0(x), y0(y), H(h), ex(ox), ey(oy) {}
	double altitude(double a, double b) const;
	
	private:
	double x0;
	double y0;
	double H;
	double ex;
	double ey;
};
