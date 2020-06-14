#include "group.h"

int main(int argc, char* argv[]){
//// Abstract Fac ////
	Bed* MyBed;

    if(argc > 2){
	    if(!strcmp(argv[1], "Ace"))
	    	MyBed = new Bed_Ace();
	    else
	    	MyBed = new Bed_Simons();

        Leg* MyBedLeg = MyBed->createLeg();
        Frame* MyBedFrame = MyBed->createFrame();
        Mat* MyBedMat = MyBed->createMat();
    }

//// Composite ////
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

//// Decorator ////
    myBedLegLine->addItem(new FlowerPattern(new ClassicLeg(2), 5));  
    myBedLegLine->addItem(new TraditionalPattern(new ClassicLeg(2), 10));  
    myBedLegLine->addItem(new StarPattern(new ClassicLeg(2), 15));    
    myBedLegLine->addItem(new TraditionalPattern(new FlowerPattern(new StarPattern(new ClassicLeg(2), 15), 5), 10));    

    //myBedLegLine->manufacture();

    //std::cout << myBedLegLine->manufacturingTime() << std::endl;

//// facade /////
    BedLineProcess* myBedLineProcess = new BedLineProcess();

    if(myBedLineProcess->run("Leg", myBedLegLine))
        std::cout << myBedLegLine->manufacturingTime() << std::endl;

    if(myBedLineProcess->run("Frame", myBedFrameLine))
        std::cout << myBedFrameLine->manufacturingTime() << std::endl;

    if(myBedLineProcess->run("Mat", myBedMatLine))
        std::cout << myBedMatLine->manufacturingTime() << std::endl;

	return 0;
}