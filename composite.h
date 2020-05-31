#include <iostream>
#include <string>
#include <vector>

class Item{
    std::string _name; 
 public:
    Item(std::string name) : _name(name) {}
    std::string GetName() { return _name; }
    virtual void manufacture() = 0;
    virtual int manufacturingTime() = 0;
};

class ProductLine : public Item{
    std::vector<Item*> v;
public:
    ProductLine(std::string name) : Item(name) {};
    void addItem(Item* item) {
        v.push_back(item);
    }
    void manufacture() {
        for(int i = 0 ; i < v.size() ; i++){
            v[i]->manufacture();
        }
    }
    int manufacturingTime() {
        int totalTime = 0;
        for(int i = 0 ; i < v.size() ; i++){
            totalTime += v[i]->manufacturingTime();
        }
        return totalTime;
    }

};

class Product : public Item{
    int _time;
public:
    Product(std::string name, int time) : Item(name), _time(time) {}
    void manufacture() {
        std::cout << "manufacturing " << GetName() << std::endl;
    }
    int manufacturingTime() {
        return _time;
    }
};