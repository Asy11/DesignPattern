#include "interpreter.h"
#include "mediator.h"
#include "observer.h"

AbstractExpression* buildInterpreterTree(){
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

//// interpreter ////
    Bed_Simons* mybed = new Bed_Simons();

    std::string context1("bed, I want my leg up");
    std::string context2("body down please my bed");
    std::string context3("body down please");

    AbstractExpression* myInterpreterTree = buildInterpreterTree();

    std::cout << context1 << " -> "<< myInterpreterTree->evaluate(context1) << std::endl;
    mybed->moveLegUp(15);
    std::cout << context2 << " -> "<< myInterpreterTree->evaluate(context2) << std::endl;
    mybed->moveBodyUp(15);
    std::cout << context3 << " -> "<< myInterpreterTree->evaluate(context3) << std::endl;

//// mediator ////
    ControlPanel* cp = new ControlPanel();

    cp->createWidget();
    cp->showMenu();

    cp->pMusic();
    cp->onProjector();


//// observer ////
    TemperatureSubject* ts = new TemperatureSubject();
    TemperatureObserver* to = new TemperatureObserver(ts);

    for(size_t i = 0 ; i < 20 ; i++)
    {
        ts->setTemperture(ts->getTemperture()+0.5);
        ts->notify();
    }

	return 0;
}