#include "GridArea.h"
#include <iostream>
#include <cmath>
#include <iomanip>

// Default Constructor
GridArea::GridArea() : GridArea(0, 0, UNKNOWN, 0, 0) {}

// Constructor with X and Y only
GridArea::GridArea(int _x, int _y) : GridArea(_x, _y, UNKNOWN, 0, 0) {}

// Constructor with Terrain Type
GridArea::GridArea(int _x, int _y, TERRAIN_TYPE _t) : GridArea(_x, _y, _t, 0, 0) {}

// Constructor with all parameters
GridArea::GridArea(int _x, int _y, TERRAIN_TYPE _t, long _shldEngReqd, long _movtEngReqd) {
    x = _x;
    y = _y;
    terrain = _t;
    shldEngReqd = _shldEngReqd;
    movtEngReqd = _movtEngReqd;
}

// Accessor Methods
int GridArea::getX() const { return x; }
int GridArea::getY() const { return y; }
TERRAIN_TYPE GridArea::getTerrain() const { return terrain; }
long GridArea::getShldEngReqd() const { return shldEngReqd; }
long GridArea::getMovtEngReqd() const { return movtEngReqd; }

// Mutator Methods
void GridArea::setX(int _x) { x = _x; }
void GridArea::setY(int _y) { y = _y; }
void GridArea::setTerrain(TERRAIN_TYPE _t) { terrain = _t; }
void GridArea::setShldEngReqd(long _newValue) { shldEngReqd = _newValue; }
void GridArea::setMovtEngReqd(long _newValue) { movtEngReqd = _newValue; }

// Utility Function: Check if two points are adjacent
bool GridArea::isAdjacent(const GridArea& anotherPt) const {
    int verticalDist = abs(anotherPt.y - y);
    int horizontalDist = abs(anotherPt.x - x);
    return ((anotherPt.x == x && verticalDist == 1) || (anotherPt.y == y && horizontalDist == 1));
}

// Convert character symbol to TERRAIN_TYPE
TERRAIN_TYPE GridArea::convertCharToTerrainType(char terrainSymbol) {
    switch (terrainSymbol) {
        case '#': return BARRIER;
        case 'S': return START;
        case 'E': return END;
        case 'X': return DANGER;
        case 'g': return GRASS_LAND;
        case 'j': return JUNGLE;
        case 'M': return MOUNTAINOUS;
        case 'w': return WATERY;
        case 'h': return HILLY;
        case '~': return SWAMP;
        case 'f': return FOREST;
        default: return UNKNOWN;
    }
}

// Convert TERRAIN_TYPE to string
string GridArea::convertTerrainToString() const {
    switch (terrain) {
        case BARRIER: return "BARRIER";
        case START: return "START";
        case END: return "END";
        case DANGER: return "DANGER";
        case GRASS_LAND: return "GRASS_LAND";
        case JUNGLE: return "JUNGLE";
        case MOUNTAINOUS: return "MOUNTAINOUS";
        case WATERY: return "WATERY";
        case HILLY: return "HILLY";
        case SWAMP: return "SWAMP";
        case FOREST: return "FOREST";
        default: return "UNKNOWN";
    }
}

// Display grid information
void GridArea::displayInfo() const {
    cout << "GridArea [" << x << ", " << y << "], Terrain: "
         << convertTerrainToString() << endl;
}
