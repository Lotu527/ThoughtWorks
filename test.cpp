#include<assert.h>
#include "Display.h"
#include<fstream>
#include<iostream>
#include<cstdio>

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

    // World worldshow(width, height, map);
    // worldshow.show();

}

void TestCalculateTheNextStateOfWorld()
{
    const int width=5;
    const int height=5;
    const int cellsX=3;
    const int cellsY=3;
    const int cellsX1=0;
    const int cellsY1=0;
    const int cellsX2=4;
    const int cellsY2=4;
    bool ** map = new bool*[width];
    for(int row=0;row<width;row++){
        map[row] = new bool[height];
        for(int cow=0;cow<height;cow++)
        if((row == cow) || (row+cow == width-1)){
            map[row][cow] = 1;
        }
    }  

    bool ** nextMap = new bool*[width];
    for(int row=0;row<width;row++){
        nextMap[row] = new bool[height];
        for(int cow = 0;cow<height;cow++){
            if(row>0 && row<width-1 && cow>0 && cow<height-1){
                nextMap[row][cow]=1;
            }
        }
    }
    nextMap[2][2]=0;
      
    
    World world(width,height,map);

    assert(world.nextState(cellsX,cellsY)==1);    
    assert(world.nextState(cellsX1,cellsY1)==0);
    assert(world.nextState(cellsX2,cellsY2)==0);
    map=world.nextState();
    for(int row=0;row<width;row++){
        for(int cow = 0;cow<height;cow++){
            assert(map[row][cow]==nextMap[row][cow]);
        }
    }

}

void TestAnimation()
{
    int width = 50;
    int height = 100;
    bool ** map = new bool*[width];
    for(int row=0;row<width;row++){
        map[row] = new bool[height];
        for(int cow=0;cow<height;cow++)
        if((row == cow) || (row+cow == width-1)){
            map[row][cow] = 1;
        }
    }   

    World *world = new World(width,height,map);
    Display display(world);
    display.animation();

}

void TestDisplayInput()
{
    freopen("data.in","r",stdin);
    int width;
    int height;
    int rate;
    scanf("%d %d %d",&width,&height,&rate);
    bool ** map = new bool*[width];
    for(int row=0,tmp;row<width;row++){
        map[row] = new bool[height];
        for(int cow=0;cow<height;cow++){
            scanf("%d",&tmp);
            if(tmp)
                map[row][cow]=true;
            else
                map[row][cow]=false;
        }
    }
    Display display("data.in");

    for(int row=0;row<width;row++){
        for(int cow=0;cow<height;cow++){
            assert(map[row][cow]==display.world()->map()[row][cow]);
        }
    }
    display.animation();
    
}
void TestAdjustRate()
{
    TestAnimation();
} 
int main()
{
    TestInitWorld();
    TestWorldShow();
    TestCalculateTheNextStateOfWorld();
    TestAnimation();
    // TestDisplayInput();
    // TestAdjustRate();
    return 0;
}