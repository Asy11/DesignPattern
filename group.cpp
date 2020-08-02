#include "interpreter.h"
#include "mediator.h"
#include "observer.h"

AbstractExpression* InterpreterTree(){
    AbstractExpression* b = new TerminalExpression("bed");

    AbstractExpression* lu = new TerminalExpression("leg up");
    AbstractExpression* ld = new TerminalExpression("leg down");

    AbstractExpression* bu = new TerminalExpression("body up");
    AbstractExpression* bd = new TerminalExpression("body down");

    // leg up or leg down
    AbstractExpression* legside = new OrExpression(lu, ld);

    // body up or body down
    AbstractExpression* bodyside = new OrExpression(bu, bd);

    // move
    AbstractExpression* move = new OrExpression(legside, bodyside);

    // legside or bodyside
    return new AndExpression(b, move);
}

AbstractExpression* legUpInterpreter(){
    AbstractExpression* b = new TerminalExpression("bed");
    AbstractExpression* lu = new TerminalExpression("leg up");

    return new AndExpression(b, lu);
}

AbstractExpression* legDownInterpreter(){
    AbstractExpression* b = new TerminalExpression("bed");
    AbstractExpression* ld = new TerminalExpression("leg down");

    return new AndExpression(b, ld);
}

AbstractExpression* bodyUpInterpreter(){
    AbstractExpression* b = new TerminalExpression("bed");
    AbstractExpression* bu = new TerminalExpression("body up");

    return new AndExpression(b, bu);
}

AbstractExpression* bodyDownInterpreter(){
    AbstractExpression* b = new TerminalExpression("bed");
    AbstractExpression* bd = new TerminalExpression("body down");

    return new AndExpression(b, bd);
}

AbstractExpression* lu = legUpInterpreter();
AbstractExpression* ld = legDownInterpreter();
AbstractExpression* bu = bodyUpInterpreter();
AbstractExpression* bd = bodyDownInterpreter();

void voiceRecognition(std::string s, Bed* mybed){
    bool legUp, legDown, bodyUp, bodyDown;

    legUp    = lu->evaluate(s);
    legDown  = ld->evaluate(s);
    bodyUp   = bu->evaluate(s);
    bodyDown = bd->evaluate(s);

    if(legUp){
        std::cout << s << " -> "<< legUp << std::endl;
        mybed->movement(15, LEG_UP);
    }
    else if(legDown){
        std::cout << s << " -> "<< legDown << std::endl;  
        mybed->movement(15, LEG_DOWN);      
    }
    else if(bodyUp){
        std::cout << s << " -> "<< bodyUp << std::endl; 
        mybed->movement(15, BODY_UP);      
    }
    else if(bodyDown){
        std::cout << s << " -> "<< bodyDown << std::endl;  
        mybed->movement(15, BODY_DOWN);      
    }
    else{
        std::cout << s << " -> " << "Wrong msg" << std::endl;
    }
}

int main(int argc, char* argv[]){
//// Abstract Fac ////
/*
	Bed* MyBed;

    if(argc > 1){
	    if(!strcmp(argv[1], "Ace"))
	    	MyBed = new Bed_Ace();
	    else
	    	MyBed = new Bed_Simons();

        Leg* MyBedLeg = MyBed->createLeg();
        Frame* MyBedFrame = MyBed->createFrame();
        Mat* MyBedMat = MyBed->createMat();
    }
*/
//// Composite ////
/*
    BedLegLine* myBedLegLine = new BedLegLine();
    myBedLegLine->addItem(new ClassicLeg(2));
    myBedLegLine->addItem(new ModernLeg(4));

    BedFrameLine* myBedFrameLine = new BedFrameLine();
    myBedFrameLine->addItem(new ClassicFrame(4));
    myBedFrameLine->addItem(new ModernFrame(8));

    BedMatLine* myBedMatLine = new BedMatLine();
    myBedMatLine->addItem(new ClassicMat(8));
    myBedMatLine->addItem(new ModernMat(12));

    //std::cout << myBedLegLine->manufacturingTime() << std::endl;
    //std::cout << myBedFrameLine->manufacturingTime() << std::endl;
    //std::cout << myBedMatLine->manufacturingTime() << std::endl;
*/
//// Decorator ////
/*
    myBedLegLine->addItem(new FlowerPattern(new ClassicLeg(2), 5));  
    myBedLegLine->addItem(new TraditionalPattern(new ClassicLeg(2), 10));  
    myBedLegLine->addItem(new StarPattern(new ClassicLeg(2), 15));    
    myBedLegLine->addItem(new TraditionalPattern(new FlowerPattern(new StarPattern(new ClassicLeg(2), 15), 5), 10));    

    //myBedLegLine->manufacture();

    //std::cout << myBedLegLine->manufacturingTime() << std::endl;
*/
//// facade /////
/*
    BedLineProcess* myBedLineProcess = new BedLineProcess();

    if(myBedLineProcess->run("Leg", myBedLegLine))
        std::cout << myBedLegLine->manufacturingTime() << std::endl;

    if(myBedLineProcess->run("Frame", myBedFrameLine))
        std::cout << myBedFrameLine->manufacturingTime() << std::endl;

    if(myBedLineProcess->run("Mat", myBedMatLine))
        std::cout << myBedMatLine->manufacturingTime() << std::endl;
*/

//// interpreter with strategy ////
    Bed_Simons* mybed = new Bed_Simons();

    voiceRecognition("bed, I want my leg up", mybed);
    voiceRecognition("leg down please my bed", mybed);
    voiceRecognition("body down please", mybed);

//// mediator ////
/*
    ControlPanel* cp = new ControlPanel();

    cp->createWidget();
    cp->showMenu();

    cp->pMusic();
    cp->onProjector();
*/

//// observer ////
/*
    TemperatureSubject* ts = new TemperatureSubject();
    TemperatureObserver* to = new TemperatureObserver(ts);

    for(size_t i = 0 ; i < 20 ; i++)
    {
        ts->setTemperture(ts->getTemperture()+0.5);
        ts->notify();
    }
*/
	return 0;
}