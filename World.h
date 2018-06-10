#ifndef WORLDH
#define WORLDH
#include<cstring>
#include<time.h>
#include<cstdlib>
class World
{
public:
    World(int width, int height, bool **map){
        randWorld(width,height);
        for(int row=0; row<width; row++){
            for(int cow=0; cow<height; cow++){
                _map[row][cow] = map[row][cow];
            }
        }
    }
    World(int width,int height){
        randWorld(width,height);
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
    
    bool cmp(bool** now,bool** next){
        for(int cow=0;cow<_width;cow++){
            if(memcmp(now[cow],next[cow],_height))
                return false;
        }
        return true;
    }

    bool** next(){
        bool **next = nextState();
        if(cmp(next,_map)){
            free();
            return NULL;
        }
        free();
        _map = next;
        return _map;
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
    void randWorld(int width,int height,bool rand_init=false){
        if(rand_init){
            srand(time(NULL));
        }
        _width = width;
        _height = height;
        _map = new bool*[width];
        for(int row=0;row<width;row++){
            _map[row] = new bool[height];
            for(int cow = 0;cow<height;cow++){
                _map[row][cow]=(bool)(rand()%2);
            }
        }
    }
};
#endif