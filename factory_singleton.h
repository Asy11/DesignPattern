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

struct chargerFac{
	virtual Circuit* Create_Circuit() = 0;
	virtual Plastic* Create_Plastic() = 0;
};

struct ChargerFac_LG : public chargerFac{
	private:
		static ChargerFac_LG* instance;
	public:
		ChargerFac_LG* Getinstance(){
			if (instance == NULL) 
				instance = new ChargerFac_LG;
			else 
				return instance;
		}
		Circuit* Create_Circuit(){
			return new Circuit_LG;
		}
		Plastic* Create_Plastic(){
			return new Plastic_LG;
		}
};

struct ChargerFac_SS : public chargerFac{
	private:
		static ChargerFac_SS* instance;
	public:
		ChargerFac_SS* Getinstance(){
			if (instance == NULL) 
				instance = new ChargerFac_SS;
			else 
				return instance;
		}
		Circuit* Create_Circuit(){
			return new Circuit_SS;
		}
		Plastic* Create_Plastic(){
			return new Plastic_SS;
		}
};

