#ifndef GRIDAREA_H
#define GRIDAREA_H

#include <string>
using namespace std;

enum TERRAIN_TYPE { 
    BARRIER, START, END, DANGER, GRASS_LAND, JUNGLE, 
    MOUNTAINOUS, WATERY, HILLY, SWAMP, FOREST, UNKNOWN 
};

class GridArea {
private:
    int x, y;
    TERRAIN_TYPE terrain;
    long shldEngReqd;  // Shield protection energy
    long movtEngReqd;  // Movement energy

public:
    // Constructors
    GridArea();
    GridArea(int _x, int _y);
    GridArea(int _x, int _y, TERRAIN_TYPE _t);
    GridArea(int _x, int _y, TERRAIN_TYPE _t, long _shldEngReqd, long _movtEngReqd);

    // Accessors
    int getX() const;
    int getY() const;
    TERRAIN_TYPE getTerrain() const;
    long getShldEngReqd() const;
    long getMovtEngReqd() const;

    // Mutators
    void setX(int _x);
    void setY(int _y);
    void setTerrain(TERRAIN_TYPE _t);
    void setShldEngReqd(long _newValue);
    void setMovtEngReqd(long _newValue);

    // Utility functions
    bool isAdjacent(const GridArea& anotherPt) const;
    string convertTerrainToString() const;
    void displayInfo() const;

    static TERRAIN_TYPE convertCharToTerrainType(char terrainSymbol);
};

#endif // GRIDAREA_H
