#include <iostream>
#include <string.h>

using namespace std;

struct Circuit{
	virtual void Create() = 0;
};

struct Plastic{
	virtual void Create() = 0;
};

struct CircuitA : public Circuit{
	void Create(){
		cout << "Create CircuitA" << endl;
	}	
};

struct CircuitB : public Circuit{
	void Create(){
		cout << "Create CircuitB" << endl;
	}	
};

struct PlasticA : public Plastic{
	void Create(){
		cout << "Create PlasticA" << endl;
	}
};

struct PlasticB : public Plastic{
	void Create(){
		cout << "Create PlasticB" << endl;
	}
};

struct ChargerFac{
	virtual Circuit* CreateCircuit() = 0;
	virtual Plastic* CreatePlastic() = 0;
};

struct ChargerFacA : public ChargerFac{
	Circuit* CreateCircuit(){
		return new(CircuitA); 
	}
	Plastic* CreatePlastic(){
		return new(PlasticA);
	}
};

struct ChargerFacB : public ChargerFac{
	Circuit* CreateCircuit(){
		return new(CircuitB); 
	}
	Plastic* CreatePlastic(){
		return new(PlasticB);
	}
};
