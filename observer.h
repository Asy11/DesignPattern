#include <list>
#include <iostream>
#include <string.h>

class Subject;

class Observer{
public:
    virtual void update(Subject* s) = 0;
    int idx;
};

class Subject{
public:
    virtual void attach(Observer*) = 0;
    virtual void detach(Observer*) = 0;
    virtual void notify() = 0;
};

class TemperatureSubject : public Subject{
public:
    TemperatureSubject() : _temperature(36.5){}

    void attach(Observer* o){
        _observers.push_back(o);
        o->idx = _observers.size() - 1;
    }
    void detach(Observer* o){
        _observers.remove(o);
    }
    void notify(){
        std::list<Observer*>::iterator it;
        for(it = _observers.begin(); it != _observers.end(); it++){
            //noti to everyone
            (*it)->update(this);
        }
    }
    float getTemperture(){
        return _temperature;
    }
    float setTemperture(float t){
        _temperature = t;
    }
    
private:
    std::list<Observer*> _observers;
    float _temperature; 
};

class TemperatureObserver : public Observer{
public:
    TemperatureObserver(TemperatureSubject* t) : _tsubject(t) {
        _tsubject->attach(this);
        std::cout<< "attach succ" <<std::endl;
    }
    ~TemperatureObserver(){
        _tsubject->detach(this);
        std::cout<< "detach succ" <<std::endl;
    }
    void update(Subject* s){
        if(s == _tsubject){
            change();
        }
    }
    void change(){
        float temperature = _tsubject->getTemperture();

        if(temperature > 36.5){
            std::cout<< "start cooling" << std::endl;
            _tsubject->setTemperture(30);
        }
        else{
            std::cout<< "water temperature is still ok" <<std::endl;
        }
    }

private:
    TemperatureSubject* _tsubject;
};
