#include <iostream>
#include <string.h>
#include <vector>
#include <cstring>

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
    Bed_Simons() { LegSideAngle = 0; BodySideAngle = 0; }

	Leg* createLeg(){
		return new Leg_Simons(); 
	}
	Frame* createFrame(){
		return new Frame_Simons();
	}
    Mat* createMat(){
		return new Mat_Simons();
	}

    bool moveLegUp(int angle){
        if( 0 <= LegSideAngle &&  LegSideAngle <= 30 )
            LegSideAngle += angle;
        std::cout << "current leg angel is " << LegSideAngle << std::endl;
    }

    bool moveLegDown(int angle){
        if( 15 <= LegSideAngle &&  LegSideAngle <= 45 )
            LegSideAngle -= angle;
        std::cout << "current leg angel is " << LegSideAngle << std::endl;
    }

    bool moveBodyUp(int angle){
        if( 0 <= BodySideAngle &&  BodySideAngle <= 30 )
            BodySideAngle += angle;
        std::cout << "current body angel is " << LegSideAngle << std::endl;
    }

    bool moveBodyDown(int angle){
        if( 15 <= BodySideAngle &&  BodySideAngle <= 45 )
            BodySideAngle += angle;
        std::cout << "current body angel is " << LegSideAngle << std::endl;
    }

private:
    int LegSideAngle;
    int BodySideAngle;
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

class BedComponentLine : public BedComponent{
    std::vector<BedComponent*> v;
public:

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

    int sizeOfBedComponentLine(){
        return v.size();
    }
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

////////// proxy pattern ///////////
class Electric{

public:
    virtual bool getElectric() = 0;
    virtual void setElectric(bool e) = 0;
};

/////// facade pattern ////////
class ElectricCenter : public Electric{
    bool electric;
public:
    ElectricCenter() { electric = false; }

    void setElectric(bool e){
        electric = e;
    }

    bool getElectric(){
        return electric;
    }
};

class ElectricProxy : public Electric{
    ElectricCenter* ec;
    int referenceCount;
public:
    ElectricProxy(){ ec = new ElectricCenter(); referenceCount = 0; }

    int checkElectricUseCount(){
        return referenceCount;
    }

    bool getElectric(){
        if( checkElectricUseCount() <= 100 ){
            referenceCount++;
            std::cout<< "전기 사용량 : " << referenceCount  << std::endl;
            return ec->getElectric();
        }
        else{
            std::cout<< "전기 사용량 초과" << std::endl;
            return false;
        }   
    }

    void setElectric(bool e){
        ec->setElectric(e);
    }

};

class ResourcePreprocess{
    int wood;
    int moltenPlastic;
    int moltenSteel;
    int clothes;
public:
    ResourcePreprocess() { wood = 0; moltenPlastic = 0 ; moltenSteel = 0; clothes = 0; }

    void Preprocess( ElectricProxy* p, const char* c ){
        if( p->getElectric() ){
            if( !strcmp(c, "wood") ){
                wood += 1;
            }
            else if ( !strcmp(c, "moltenPlastic") ){
                moltenPlastic += 1;
            }
            else if ( !strcmp(c, "moltenSteel") ){
                moltenSteel += 1;
            }
            else if ( !strcmp(c, "clothes") ){
                clothes += 1;
            }
            else{
                std::cout<< "올바른 재료 이름을 입력하세요" << std::endl;
            }
        }
    }

    bool getWood(){
        if(wood > 0){
            wood -= 1;
            return true;
        }
        else{
            return false;
        }
    }

    int getMoltenPlastic(){
        if(moltenPlastic > 0){
            moltenPlastic -= 1;
            return true;
        }
        else{
            return false;
        }
    }

    int getMoltenSteel(){
        if(moltenSteel > 0){
            moltenSteel -= 1;
            return true;
        }
        else{
            return false;
        }
    }

    int getClothes(){
        if(clothes > 0){
            clothes -= 1;
            return true;
        }
        else{
            return false;
        }
    }
};

class BedLegLine : public BedComponentLine{
public:
    void manufacture(ElectricProxy* p, ResourcePreprocess r){
        if( p->getElectric() && r.getMoltenPlastic() ){
            BedComponentLine::manufacture();
        }
    }
};

class BedFrameLine : public BedComponentLine{
public:
    void manufacture(ElectricProxy* p, ResourcePreprocess r){
        if( p->getElectric() && r.getWood() && r.getMoltenPlastic() && r.getMoltenSteel() ){
            BedComponentLine::manufacture();
        }
    }
};

class BedMatLine : public BedComponentLine{
public:
    void manufacture(ElectricProxy* p, ResourcePreprocess r){
        if( p->getElectric() && r.getClothes() && r.getMoltenSteel() ){
            BedComponentLine::manufacture();
        }
    }
};

class BedLineProcess{
    bool runningstatus;
    ResourcePreprocess r;
    ElectricProxy* proxy;
public:
    BedLineProcess() { proxy = new ElectricProxy(); runningstatus = false; }

    bool stop(){
        runningstatus = false;
        return runningstatus;
    }

    bool run( const char* c, BedComponentLine* b ){
        proxy->setElectric(true);

        if( !strcmp(c, "Leg") ){
            BedLegLine* bll = dynamic_cast<BedLegLine*>(b);

            for(size_t i = 0 ; i < bll->sizeOfBedComponentLine() ; i++){
                r.Preprocess( proxy, "moltenPlastic" );
            }

            bll->manufacture( proxy, r );
        }        
        else if( !strcmp(c, "Frame") ){
            BedFrameLine* bfl = dynamic_cast<BedFrameLine*>(b);

            for(size_t i = 0 ; i < bfl->sizeOfBedComponentLine() ; i++){
                r.Preprocess( proxy, "wood" );
                r.Preprocess( proxy, "moltenPlastic" );
                r.Preprocess( proxy, "moltenSteel" );
            }

            bfl->manufacture( proxy, r );
        }
        else if( !strcmp(c, "Mat") ){
            BedMatLine* bml = dynamic_cast<BedMatLine*>(b);

            for(size_t i = 0 ; i < bml->sizeOfBedComponentLine() ; i++){
                r.Preprocess( proxy, "clothes" );
                r.Preprocess( proxy, "moltenSteel" );
            }

            bml->manufacture( proxy, r );
        }
        else{
            std::cout<< "올바른 생산 라인 이름을 입력하세요" << std::endl;
            return false;
        }
        
        runningstatus = true;
        return runningstatus;
    }

    bool checkStatus() {
        return runningstatus;
    }

};