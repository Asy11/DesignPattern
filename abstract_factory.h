#include <iostream>
#include <string.h>

using namespace std;

struct Circuit{
	virtual void Create() = 0;
};

struct Plastic{
	virtual void Create() = 0;
};

struct Circuit_LG : public Circuit{
	void Create(){
		cout << "Create Circuit_LG" << endl;
	}	
};

struct Circuit_SS : public Circuit{
	void Create(){
		cout << "Create Circuit_SS" << endl;
	}	
};

struct Plastic_LG : public Plastic{
	void Create(){
		cout << "Create Plastic_LG" << endl;
	}
};

struct Plastic_SS : public Plastic{
	void Create(){
		cout << "Create Plastic_SS" << endl;
	}
};

struct ChargerFac{
	virtual Circuit* CreateCircuit() = 0;
	virtual Plastic* CreatePlastic() = 0;
};

struct ChargerFac_LG : public ChargerFac{
	Circuit* CreateCircuit(){
		return new(Circuit_LG); 
	}
	Plastic* CreatePlastic(){
		return new(Plastic_LG);
	}
};

struct ChargerFac_SS : public ChargerFac{
	Circuit* CreateCircuit(){
		return new(Circuit_SS); 
	}
	Plastic* CreatePlastic(){
		return new(Plastic_SS);
	}
};
