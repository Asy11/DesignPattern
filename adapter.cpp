#include "adapter.h"

int main(void){

    StorageBed_Class* SBed_C = new StorageBed_Class();
    Bed* SimmonsBed = SBed_C;
    
    SimmonsBed->Use();

    Cabinet* IkeaCabinet = new Cabinet();
    StorageBed_Object SBed_O(IkeaCabinet);
    Bed* IkeaBed = &SBed_O;

    IkeaBed->Use();

    return 0;
}