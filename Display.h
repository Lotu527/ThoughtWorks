#ifndef DISPLAYH
#define DISPLAYH
#include "World.h"
#include "KeyBoard.h"
#include<cstdio>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
const char LIVING = 'o';
const char DEATH = ' ';
class Display
{
public:
    Display(World* world)
    {
        _world = new World(world->width(),world->height(),world->map());
        DISPLAY_RATE = 1000;
    }

    Display(const char* file){
        freopen(file,"r",stdin);
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
        _world = new World(width,height,map);
        DISPLAY_RATE = rate;
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
    
    void animation(){
        listen();
        clear();
        show();
        bool** map=NULL;
        while((map = _world->next())!=NULL){
            while(DISPLAY_STOP){
                msleep(DISPLAY_RATE);
            }
            msleep(DISPLAY_RATE);
            clear();
            show();
        }
        animationEnd();
    }
    World* world(){
        return _world;
    }
private:
    World* _world;
};
#endif