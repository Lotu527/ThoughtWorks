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

private:
    int _width;
    int _height;
    bool ** _map;
};