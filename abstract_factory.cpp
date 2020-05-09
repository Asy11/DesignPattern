#include "abstract_factory.h"

int main(int argc, char* argv[]){
	ChargerFac* MyFac;

	if(!strcmp(argv[1], "A"))
		MyFac = new ChargerFacA;
	else
		MyFac = new ChargerFacB;

	Circuit* MyCircuit = MyFac->CreateCircuit();
	Plastic* MyPlastic = MyFac->CreatePlastic();

	MyCircuit->Create();
	MyPlastic->Create();

	return 0;
}
