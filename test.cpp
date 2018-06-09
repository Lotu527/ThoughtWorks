#include<assert.h>
#include "World.h"
void TestInitWorld()
{
    int width=100;
    int height=100;
    bool ** map = new bool*[width];
    for(int i=0;i<width;i++){
        map[i] = new bool[height];
    }
    
    World world(width,height,map);
    assert(width == world.width());
    assert(height == world.height());
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++)
            assert(map[i][j] == world.map()[i][j]);
    }
}

void TestWorldShow()
{
    int width = 100;
    int height = 100;
    bool ** map = new bool*[width];
    for(int i=0;i<width;i++){
        map[i] = new bool[height];
    }

    for(int i=0; i<width; i++){
        for(int j=0; j<height; j++){
            map[i][j] = 1;
        }
    }

    World worldshow(width, height, map);
    worldshow.show();

}

void TestCalculateTheNextStateOfWorld()
{
    int width=10;
    int height=10;
    int cellsX=3;
    int cellsY=3;
    int cellsX1=0;
    int cellsY1=0;
    int cellsX2=9;
    int cellsY2=9;
    bool ** map = new bool*[width];
    for(int i=0;i<width;i++){
        map[i] = new bool[height];
        for(int j=0;j<height;j++)
        if((i == j) || (i+j == 9)){
            map[i][j] = 1;
        }
    }
    

    
    World world(width,height,map);

    world.show();

    assert(world.nextState(cellsX,cellsY)==1);    
    assert(world.nextState(cellsX1,cellsY1)==0);
    assert(world.nextState(cellsX2,cellsY2)==0);
    world.show(width,height,world.nextState());

}

void TestAnimation()
{
    int width = 10;
    int height = 10;
    int rate = 1000;
    bool ** map = new bool*[width];
    for(int i=0;i<width;i++){
        map[i] = new bool[height];
        for(int j=0;j<height;j++)
        if((i == j) || (i+j == width-1)){
            map[i][j] = 1;
        }
    }

    World world(width,height,map);
    world.animation(rate);

}

int main()
{
    TestInitWorld();
    TestWorldShow();
    TestCalculateTheNextStateOfWorld();
    return 0;
}