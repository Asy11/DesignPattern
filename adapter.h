#include <iostream>
#include <string>

using namespace std;

class Bed {
public:
    virtual void Use() = 0;
};

class Cabinet{
public:
    void Store(){
        cout << "use cabinet" << endl;
    }
};

// 클래스 어답터
class StorageBed_Class : public Bed, public Cabinet{
public:
    void Use() {
        cout << "lay down on bed" << endl;
        Cabinet::Store();
    }
};

// 객체 어답터
class StorageBed_Object : public Bed{
    Cabinet* cabinet_instance;
public:
    StorageBed_Object(Cabinet* c) : cabinet_instance(c) {};
    void Use() {
        cout << "lay down on bed" << endl;
        cabinet_instance->Store();
    }
};