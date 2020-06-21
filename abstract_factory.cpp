#include "abstract_factory.h"

int main(int argc, char* argv[]){
	ChargerFac* MyFac;

	if(!strcmp(argv[1], "LG"))
		MyFac = new ChargerFac_LG;
	else
		MyFac = new ChargerFac_SS;

	Circuit* MyCircuit = MyFac->CreateCircuit();
	Plastic* MyPlastic = MyFac->CreatePlastic();

	MyCircuit->Create();
	MyPlastic->Create();

	return 0;
}