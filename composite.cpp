#include "composite.h"

int main (void)
{
    ProductLine* BedFactory = new ProductLine("Bed Factory");
    ProductLine* BedLegLine = new ProductLine("BedLeg Line");
    ProductLine* BedMatLine = new ProductLine("BedMat Line");
    ProductLine* BedFrameLine = new ProductLine("BedFrame Line");

    BedFactory->addItem(BedLegLine);
    BedFactory->addItem(BedMatLine);
    BedFactory->addItem(BedFrameLine);

    Product* ClassicLeg = new Product("Classic Leg", 3);
    Product* ModernLeg = new Product("Modern Leg", 5);
    
    BedLegLine->addItem(ClassicLeg);
    BedLegLine->addItem(ModernLeg);

    Product* ClassicMat = new Product("Classic Mat", 8);
    Product* ModernMat = new Product("Modern Mat", 10);
    
    BedMatLine->addItem(ClassicMat);
    BedMatLine->addItem(ModernMat);

    Product* ClassicFrame = new Product("Classic Frame", 10);
    Product* ModernFrame = new Product("Modern Frame", 12);
    
    BedFrameLine->addItem(ClassicFrame);
    BedFrameLine->addItem(ModernFrame);

    BedFactory->manufacture();
    std::cout << BedFactory->manufacturingTime() << std::endl;
    BedLegLine->manufacture();
    std::cout << BedLegLine->manufacturingTime() << std::endl;
    BedMatLine->manufacture();
    std::cout << BedMatLine->manufacturingTime() << std::endl;
    BedFrameLine->manufacture();
    std::cout << BedFrameLine->manufacturingTime() << std::endl;

    return 0;
}