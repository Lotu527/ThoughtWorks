#include<cstdio>
#include<unistd.h>
#include<stdlib.h>
#include<cstring>

const char LIVING = 'o';
const char DEATH = ' ';

class World
{
public:
    World(int width, int height, bool **map){
        _width = width;
        _height = height;
        _map = new bool*[width];
        for(int row=0;row<height;row++){
            _map[row] = new bool[height];
        }

        for(int row=0; row<width; row++){
            for(int cow=0; cow<height; cow++){
                _map[row][cow] = map[row][cow];
            }
        }
    } 

    ~World(){
        free();
    }

    int width(){
        return _width;
    }

    int height(){
        return _height;
    }

    bool **map(){
        return _map;
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

    void show(){
        show(_width,_height,_map);
    }

    int livingCellsNums(int cellsX,int cellsY){
        int livingCellsNum = 0;

        for(int row=0; row<3; row++){
            for(int cow=0; cow<3; cow++){
                if(cellsX-1+row < 0 || cellsY-1+cow < 0)
                    continue;
                if(cellsX-1+row > _width-1 || cellsY-1+cow > _height-1)
                    continue;
                if(row==1 && cow==1)
                    continue;
                if(_map[cellsX-1+row][cellsY-1+cow])
                    livingCellsNum++;
            }
        }
        return livingCellsNum;
    }

    bool nextState(int cellsX, int cellsY){
        
        int livingCellsNum = livingCellsNums(cellsX,cellsY);

        if( livingCellsNum == 2 ){
            return _map[cellsX][cellsY];
        }
        if( livingCellsNum == 3 ){
            return true;
        }      
        return false; 
    }

    bool ** nextState(){
        bool **mapNext = new bool*[_width];
        for(int row=0; row<_width; row++){
            mapNext[row] = new bool[_height];
            for(int cow=0; cow< _height; cow++){
                mapNext[row][cow] = nextState(row ,cow);
            }
        }
        return mapNext;
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
        show(_width,_height,_map);
        bool** map=nextState();
        while(!cmp(map,_map)){
            msleep(mrate);
            clear();
            show(_width,_height,map);
            free();
            _map = map;
            map = nextState();
        }
        animationEnd();
    }

private:
    int _width;
    int _height;
    bool ** _map;

    void free(){
        for(int row=0;row<_width;row++)
            delete[] _map[row];
        delete[] _map;
        _map=NULL;
    }

    bool cmp(bool** now,bool** next){
        for(int cow=0;cow<_width;cow++){
            if(memcmp(now[cow],next[cow],_height))
                return false;
        }
        return true;
    }
};