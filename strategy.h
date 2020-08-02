#include <iostream>

enum VOICE_REC{
    BODY_UP = 1,
    BODY_DOWN = 2,
    LEG_UP = 3,
    LEG_DOWN = 4
};

class Strategy{
public: 
    virtual void changeAngel(int angle, int &curAngle) = 0;
};

class BodySideUP : public Strategy{
public:
    void changeAngel(int angle, int &curAngle){
        if( 0 <= curAngle &&  curAngle <= 30 )
            curAngle += angle;
        std::cout << "current body angel is " << curAngle << std::endl;
    }
};

class BodySideDown : public Strategy{
public:
    void changeAngel(int angle, int &curAngle){
        if( 15 <= curAngle &&  curAngle <= 45 )
            curAngle -= angle;
        std::cout << "current body angel is " << curAngle << std::endl;
    }
};

class LegSideUP : public Strategy{
public:
    void changeAngel(int angle, int &curAngle){
        if( 0 <= curAngle &&  curAngle <= 30 )
            curAngle += angle;
        std::cout << "current leg angel is " << curAngle << std::endl;
    }
};

class LegSideDown : public Strategy{
public:
    void changeAngel(int angle, int &curAngle){
        if( 15 <= curAngle &&  curAngle <= 45 )
            curAngle -= angle;
        std::cout << "current leg angel is " << curAngle << std::endl;
    }
};