#include "Display.h"
#include "World.h"

int main(int argc, char* argv[])
{
    if(argc == 2){
        Display display(argv[1]);
        display.animation();
    }else if(argc == 1){
        Display display(new World(40,40));
        display.animation();
    }

    return 0;
}
