#pragma once
#include <vector>
#include <random>
class Conway {
public:
    std::vector<std::vector<uint8_t>> cells;
    int w, h;

    Conway(int _w, int _h) : w(_w), h(_h) {
        for(int x = 0; x < w; x++){
            cells.push_back({});
            for(int y = 0; y < h; y++){
                cells[x].push_back( rand() % 8 ? 0 : 1);
            }
        }
        nextFrame();
    }
    
    void getRowAjacencies(std::vector<int>& ajacent, int y, int x, bool cellsRow) {
        if(x > 0){
            if(cells[x-1][y] == 1)
                ajacent.push_back(x);
        }
        if(x < w - 1){
            if(cells[x+1][y] == 1)
                ajacent.push_back(x);
        }
        if(!cellsRow){
            if(cells[x][y] == 1)
                ajacent.push_back(x);
        }
    }
    void nextFrame(){

        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                std::vector<int> ajacent;  // Hold the neighbors
                // Check all 8 neighbors
                if(y > 0){
                    getRowAjacencies(ajacent, y-1, x, false);
                }
                if(y < h-1){
                    getRowAjacencies(ajacent, y+1, x, false);
                }
                getRowAjacencies(ajacent, y, x, true);
                // Now apply the Game of Life rules
                uint8_t p = cells[x][y];
                if (p == 1) {  // Alive cell
                    if (ajacent.size() < 2 || ajacent.size() > 3) {
                        cells[x][y] = 0;  // Cell dies
                    }
                } else {  // Dead cell
                    if (ajacent.size() == 3) {
                        cells[x][y] = 1;  // Cell becomes alive
                    }
                }
                ajacent.clear();
            }
        }
    }
    
};