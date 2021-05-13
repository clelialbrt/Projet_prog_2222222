#pragma once

class Boite3D
{
	public:
	Boite3D(unsigned int nomx, unsigned int nomy, unsigned int nomz, double ps) : Nx(nomx), Ny(nomy), Nz(nomz), pas(ps) {}
	int getNx();
	int getNy();
	int getNz();
	double getpas();
	
	protected:
	unsigned int Nx;
	unsigned int Ny;
	unsigned int Nz;
	double pas;
};
