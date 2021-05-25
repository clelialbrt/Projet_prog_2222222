#pragma once
#include <iostream>


class Boite3D
{
	public:
	Boite3D(unsigned int nomx, unsigned int nomy, unsigned int nomz, double ps) : Nx(nomx), Ny(nomy), Nz(nomz), pas(ps) {}
	int getNx() const;
	int getNy() const;
	int getNz() const;
	double getpas() const;
	
	protected:
	unsigned int Nx;
	unsigned int Ny;
	unsigned int Nz;
	double pas;
};
