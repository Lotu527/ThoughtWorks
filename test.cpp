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

int main()
{
    // TestInitWorld();
    TestWorldShow();
    return 0;
}