#include "factory_singleton.h"

int main(int argc, char* argv[]){

	ChargerFac_LG LG_Fac;
	ChargerFac_SS SS_Fac;

	Circuit* MyCircuit;
	Plastic* MyPlastic;
	
	if(!strcmp(argv[1], "LG"))
	{
		MyCircuit = LG_Fac.Create_Circuit();
		MyPlastic = LG_Fac.Create_Plastic();
	}
	else
	{
		MyCircuit = SS_Fac.Create_Circuit();
		MyPlastic = SS_Fac.Create_Plastic();
	}

	MyCircuit->Create();
	MyPlastic->Create();

	return 0;
}