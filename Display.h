#include "World.h"
#include<cstdio>
#include<unistd.h>
#include<stdlib.h>

const char LIVING = 'o';
const char DEATH = ' ';

class Display
{
public:
    Display(World* world)
    {
        _world = new World(world->width(),world->height(),world->map());
    }

    void show(int width, int height, bool **map){
        for(int row=0; row<width; row++){
            for(int cow=0; cow<height; cow++){
                if(map[row][cow])
                    printf("%c",LIVING);
                else
                    printf("%c",DEATH);
            }
            printf("\n");
        }
    }

    void show()
    {
        show(_world->width(),_world->height(),_world->map());
    }

    void clear(){
        system("clear");
    }
    void msleep(int urate){
        usleep(urate*1000);
    }
    void animationEnd(){
        printf("世界和平！\n");
    }
    void animation(int mrate = 1000){
        clear();
        show();
        bool** map=NULL;
        while((map = _world->next())!=NULL){
            msleep(mrate);
            clear();
            show();
        }
        animationEnd();
    }
private:
    World* _world;
};