#prama once 
#include <iostream>
#include <vector>
#include "Boite3D.h"
#include "CubeAir.h"
#include "Dessinable.h"

class Ciel : public Boite3D Dessinable

{
	friend class CubedAir;
	public:
	Ciel(const ChampsPotentiels& champ) : Boite3D(champ.Nx, champ.Ny, champ.Nz, champ.pas) {}
	
	
	private:
	std::vector<std::vector<std::vector<CubedAir>>> cubes_dair;
};
