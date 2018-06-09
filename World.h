#include<cstdio>
#include<unistd.h>
#include<stdlib.h>
const char LIVING = 'o';
const char DEATH = ' ';

class World
{
public:
    World(int width, int height, bool **map){
        _width = width;
        _height = height;
        _map = new bool*[width];
        for(int i=0;i<height;i++){
            _map[i] = new bool[height];
        }

        for(int i=0; i<width; i++){
            for(int j=0; j<height; j++){
                _map[i][j] = map[i][j];
            }
        }
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
        for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                if(map[i][j])
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

    bool nextState(int cellsX, int cellsY){
        
        int livingCellsNum = 0;

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(cellsX-1+i < 0 || cellsY-1+j < 0)
                    continue;
                if(cellsX-1+i > _width-1 || cellsY-1+j > _height-1)
                    continue;
                if(i==1 && j==1)
                    continue;
                if(_map[cellsX-1+i][cellsY-1+j])
                    livingCellsNum++;
            }
        }
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
        for(int i=0;i<_width;i++){
            mapNext[i] = new bool[_height];
            for(int j=0; j< _height; j++){
                mapNext[i][j] = nextState(i ,j);
            }
        }
        return mapNext;
    }
    void clear(){
        system("clear");
    }
    void animation(int rate = 1 , int times = 50){
        bool** map=NULL;
        while(times--){
            clear();
            map = nextState();
            show(_width,_height,map);
            usleep(rate*1000);
            this->free();
            _map = map;
        }
    }

private:
    int _width;
    int _height;
    bool ** _map;

    void free(){
        for(int i=0;i<_width;i++)
            delete[] _map[i];
        delete[] _map;
        _map=NULL;
    }
};