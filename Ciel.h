#prama once 

class Ciel : public Boite3D
{
	friend class CubedAir;
	public:
	Ciel(const ChampsPotentiels& champ) : Boite3D(champ.Nx, champ.Ny, champ.Nz, champ.pas) {}
	
	
	private:
	std::vector<std::vector<std::vector<CubedAir>>> cubes_dair;
};
