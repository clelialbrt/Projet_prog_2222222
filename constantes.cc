#include "constantes.h"


	extern const double Physique::g(9.81);
	extern const double Physique::vinfini(15);
	extern const double Physique::Tinfini(284.5);
	extern const double Physique::Pinfini(101325);
	extern const double Physique::Pref(101325);
	extern const double Physique::tau(8.10e-3);
	extern const double Physique::Meau(0.0180153);
	extern const double Physique::Mair_sec(0.02896);
	extern const double Physique::R(8.3144621);
	extern const double Physique::hinfini((7/2)*(R/Mair_sec)*Tinfini);
	extern const double Physique::cte(0.5*vinfini*vinfini + hinfini);
