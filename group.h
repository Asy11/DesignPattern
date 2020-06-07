#include <iostream>
#include <string.h>
#include <vector>

///////// Abstract Fac ////////
class Leg{
	virtual void create() = 0;
};

class Frame{
	virtual void create() = 0;
};

class Mat{
	virtual void create() = 0;
};

class Leg_Simons : public Leg{
public:
    Leg_Simons() : Leg(){}
	void create(){
		std::cout << "Create Leg_Simons" << std::endl;
	}	
};

class Leg_Ace : public Leg{
public:
    Leg_Ace() : Leg(){}
	void create(){
		std::cout << "Create Leg_Ace" << std::endl;
	}	
};

class Frame_Simons : public Frame{
public:
    Frame_Simons() : Frame(){}
	void create(){
		std::cout << "Create Frame_Simons" << std::endl;
	}	
};

class Frame_Ace : public Frame{
public:
    Frame_Ace() : Frame(){}
	void create(){
		std::cout << "Create Frame_Ace" << std::endl;
	}	
};

class Mat_Simons : public Mat{
public:
    Mat_Simons() : Mat(){}
	void create(){
		std::cout << "Create Mat_Simons" << std::endl;
	}	
};

class Mat_Ace : public Mat{
public:
    Mat_Ace() : Mat(){}
	void create(){
		std::cout << "Create Mat_Ace" << std::endl;
	}	
};

class Bed{
public:
	virtual Leg* createLeg() = 0;
	virtual Frame* createFrame() = 0;
	virtual Mat* createMat() = 0;
};

class Bed_Simons : public Bed{
public:
	Leg* createLeg(){
		return new Leg_Simons(); 
	}
	Frame* createFrame(){
		return new Frame_Simons();
	}
    Mat* createMat(){
		return new Mat_Simons();
	}
};

class Bed_Ace : public Bed{
public:
	Leg* createLeg(){
		return new Leg_Ace(); 
	}
	Frame* createFrame(){
		return new Frame_Ace();
	}
    Mat* createMat(){
		return new Mat_Ace();
	}
};

//////// Composite ////////
class BedComponent{
public:
    virtual void manufacture() = 0;
    virtual int manufacturingTime() = 0;
    virtual void extramanufacturingTime(int t) = 0;
};

class ClassicLeg : public BedComponent{
    int _time;
public:
    ClassicLeg(int t) : _time(t){}

    void manufacture(){
        std::cout << "manufacturing Classic Leg (" << _time << " Min)"<< std::endl;
    }
    int manufacturingTime(){
        return _time;
    }
    void extramanufacturingTime(int t){
        _time += t;
    }
};

class ModernLeg : public BedComponent{
    int _time;
public:
    ModernLeg(int t) : _time(t){}

    void manufacture(){
        std::cout << "manufacturing Modern Leg (" << _time << " Min)"<< std::endl;
    }
    int manufacturingTime(){
        return _time;
    }
    void extramanufacturingTime(int t){
        _time += t;
    }
};

class ClassicFrame : public BedComponent{
    int _time;
public:
    ClassicFrame(int t) : _time(t){}

    void manufacture(){
        std::cout << "manufacturing Classic Frame (" << _time << " Min)"<< std::endl;
    }
    int manufacturingTime(){
        return _time;
    }
    void extramanufacturingTime(int t){
        _time += t;
    }
};

class ModernFrame : public BedComponent{
    int _time;
public:
    ModernFrame(int t) : _time(t){}

    void manufacture(){
        std::cout << "manufacturing Modern Frame (" << _time << " Min)"<< std::endl;
    }
    int manufacturingTime(){
        return _time;
    }
    void extramanufacturingTime(int t){
        _time += t;
    }
};

class ClassicMat : public BedComponent{
    int _time;
public:
    ClassicMat(int t) : _time(t){}

