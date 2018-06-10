#include "Display.h"
#include "World.h"

int main(int argc, char* argv[])
{
    if(argc == 2){
        Display display(argv[1]);
        display.animation();
    }else if(argc == 1){
        srand(time(NULL));
        Display display(new World(rand()%50+10,rand()%60+10));
        display.animation();
    }

    return 0;
}
