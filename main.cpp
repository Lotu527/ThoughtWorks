#include "Display.h"
#include "World.h"
const int maxRow = 60;
const int maxCow = 70;
const int minRow = 10;
const int minCow = 10;
int main(int argc, char* argv[])
{
    if(argc == 2){
        Display display(argv[1]);
        display.animation();
    }else if(argc == 1){
        srand(time(NULL));
        Display display(new World(rand()%maxRow+minRow,rand()%maxCow+minCow));
        display.animation();
    }
    return 0;
}