    void manufacture(){
        std::cout << "manufacturing Classic Mat (" << _time << " Min)"<< std::endl;
    }
    int manufacturingTime(){
        return _time;
    }
    void extramanufacturingTime(int t){
        _time += t;
    }
};

class ModernMat : public BedComponent{
    int _time;
public:
    ModernMat(int t) : _time(t){}

    void manufacture(){
        std::cout << "manufacturing Modern Mat (" << _time << " Min)"<< std::endl;
    }
    int manufacturingTime(){
        return _time;
    }
    void extramanufacturingTime(int t){
        _time += t;
    }
};

class BedLegLine : public BedComponent{
    std::vector<BedComponent*> v;
public:
    BedLegLine() : BedComponent() {};

    void addItem(BedComponent* item) {
        v.push_back(item);
    }
    void manufacture(){
        for(size_t i = 0 ; i < v.size() ; i++){
            v[i]->manufacture();
        }
    }
    int manufacturingTime(){
        int totalTime = 0;
        for(size_t i = 0 ; i < v.size() ; i++){
            totalTime += v[i]->manufacturingTime();
        }
        return totalTime;
    }
    void extramanufacturingTime(int t){}
};

class BedFrameLine : public BedComponent{
    std::vector<BedComponent*> v;
public:
    BedFrameLine() : BedComponent() {};

    void addItem(BedComponent* item) {
        v.push_back(item);
    }
    void manufacture(){
        for(size_t i = 0 ; i < v.size() ; i++){
            v[i]->manufacture();
        }
    }
    int manufacturingTime(){
        int totalTime = 0;
        for(size_t i = 0 ; i < v.size() ; i++){
            totalTime += v[i]->manufacturingTime();
        }
        return totalTime;
    }
    void extramanufacturingTime(int t){}
};

class BedMatLine : public BedComponent{
    std::vector<BedComponent*> v;
public:
    BedMatLine() : BedComponent() {};

    void addItem(BedComponent* item) {
        v.push_back(item);
    }
    void manufacture(){
        for(size_t i = 0 ; i < v.size() ; i++){
            v[i]->manufacture();
        }
    }
    int manufacturingTime(){
        int totalTime = 0;
        for(size_t i = 0 ; i < v.size() ; i++){
            totalTime += v[i]->manufacturingTime();
        }
        return totalTime;
    }
    void extramanufacturingTime(int t){}
};

//////// Decorator /////////
class Decorator : public BedComponent{
    BedComponent* pComponent; 
public:
    Decorator(BedComponent* bc) : pComponent(bc){}

    void manufacture(){
        pComponent->manufacture();
    }
    int manufacturingTime(){
        pComponent->manufacturingTime();
    }
    void extramanufacturingTime(int t){
        pComponent->extramanufacturingTime(t);
    }
};

class FlowerPattern : public Decorator{
    int _extraTime;
public:
    FlowerPattern(BedComponent* bc, int t) : Decorator(bc), _extraTime(t){}

    void manufacture(){
        std::cout << "(add flower Pattern) ";
        Decorator::extramanufacturingTime(_extraTime);
        Decorator::manufacture();
    }
    int manufacturingTime(){
        Decorator::manufacturingTime();
    }
};

class TraditionalPattern : public Decorator{
    int _extraTime;
public:
    TraditionalPattern(BedComponent* bc, int t) : Decorator(bc), _extraTime(t){}

    void manufacture(){
        std::cout << "(add traditional Pattern) ";
        Decorator::extramanufacturingTime(_extraTime);
        Decorator::manufacture();
    }
    int manufacturingTime(){
        Decorator::manufacturingTime();
    }
};

class StarPattern : public Decorator{
    int _extraTime;
public:
    StarPattern(BedComponent* bc, int t) : Decorator(bc), _extraTime(t){}

    void manufacture(){
        std::cout << "(add star Pattern) ";
        Decorator::extramanufacturingTime(_extraTime);
        Decorator::manufacture();
    }
    int manufacturingTime(){
        Decorator::manufacturingTime();
    }
};